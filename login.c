#include"showmenu.h"
#include"login.h"
#include"define.h"
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdio.h>


void Create_File()					//����һ�����������˺�������ļ�
{
	FILE *fp=NULL;
	if((fp=fopen("account.txt","rb"))==NULL)
	{
		if((fp=fopen("account.txt","wb+"))==NULL)
		{
			printf("�޷������ļ�!\n");
			exit(1);
		}
	}
}

//ע��
void Registers()					
{
	Node a,b;						//a���������û�������˺ţ�b���������ļ��е��˺Ų�������a���жԱ�
	FILE *fp=NULL;
	char temp[20];					//��������û��ٴ���������룬�����һ�������������бȽ�
	int i,j,k;							//i����ѡ���Ա�,j����ѡ����,k����ѡ��ְλ

	printf("��ӭ����ע�����\n");
	Sleep(1000);
	fp=fopen("account.txt","rb");
	fread(&b,LEN,1,fp);
	printf("�������˺ţ�\n");
	scanf("%s",&a.data.id);

	while(1)						//�ж��ļ����Ƿ���ڸ��˺�
	{
		if(strcmp(a.data.id,b.data.id))		//��������ַ��������	
		{
			if(!feof(fp))			//���δ���ļ���β
			{
				fread(&b,LEN,1,fp);
			}
			else
				break;
		}
		else
		{
			printf("���û��Ѿ����ڣ�����������!\n");
			scanf("%s",&a.data.id);
		}
	}
	fclose(fp);
	printf("���������룺\n");
	scanf("%s",&a.data.password);
	printf("���ٴ��������룺\n");
	scanf("%s",&temp);
	do
	{
		if(!(strcmp(a.data.password,temp)))
		{
			printf("���������ѧ�ţ�\n");
			scanf("%s",&a.data.number );
			printf("������������֣�\n");
			scanf("%s",&a.data.name );
			printf("��ѡ������Ա�1.m��2.w\n");
			scanf("%d",&i);
			while(!(i>=1&&i<=2))
			{
				printf("����������������룺1.m,2.w\n");
				scanf("%d",&i);
			}
			switch(i)
			{
				case 1 :a.data.sex = 'm';break;
				case 2 :a.data.sex = 'w';break;
			}			
			printf("���������ѧԺ��\n");
			scanf("%s",&a.data .college );
			printf("���������רҵ��\n");
			scanf("%s",&a.data .major );
			printf("��������İ༶��\n");
			scanf("%s",&a.data .clas );
			printf("��ѡ����Ĳ��ţ�1.����Ӳ������2.�ƶ���������3.��Ϸ��������4.��Ʒ��Ӫ����5.��Ʋ�\n");
			scanf("%d",&j);
			while(!(j>=1&&j<=5))
			{
				printf("����������������룺1.����Ӳ������2.�ƶ���������3.��Ϸ��������4.��Ʒ��Ӫ����5.��Ʋ�\n");
				scanf("%d",&j);
			}
			switch(j)
			{
				case 1:strcpy(a.data .dept ,"����Ӳ����");break;
				case 2:strcpy(a.data .dept ,"�ƶ�������");break;
				case 3:strcpy(a.data .dept ,"��Ϸ������");break;
				case 4:strcpy(a.data .dept ,"��Ʒ��Ӫ��");break;
				case 5:strcpy(a.data .dept ,"��Ʋ�");break;
			}
			printf("���������ְλ��1.������2.��Ա\n");
			scanf("%d",&k);
			while(!(k>=1&&k<=2))
			{
				printf("����������������룺1.����,2.��Ա\n");
				scanf("%d",&k);
			}
			switch(k)
			{
				case 1 :strcpy(a.data .position ,"����");break;
				case 2 :strcpy(a.data .position ,"��Ա");break;
			}			
			printf("���������QQ�ţ�\n");
			scanf("%s",&a.data .QQ );
			printf("���������΢�źţ�\n");
			scanf("%s",&a.data .weixin );

			fp=fopen("account.txt","ab");
			fwrite(&a,LEN,1,fp);
			printf("�˺�ע��ɹ��������½��벢��¼\a\n");
			Sleep(2000);
			fclose(fp);
			return;
		}
		else
		{
			printf("�������벻ƥ�䣬����������\n");
			scanf("%s",&a.data.password);
			printf("���ٴ��������룺\n");
			scanf("%s",&temp);
		}
	}while(1);
}

//��¼
void Login(Link head)
{
	int i,j;						// i ʵ�ֲ����Ĺ���Ȩ��, j ʵ�ֲ�Ա�Ĺ���Ȩ��
	char number[15];					//�������ҪѰ�ҵĳ�Ա��ѧ��
	Link p;							//��������ҪѰ�ҵĳ�Ա�ĵ�ַ
	Node a,b;						//a����û�������˺ţ�b���������ļ��е��˺Ų�������a���жԱ�
	FILE *fp=NULL;

	printf("��ӭ������¼����\n");
	Sleep(1000);
	fp=fopen("account.txt","rb");
	fread(&b,LEN,1,fp);
	printf("�������˺�\n");
	scanf("%s",&a.data.id);
	while(1)
	{
		if(strcmp(a.data.id,b.data.id)==0)				//����д��û�
		{
			break;
		}
		else
		{
			if(!feof(fp))							//�����û�ж����ļ���β
			{
				fread(&b,LEN,1,fp);
			}
			else
			{
				printf("���û������ڣ���ע�����ٵ�½����������!\n");
				scanf("%s",&a.data.id);
			}
		}
	}
	printf("���������룺\n");
	scanf("%s",&a.data.password);
	do
	{
		if(strcmp(a.data.password,b.data.password)==0)			//�������ƥ��
		{
			
			printf("��¼�ɹ�����ӭ����ʹ��!\a\n");
			Sleep(1000);

			if(strcmp(b.data.position,"����")==0)				//�ж�ְλ
			{
				Showmenu_minister();							//���벿�����˵�
				printf("������������Ҫѡ��Ĺ���ǰ����ţ�\n");
				scanf("%d",&i);
				switch(i)
				{
					case 1:
						{
							Display_all(head);				//��ӡ�����е�ȫ����Ա
							break;
						}
					case 2:
						{
							printf("����������Ҫɾ���ĳ�Ա��ѧ�ţ�\n");
							scanf("%s",number);
							p=Delete(head,number);				//������ѧ��ɾ�������иó�Ա,�������������ͷָ��
							Display_all(p);						//��ӡɾ����������е�ȫ����Ա
							break;
						}
					case 3:
						{
							printf("����������Ҫ��ѯ�ĳ�Ա��ѧ�ţ�\n");
							scanf("%s",number);
							p=Query(head,number);				//������ѧ�Ų��Ҹó�Ա�������ظó�Ա�ĵ�ַ
							Display_a(p);						//��ӡ�����ҵĳ�Ա��Ϣ
							break;
						}
					case 4:
						{
							printf("����������Ҫ���ӵĳ�Ա��ѧ�ţ�\n");
							scanf("%s",number);
							Addition(head,number);
							Display_all(head);
							break;
						}
				}
			}
			else if(strcmp(b.data .position ,"��Ա")==0)		//�ж�ְλ
			{
				Showmenu_member();								//���벿Ա���˵�
			}
			fclose(fp);							
			return;
		}
		else
		{
			printf("���벻��ȷ������������\n");
			scanf("%s",&a.data.password);
		}
	}while(strcmp(a.data.password,b.data.password)==0);
}
