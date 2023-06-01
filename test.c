#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
void menu()
{
	puts("********        ��  ѡ  ��        *******\n");
	puts("******* 1.  	 ��ӳɼ� 	  *******\n");
	puts("******* 2.	 ɾ���ɼ� 	  *******\n");
	puts("******* 3.	 ����ɼ� 	  *******\n");
	puts("******* 4.   ѧ�ּ�Ȩƽ������     *******\n");
	puts("******* 0.	 �˳�����         *******\n");
}
void Add(Contact* con)
{
	printf("����γ�����:>");
	scanf("%s", con->Data[con->num].name);
	printf("����γ����ճɼ�:>");
	scanf("%d", &con->Data[con->num].grade);
	printf("����γ�ѧ��:>");
	scanf("%lf", &con->Data[con->num].score);
	con->num++;
	printf("\n��ӳɹ�\n\n");
}
void Delete(Contact* con)
{	
	int x = 0;
	printf("����Ҫɾ���Ŀγ����:>");
	scanf("%d", &x);
	if (x >= con->num)
		printf("\n�γ̲�����\n");
	else
	{
		int i;
		for (i = x; i < con->num; i++)
		{
			con->Data[i] = con->Data[i + 1];
		}
		con->num--;
		printf("\nɾ�����\n\n");
	}

}
void Print(Contact* con)
{
	int i = 0;
	printf("%-10s\t%-20s\t%-10s\t%-10s\n","���","�γ�����", "�ɼ�", "ѧ��");
	for (i = 0; i < con->num; i++)
	{
		printf("%-10d\t%-20s\t%-10d\t%-10lf\n",i, con->Data[i].name, con->Data[i].grade, con->Data[i].score);
	}
	printf("\n");
}
void Culculate(Contact* con)
{
	double Final = 0;
	double Score = 0;
	double Grade = 0;
	int i = 0;
	for (i = 0; i < con->num; i++)
	{
		Score += con->Data[i].score;
		Grade += con->Data[i].score * con->Data[i].grade;
	}
	Final = 1.0 * Grade / Score;
	printf("\n����ѧ�ּ�Ȩƽ����Ϊ:%.4lf��\n\n", Final);
}
void InitContact(Contact* con)
{
	FILE* fp = fopen("contact.dat", "r");
	if (fp == NULL)
	{	
		perror("fopen");
		return 1;
	}
	//���ļ�
	CourseInfo tmp = { 0 };
	con->num = 0;
	memset(con->Data, 0, sizeof(CourseInfo));
	while(fread(&tmp, sizeof(CourseInfo), 1, fp))
	{
		con->Data[con->num] = tmp;
		con->num++;
	}
	//�ر��ļ�
	fclose(fp);
	fp = NULL;
}
void SaveContact(Contact* con)
{
	FILE* fp = fopen("contact.dat", "w");
	if (fp == NULL)
	{	
		perror("fopen");
		return 2;
	}
	int i;
	for (i = 0; i < con->num; i++)
	{
		fwrite(&con->Data[i], sizeof(CourseInfo), 1, fp);
	}
	
	fclose(fp);
	fp = NULL;
}
void DestroyContact(Contact* con)
{
	con->num = 0;
}