#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\linkstack.h"

//��������ջ��ADT 


//ջ�ĳ�ʼ�� 
Stack *initStack()
{
	Stack *s=(Stack *)malloc(sizeof(Stack));
	s->data=0;
	s->next=NULL;
	return s;
}

//ջ���п� 
int isEmpty(Stack *s)
{
	if(s->next==NULL)
	{
		printf("�ǿյ�\n");	
		return 0;
	}
	return 1;
}

//��ջ 
int push(Stack *s,elemType e)
{
	Stack *p=(Stack *)malloc(sizeof(Stack));
	p->data=e;
	p->next=s->next;
	s->next=p;
	return 1;
}

//��ջ 
int pop(Stack *s,elemType *e)
{
	if(s->next==NULL)
	{
		printf("�ǿյ�\n");	
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

//��ȡջ��Ԫ�� 
int getTop(Stack *s,elemType *e)
{
	if(s->next==NULL)
	{
		printf("�ǿյ�\n");	
		return 0;
	}	
	else
	{
		*e=s->next->data;
		return 1;
	}	
} 


