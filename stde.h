#ifndef _test_stde_
#define _test_stde_

#include"define.h"

struct Node *Create_Link();					//��������
void Print_Link(Link head);					//��ӡ����
void Display_all(Link head);				//��ӡȫ����Ա��Ϣ
void Display_a(Link p);						//��ӡһ����Ա��Ϣ
Link Query(Link head,char number[]);			//���ҳ�Ա
Link Delete(Link head,char number[]);			//ɾ����Ա
void Addition(Link head,char number[]);			//���ӳ�Ա

#endif
