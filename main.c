#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>			//��������
#include"login.h"			//ʵ���û���¼
#include"stde.h"			//ʵ�����ݵĲٿ�
#include"showmenu.h"		//��ӡ����
#include"define.h"			//�������������


//enum Member.sex {w,m};	//�޶��Ա������

int main()
{
	Link head=NULL;              //���ܷ��ص�ͷָ��
	int i;						// i ʵ��ѡ���½��ע�Ṧ��

	Loginscreen();				//��ӡ��½����
	scanf("%d",&i);
	Create_File();				//�����ı�
	if(i==1)
	{
		head=Create_Link();				//��������
		Login(head);					//��½	
	}
	else if(i==2)
	{
		Create_File();		//�����ļ�
		Registers();		//ע��
		return;
	}

	return 0;
}
