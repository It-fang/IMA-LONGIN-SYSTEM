#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//清屏函数
#include"login.h"			//实现用户登录
#include"stde.h"			//实现数据的操控
#include"showmenu.h"		//打印界面
#include"define.h"			//放置所需的声明


//enum Member.sex {w,m};	//限定性别的输入

int main()
{
	Link head=NULL;              //接受返回的头指针
	int i;						// i 实现选择登陆或注册功能

	Loginscreen();				//打印登陆界面
	scanf("%d",&i);
	Create_File();				//创建文本
	if(i==1)
	{
		head=Create_Link();				//创建链表
		Login(head);					//登陆	
	}
	else if(i==2)
	{
		Create_File();		//创建文件
		Registers();		//注册
		return;
	}

	return 0;
}
