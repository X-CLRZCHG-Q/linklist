#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Headers\linkstack.h"
#define MAXSIZE 256

typedef enum//����ö�� 
{
	ADD='+',
	MIN='-',
	MUL='*',
	DIV='/',
	Leftpar='(',
	Rightpar=')',
	END='\0',
	NUM
}contentType;


contentType tokenType(char *symbol,int *i,char *fix) //��ȡ���ʽÿһλ������ 
{
	*symbol=fix[*i];
	*i=*i+1;
	switch(*symbol)
	{
		case '+':return ADD;
		case '-':return MIN;
		case '*':return MUL;
		case '/':return DIV;
		case '(':return Leftpar;
		case ')':return Rightpar;
		case '\0':return END;
		default:return NUM;
	}
}



int insertChar(char *postfix,char x)//���ַ��������� 
{
	int len=strlen(postfix);
	if(len+2>=MAXSIZE)
	{
		printf("����,�������ݹ���\n");
		return 0;
	}
	else
	{
		postfix[len]=x;
		postfix[len+1]='\0';
		return 1;
	}
}

int inPriority(contentType type)//ջ�����ȼ�
{
	if(type==ADD||type==MIN) return 1;
	if(type==MUL||type==DIV) return 2;
	if(type==Leftpar) return 0;
	if(type==Rightpar) return 3;
	if(type==END) return 0;
}

int outPriority(contentType type)//ջ�����ȼ� 
{
	if(type==ADD||type==MIN) return 1;
	if(type==MUL||type==DIV) return 2;
	if(type==Leftpar) return 3;
	if(type==Rightpar) return 3;
	if(type==END) return 0;
}


int toPostfix(Stack *s,char *infix,char *postfix)//��׺ת��׺ 
{

	int a=0;
	char symbol;
	char e;//�����ӳ�ջ���ַ� ����content type��
	postfix[0]='\0'; 
	contentType token;
	s->next->data=END;  //��һ����ջ��ջ��Ԫ�أ� 
	token=tokenType(&symbol,&a,infix);
	
	while(token!=END)
	{
		if(token==NUM)
		{
			insertChar(postfix,symbol);
		}
		else if(token==Rightpar)//���������� 
		{
			if(s->next->data==Leftpar)
			{
				printf("ERROR!����֮��û�����ݣ�����������\n"); 
				return 0;
			}
			else
			{
				while(s->next->data!=Leftpar&&s->next->data!='\0')
				{
					pop(s,&e);
					insertChar(postfix,e);
				}    
				
				if(s->next->data==Leftpar)
				{
					pop(s,&e);
				}
				else if(s->next->data=='\0')
				{
					printf("ERROR!δ�ҵ������ţ�����������\n");
					return 0;
				}
			}
		}
		else
		{
			while(outPriority(token)<=inPriority(s->next->data))//contentType
			{
				pop(s,&e);
				insertChar(postfix,e);
			}
			push(s,token);
		}
		
		token=tokenType(&symbol,&a,infix);
	}
	while(s->next->data!=END)
	{
		pop(s,&e);
		insertChar(postfix,e);
	}
	return 1;
}



int calculate(Stack *s,char *postfix)//�����׺���ʽ 
{
	char symbol;
	elemType op1,op2;
	contentType token;
	int i=0;
	token=tokenType(&symbol,&i,postfix);
	elemType result;
	while(token!=END)
	{
		if(token==NUM)
		{
			push(s,symbol-'0');
		}
		else
		{
			pop(s,&op2);
			pop(s,&op1);
			
			switch(token)
			{
				case ADD:push(s,op1+op2);break;
				case MIN:push(s,op1-op2);break;
				case MUL:push(s,op1*op2);break;
				case DIV:push(s,op1/op2);break;

			}
		}
		token=tokenType(&symbol,&i,postfix);
	}
	pop(s,&result);
	printf("%d\n",result);
	return 1;
}

void initArray(char* fix)
{
	int i=0;
	for(i=0;i<MAXSIZE;i++)
	{
		fix[i]='\0';	
	}
}


int main()//���Ʒ��д�����죬д��һ��bug���п���д�� 
{
	Stack *linkStack=initStack();
	push(linkStack,END);
	char infix[MAXSIZE];
	initArray(infix);
	char postfix[MAXSIZE];
	initArray(postfix);
	int c;
	int number=0;
	printf("��������ʽ\n");
	do
	{
		scanf("%s",infix);
	
		c = toPostfix(linkStack, infix, postfix);

	}while(c==0);
	
		calculate(linkStack,postfix);

	
	return 0;
}
