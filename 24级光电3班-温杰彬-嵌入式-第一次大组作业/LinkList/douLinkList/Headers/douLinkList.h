#ifndef DOUBLE_LINKED_LIST_H  
#define DOUBLE_LINKED_LIST_H

//把int类型命名为elemType 
typedef int elemType;

//定义一个结构体，同时重命名为Node 
typedef struct node
{
	elemType data;
	struct node *prev;
	struct node *next;
}Node;

//初始化链表
Node *initList();

//头插节点
int headInsert(Node *List,elemType e);

//获取尾节点
Node *getTail(Node *List);

//尾插节点 
Node *tailInsert(Node *tail,elemType e);

//遍历链表
void listNode(Node *List);

//指定位置插入
int insertNode(Node *List,int pos,elemType e);

//删除节点
int deleteNode(Node *List,int pos);

//计算链表长度
int listLength(Node *List);

//链表判空
int  checkEmpty(Node *List);

//链表改值
int changeData(Node *List,int pos,elemType e);

//链表查找
int searchNode(Node *List,elemType e);

//链表释放
void freeList(Node *List);

#endif
