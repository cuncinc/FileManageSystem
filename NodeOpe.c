<<<<<<< HEAD
/*
 * timeï¼š2019å¹´12æœˆ7æ—¥ 11ç‚¹41åˆ†
 * authorï¼šå®‹æ·³
 * æè¿°ï¼šè¦å°è£…çš„æ“ä½œï¼Œä¸å¯¹å¤–æš´éœ²çš„ç»†èŠ‚
*/
#include "NodeInfo.h"
#include "State.h"
#include "NodeOpe.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//è·å–æ–‡ä»¶çŠ¶æ€æ‰€éœ€çš„å¤´æ–‡ä»¶
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<dirent.h>

/*
 * Author: è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šåˆ¤æ–­è·¯å¾„ç»ˆç‚¹æ˜¯å¦ä¸ºæ–‡ä»¶
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶çš„è·¯å¾„,å¦‚æœæ˜¯æ–‡ä»¶åˆ™è¿”å›trueï¼Œå¦åˆ™è¿”å›false
*/
boolean file_exsists(char *path)
{
	struct _stat buf;
	//è·å¾—æ–‡ä»¶çŠ¶æ€ä¿¡æ¯
	_stat(path, &buf);
	if(_S_IFREG & buf.st_mode) //å¦‚æœæ˜¯æ–‡ä»¶ï¼Œè¿”å›true
	{
		return true;
	}
	else  //å¦‚æœä¸æ˜¯æ–‡ä»¶æˆ–å…¶ä»–æƒ…å†µï¼Œè¿”å›false
	{
		return false;
	}
}

/*
 * Author: è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šåˆ¤æ–­è·¯å¾„ç»ˆç‚¹æ˜¯å¦ä¸ºæ–‡ä»¶å¤¹
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶å¤¹çš„è·¯å¾„,å¦‚æœæ˜¯æ–‡ä»¶å¤¹åˆ™è¿”å›trueï¼Œå¦åˆ™è¿”å›false
*/
boolean folder_exsists(char *path)
{
	struct _stat buf;
	//è·å¾—æ–‡ä»¶çŠ¶æ€ä¿¡æ¯
	_stat(path, &buf);
	if(_S_IFDIR & buf.st_mode) //å¦‚æœæ˜¯æ–‡ä»¶å¤¹ï¼Œè¿”å›true
	{
		return true;
	}
	else  //å¦‚æœä¸æ˜¯æ–‡ä»¶å¤¹æˆ–å…¶ä»–æƒ…å†µï¼Œè¿”å›false
	{
		return false;
	}
}

/*
 * Author: è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šè¿”å›æ–‡ä»¶åŸºæœ¬åçš„æŒ‡é’ˆ
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶çš„ç»å¯¹è·¯å¾„ï¼Œæ–‡ä»¶ä¸å­˜åœ¨è¿”å›NULL
 */
char * get_base_name(char * path)
{
    if(path == NULL)  //è‹¥è·¯å¾„ä¸å­˜åœ¨è¿”å›NULL
    {
    	return NULL;
	}
	char *name = (char *)malloc(sizeof(char) * (strlen(path)+1));
	int idx; //ä½ç½®æ ‡è®°
	int i, j;
	//æå–å‡ºè·¯å¾„å°¾çš„æ–‡ä»¶å
	for(i = strlen(path); path[i] != '\\'; i--)
	{
		idx = i;
	}
	for(i = idx, j=0; path[i] != '\0'; i++, j++)
	{
		name[j] = path[i];
	}
	name[j] = '\0';
	if(file_exsists(path))  //å¦‚æœæ˜¯æ–‡ä»¶åˆ™ç¥›é™¤åç¼€å
	{
		for(i = strlen(name); name[i] != '.'; i--)
		{
			name[i] = '\0';
		}
		name[i] = '\0';
	}
	char *name1 = (char *)malloc(sizeof(char) * (strlen(name)+1));
	strcpy(name1, name);
	free(name);
	return name1;
}


/*
 * Author: è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šè¿”å›æ–‡ä»¶æ‹“å±•åçš„æŒ‡é’ˆ
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶çš„ç»å¯¹è·¯å¾„ï¼Œæ‹“å±•åä¸å­˜åœ¨è¿”å›NULL
 */
char *get_extension(char *path)
{
	if(path == NULL || strchr(path, '.') == NULL)  //è‹¥è·¯å¾„ä¸å­˜åœ¨æˆ–åç¼€åä¸å­˜åœ¨åˆ™è¿”å›NULL
    {
    	return NULL;
	}
	char *extension = (char *)malloc(sizeof(char) *(strlen(path)+1));
	int idx; //ä½ç½®æ ‡è®°
	int i, j;
	//æå–å‡ºè·¯å¾„å°¾çš„æ–‡ä»¶æ‹“å±•å
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
 * Author: å®‹æ·³  Modify:è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šè¿”å›æ–‡ä»¶çš„å¤§å°ï¼Œå•ä½ä¸ºByte(å­—èŠ‚)
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶çš„è·¯å¾„ï¼Œæ–‡ä»¶ä¸å­˜åœ¨è¿”å›-1
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



#if 0
/*
 * Author: å®‹æ·³  Modify:è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šè·å–æ–‡ä»¶å½“å‰çŠ¶æ€
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶çš„è·¯å¾„,æ‰“å°å‡ºæ–‡ä»¶çš„ç›¸å…³ä¿¡æ¯
*/
void get_file_status(char *path)
 {
     struct _stat buf;
     int result;
     //è·å¾—æ–‡ä»¶çŠ¶æ€ä¿¡æ¯
     result = _stat(path , &buf );
     //æ˜¾ç¤ºæ–‡ä»¶çŠ¶æ€ä¿¡æ¯
    if( result != 0 )
        printf( "æ˜¾ç¤ºæ–‡ä»¶çŠ¶æ€ä¿¡æ¯å‡ºé”™" );//å¹¶æç¤ºå‡ºé”™çš„åŸå› ï¼Œå¦‚No such file or directoryï¼ˆæ— æ­¤æ–‡ä»¶æˆ–ç´¢å¼•ï¼‰
     else
     {
         printf("æ–‡ä»¶å¤§å°: %ld", buf.st_size);
         printf("\næ–‡ä»¶åˆ›å»ºæ—¶é—´: %s", ctime(&buf.st_ctime));
         printf("è®¿é—®æ—¥æœŸ: %s", ctime(&buf.st_atime));
         printf("æœ€åä¿®æ”¹æ—¥æœŸ: %s", ctime(&buf.st_mtime));
     }
	 return;
 }
#endif




/*
 * Author: è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šè·å–æ–‡ä»¶ç»å¯¹è·¯å¾„
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶çš„è·¯å¾„,è·¯å¾„ä¸å­˜åœ¨æ—¶è¿”å›NULL
 * å¤‡æ³¨ï¼šæ­¤å‡½æ•°å¯èƒ½æœ‰bug
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
 * Author: è°¢æ–‡éŸ¬
 * ä½œç”¨ï¼šè·å–è·¯å¾„æ–‡ä»¶ç›¸å…³ä¿¡æ¯
 * ç”¨æ³•ï¼šå‚æ•°pathæ˜¯æ–‡ä»¶çš„è·¯å¾„,è·¯å¾„ä¸å­˜åœ¨æ—¶è¿”å›NULL
*/
FileInfo * create_info_node(char * path)
{
	struct _stat buf;
	int result;
	int filenum = 0;
	result = _stat(path, &buf); //è·å¾—æ–‡ä»¶çŠ¶æ€ä¿¡æ¯
	FileInfo * filehead = (FileInfo *)malloc(sizeof(FileNode));
	if(filehead == NULL || path == NULL || result != 0)// è‹¥å†…å­˜åˆ†é…å¤±è´¥ï¼Œè·¯å¾„ä¸å­˜åœ¨æˆ–æ–‡ä»¶ä¸å­˜åœ¨ï¼Œè¿”å›NULL
	{
		return NULL;
	}
	char *modify = ctime(&buf.st_mtime);
	filehead->modifyTime = modify;   //è·å¾—ä¿®æ”¹æ—¶é—´
	filehead->modifyTimeNum = buf.st_mtime;  //è·å¾—ä¿®æ”¹æ—¶é—´
	strcpy(filehead->modifyTime, modify);
	filehead->path = path;
	filehead->baseName = get_base_name(path);
	if(file_exsists(path))  //å¦‚æœæ˜¯æ–‡ä»¶
	{
		filehead->type = file;
		filehead->size = buf.st_size;
		filehead->extension = get_extension(path);
		filehead->innerFileNum = -1;
	}
	else if(folder_exsists(path)) //å¦‚æœæ˜¯æ–‡ä»¶å¤¹
	{
		filehead->type = folder;
		filehead->size = -1;
		filehead->extension = NULL;
		struct dirent *entry;
    	DIR *dir = NULL;
    	dir = opendir(path);
		while((entry = readdir(dir)) != 0)
		{
			filenum++;  //æ–‡ä»¶æ•°ç›®åŠ åŠ 
		}
		closedir(dir);
		filehead->innerFileNum = filenum;
	}
	return filehead;
}
=======
/*
 * time£º2019Äê12ÔÂ7ÈÕ 11µã41·Ö
 * author£ºËÎ´¾
 * ÃèÊö£ºÒª·â×°µÄ²Ù×÷£¬²»¶ÔÍâ±©Â¶µÄÏ¸½Ú
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//»ñÈ¡ÎÄ¼ş×´Ì¬ËùĞèµÄÍ·ÎÄ¼ş 
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<dirent.h>

#include"NodeInfo.h"
#include"State.h"
#define maxlen 100 //ÎÄ¼şÂ·¾¶µÄ³¤¶È×î´óÎª100 

/*
 * Author: Ğ»ÎÄèº
 * ×÷ÓÃ£º·µ»ØÎÄ¼ş»ù±¾ÃûµÄÖ¸Õë
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼şµÄ¾ø¶ÔÂ·¾¶£¬ÎÄ¼ş²»´æÔÚ·µ»ØNULL
 */
char * get_base_name(char * path)
{
    if(path == NULL)  //ÈôÂ·¾¶²»´æÔÚ·µ»ØNULL 
    {
    	return NULL;
	}
	char *name = (char *)malloc(maxlen);
	int idx; //Î»ÖÃ±ê¼Ç 
	int i, j;
	//ÌáÈ¡³öÂ·¾¶Î²µÄÎÄ¼şÃû 
	for(i = strlen(path); path[i] != '\\'; i--)
	{
		idx = i;
	}
	for(i = idx, j=0; path[i] != '\0'; i++, j++)
	{
		name[j] = path[i];
	}
	name[j] = '\0';
	if(file_exsists(path))  //Èç¹ûÊÇÎÄ¼şÔòìî³ıºó×ºÃû 
	{
		for(i = strlen(name); name[i] != '.'; i--)
		{
			name[i] = '\0';
		}
		name[i] = '\0';	
	}
	return name;

}

/*
 * Author: Ğ»ÎÄèº
 * ×÷ÓÃ£º·µ»ØÎÄ¼şÍØÕ¹ÃûµÄÖ¸Õë 
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼şµÄ¾ø¶ÔÂ·¾¶£¬ÍØÕ¹Ãû²»´æÔÚ·µ»ØNULL
 */
char *get_extension(char *path)
{
	if(path == NULL || strchr(path, '.') == NULL)  //ÈôÂ·¾¶²»´æÔÚ»òºó×ºÃû²»´æÔÚÔò·µ»ØNULL 
    {
    	return NULL;
	}
	char *extension = (char *)malloc(maxlen);
	int idx; //Î»ÖÃ±ê¼Ç 
	int i, j;
	//ÌáÈ¡³öÂ·¾¶Î²µÄÎÄ¼şÍØÕ¹Ãû 
	for(i = strlen(path); path[i] != '.'; i--)
	{
		idx = i;
	}
	for(i = idx, j=0; path[i] != '\0'; i++, j++)
	{
		extension[j] = path[i];
	}
	extension[j] = '\0';
	return extension;
		
} 



/*
 * Author: ËÎ´¾  Modify:Ğ»ÎÄèº 
 * ×÷ÓÃ£º·µ»ØÎÄ¼şµÄ´óĞ¡£¬µ¥Î»ÎªByte(×Ö½Ú)
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼şµÄÂ·¾¶£¬ÎÄ¼ş²»´æÔÚ·µ»Ø-1
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
 * Author: ËÎ´¾  Modify:Ğ»ÎÄèº
 * ×÷ÓÃ£º»ñÈ¡ÎÄ¼şµ±Ç°×´Ì¬
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼şµÄÂ·¾¶,´òÓ¡³öÎÄ¼şµÄÏà¹ØĞÅÏ¢
*/
void get_file_status(char *path)
 {
     struct _stat buf;
     int result;
     //»ñµÃÎÄ¼ş×´Ì¬ĞÅÏ¢
     result = _stat(path , &buf );
     //ÏÔÊ¾ÎÄ¼ş×´Ì¬ĞÅÏ¢
    if( result != 0 )
        printf( "ÏÔÊ¾ÎÄ¼ş×´Ì¬ĞÅÏ¢³ö´í" );//²¢ÌáÊ¾³ö´íµÄÔ­Òò£¬ÈçNo such file or directory£¨ÎŞ´ËÎÄ¼ş»òË÷Òı£©

     else
     {
         printf("ÎÄ¼ş´óĞ¡: %d", buf.st_size);
         printf("\nÎÄ¼ş´´½¨Ê±¼ä: %s", ctime(&buf.st_ctime));
         printf("·ÃÎÊÈÕÆÚ: %s", ctime(&buf.st_atime));
         printf("×îºóĞŞ¸ÄÈÕÆÚ: %s", ctime(&buf.st_mtime));
     }
 }

/*
 * Author: Ğ»ÎÄèº
 * ×÷ÓÃ£ºÅĞ¶ÏÂ·¾¶ÖÕµãÊÇ·ñÎªÎÄ¼ş
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼şµÄÂ·¾¶,Èç¹ûÊÇÎÄ¼şÔò·µ»Øtrue£¬·ñÔò·µ»Øfalse
*/
boolean file_exsists(char *path)
{

	struct _stat buf;
	int result;
	//»ñµÃÎÄ¼ş×´Ì¬ĞÅÏ¢
	result = _stat(path, &buf);
	if(_S_IFREG & buf.st_mode) //Èç¹ûÊÇÎÄ¼ş£¬·µ»Øtrue
	{
		return true;
	}
	else  //Èç¹û²»ÊÇÎÄ¼ş»òÆäËûÇé¿ö£¬·µ»Øfalse
	{
		return false;
	}
}

/*
 * Author: Ğ»ÎÄèº
 * ×÷ÓÃ£ºÅĞ¶ÏÂ·¾¶ÖÕµãÊÇ·ñÎªÎÄ¼ş¼Ğ
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼ş¼ĞµÄÂ·¾¶,Èç¹ûÊÇÎÄ¼ş¼ĞÔò·µ»Øtrue£¬·ñÔò·µ»Øfalse
*/
boolean folder_exsists(char *path)
{
	struct _stat buf;
	int result;
	//»ñµÃÎÄ¼ş×´Ì¬ĞÅÏ¢
	result = _stat(path, &buf);
	if(_S_IFDIR & buf.st_mode) //Èç¹ûÊÇÎÄ¼ş¼Ğ£¬·µ»Øtrue
	{
		return true;
	}
	else  //Èç¹û²»ÊÇÎÄ¼ş¼Ğ»òÆäËûÇé¿ö£¬·µ»Øfalse
	{
		return false;
	}

}

/*
 * Author: Ğ»ÎÄèº
 * ×÷ÓÃ£º»ñÈ¡Â·¾¶ÎÄ¼şÏà¹ØĞÅÏ¢
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼şµÄÂ·¾¶,Â·¾¶²»´æÔÚÊ±·µ»ØNULL
*/
FileInfo * create_info_node(char * path)
{
	struct _stat buf;
	int result;
	int filenum = 0;
	result = _stat(path, &buf); //»ñµÃÎÄ¼ş×´Ì¬ĞÅÏ¢ 
	FileInfo * filehead = (FileInfo *)malloc(sizeof(FileNode));
	if(filehead == NULL || path == NULL || result != 0)// ÈôÄÚ´æ·ÖÅäÊ§°Ü£¬Â·¾¶²»´æÔÚ»òÎÄ¼ş²»´æÔÚ£¬·µ»ØNULL 
	{
		return NULL;
	}
	char *modify = ctime(&buf.st_mtime);
	filehead->modifyTime = modify;   //»ñµÃĞŞ¸ÄÊ±¼ä 	
	//filehead->modifyTimeNum = buf.st_mtime;  //»ñµÃĞŞ¸ÄÊ±¼ä 
	strcpy(filehead->modifyTime, modify); 
	filehead->path = path;
	filehead->baseName = get_base_name(path);
	if(file_exsists(path))  //Èç¹ûÊÇÎÄ¼ş
	{
		filehead->type = file;
		filehead->size = buf.st_size;
		filehead->extension = get_extension(path);
		filehead->innerFileNum = -1;
	 } 
	else if(folder_exsists(path)) //Èç¹ûÊÇÎÄ¼ş¼Ğ
	{
		filehead->type = folder;
		filehead->size = -1;
		filehead->extension = NULL;
		struct dirent *entry;
    	DIR *dir = NULL;
    	dir = opendir(path);
		while(entry = readdir(dir))
		{		
			filenum++;  //ÎÄ¼şÊıÄ¿¼Ó¼Ó
		}
		closedir(dir);
		filehead->innerFileNum = filenum;
	 } 
	
	 
}
/*
 * Author: Ğ»ÎÄèº
 * ×÷ÓÃ£º»ñÈ¡ÎÄ¼ş¾ø¶ÔÂ·¾¶ 
 * ÓÃ·¨£º²ÎÊıpathÊÇÎÄ¼şµÄÂ·¾¶,Â·¾¶²»´æÔÚÊ±·µ»ØNULL
 * ±¸×¢£º´Ëº¯Êı¿ÉÄÜÓĞbug 
*/

char * get_dir(char * path)
{
	if(path == NULL)
	{
		return NULL;
	}
	char *absolut_path = (char*) malloc (maxlen);
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
	return absolut_path; 
	
}

 
>>>>>>> 8a3c5d4244960796bed9289594ad56b9a020721e
