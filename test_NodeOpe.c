#include"NodeOpe.c"
//测试NodeOpe.c文件里函数正确性
//Author:谢文韬
//2019.12.11
int main()
{
	char *path1 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS\\test_NodeOpe.c"; //文件
	char *path2 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS"; //文件夹

//	测试get_base_name()函数
	// char *name  = get_base_name(path1);
	// printf("%s", name);

//	测试get_extension()函数
	// char *extension = get_extension(path1);
	// printf("%s", extension);

//	测试get_file_size()函数
//	long int size  = get_file_size(path1);
//	printf("%ld", size);

//	测试get_file_status()函数
//	get_file_status(path1);

//	测试file_exsists()函数
//	printf("%d %d", file_exsists(path1), file_exsists(path2));

//	测试folder_exsists()函数
//	printf("%d %d", folder_exsists(path1), folder_exsists(path2));

//	测试get_dir()函数
	// printf("%s", get_dir(path1));


//	测试create_info_node()函数
	FileInfo * head =  create_info_node(path2);
	printf("type: %d\n", head->type);
	printf("basename: %s\n", head->baseName);
	printf("path: %s\n", head->path);
	printf("timeNum:  %ld\n", head->modifyTimeNum);
	printf("time: %s\n", head->modifyTime);
	printf("size: %ld\n", head->size);
	printf("extension: %s\n", head->extension);
	printf("innerFileNum: %d\n", head->innerFileNum);

	system("pause");
	return 0;
}