#ifndef DOUBLE_LINKED_LIST_H  
#define DOUBLE_LINKED_LIST_H

//��int��������ΪelemType 
typedef int elemType;

//����һ���ṹ�壬ͬʱ������ΪNode 
typedef struct node
{
	elemType data;
	struct node *prev;
	struct node *next;
}Node;

//��ʼ������
Node *initList();

//ͷ��ڵ�
int headInsert(Node *List,elemType e);

//��ȡβ�ڵ�
Node *getTail(Node *List);

//β��ڵ� 
Node *tailInsert(Node *tail,elemType e);

//��������
void listNode(Node *List);

//ָ��λ�ò���
int insertNode(Node *List,int pos,elemType e);

//ɾ���ڵ�
int deleteNode(Node *List,int pos);

//����������
int listLength(Node *List);

//�����п�
int  checkEmpty(Node *List);

//�����ֵ
int changeData(Node *List,int pos,elemType e);

//�������
int searchNode(Node *List,elemType e);

//�����ͷ�
void freeList(Node *List);

#endif
