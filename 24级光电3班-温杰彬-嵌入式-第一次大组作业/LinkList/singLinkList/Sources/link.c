//下面是一个单向链表ADT 

#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\singLinkList.h"


//初始化链表
Node *initList()
{
	Node *head=(Node*)malloc(sizeof(Node));//在堆内存中开辟一段空间，首地址给head指针 
	head->data =0;                         //首节点数据域赋值为0 
	head->next=NULL;                       //首节点的指针域赋值为NULL 
	return head;                           //把head的值（即开辟空间的首地址）传递给函数 
}

//头插节点
int headInsert(Node *List,elemType e)    //传入链表和要插入的值 
{
	Node *p=(Node *)malloc(sizeof(Node)); //在堆内存中开辟一段空间，首地址给p指针，即新节点 
	p->data=e;                            //把插入数据给新节点p数据域 
	p->next=List->next;                   //把原来第一个节点的地址给新节点p，即p指向原第一节点 
	List->next=p;                         //把新节点p的地址给首节点 
	return 1;
}

//获取尾节点
Node *getTail(Node *List)
{
	Node *p=List;                         //把list链表的地址给p 
	while(p->next!=NULL)
	{
		p=p->next;	                      //利用循环找到尾节点 
	}	
	return p;                             //返回尾节点地址给函数 
} 

//尾插节点 
Node *tailInsert(Node *tail,elemType e)    
{
	Node *p=(Node *)malloc(sizeof(Node));
	p->data=e;                            //把传入的数据赋值给新节点 
	p->next=NULL;                         //新节点指向NULL 
	tail->next=p;                         //把新节点的地址给原来的尾节点 
	return p;                             //新节点成为新的尾节点，返回给函数 
}

//遍历链表
void listNode(Node *List)
{
	Node *p=List->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;                        //当p不为空时一直循环，输出链表每一个数据 
	}
	printf("\n");
}

//指定位置插入
int insertNode(Node *List,int pos,elemType e)
{
	Node *p=List;                         
	int i=0;
	while(i<pos-1)                       //该循环执行pos-1次 
	{
		p=p->next;                       
		i++;                             //每次执行使p指向下一个节点，同时i+1 
		
		if(p==NULL)
		{
			printf("错误，数据长度不够，找不到该位置\n"); 
			return 0;                   
		}                                //如果循环过程中指向了空指针，则说明数据不够 
	}
	
	Node *q=(Node *)malloc(sizeof(Node));//在堆内存新开辟一个新的节点 
	q->data=e;                           //把值赋给新的节点 
	q->next=p->next;                     //把新节点q前一个节点所存的地址给q，即q指向后一个节点 
	p->next=q;                           //把新节点q的地址给前一个节点p，即p指向q 
	return 1;
}

//删除节点
int deleteNode(Node *List,int pos)
{
	Node *p=List;
	int i=0;
	while(i<pos-1)
	{
		p=p->next;
		i++;                              //同上，找到要删除节点的前一个节点，地址给p 
		
		if(p==NULL)
		{
			printf("错误，数据长度不够，找不到该位置\n"); 
			return 0;                    //如果循环过程中指向了空指针，则说明数据不够 
		}
	}
	
	if(p->next==NULL)                    //判断如果要删除的节点也是空，则数据也是不够 
	{
		printf("错误，数据长度不够，找不到该位置\n");
		return 0;
	}
	else
	{
		Node *q=p->next;                 //创建指针q指向要删除的节点 
		p->next=q->next;                 //把要q所指向节点的地址给p，即使q的前一个节点指向q的后一个节点 
		free(q);                         //然后把q节点的内存空间free掉 
		return 1;
	}
}

//计算链表长度
int listLength(Node *List)
{
	Node *p=List->next;                  //p指向链表第一个节点（不是首节点） 
	int length=0;
	while(p!=NULL)
	{
		p=p->next;
		length++;                        //通过循环知道最后一个节点 
	}
	
	return length;                       //最后返回length的值给函数 
}

//链表判空
int  checkEmpty(Node *List)
{
	if(List->next==NULL)
	{
		printf("该链表为空\n");          //如果首节点指向空，即链表为空 
		return 0;
	}
	else
	{
		printf("该链表不为空\n");
		return 1;
	}
}

//链表改值
int changeData(Node *List,int pos,elemType e)
{
	Node *p=List;
	int i=0;
	while(i<pos)
	{
		p=p->next;                       //通过循环找到要改值的那个位置的节点 
		i++;
		
		if(p==NULL)
		{
			printf("错误，数据长度不够，找不到该位置\n"); 
			return 0;                    //如果循环过程中指向了空指针，则说明数据不够
		}
	}
	
	p->data=e;                           //把新值赋值给该节点 
	return 1;	
}

//链表查找
int searchNode(Node *List,elemType e)
{
	Node *p=List;
	int i=0;
	while(p->data!=e)                     //一直循环直到找到值e   
	{
		if(p->next==NULL)
		{
			printf("查找不到该数据\n");
			return 0;                     //如果p为空则说明已经找到最后一个节点，仍然找不到数据，返回0 
		}
		else
		{
			p=p->next;                    //还没有到最后一个节点，则一直循环使p指向下一个节点 
			i++;
		}
	}
	printf("查找到该数据，位置为%d\n",i);//跳出循环，则说明找到数据，数据在第i位 
	return i;
}

//链表释放
void freeList(Node *List)
{
	Node *p=List->next;                  //p指向第一个节点 
	Node *q;
	
	while(p!=NULL)                       //当p不为NULL时 
	{
		q=p->next;                       //使q指向p的下一个节点 
		free(p);                         //然后将p所指向的节点free释放 
		p=q;                             //然后使p指向q指向的节点 
	}                                    //最后p和q同时为NULL 
	
	List->next=NULL;                     //把首节点指向NULL 
} 
 



int main()
{
	Node *list=initList();                //初始化链表，并把地址给指针list
	printf("本程序为了方便检验与操作，节点的数据域仅设置为1个整数，并不是因为本人菜哦（狗头保命）\n") ;
	printf("请选择你想要的操作：\n");
	printf("输入1使用头插法插入数据\n");
	printf("输入2使用尾插法插入数据\n");
	printf("输入3遍历链表\n");
	printf("输入4指定位置插入数据\n");
	printf("输入5删除节点\n");
	printf("输入6计算链表长度\n");
	printf("输入7链表判空\n");
	printf("输入8链表节点改值\n");
	printf("输入9查找数据\n");
	printf("输入10链表释放\n");
	printf("输入0退出操作：\n");
	printf("本程序插入、删除、更改数据后不会展示新链表，如需查看请输入3进行遍历查看检验\n");
	printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
	
	int a=0;
	scanf("%d",&a);
	
	while(a!=0)
	{
		if(a==1)
		{
			int i,t;
			printf("请插入你想输入的值：\n");
			scanf("%d",&i);
			t=headInsert(list,i);
			if(t==1) printf("已成功插入\n");    //前插法插入数据i
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
		else if(a==2)
		{
			int i;
			printf("请插入你想输入的值：\n");
			scanf("%d",&i);
			Node *tail=getTail(list);        //获取尾节点地址，并赋值给tail指针 
			tailInsert(tail,i);              //使用尾插法在链表尾部插入数据i 
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
		else if(a==3)
		{
			printf("目前链表的数据有：\n") ;
			listNode(list);
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
		else if(a==4)
		{
			int p,i,t;
			printf("请输入要插入的位置：\n");
			scanf("%d",&p);
			printf("请输入要插入的数据：\n");
			scanf("%d",&i);
			t=insertNode(list,p,i);
			if(t==1) printf("已成功插入\n");
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
		else if(a==5)
		{
			int p; 
			printf("请输入要删除的位置:\n");
			scanf("%d",&p);
			deleteNode(list,p);
			printf("删除成功\n");
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
		else if(a==6)
		{
			int t;
			t=listLength(list);
			printf("链表目前的数据长度为%d\n",t);
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
		else if(a==7)
		{
			checkEmpty(list);
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
		else if(a==8)
		{
			int p,i,t;
			printf("请输入你要更改数据的位置：\n");
			scanf("%d",&p);
			printf("你要将此位置的数据更改为：\n");
			scanf("%d",&i);
			t=changeData(list,p,i);
			if(t==1) printf("数据更改成功");
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}	
		else if(a==9)
		{
			int i;
			printf("请输入你要查找的数据：\n");
			scanf("%d",&i);
			searchNode(list,i);
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}	
		else if(a==10)
		{
			int i;
			printf("你确定要释放链表？若进行操作会使全部数据丢失！\n");
			printf("确认请输入1，返回请输入0\n"); 
			scanf("%d",&i);
			while(i!=1&&i!=0)
			{
				printf("请做出正确的选择\n");
				scanf("%d",&i);
			}
			if(i==1)
			{
				freeList(list);
				printf("链表释放成功\n");	
			}
			if(i==0)
			{
				printf("已返回\n");
			}
			printf("请继续选择你想要的操作：\n"); 
			printf("请输入对应数字(每次输入一个数字，进行一次操作)：\n");
			scanf("%d",&a);
		}
	}
	
	getchar();
	return 0;
}
