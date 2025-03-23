#ifndef __LINKSTACK_H_
#define __LINKSTACK_H_


typedef char elemType;

typedef struct stack
{
	elemType data;
	struct stack *next;
	
}Stack;

//栈的初始化 
Stack *initStack();

//栈的判空 
int isEmpty(Stack *s);

//入栈 
int push(Stack *s,elemType e);

//出栈 
int pop(Stack *s,elemType *e);

//获取栈顶元素 
int getTop(Stack *s,elemType *e);

#endif
