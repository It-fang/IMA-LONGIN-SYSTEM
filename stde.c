#include"define.h"
#include"login.h"
#include"stde.h"
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

struct Node *Create_Link()				//��������
{
	Link head=NULL;							//ͷָ��
	Link p1=NULL,p2=NULL;							//ָ�����ָ��
	FILE *fp=NULL;
	
	m=0;								//��ʼ������
	p1=p2=(Node *) malloc (LEN);
	p1->next =NULL;
	p2->next =NULL;
	
	if((fp=fopen("account.txt","rb"))==NULL)
	{
		printf("�޷����ļ�");
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




void Print_Link(Link head)				//�������
{
	
	Link p=NULL;						//ָ��ǰ������

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
		printf("������Ϊ������\n");
	}
}

void Display_all(Link head)					//��ʾȫ����Ա��Ϣ
{
	printf("\n������%d����Ա\n",m);
	Puttitle();							//��ӡ��ͷ
	Print_Link(head);					//��ӡ��������
}

Link Query(Link head,char number[])			//Ѱ�Ҹó�Ա�������ظó�Ա�ĵ�ַ
{
	Link p=NULL;					//ָ��ǰ���
	int n=0;							//ͨ���� m �Ƚ����ж��Ƿ��ҵ��ó�Ա

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
		printf("û�ҵ��ó�Ա\n");
		exit(0);
	}

	return(p);
}

void Display_a(Link p)				//��ӡ��Ѱ�ҵĳ�Ա��Ϣ
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

Link Delete(Link head,char number[])				//ɾ����Ա
{
	Link p1,p2;					//p1ָ��ǰ���,p2ָ��ǰ����ǰһ�����

	if(head==NULL)
	{
		printf("����һ��������");
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
		if(p1==head)			//���Ҫɾ���ĳ�Աλ��ͷ���
		{

			head=p1->next ;
		}
		else				//һ�������
		{
			p2->next =p1->next ;
		}
		printf("��ѧ��Ϊ%s�ĳ�Ա�Ѿ���ɾ����\n",number);
		m-=1;				//��Ա������ 1
	}
	else
	{
		printf("ɾ��ʧ�ܣ�û���ҵ��ó�Ա\n");
	}

	return(head);
}

void Addition(Link head,char number[])			//���ӳ�Ա
{
	Link p1=NULL,p2=NULL;						// p1 ָ��ǰ���, p2 �����µĽ�����³�Ա��Ϣ
	int i,j,k;						// i ʵ�ֳ�Ա���Ա�ѡ�� j ʵ�ֳ�Ա�Ĳ���ѡ��, k ʵ�ֳ�Ա��ְλѡ��

	p2=(Node *)malloc(LEN);
	p1=head;
	while((strcmp(p1->data.number ,number)!=0)&&(p1->next  !=NULL))
	{
		p1=p1->next ;
	}
	if(p1->next!=NULL)
	{
		printf("�ó�Ա�Ѿ�����\n");
		exit(0);
	}
	else
	{
		p1->next = p2;
	}
	strcpy(p2->data.number ,number);
	printf("������ó�Ա��id:\n");
	scanf("%s",p2->data .id );
	printf("������ó�Ա�����룺\n");
	scanf("%s",p2->data .password );
	printf("������ó�Ա�����֣�\n");
	scanf("%s",p2->data .name );
	printf("��ѡ��ó�Ա���Ա�1.m��2.w\n");
	scanf("%d",&i);
	while(!(i>=1&&i<=2))
	{
		printf("����������������룺1.m,2.w\n");
		scanf("%d",&i);
	}
	switch(i)
	{
		case 1 :p2->data.sex = 'm';break;
		case 2 :p2->data.sex = 'w';break;
	}
	printf("������ó�Ա��ѧԺ��\n");
	scanf("%s",p2->data .college );
	printf("������ó�Ա��רҵ��\n");
	scanf("%s",p2->data .major );
	printf("������ó�Ա�İ༶��\n");
	scanf("%s",p2->data .clas );
	printf("��ѡ��ĸó�Ա���ţ�1.����Ӳ������2.�ƶ���������3.��Ϸ��������4.��Ʒ��Ӫ����5.��Ʋ�\n");
	scanf("%d",&j);
	while(!(j>=1&&j<=5))
	{
		printf("����������������룺1.����Ӳ������2.�ƶ���������3.��Ϸ��������4.��Ʒ��Ӫ����5.��Ʋ�\n");
		scanf("%d",&j);
	}
	switch(j)
	{
		case 1:strcpy(p2->data .dept ,"����Ӳ����");break;
		case 2:strcpy(p2->data .dept ,"�ƶ�������");break;
		case 3:strcpy(p2->data .dept ,"��Ϸ������");break;
		case 4:strcpy(p2->data .dept ,"��Ʒ��Ӫ��");break;
		case 5:strcpy(p2->data .dept ,"��Ʋ�");break;
	}
	printf("������ó�Ա��ְλ��1.������2.��Ա\n");
	scanf("%d",&k);
	while(!(k>=1&&k<=2))
	{
		printf("����������������룺1.����,2.��Ա\n");
		scanf("%d",&k);
	}
	switch(k)
	{
		case 1 :strcpy(p2->data .position ,"����");break;
		case 2 :strcpy(p2->data .position ,"��Ա");break;
	}
	printf("������ó�Ա��QQ��\n");
	scanf("%s",p2->data .QQ );
	printf("������ó�Ա��weixin��\n");
	scanf("%s",p2->data .weixin );
	p2->next =NULL;
	++m;											//��Ա���� 1
	printf("ѧ��Ϊ%s�ĳ�Ա���ӳɹ�\n");
}