/*
 * time：2019年12月7日 11点41分
 * author：宋淳
 * 描述：要封装的操作，不对外暴露的细节
*/
#include "NodeInfo.h"
#include "NodeOpe.h"
#include "State.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//获取文件状态所需的头文件
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/*
 * Author: 谢文韬
 * 作用：判断路径终点是否为文件
 * 用法：参数path是文件的路径,如果是文件则返回true，否则返回false
*/
boolean file_exsists(char *path)
{
	struct _stat buf;
	//获得文件状态信息
	_stat(path, &buf);
	if(_S_IFREG & buf.st_mode) //如果是文件，返回true
	{
		return true;
	}
	else  //如果不是文件或其他情况，返回false
	{
		return false;
	}
}

/*
 * Author: 谢文韬
 * 作用：判断路径终点是否为文件夹
 * 用法：参数path是文件夹的路径,如果是文件夹则返回true，否则返回false
*/
boolean folder_exsists(char *path)
{
	struct _stat buf;
	//获得文件状态信息
	_stat(path, &buf);
	if(_S_IFDIR & buf.st_mode) //如果是文件夹，返回true
	{
		return true;
	}
	else  //如果不是文件夹或其他情况，返回false
	{
		return false;
	}
}

/*
 * Author: 谢文韬
 * 作用：返回文件(夹)名，从最后一个'\'开始到末尾
 * 用法：参数path是文件的绝对路径，文件不存在返回NULL
 */
char * get_name(char * path)
{
    if(path == NULL || 0==strlen(path))  //若路径不存在返回NULL
    {
    	return NULL;
	}

	char *name = (char *)malloc(sizeof(char) * (strlen(path)+1));
	int idx; //位置标记
	int i, j;
	//提取出路径尾的文件名
	for(i = strlen(path); path[i] != '\\'; i--)
	{
		idx = i;
	}

	for(i = idx, j=0; path[i] != '\0'; i++, j++)
	{
		name[j] = path[i];
	}
	name[j] = '\0';

	// 以下是去掉后缀名的代码，不需要使用

	// if(file_exsists(path))  //如果是文件则祛除后缀名
	// {
	// 	for(i=strlen(name); i>=0 && name[i]!='.'; i--)
	// 	{
	// 		;	//空语句
	// 	}

	// 	if ( -1!=i || 0!=i  )	//排除文件名没有'.'的文件以及如".gitignore"的隐藏文件
	// 	{
	// 		name[i] = '\0';
	// 	}
	// }
	char *name1 = (char *)malloc(sizeof(char) * (strlen(name)+1));
	strcpy(name1, name);
	free(name);
	return name1;
}


/*
 * Author: 谢文韬
 * 作用：返回文件拓展名的指针
 * 用法：参数path是文件的绝对路径，拓展名不存在返回NULL
 */
char *get_extension(char *path)
{
	if(path == NULL || strchr(path, '.') == NULL)  //若路径不存在或后缀名不存在则返回NULL
    {
    	return NULL;
	}
	char *extension = (char *)malloc(sizeof(char) *(strlen(path)+1));
	int idx; //位置标记
	int i, j;
	//提取出路径尾的文件拓展名
	for(i = strlen(path); path[i] != '.'; i--)
	{
		idx = i;
	}
	for(i = idx, j=0; path[i] != '\0'; i++, j++)
	{
		extension[j] = path[i];
	}
	extension[j] = '\0';
	char *extension1 = (char *) malloc(sizeof(char) * (strlen(extension)+1));
	strcpy(extension1, extension);
	free(extension);
	return extension1;
}


/*
 * Author: 宋淳  Modify:谢文韬
 * 作用：返回文件的大小，单位为Byte(字节)
 * 用法：参数path是文件的路径，文件不存在返回-1
 */
long get_file_size(char *path)
{
    long size;
    FILE* f = fopen(path, "rb");
    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fclose(f);
    return size;
}



/*
 * Author: 谢文韬
 * 作用：获取文件绝对路径
 * 用法：参数path是文件的路径,路径不存在时返回NULL
 * 备注：此函数可能有bug
*/
char * get_dir(char * path)
{
	if(path == NULL)
	{
		return NULL;
	}
	char *absolut_path = (char *)malloc(sizeof(char) * (strlen(path)+1));
	int i, j ;
	for(i = 0, j=0; i<strlen(path); i++, j++)
	{
		absolut_path[i] = path[i];
		if(path[i] == '\\')
		{
			absolut_path[j+1] = '\\';
			j++;
		}
	}
	absolut_path[j-2] = '\0';
	printf("%s", absolut_path);
	char *absolut_path1 = (char *) malloc(sizeof(char) * (strlen(absolut_path)+1));
	strcpy(absolut_path1, absolut_path);
	free(absolut_path);
	return absolut_path1;
}

/*
 * Author: 谢文韬
 * 作用：获取路径文件相关信息
 * 用法：参数path是文件的路径,路径不存在时返回NULL
*/
FileInfo * create_info_node(char * path)
{
	struct _stat buf;
	int result;
	int filenum = 0;
	result = _stat(path, &buf); //获得文件状态信息
	FileInfo * filehead = (FileInfo *)malloc(sizeof(FileNode));
	if(filehead == NULL || path == NULL || result != 0)// 若内存分配失败，路径不存在或文件不存在，返回NULL
	{
		return NULL;
	}
	char *modify  = (char *)malloc(sizeof(char) * strlen(ctime(&buf.st_mtime)));
	strcpy(modify, ctime(&buf.st_mtime));
	int i;
	for(i = 0; modify[i] != '\n'; i++ );
	modify[i] = '\0';
	filehead->modifyTime = modify;   //获得修改时间
	filehead->modifyTimeNum = buf.st_mtime;  //获得修改时间

	strcpy(filehead->modifyTime, modify);
	filehead->path = path;
	filehead->name = get_name(path);
	if(file_exsists(path))  //如果是文件
	{
		filehead->type = file;
		filehead->size = buf.st_size;
		filehead->extension = get_extension(path);
		filehead->innerFileNum = -1;
	}
	else if(folder_exsists(path)) //如果是文件夹
	{
		filehead->type = folder;
		filehead->size = -1;
		filehead->extension = NULL;
		struct dirent *entry;
    	DIR * dir = NULL;
    	dir = opendir(path);
		while((entry = readdir(dir)) != 0)
		{
			filenum++;  //文件数目加加
		}
		closedir(dir);
		filehead->innerFileNum = filenum - 2;
	}

	return filehead;
}



/*
 * Author：宋淳
 * 作用：在spacing个宽度下输出name，超过spacing的字符回被截断
*/
void print_name(char *name, int spacing)
{
    if (strlen(name) > spacing)
    {
        char *p = name;
        int i;
        for (i=0; i<spacing-1; ++i)
        {
            printf("%c", *p++);
        }
        printf("..");
    }
    else
    {
        printf("%s", name);
        int i;
        for (i=strlen(name); i<=spacing; ++i)
        {
            printf(" ");
        }
    }
    printf("  ");
    return;
}



/*
 * Author：谢文韬
 * 作用：前序遍历输出文件二叉树节点的name
*/
void pre_order_in_name(FilesBiTree root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%s\n", root->info->name);

	pre_order_in_name(root->lch);
	pre_order_in_name(root->rch);
}



/*
 * Author：宋淳
 * 作用：释放一颗树的内存
 * 调用须知：调用这个函数后，要把FilesBiTree置NULL
*/
void free_tree(FilesBiTree tree)
{
	if (NULL == tree)
		return;
	free(tree->lch);
	free(tree->rch);
	free(tree);
	return;
}























#if 0
/*
 * Author: 宋淳  Modify:谢文韬
 * 作用：获取文件当前状态
 * 用法：参数path是文件的路径,打印出文件的相关信息
*/
void get_file_status(char *path)
 {
     struct _stat buf;
     int result;
     //获得文件状态信息
     result = _stat(path , &buf );
     //显示文件状态信息
    if( result != 0 )
        printf( "显示文件状态信息出错" );//并提示出错的原因，如No such file or directory（无此文件或索引）
     else
     {
         printf("文件大小: %ld", buf.st_size);
         printf("\n文件创建时间: %s", ctime(&buf.st_ctime));
         printf("访问日期: %s", ctime(&buf.st_atime));
         printf("最后修改日期: %s", ctime(&buf.st_mtime));
     }
	 return;
 }
#endif
