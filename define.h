#ifndef _test_define_
#define _test_define_

#define LEN sizeof(Node)

typedef struct Member				//���岿Ա����Ϣ�����ݽṹ
{	
	char id[15];					//�˺�
	char password[15];				//����
	char number[15];				//ѧ��
	char name[20];					//����
	char sex;						//�Ա�
	char college[10];				//ѧԺ
	char major[10];					//רҵ
	char clas[10];					//�༶
	char dept[30];					//����
	char position[15];				//ְλ
	char QQ[15];					//QQ
	char weixin[20];				//΢��
}Member;



typedef struct Node					//����һ����Ա��Ϣ�Ľڵ�
{
	Member data;					//������
	struct Node *next;				//ָ����
}Node, *Link;


int m;								//�ܼ�����

#endif