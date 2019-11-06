#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//清屏函数
#include"login.h"			//实现用户登录
#include"stde.h"			//实现数据的操控
#include"showmenu.h"		//打印界面
#include"define.h"			//放置所需的声明

void Loginscreen()		//登陆界面
{
	printf("                    欢迎使用IMA部员管理系统\n");
	printf("        -----------------------------------------------\n");
	printf("        |      1.登陆                      2.注册      |\n");
	printf("        -----------------------------------------------\n");
	printf("登陆请按1，注册请按2\n");
}

void Showmenu_minister()			//部长主菜单
{
	system("cls");
	printf("						IMA部员信息管理系统\n");
	printf("				--------------------------------------------------\n");
	printf("				|       1.显示所有成员信息       2.删除部员        |\n");
	printf("				|       3.查找部员信息           4.增加部员       |\n");
	printf("				|       5.修改信息               6.保存信息       |\n");
	printf("				|       0.退出系统                                |\n");
	printf("				3---------------------------------------------------\n");
}

void Showmenu_member()				//部员主菜单
{
	system("cls");
	printf("						IMA部员信息管理系统\n");
	printf("				---------------------------------------------------\n");
	printf("				|        1.显示所有部员信息       2.查找部员信息   |\n");
	printf("				|        3.修改自身信息           4.保存信息       |\n");
	printf("				|        5.退出系统                                |\n");
	printf("				---------------------------------------------------\n");
}

void Puttitle()						//表格标题
{
	printf("账号	学号	姓名	性别	学院	专业	班级	部门		职位	QQ	微信\n");
}	