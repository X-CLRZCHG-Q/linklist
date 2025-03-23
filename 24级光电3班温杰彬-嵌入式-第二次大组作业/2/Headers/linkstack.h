#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_


typedef char elemType;

typedef struct stack
{
	elemType data;
	struct stack *next;
	
}Stack;

//ջ�ĳ�ʼ�� 
Stack *initStack();

//ջ���п� 
int isEmpty(Stack *s);

//��ջ 
int push(Stack *s,elemType e);

//��ջ 
int pop(Stack *s,elemType *e);

//��ȡջ��Ԫ�� 
int getTop(Stack *s,elemType *e);

#endif
