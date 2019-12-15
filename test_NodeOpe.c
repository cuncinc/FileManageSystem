#include "NodeOpe.c"
//测试NodeOpe.c文件里函数正确??
//Author:谢文??
//2019.12.11
int main()
{
	char *path2 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS\\test_NodeOpe.c"; //文件
	char *path1 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS"; //文件夹
// 测试get_name()函数
	char *name  = get_name(path1);
	printf("name = %s\n", name);

//	测试get_extension()函数
	char *extension = get_extension(path1);
	printf("extension = %s\n", extension);

//	测试get_file_size()函数
	long int size  = get_file_size(path1);
	printf("size = %ldByte, %s\n", size, get_size_string(size));

//	测试file_exsists()函数
	printf("if file exsists? %d\n", file_exsists(path1));

//	测试folder_exsists()函数
	printf("if folder exsists? %d\n\n", folder_exsists(path1));

//	测试create_info_node()函数
	FileInfo * head =  create_info_node(path1);
	printf("type: %d\n", head->type);
	printf("name: %s\n", head->name);
	printf("path: %s\n", head->path);
	printf("timeNum:  %ld\n", head->modifyTimeNum);
	printf("time: %s\n", head->modifyTime);
	printf("size: %ld\n", head->size);
	printf("extension: %s\n", head->extension);
	printf("innerFileNum: %d\n", head->innerFileNum);

	system("pause");
	return 0;
}
