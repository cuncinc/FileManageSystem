/*
 * time：2019年12月7日 11点41分
 * author：宋淳
 * 描述：要封装的操作，不对外暴露的细节
*/



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