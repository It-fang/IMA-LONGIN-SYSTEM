#include"define.h"
#include"login.h"
#include"stde.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

struct Node *Create_Link()				//创建链表
{
	Link head=NULL;							//头指针
	Link p1=NULL,p2=NULL;							//指向结点的指针
	FILE *fp=NULL;
	
	m=0;								//初始化人数
	p1=p2=(Node *) malloc (LEN);
	p1->next =NULL;
	p2->next =NULL;
	
	if((fp=fopen("account.txt","rb"))==NULL)
	{
		printf("无法打开文件");
		exit(1);
	}
	head=NULL;

	while(fread(p1,LEN,1,fp)!=0)
	{
	
		m++;
		if(m==1)
		{
			head=p1;
		}
		else
		{
			p2->next = p1;
			p2=p1;
		}
		p1=(Node *) malloc (LEN);

	}
	
	p2->next = NULL;
	fclose(fp);
	return(head);
}




void Print_Link(Link head)				//输出链表
{
	
	Link p=NULL;						//指向当前链表结点

	p=head;
	if(head!=NULL)
	{
		do
		{
			printf("%s\t",p->data.id );
			printf("%s\t",p->data .number );
			printf("%s\t",p->data .name );
			printf("%c\t",p->data .sex );
			printf("%s\t",p->data.college );
			printf("%s\t",p->data .major );
			printf("%s\t",p->data .clas );
			printf("%s\t",p->data .dept );
			printf("%s\t",p->data .position );
			printf("%s\t",p->data .QQ );
			printf("%s\t",p->data .weixin );
			printf("\n");
			p=p->next;
		}while(p!=NULL);
	}
	else
	{
		printf("此链表为空链表\n");
	}
}

void Display_all(Link head)					//显示全部成员信息
{
	printf("\n现在有%d个成员\n",m);
	Puttitle();							//打印表头
	Print_Link(head);					//打印整个链表
}

Link Query(Link head,char number[])			//寻找该成员，并返回该成员的地址
{
	Link p=NULL;					//指向当前结点
	int n=0;							//通过与 m 比较来判断是否找到该成员

	p=head;
	while(p!=NULL)
	{
		if(strcmp(p->data.name ,number)==0)
		{
			break;
		}
		n++;
		p=p->next;
	}
	if(n==m)
	{
		printf("没找到该成员\n");
		exit(0);
	}

	return(p);
}

void Display_a(Link p)				//打印所寻找的成员信息
{
	Puttitle();
	printf("%s\t",p->data.id );
	printf("%s\t",p->data .number );
	printf("%s\t",p->data .name );
	printf("%c\t",p->data .sex );
	printf("%s\t",p->data.college );
	printf("%s\t",p->data .major );
	printf("%s\t",p->data .clas );
	printf("%s\t",p->data .dept );
	printf("%s\t",p->data .position );
	printf("%s\t",p->data .QQ );
	printf("%s\t",p->data .weixin );
	printf("\n");
}

Link Delete(Link head,char number[])				//删除成员
{
	Link p1,p2;					//p1指向当前结点,p2指向当前结点的前一个结点

	if(head==NULL)
	{
		printf("这是一个空链表");
		exit(0);
	}

	p1=head;
	while((strcmp(p1->data.number ,number)!=0)&&p1->next !=NULL)
	{
		p2=p1;
		p1=p1->next ;
	}
	if(strcmp(p1->data.number ,number)==0)
	{
		if(p1==head)			//如果要删除的成员位于头结点
		{

			head=p1->next ;
		}
		else				//一般情况下
		{
			p2->next =p1->next ;
		}
		printf("该学号为%s的成员已经被删除！\n",number);
		m-=1;				//成员数减少 1
	}
	else
	{
		printf("删除失败，没有找到该成员\n");
	}

	return(head);
}

void Addition(Link head,char number[])			//增加成员
{
	Link p1=NULL,p2=NULL;						// p1 指向当前结点, p2 建立新的结点存放新成员信息
	int i,j,k;						// i 实现成员的性别选择， j 实现成员的部门选择, k 实现成员的职位选择

	p2=(Node *)malloc(LEN);
	p1=head;
	while((strcmp(p1->data.number ,number)!=0)&&(p1->next  !=NULL))
	{
		p1=p1->next ;
	}
	if(p1->next!=NULL)
	{
		printf("该成员已经存在\n");
		exit(0);
	}
	else
	{
		p1->next = p2;
	}
	strcpy(p2->data.number ,number);
	printf("请输入该成员的id:\n");
	scanf("%s",p2->data .id );
	printf("请输入该成员的密码：\n");
	scanf("%s",p2->data .password );
	printf("请输入该成员的名字：\n");
	scanf("%s",p2->data .name );
	printf("请选择该成员的性别：1.m，2.w\n");
	scanf("%d",&i);
	while(!(i>=1&&i<=2))
	{
		printf("输入错误，请重新输入：1.m,2.w\n");
		scanf("%d",&i);
	}
	switch(i)
	{
		case 1 :p2->data.sex = 'm';break;
		case 2 :p2->data.sex = 'w';break;
	}
	printf("请输入该成员的学院：\n");
	scanf("%s",p2->data .college );
	printf("请输入该成员的专业：\n");
	scanf("%s",p2->data .major );
	printf("请输入该成员的班级：\n");
	scanf("%s",p2->data .clas );
	printf("请选择的该成员部门：1.智能硬件部，2.移动互联部，3.游戏开发部，4.产品运营部，5.设计部\n");
	scanf("%d",&j);
	while(!(j>=1&&j<=5))
	{
		printf("输入错误，请重新输入：1.智能硬件部，2.移动互联部，3.游戏开发部，4.产品运营部，5.设计部\n");
		scanf("%d",&j);
	}
	switch(j)
	{
		case 1:strcpy(p2->data .dept ,"智能硬件部");break;
		case 2:strcpy(p2->data .dept ,"移动互联网");break;
		case 3:strcpy(p2->data .dept ,"游戏开发部");break;
		case 4:strcpy(p2->data .dept ,"产品运营部");break;
		case 5:strcpy(p2->data .dept ,"设计部");break;
	}
	printf("请输入该成员的职位：1.部长，2.部员\n");
	scanf("%d",&k);
	while(!(k>=1&&k<=2))
	{
		printf("输入错误，请重新输入：1.部长,2.部员\n");
		scanf("%d",&k);
	}
	switch(k)
	{
		case 1 :strcpy(p2->data .position ,"部长");break;
		case 2 :strcpy(p2->data .position ,"部员");break;
	}
	printf("请输入该成员的QQ：\n");
	scanf("%s",p2->data .QQ );
	printf("请输入该成员的weixin：\n");
	scanf("%s",p2->data .weixin );
	p2->next =NULL;
	++m;											//成员数加 1
	printf("学号为%s的成员增加成功\n");
}