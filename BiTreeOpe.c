#include"BiTreeOpe.h"
#include"NodeOpe.c"
#include "NodeInfo.h"

// * Author: 谢文韬 Modify：宋淳 
// * 作用：返回文件目录下的所有文件名路径 
// * 用法：参数path是文件的绝对路径，path不存在返回NULL

char **get_inner_pathes(FileInfo *info)
{
//	printf("%p",info);
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
 * Author: 谢文韬  Modify:宋淳 
 * 作用：返回文件目录二叉树的根节点 
 * 用法：参数path是文件的绝对路径，path不存在返回NULL
 */
 
FilesBiTree create_files_bitree(char *path)
{
	FilesBiTree root = (FilesBiTree) malloc (sizeof(FileNode));
	if(root == NULL) //若分配空间失败 
	{
		return NULL;\
	 } 
 
	root->info = create_info_node(path); //获取文件信息

	char **p = get_inner_pathes(root->info);  //获取文件夹内的文件路径 
	

//	int i;
//	for (i=0; i<root->info->innerFileNum; ++i)
//	{
//		
//		printf("%s\n", p[i]);
//	}

	return root;
}	
 








 
