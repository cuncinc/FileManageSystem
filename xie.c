#include"BiTreeOpe.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Maxsize 10  //文件层数最大10
#define Maxlen 50  //文件名长度50
/*
 * 实现功能：在node文件夹下新建一个名称为fileName的文件
 * 实现要求：
 *      1. 检查是否为文件夹，检查fileName是否已存在
 *      2. 先新建文件，再创建此文件二叉树节点，把节点插到node的左孩子
 */
int new_file(FileNode *node , char *fileName)
{
	FILE *fp = NULL;






 }


/*
 * 功能描述：创建path目录下的二叉树
 * 实现要求：
 *      1. 用左孩子右兄弟法存储节点
 *      2. 应先判断此path是否为空，若为空，直接返回NULL
 *      3. 递归创建此path目录下的其他文件夹的节点
 *      4. 可调用creat_node函数
 */


FilesBiTree create_files_bitree(char *path)
{
    if(path == NULL)   //若路径为空，返回NULL
    {
        return NULL;
    }
    char fileName[Maxsize][Maxlen];  //路径下的每一层文件名
	char *token;
	int i = 0;
	token = strtok(path, "\\"); //获取绝对路径下每一层的文件名
    printf("%s", token);
    while(token!=NULL)
    {
        strcpy(fileName[i], token);
        token = strtok(NULL, "\\");
        printf("%s", token);
        printf("test\n");
        i++;
    }




    /*char drive[_MAX_DIR];
    char dir[_MAX_DRIVE];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath(path, drive,dir,fname, ext);
    printf("Drive:%s\n file name: %s\n file type: %s\n",drive,fname,ext);
    strcat(fname,ext);
    printf("File name with extension :%s\n",fname);
*/

}

int main()
{
	printf("hhh");
	char *path = "E:\\lava_answer\\lava\\lava\\experiment2\\t1\\test.txt";
	create_files_bitree(path);
	return 0;
}


