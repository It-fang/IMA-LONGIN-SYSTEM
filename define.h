#ifndef _test_define_
#define _test_define_

#define LEN sizeof(Node)

typedef struct Member				//定义部员的信息的数据结构
{	
	char id[15];					//账号
	char password[15];				//密码
	char number[15];				//学号
	char name[20];					//名字
	char sex;						//性别
	char college[10];				//学院
	char major[10];					//专业
	char clas[10];					//班级
	char dept[30];					//部门
	char position[15];				//职位
	char QQ[15];					//QQ
	char weixin[20];				//微信
}Member;



typedef struct Node					//定义一个部员信息的节点
{
	Member data;					//数据域
	struct Node *next;				//指针域
}Node, *Link;


int m;								//总计人数

#endif