#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Headers\linkstack.h"
#define MAXSIZE 256

typedef enum//定义枚举 
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


contentType tokenType(char *symbol,int *i,char *fix) //获取表达式每一位的类型 
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



int insertChar(char *postfix,char x)//将字符插入数组 
{
	int len=strlen(postfix);
	if(len+2>=MAXSIZE)
	{
		printf("错误,输入数据过多\n");
		return 0;
	}
	else
	{
		postfix[len]=x;
		postfix[len+1]='\0';
		return 1;
	}
}

int inPriority(contentType type)//栈内优先级
{
	if(type==ADD||type==MIN) return 1;
	if(type==MUL||type==DIV) return 2;
	if(type==Leftpar) return 0;
	if(type==Rightpar) return 3;
	if(type==END) return 0;
}

int outPriority(contentType type)//栈外优先级 
{
	if(type==ADD||type==MIN) return 1;
	if(type==MUL||type==DIV) return 2;
	if(type==Leftpar) return 3;
	if(type==Rightpar) return 3;
	if(type==END) return 0;
}


int toPostfix(Stack *s,char *infix,char *postfix)//中缀转后缀 
{

	int a=0;
	char symbol;
	char e;//用来接出栈的字符 ？？content type？
	postfix[0]='\0'; 
	contentType token;
	s->next->data=END;  //第一个入栈（栈底元素） 
	token=tokenType(&symbol,&a,infix);
	
	while(token!=END)
	{
		if(token==NUM)
		{
			insertChar(postfix,symbol);
		}
		else if(token==Rightpar)//遇到右括号 
		{
			if(s->next->data==Leftpar)
			{
				printf("ERROR!括号之间没有数据，请重新输入\n"); 
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
					printf("ERROR!未找到左括号，请重新输入\n");
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



int calculate(Stack *s,char *postfix)//计算后缀表达式 
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


int main()//半成品，写了两天，写了一堆bug，有空再写吧 
{
	Stack *linkStack=initStack();
	push(linkStack,END);
	char infix[MAXSIZE];
	initArray(infix);
	char postfix[MAXSIZE];
	initArray(postfix);
	int c;
	int number=0;
	printf("请输入表达式\n");
	do
	{
		scanf("%s",infix);
	
		c = toPostfix(linkStack, infix, postfix);

	}while(c==0);
	
		calculate(linkStack,postfix);

	
	return 0;
}
