#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\linkstack.h"

//这里是链栈的ADT 


//栈的初始化 
Stack *initStack()
{
	Stack *s=(Stack *)malloc(sizeof(Stack));
	s->data=0;
	s->next=NULL;
	return s;
}

//栈的判空 
int isEmpty(Stack *s)
{
	if(s->next==NULL)
	{
		printf("是空的\n");	
		return 0;
	}
	return 1;
}

//入栈 
int push(Stack *s,elemType e)
{
	Stack *p=(Stack *)malloc(sizeof(Stack));
	p->data=e;
	p->next=s->next;
	s->next=p;
	return 1;
}

//出栈 
int pop(Stack *s,elemType *e)
{
	if(s->next==NULL)
	{
		printf("是空的\n");	
		return 0;
	}
	else
	{
		*e=s->next->data;
		Stack *p=s->next;
		s->next=p->next;
		free(p);
		return 1;
	}
}

//获取栈顶元素 
int getTop(Stack *s,elemType *e)
{
	if(s->next==NULL)
	{
		printf("是空的\n");	
		return 0;
	}	
	else
	{
		*e=s->next->data;
		return 1;
	}	
} 


