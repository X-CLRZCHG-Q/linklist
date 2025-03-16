//������һ����������ADT 

#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\singLinkList.h"


//��ʼ������
Node *initList()
{
	Node *head=(Node*)malloc(sizeof(Node));//�ڶ��ڴ��п���һ�οռ䣬�׵�ַ��headָ�� 
	head->data =0;                         //�׽ڵ�������ֵΪ0 
	head->next=NULL;                       //�׽ڵ��ָ����ֵΪNULL 
	return head;                           //��head��ֵ�������ٿռ���׵�ַ�����ݸ����� 
}

//ͷ��ڵ�
int headInsert(Node *List,elemType e)    //���������Ҫ�����ֵ 
{
	Node *p=(Node *)malloc(sizeof(Node)); //�ڶ��ڴ��п���һ�οռ䣬�׵�ַ��pָ�룬���½ڵ� 
	p->data=e;                            //�Ѳ������ݸ��½ڵ�p������ 
	p->next=List->next;                   //��ԭ����һ���ڵ�ĵ�ַ���½ڵ�p����pָ��ԭ��һ�ڵ� 
	List->next=p;                         //���½ڵ�p�ĵ�ַ���׽ڵ� 
	return 1;
}

//��ȡβ�ڵ�
Node *getTail(Node *List)
{
	Node *p=List;                         //��list����ĵ�ַ��p 
	while(p->next!=NULL)
	{
		p=p->next;	                      //����ѭ���ҵ�β�ڵ� 
	}	
	return p;                             //����β�ڵ��ַ������ 
} 

//β��ڵ� 
Node *tailInsert(Node *tail,elemType e)    
{
	Node *p=(Node *)malloc(sizeof(Node));
	p->data=e;                            //�Ѵ�������ݸ�ֵ���½ڵ� 
	p->next=NULL;                         //�½ڵ�ָ��NULL 
	tail->next=p;                         //���½ڵ�ĵ�ַ��ԭ����β�ڵ� 
	return p;                             //�½ڵ��Ϊ�µ�β�ڵ㣬���ظ����� 
}

//��������
void listNode(Node *List)
{
	Node *p=List->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;                        //��p��Ϊ��ʱһֱѭ�����������ÿһ������ 
	}
	printf("\n");
}

//ָ��λ�ò���
int insertNode(Node *List,int pos,elemType e)
{
	Node *p=List;                         
	int i=0;
	while(i<pos-1)                       //��ѭ��ִ��pos-1�� 
	{
		p=p->next;                       
		i++;                             //ÿ��ִ��ʹpָ����һ���ڵ㣬ͬʱi+1 
		
		if(p==NULL)
		{
			printf("�������ݳ��Ȳ������Ҳ�����λ��\n"); 
			return 0;                   
		}                                //���ѭ��������ָ���˿�ָ�룬��˵�����ݲ��� 
	}
	
	Node *q=(Node *)malloc(sizeof(Node));//�ڶ��ڴ��¿���һ���µĽڵ� 
	q->data=e;                           //��ֵ�����µĽڵ� 
	q->next=p->next;                     //���½ڵ�qǰһ���ڵ�����ĵ�ַ��q����qָ���һ���ڵ� 
	p->next=q;                           //���½ڵ�q�ĵ�ַ��ǰһ���ڵ�p����pָ��q 
	return 1;
}

//ɾ���ڵ�
int deleteNode(Node *List,int pos)
{
	Node *p=List;
	int i=0;
	while(i<pos-1)
	{
		p=p->next;
		i++;                              //ͬ�ϣ��ҵ�Ҫɾ���ڵ��ǰһ���ڵ㣬��ַ��p 
		
		if(p==NULL)
		{
			printf("�������ݳ��Ȳ������Ҳ�����λ��\n"); 
			return 0;                    //���ѭ��������ָ���˿�ָ�룬��˵�����ݲ��� 
		}
	}
	
	if(p->next==NULL)                    //�ж����Ҫɾ���Ľڵ�Ҳ�ǿգ�������Ҳ�ǲ��� 
	{
		printf("�������ݳ��Ȳ������Ҳ�����λ��\n");
		return 0;
	}
	else
	{
		Node *q=p->next;                 //����ָ��qָ��Ҫɾ���Ľڵ� 
		p->next=q->next;                 //��Ҫq��ָ��ڵ�ĵ�ַ��p����ʹq��ǰһ���ڵ�ָ��q�ĺ�һ���ڵ� 
		free(q);                         //Ȼ���q�ڵ���ڴ�ռ�free�� 
		return 1;
	}
}

//����������
int listLength(Node *List)
{
	Node *p=List->next;                  //pָ�������һ���ڵ㣨�����׽ڵ㣩 
	int length=0;
	while(p!=NULL)
	{
		p=p->next;
		length++;                        //ͨ��ѭ��֪�����һ���ڵ� 
	}
	
	return length;                       //��󷵻�length��ֵ������ 
}

//�����п�
int  checkEmpty(Node *List)
{
	if(List->next==NULL)
	{
		printf("������Ϊ��\n");          //����׽ڵ�ָ��գ�������Ϊ�� 
		return 0;
	}
	else
	{
		printf("������Ϊ��\n");
		return 1;
	}
}

//�����ֵ
int changeData(Node *List,int pos,elemType e)
{
	Node *p=List;
	int i=0;
	while(i<pos)
	{
		p=p->next;                       //ͨ��ѭ���ҵ�Ҫ��ֵ���Ǹ�λ�õĽڵ� 
		i++;
		
		if(p==NULL)
		{
			printf("�������ݳ��Ȳ������Ҳ�����λ��\n"); 
			return 0;                    //���ѭ��������ָ���˿�ָ�룬��˵�����ݲ���
		}
	}
	
	p->data=e;                           //����ֵ��ֵ���ýڵ� 
	return 1;	
}

//�������
int searchNode(Node *List,elemType e)
{
	Node *p=List;
	int i=0;
	while(p->data!=e)                     //һֱѭ��ֱ���ҵ�ֵe   
	{
		if(p->next==NULL)
		{
			printf("���Ҳ���������\n");
			return 0;                     //���pΪ����˵���Ѿ��ҵ����һ���ڵ㣬��Ȼ�Ҳ������ݣ�����0 
		}
		else
		{
			p=p->next;                    //��û�е����һ���ڵ㣬��һֱѭ��ʹpָ����һ���ڵ� 
			i++;
		}
	}
	printf("���ҵ������ݣ�λ��Ϊ%d\n",i);//����ѭ������˵���ҵ����ݣ������ڵ�iλ 
	return i;
}

//�����ͷ�
void freeList(Node *List)
{
	Node *p=List->next;                  //pָ���һ���ڵ� 
	Node *q;
	
	while(p!=NULL)                       //��p��ΪNULLʱ 
	{
		q=p->next;                       //ʹqָ��p����һ���ڵ� 
		free(p);                         //Ȼ��p��ָ��Ľڵ�free�ͷ� 
		p=q;                             //Ȼ��ʹpָ��qָ��Ľڵ� 
	}                                    //���p��qͬʱΪNULL 
	
	List->next=NULL;                     //���׽ڵ�ָ��NULL 
} 
 



int main()
{
	Node *list=initList();                //��ʼ���������ѵ�ַ��ָ��list
	printf("������Ϊ�˷��������������ڵ�������������Ϊ1����������������Ϊ���˲�Ŷ����ͷ������\n") ;
	printf("��ѡ������Ҫ�Ĳ�����\n");
	printf("����1ʹ��ͷ�巨��������\n");
	printf("����2ʹ��β�巨��������\n");
	printf("����3��������\n");
	printf("����4ָ��λ�ò�������\n");
	printf("����5ɾ���ڵ�\n");
	printf("����6����������\n");
	printf("����7�����п�\n");
	printf("����8����ڵ��ֵ\n");
	printf("����9��������\n");
	printf("����10�����ͷ�\n");
	printf("����0�˳�������\n");
	printf("��������롢ɾ�����������ݺ󲻻�չʾ����������鿴������3���б����鿴����\n");
	printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
	
	int a=0;
	scanf("%d",&a);
	
	while(a!=0)
	{
		if(a==1)
		{
			int i,t;
			printf("��������������ֵ��\n");
			scanf("%d",&i);
			t=headInsert(list,i);
			if(t==1) printf("�ѳɹ�����\n");    //ǰ�巨��������i
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
		else if(a==2)
		{
			int i;
			printf("��������������ֵ��\n");
			scanf("%d",&i);
			Node *tail=getTail(list);        //��ȡβ�ڵ��ַ������ֵ��tailָ�� 
			tailInsert(tail,i);              //ʹ��β�巨������β����������i 
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
		else if(a==3)
		{
			printf("Ŀǰ����������У�\n") ;
			listNode(list);
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
		else if(a==4)
		{
			int p,i,t;
			printf("������Ҫ�����λ�ã�\n");
			scanf("%d",&p);
			printf("������Ҫ��������ݣ�\n");
			scanf("%d",&i);
			t=insertNode(list,p,i);
			if(t==1) printf("�ѳɹ�����\n");
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
		else if(a==5)
		{
			int p; 
			printf("������Ҫɾ����λ��:\n");
			scanf("%d",&p);
			deleteNode(list,p);
			printf("ɾ���ɹ�\n");
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
		else if(a==6)
		{
			int t;
			t=listLength(list);
			printf("����Ŀǰ�����ݳ���Ϊ%d\n",t);
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
		else if(a==7)
		{
			checkEmpty(list);
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
		else if(a==8)
		{
			int p,i,t;
			printf("��������Ҫ�������ݵ�λ�ã�\n");
			scanf("%d",&p);
			printf("��Ҫ����λ�õ����ݸ���Ϊ��\n");
			scanf("%d",&i);
			t=changeData(list,p,i);
			if(t==1) printf("���ݸ��ĳɹ�");
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}	
		else if(a==9)
		{
			int i;
			printf("��������Ҫ���ҵ����ݣ�\n");
			scanf("%d",&i);
			searchNode(list,i);
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}	
		else if(a==10)
		{
			int i;
			printf("��ȷ��Ҫ�ͷ����������в�����ʹȫ�����ݶ�ʧ��\n");
			printf("ȷ��������1������������0\n"); 
			scanf("%d",&i);
			while(i!=1&&i!=0)
			{
				printf("��������ȷ��ѡ��\n");
				scanf("%d",&i);
			}
			if(i==1)
			{
				freeList(list);
				printf("�����ͷųɹ�\n");	
			}
			if(i==0)
			{
				printf("�ѷ���\n");
			}
			printf("�����ѡ������Ҫ�Ĳ�����\n"); 
			printf("�������Ӧ����(ÿ������һ�����֣�����һ�β���)��\n");
			scanf("%d",&a);
		}
	}
	
	getchar();
	return 0;
}
