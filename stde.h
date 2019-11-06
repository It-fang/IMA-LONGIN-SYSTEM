#ifndef _test_stde_
#define _test_stde_

#include"define.h"

struct Node *Create_Link();					//创建链表
void Print_Link(Link head);					//打印链表
void Display_all(Link head);				//打印全部成员信息
void Display_a(Link p);						//打印一个成员信息
Link Query(Link head,char number[]);			//查找成员
Link Delete(Link head,char number[]);			//删除成员
void Addition(Link head,char number[]);			//增加成员

#endif
