#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct CourseInfo//�γ���Ϣ
{
	char name[40]; //�γ�����
	int grade;//��ĩ�ɼ�
	double score;//ѧ��

}CourseInfo;

typedef struct Contact//��ǰ�б�
{
	CourseInfo Data[N];//�������
	int num;//��������

}Contact;

void menu();//�˵�
void Add(Contact* con);//��ӿγ�
void Delete(Contact* con);//ɾ���γ�
void Print(Contact* con);//��ӡ�γ�
void Culculate(Contact* con);//����ѧ�ּ�Ȩƽ����
void InitContact(Contact* con);//��ʼ���б�
void SaveContact(Contact* con);//�����б�
void DestroyContact(Contact* con);//�����б�