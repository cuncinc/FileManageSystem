/*
 * time：2019年12月7日 11点41分
 * author：宋淳
 * 描述：要封装的操作，不对外暴露的细节
*/
#include "State.h"
#include "NodeInfo.h"

/*
 * 字符串操作，从路径种返回文件基本名(除了拓展名的字符串)
 * 如C:\\test.txt返回test
 * 注意要用动态内存
 */
char * get_base_name(char * path);


/*
 * 返回文件的拓展名，没有拓展名就返回NULL
*/
char * get_extension(char *path);

//这个函数好像没什么用
// /*
//  * 返回文件所在的路径
//  * 注意要用动态内存
//  */
// char * get_dir(char * path);


//实现每个函数都要写注释，下面时一个例子：
/*
 * Author: 宋淳
 * 作用：返回文件的大小，单位为Byte(字节)
 * 用法：参数str是文件的路径，文件不存在返回-1
 */
long get_file_size(char *str)
{
    long size;
    FILE* f = fopen(str, "rb");
    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fclose(f);
    return size;
}

/*
 * 使用方式：传入一个文件的绝对路径path，返回这个文件的FileInfo节点。注意使用前要判断是否为NULL
 * 实现要求：
 *      1.先判断path是否为文件夹或不存在，是的话直接返回NULL
 *      2.可调用其他已经写好的函数，节点的所有信息都要获取
*/
FileInfo * create_info_node(char *path);


boolean is_file(FileNode *node);    //如果节点寸的是文件则返回true，否则返回false
boolean is_folder(FileNode *node);  //是文件夹则返回true，否则返回false
boolean file_exsists(char *path);   //若path不存在或者是文件夹，返回false
boolean folder_exsists(char *path); //若path不存在或是文件，返回false



// 这是一个获取文件状态的例子和方法
// /*
//  *  需要加的头文件
//  *  #include <time.h>
//     #include <sys/types.h>
//     #include <sys/stat.h>
//  */
// void get_file_status(char *path)
// {
//     struct stat buf;
//     int result;
//     //获得文件状态信息
//     result =stat(path , &buf );
//     //显示文件状态信息
//    if( result != 0 )
//        perror( "显示文件状态信息出错" );//并提示出错的原因，如No such file or directory（无此文件或索引）

//     else
//     {
//         printf("文件大小: %d", buf.st_size);
//         printf("文件创建时间: %s", ctime(&buf.st_ctime));
//         printf("访问日期: %s", ctime(&buf.st_atime));
//         printf("最后修改日期: %s", ctime(&buf.st_mtime));
//     }
// }