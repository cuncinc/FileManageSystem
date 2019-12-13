//Author:谢文韬
//time：2019.12.12
//测试BiTreeOpe.c文件中函数的正确性


#include "BiTreeOpe.c"


int main()
{
	char *path1 = "D:\\桌面\\FileManageSystem";
	char *path2 = "D:\\桌面\\Java_answer\\java\\experiment2";
	char *path3 = "E:\\CC\\Code\\From_GitHub\\Xin-Yue";
	//测试create_fil es_bitree()函数
	FilesBiTree head = create_files_bitree(path3);
 	pre_order(head);

	system("pause");
	return 0;
}
