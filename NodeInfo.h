/*
 * Author: 宋淳
 * Time: 2019年12月6日 12点26分
 * 描述：定义了节点、树的结构体
 */

#ifndef NODEINFO_H
#define NODEINFO_H

enum NodeType
{
    folder,  //folder是0
    file     //file是1
};

struct FileInfo
{
    enum NodeType type; //节点存储的类型，folder和file
    char * path;        //文件(夹)绝对路径名。
    char *extension;    //>>仅file有效<<。文件的拓展(后缀)名，用于排序，或者GUI显示不同的图标，没有则设为NULL
    char * name;    //文件(夹)的名字，文件名包含拓展名
    char *modifyTime;   //用字符串存储的时间
    long modifyTimeNum; //从1970年到现在的秒数(或者毫秒)，便于排序
    long size;          //文件(夹)大小，单位是字节。文件为其本身大小；文件夹为里面所有文件的总大小
    int innerFileNum;   //>>仅folder有效<<。此文件夹里这一层的文件(夹)数量，空则设为0。若是文件类型则设为-1
};
typedef struct FileInfo FileInfo;

struct FileNode
{
    struct FileInfo * info;
    struct FileNode * lch;  //左孩子
    struct FileNode * rch;  //右孩子
};
typedef struct FileNode FileNode;
typedef struct FileNode *FilesBiTree;



#endif