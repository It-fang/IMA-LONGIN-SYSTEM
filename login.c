#include"showmenu.h"
#include"login.h"
#include"define.h"
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdio.h>


void Create_File()					//建立一个用来储存账号密码的文件
{
	FILE *fp=NULL;
	if((fp=fopen("account.txt","rb"))==NULL)
	{
		if((fp=fopen("account.txt","wb+"))==NULL)
		{
			printf("无法建立文件!\n");
			exit(1);
		}
	}
}

//注册
void Registers()					
{
	Node a,b;						//a用来储存用户输入的账号，b用来储存文件中的账号并用来与a进行对比
	FILE *fp=NULL;
	char temp[20];					//用来存放用户再次输入的密码，并与第一次输入的密码进行比较
	int i,j,k;							//i用来选择性别,j用来选择部门,k用来选择职位

	printf("欢迎来到注册界面\n");
	Sleep(1000);
	fp=fopen("account.txt","rb");
	fread(&b,LEN,1,fp);
	printf("请输入账号：\n");
	scanf("%s",&a.data.id);

	while(1)						//判断文件中是否存在该账号
	{
		if(strcmp(a.data.id,b.data.id))		//如果两个字符串不相等	
		{
			if(!feof(fp))			//如果未到文件结尾
			{
				fread(&b,LEN,1,fp);
			}
			else
				break;
		}
		else
		{
			printf("该用户已经存在，请重新输入!\n");
			scanf("%s",&a.data.id);
		}
	}
	fclose(fp);
	printf("请输入密码：\n");
	scanf("%s",&a.data.password);
	printf("请再次输入密码：\n");
	scanf("%s",&temp);
	do
	{
		if(!(strcmp(a.data.password,temp)))
		{
			printf("请输入你的学号：\n");
			scanf("%s",&a.data.number );
			printf("请输入你的名字：\n");
			scanf("%s",&a.data.name );
			printf("请选择你的性别：1.m，2.w\n");
			scanf("%d",&i);
			while(!(i>=1&&i<=2))
			{
				printf("输入错误，请重新输入：1.m,2.w\n");
				scanf("%d",&i);
			}
			switch(i)
			{
				case 1 :a.data.sex = 'm';break;
				case 2 :a.data.sex = 'w';break;
			}			
			printf("请输入你的学院：\n");
			scanf("%s",&a.data .college );
			printf("请输入你的专业：\n");
			scanf("%s",&a.data .major );
			printf("请输入你的班级：\n");
			scanf("%s",&a.data .clas );
			printf("请选择你的部门：1.智能硬件部，2.移动互联部，3.游戏开发部，4.产品运营部，5.设计部\n");
			scanf("%d",&j);
			while(!(j>=1&&j<=5))
			{
				printf("输入错误，请重新输入：1.智能硬件部，2.移动互联部，3.游戏开发部，4.产品运营部，5.设计部\n");
				scanf("%d",&j);
			}
			switch(j)
			{
				case 1:strcpy(a.data .dept ,"智能硬件部");break;
				case 2:strcpy(a.data .dept ,"移动互联网");break;
				case 3:strcpy(a.data .dept ,"游戏开发部");break;
				case 4:strcpy(a.data .dept ,"产品运营部");break;
				case 5:strcpy(a.data .dept ,"设计部");break;
			}
			printf("请输入你的职位：1.部长，2.部员\n");
			scanf("%d",&k);
			while(!(k>=1&&k<=2))
			{
				printf("输入错误，请重新输入：1.部长,2.部员\n");
				scanf("%d",&k);
			}
			switch(k)
			{
				case 1 :strcpy(a.data .position ,"部长");break;
				case 2 :strcpy(a.data .position ,"部员");break;
			}			
			printf("请输入你的QQ号：\n");
			scanf("%s",&a.data .QQ );
			printf("请输入你的微信号：\n");
			scanf("%s",&a.data .weixin );

			fp=fopen("account.txt","ab");
			fwrite(&a,LEN,1,fp);
			printf("账号注册成功，请重新进入并登录\a\n");
			Sleep(2000);
			fclose(fp);
			return;
		}
		else
		{
			printf("两次密码不匹配，请重新输入\n");
			scanf("%s",&a.data.password);
			printf("请再次输入密码：\n");
			scanf("%s",&temp);
		}
	}while(1);
}

//登录
void Login(Link head)
{
	int i,j;						// i 实现部长的功能权限, j 实现部员的功能权限
	char number[15];					//存放所想要寻找的成员的学号
	Link p;							//接收所想要寻找的成员的地址
	Node a,b;						//a存放用户输入的账号，b用来储存文件中的账号并用来与a进行对比
	FILE *fp=NULL;

	printf("欢迎来到登录界面\n");
	Sleep(1000);
	fp=fopen("account.txt","rb");
	fread(&b,LEN,1,fp);
	printf("请输入账号\n");
	scanf("%s",&a.data.id);
	while(1)
	{
		if(strcmp(a.data.id,b.data.id)==0)				//如果有此用户
		{
			break;
		}
		else
		{
			if(!feof(fp))							//如果还没有读到文件结尾
			{
				fread(&b,LEN,1,fp);
			}
			else
			{
				printf("此用户不存在，请注册完再登陆或重新输入!\n");
				scanf("%s",&a.data.id);
			}
		}
	}
	printf("请输入密码：\n");
	scanf("%s",&a.data.password);
	do
	{
		if(strcmp(a.data.password,b.data.password)==0)			//如果密码匹配
		{
			
			printf("登录成功，欢迎部长使用!\a\n");
			Sleep(1000);

			if(strcmp(b.data.position,"部长")==0)				//判断职位
			{
				Showmenu_minister();							//进入部长主菜单
				printf("请输入你所想要选择的功能前的序号：\n");
				scanf("%d",&i);
				switch(i)
				{
					case 1:
						{
							Display_all(head);				//打印链表中的全部成员
							break;
						}
					case 2:
						{
							printf("请输入你想要删除的成员的学号：\n");
							scanf("%s",number);
							p=Delete(head,number);				//按输入学号删除链表中该成员,并返回新链表的头指针
							Display_all(p);						//打印删除后的链表中的全部成员
							break;
						}
					case 3:
						{
							printf("请输入你想要查询的成员的学号：\n");
							scanf("%s",number);
							p=Query(head,number);				//按输入学号查找该成员，并返回该成员的地址
							Display_a(p);						//打印所查找的成员信息
							break;
						}
					case 4:
						{
							printf("请输入所想要增加的成员的学号：\n");
							scanf("%s",number);
							Addition(head,number);
							Display_all(head);
							break;
						}
				}
			}
			else if(strcmp(b.data .position ,"部员")==0)		//判断职位
			{
				Showmenu_member();								//进入部员主菜单
			}
			fclose(fp);							
			return;
		}
		else
		{
			printf("密码不正确，请重新输入\n");
			scanf("%s",&a.data.password);
		}
	}while(strcmp(a.data.password,b.data.password)==0);
}
