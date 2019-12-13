#include "NodeInfo.h"
#include "State.h"
#include "NodeOpe.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPACING 15	//最大的输出间距，超过这个间距，剩余的字符就会被截断



/*
 * Author: 谢文韬 Modify：宋淳
 * 作用：返回文件目录下的所有文件名路径
 * 用法：参数path是文件的绝对路径，path不存在返回NULL
*/
char **get_inner_pathes(FileInfo *info)
{
	char *path = info->path;
	char **paths_arr = (char ** )malloc(sizeof(char* ) * info->innerFileNum);  //动态分配内存空间
	DIR *dir = opendir(path);
	struct dirent *entry;
	int num;
	int lenth = strlen(path); //获取文件路径的长度
	if(paths_arr == NULL || dir == NULL)//若path为空路径不存在,或内存分配失败，返回NULL
	{
		return NULL;
	}
	//把小圆点去掉
	readdir(dir);
	readdir(dir);

	for (num=0; num<info->innerFileNum; ++num)
	{
		entry = readdir(dir);
		// char *name = (char *)malloc(sizeof(char) * (strlen(entry->d_name)+1));
		// strcpy(name, entry->d_name);

		paths_arr[num] = (char *) malloc(sizeof(char) * (lenth+strlen(entry->d_name)+2));
		// 另两个空间，一个是\\，一个是\0
		if(paths_arr[num] == NULL) //空间分配失败，返回NULL
		{
			return NULL;
		}

		strcpy(paths_arr[num], path);
		paths_arr[num][lenth] = '\\';  //分隔符

		strcpy(paths_arr[num]+lenth+1, entry->d_name);  //生成绝对路径
		// paths_arr[num][j] = '\0';
	}
	closedir(dir);
	return paths_arr;
}



/*
 * Author：宋淳
 * 功能：只建立path文件夹下的同一层的兄弟二叉树(退化为链表)
*/
FilesBiTree create_blising_tree(char *path)
{
	FilesBiTree root = (FilesBiTree) malloc (sizeof(FileNode));
	FileNode *node = root;
	if(node == NULL ) //若分配空间失败
	{
		return NULL;
	}
	node->rch = NULL;
	node->info = create_info_node(path); //获取文件信息
	int fileNum = node->info->innerFileNum;
	char **p = get_inner_pathes(node->info);  //获取文件夹内的文件路径
	node->lch = (FilesBiTree) malloc (sizeof(FileNode));
	node = node->lch;
	node->info = create_info_node(p[0]);
	node->lch = NULL;

	int i;
	for(i = 1; i < fileNum; ++i)
	{
		node->rch = (FilesBiTree) malloc (sizeof(FileNode)); //右子结点为目录下的后面文件
		node = node->rch;
		node->lch = NULL;
		node->info = create_info_node(p[i]);
	}
	node->rch = NULL;	//到了最后一个右孩子

	return root;
}



/*
 * Author: 谢文韬  Modify:宋淳
 * 作用：返回文件目录二叉树的根节点
 * 用法：参数path是文件的绝对路径，path不存在返回NULL
 */
FilesBiTree create_files_bitree(char *path)
{
	FilesBiTree root = (FilesBiTree) malloc (sizeof(FileNode));
	if(root == NULL   ) //若分配空间失败
	{
		return NULL;
	}
	root->info = create_info_node(path); //获取文件信息
	if(root->info == NULL)  //若文件不存在，返回NULL
	{
		free(root);
		return NULL;
	}

	if(file == root->info->type) //如果是文件
	{
		root->lch = NULL;
	}
	else //如果是文件夹
	{
		if (0 == root->info->innerFileNum)	//若为空文件夹
		{
			root->lch = NULL;
			return root;
		}
		char **p = get_inner_pathes(root->info);  //获取文件夹内的文件路径

		root->lch = create_files_bitree(p[0]); //左子结点为目录下的第一个 文件
		FilesBiTree pointer = root->lch;
		int i;
		for(i = 1; i < root->info->innerFileNum; i++)
		{
			pointer->rch = create_files_bitree(p[i]); //右子结点为目录下的后面文件
			pointer = pointer->rch;
		}
		pointer->rch = NULL;	//到了最后一个右孩子
	}
	root->rch = NULL;
	return root;
}



/*
 * Author:宋淳
 * 实现功能：只输出此目录下的文件(夹)的名字，按列对齐
 */
int list_files_name_only(FilesBiTree tree)
{
    FileNode *node = tree;
    if (node->info->type != folder)     //若不是文件夹，直接退出
    {
        return Error;
    }
    if (NULL == node->lch)  //若是空文件夹，提示并退出
    {
        printf("空文件夹\n");
        return OK;
    }
    FilesBiTree p = tree->lch;

    int maxLength = 0;
    int tempLength = 0;
    int spacing = 0;

    for (int i=0; i<(node->info->innerFileNum); ++i, p=p->rch)
    {
        if (maxLength < (tempLength=strlen(p->info->name)))
        {
            maxLength = tempLength;
        }
    }
    //获取间隔，若字符串的最大宽度大于预设的最大宽度，则间隔为预设的最大宽度
    spacing = maxLength < MAX_SPACING ? maxLength : MAX_SPACING;
    p = tree->lch;  //从头开始输出
    // printf("%d %d\n", maxLength, spacing);
    for (int i=1; i<node->info->innerFileNum; ++i, p=p->rch)
    {
        print_name(p->info->name, spacing);
        if (0 == i%4)
        {
            printf("\n");
        }
    }
    printf("\n");
    return OK;
}



/*
 * Author：宋淳
 * 作用：只输出此目录下的文件(夹)的名字，按列对齐
*/
int list_files_name_only_in_path(char *path)
{
    FilesBiTree blisingTree = create_blising_tree(path);
    list_files_name_only(blisingTree);
	free_tree(blisingTree);
    return OK;
}