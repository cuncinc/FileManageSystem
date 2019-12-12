<<<<<<< HEAD
#include"NodeOpe.c"
//æµ‹è¯•NodeOpe.cæ–‡ä»¶é‡Œå‡½æ•°æ­£ç¡®æ€§
//Author:è°¢æ–‡éŸ¬
//2019.12.11
int main()
{
	char *path1 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS\\test_NodeOpe.c"; //æ–‡ä»¶
	char *path2 = "E:\\CC\\Code\\VSCode\\Default\\Data structure\\FMS"; //æ–‡ä»¶å¤¹

//	æµ‹è¯•get_base_name()å‡½æ•°
	// char *name  = get_base_name(path1);
	// printf("%s", name);

//	æµ‹è¯•get_extension()å‡½æ•°
	// char *extension = get_extension(path1);
	// printf("%s", extension);

//	æµ‹è¯•get_file_size()å‡½æ•°
//	long int size  = get_file_size(path1);
//	printf("%ld", size);

//	æµ‹è¯•get_file_status()å‡½æ•°
//	get_file_status(path1);

//	æµ‹è¯•file_exsists()å‡½æ•°
//	printf("%d %d", file_exsists(path1), file_exsists(path2));

//	æµ‹è¯•folder_exsists()å‡½æ•°
//	printf("%d %d", folder_exsists(path1), folder_exsists(path2));

//	æµ‹è¯•get_dir()å‡½æ•°
	// printf("%s", get_dir(path1));


//	æµ‹è¯•create_info_node()å‡½æ•°
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
=======
#include"NodeOpe.c"
//²âÊÔNodeOpe.cÎÄ¼şÀïº¯ÊıÕıÈ·ĞÔ
//Author:Ğ»ÎÄèº
//2019.12.11 
int main()
{
	char *path1 = "D:\\×ÀÃæ\\FileManageSystem\\test.c"; //ÎÄ¼ş
	char *path2 = "D:\\×ÀÃæ\\FileManageSystem"; //ÎÄ¼ş¼Ğ 
	
//	²âÊÔget_base_name()º¯Êı
//	char *name  = get_base_name(path2);
//	printf("%s", name);	 
	
//	²âÊÔget_extension()º¯Êı
//	char *extension = get_extension(path2);
//	printf("%s", extension);
	
//	²âÊÔget_file_size()º¯Êı 
//	long int size  = get_file_size(path1);
//	printf("%ld", size);	
	
//	²âÊÔget_file_status()º¯Êı
//	get_file_status(path1);	
	
//	²âÊÔfile_exsists()º¯Êı
//	printf("%d %d", file_exsists(path1), file_exsists(path2)); 

//	²âÊÔfolder_exsists()º¯Êı
//	printf("%d %d", folder_exsists(path1), folder_exsists(path2)); 

//	²âÊÔget_dir()º¯Êı
// 	printf("%s", get_dir(path1)); 

	
//	²âÊÔcreate_info_node()º¯Êı
//	FileInfo * head =  create_info_node(path2);
//	printf("%d\n", head->type);
//	printf("%s\n", head->baseName);
//	printf("%s\n", head->path);
//	printf("%ld\n", head->modifyTimeNum);
//	printf("%s\n", head->modifyTime);
//	printf("%ld\n", head->size);
//	printf("%s\n", head->extension);
//	printf("%d\n", head->innerFileNum);		
	
	
	
	
	return 0;
}

>>>>>>> 8a3c5d4244960796bed9289594ad56b9a020721e
