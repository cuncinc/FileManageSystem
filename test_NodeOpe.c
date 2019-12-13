#include"NodeOpe.c"
//测试NodeOpe.c文件里函数正确??
//Author:谢文??
//2019.12.11
int main()
{
	char *path1 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS\\test_NodeOpe.c"; //文件
	char *path2 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS"; //文件??
	char *path3 = "E:\\CC\\Code\\From_GitHub\\Xin-Yue\\现场?_?我所亲历的邓同学被约谈事件.png";
// 测试get_base_name()函数
	char *name  = get_base_name(path3);
	printf("%s\n", name);

//	测试get_extension()函数
	char *extension = get_extension(path3);
	printf("%s\n", extension);

//	测试get_file_size()函数
	long int size  = get_file_size(path3);
	printf("%ld\n", size);

//	测试get_file_status()函数
	// get_file_status(path3);

//	测试file_exsists()函数
	printf("%d\n", file_exsists(path3));

//	测试folder_exsists()函数
	printf("%d\n", folder_exsists(path3));

//	测试get_dir()函数
	printf("%s\n", get_dir(path3));


//	测试create_info_node()函数
	// FileInfo * head =  create_info_node(path3);
	// printf("type: %d\n", head->type);
	// printf("basename: %s\n", head->baseName);
	// printf("path: %s\n", head->path);
	// printf("timeNum:  %ld\n", head->modifyTimeNum);
	// printf("time: %s\n", head->modifyTime);
	// printf("size: %ld\n", head->size);
	// printf("extension: %s\n", head->extension);
	// printf("innerFileNum: %d\n", head->innerFileNum);

	system("pause");
	return 0;
}
