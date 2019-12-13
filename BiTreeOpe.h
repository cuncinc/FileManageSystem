/*
 * time：2019年12月7日 11点38分
 * autho：宋淳
 * 描述：定义了对存储文件的二叉树的各种操作，
 *      理论上应只对外暴露这些函数的声明，屏蔽内部实现。
 *      在设计GUI时和命令行控制时也应只调用这些函数。
 */

/*modify: 谢文韬*/
//实现这个头文件时，要引入InfoOpe.h，可以使用里面的函数


#ifndef BITREEOPE_H
#define BITREEOPE_H

#include "NodeInfo.h"
#include "State.h"

// 没考虑清楚，必须要传入2个参数才行
// /*
//  * 实现功能：分别从path得到与之对应的FileNode和从FileNode得到对应的path
//  *
// */
// FileNode * get_node_from_path(char *path);
// char * get_path_from_node(FileNode *node);

/*
 * 功能描述：创建path目录下的二叉树
 * 实现要求：
 *      1. 用左孩子右兄弟法存储节点
 *      2. 应先判断此path是否为空，若为空，直接返回NULL
 *      3. 递归创建此path目录下的其他文件夹的节点
 *      4. 可调用creat_node函数
 */
FilesBiTree create_files_bitree(char *path);



/*
 * 实现功能：在node文件夹下新建一个名称为fileName的文件
 * 实现要求：
 *      1. 检查node是否为文件夹，检查fileName是否已存在
 *      2. 先新建实际的文件，再创建此文件二叉树节点，把节点插到node的左孩子
 */
int add_file(FileNode *node, char *fileName);
int add_file_in_path(char *path, char *fileName);



/*
 * 实现功能：在node文件夹下新建一个名为folderName的文件夹
 * 要求：同上
*/
int add_folder(FileNode *node, char *folderName);
int add_folder_in_path(char *path, char *folderName);



/*
 * 返回类型：OK表示成功执行，ERROR表示执行失败
 * 实现功能：打印此目录下的文件(夹)，参考在powerShell中使用tree命令的效果
 * 实现要求：
 *          1. 要先判断接收到的是文件还是文件夹
 *          2. 若文件夹为空，则直接返回
 *          3. 递归调用，输出此文件夹下的所有文件(夹)
 */
int tree_files(FilesBiTree tree);
int tree_files_in_path(char *path);   //功能同上，接受路径作为参数，可调用print_files函数



/*
 * 实现功能：只输出此目录下的文件(夹)的名字
 * 实现要求：
 *          1. 要先判断接收到的是文件还是文件夹。
 *          2. 若文件夹为空，则直接返回
 *          3. 只打印名字，一行最多6个
 *          5. **一定要对齐，行列都要，左对齐
 *              思路：先找到最长的字符串的长度，以此长度作为所有列的长度，
 *              同时，若最长长度超过某个值，则用这个值，字符串直接截掉
 *          4. 可调用sort_nodes_by_name()函数将文件排序整齐
 */
int list_files_name_only(FilesBiTree tree);
int list_files_name_only_in_path(char *path); //功能同上，接受路径作为参数，可调用以上函数



/*
 * 实现功能：在一行中输出一个文件(夹)的文件(夹)命，大小，时间
 * 实验要求：
 *      1. 判断是不是文件夹，为空文件夹直接返回
 *      2. 列与列间要对齐，参考在PowerShell中ls命令的样式
 */
int list_files(FilesBiTree tree);
int list_files_in_path(char *path);



/*
 * 较难！
 * 功能描述：在指定文件夹下查找名字中有name的文件(夹)，
 *          并把节点的指针存储在一个只读链表(数组)中，在UI中显示是需要二级指针
 * 难点：要使用二级指针
 * 优化：效率可能会很低，可以想办法建一个索引
*/
FileNode **find(FileNode * dir, char *name);



/*
 * 功能描述：在dirPath文件夹下查找名字中有name的文件(夹)，
 *          并像ls一样打印其详细信息到屏幕上
*/
int find_and_list(char * dirPath, char *name);



/*
 * 实现功能：修改此FileNode对应文件(夹)的名字，不仅要在这个系统中修改，还要对此文件的实际名字修改
 * 功能要求：
 *      1. 修改二叉树中存储的信息
 *      2. 修改实际文件信息
 *      3. 要更新节点的信息，就是修改时间那一项
*/
int rename_file(FileNode *node, char *newName);
int rename_file_in_path(char *path, char *newName);



/*
 * 调用须知：调用此函数时，要先处理好其父节点与其孩子的关系。
 *          同时，在调用要提示用户确认删除
 * 实现功能：把node指向的空间free掉，把实际文件删掉
 *          实现者不用管左右孩子，那是调用者该关心的。
 * 实现要求：
 *      1.判断是文件还是文件夹，若是文件夹直接返回
 *      2.把要删除的节点的动态内存free掉
 *      3.删除二叉树的节点
 *      4.删除实际文件，若权限不够则不理会了
*/
int remove_file(FileNode *node);
int remove_file_in_path(char *path);



/*
 * 调用须知：调用此函数前，要把其右孩子赋给其父亲指向它的那个孩子，(左孩子右兄弟法存储)
 *          删除前要用户确认。
 * 实现功能：删除此文件夹下的所有文件，循环free节点。
 * 实现要求：
 *      1.判断是文件夹还是文件，是文件就直接返回
 *      2.free掉所有动态内存
 *      3.删除此节点的左孩子及其所有孩子(其右孩子和它是同一个级别的文件)
*/
int remove_folder(FileNode *node);
int remove_folder_in_path(char *path);



/*
 * 实现功能：复制功能
 * 实现步骤：
 *      1. 判断destPath是否为存在的文件夹
 *      2. 若node为folder型，调用copy_folder函数；否则调用copy_file
*/
int copy_node(char *destPath, FileNode * node);
//把绝对路径为sourcePath的文件(夹)复制到destPath文件夹下，实现同上，
//把sourcePath翻译为相应的node参数，若没有则返回错误代码ERROR
int copy_node_in_path(char *destPath, char *sourcePath);



/*
 * 实现功能：把node指向的节点复制到目标路径destPath下
 * 实现要求：
 *      1. 把node接到destPath的左孩子，或者左孩子的右孩子上
 *      2. 实际的文件复制操作
*/
int copy_file(char * destPath, FileNode *node);



/*
 * 实现功能：把node指向的目录复制到destPath下，
 *          注意这是要复制一整个目录(包括其下的所有文件(夹))到目标路径
 * 实现要求：
 *      1. 判断node是否为目录
 *      2.
*/
int copy_folder(char *destPath, FileNode *node);



/*
 * 功能描述：把node文件移动到destPath目录下
 * 实习要求：
 *      1. 判断destPath和node
 * 实现思路：可用copy_file函数和remove_file函数
*/
int move_file(char *destPath, FileNode *node);
int move_file_in_path(char *destPath, char *sourcePath);



/*
 * 实现功能：只对tree目录下的这一层文件进行排序，ordering是排序方式，
 *          有name，modifyTime，size，拓展名(拓展名按字典序排，拓展名相同按name排)，
 *          以及升序降序的方式
 * 实现细节：
 *      1. 判断tree是否为文件夹
 *      2. 对tree的右子树排序
 * 实现思路：可以用switch_case语句解析ordering，函数跳转到特定的排序方式。当然也可以用其他更好的方法。
 * 难点：目前对这个函数的实现没有太好的办法，算是一个难点。如果不能复用代码，每个方式都写一个算法，
 *      再加上升序降序的选择，至少要写8个算法，但是这些算法只是判定的主键不同，造成大量代码复用。
*/
void sort_files(FilesBiTree tree, char *ordering);
void sort_files_in_path(char *path);



#endif
