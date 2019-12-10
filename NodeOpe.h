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



/*
 * 作用：返回文件的大小，单位为Byte(字节)
 * 用法：参数str是文件的路径，文件不存在返回-1
 */
long get_file_size(char *str);



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



//这个函数好像没什么用
// /*
//  * 返回文件所在的路径
//  * 注意要用动态内存
//  */
// char * get_dir(char * path);