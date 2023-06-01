#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
void menu()
{
	puts("********        请  选  择        *******\n");
	puts("******* 1.  	 添加成绩 	  *******\n");
	puts("******* 2.	 删除成绩 	  *******\n");
	puts("******* 3.	 输出成绩 	  *******\n");
	puts("******* 4.   学分加权平均分数     *******\n");
	puts("******* 0.	 退出程序         *******\n");
}
void Add(Contact* con)
{
	printf("输入课程名称:>");
	scanf("%s", con->Data[con->num].name);
	printf("输入课程最终成绩:>");
	scanf("%d", &con->Data[con->num].grade);
	printf("输入课程学分:>");
	scanf("%lf", &con->Data[con->num].score);
	con->num++;
	printf("\n添加成功\n\n");
}
void Delete(Contact* con)
{	
	int x = 0;
	printf("输入要删除的课程序号:>");
	scanf("%d", &x);
	if (x >= con->num)
		printf("\n课程不存在\n");
	else
	{
		int i;
		for (i = x; i < con->num; i++)
		{
			con->Data[i] = con->Data[i + 1];
		}
		con->num--;
		printf("\n删除完成\n\n");
	}

}
void Print(Contact* con)
{
	int i = 0;
	printf("%-10s\t%-20s\t%-10s\t%-10s\n","序号","课程名称", "成绩", "学分");
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
	printf("\n您的学分加权平均分为:%.4lf分\n\n", Final);
}
void InitContact(Contact* con)
{
	FILE* fp = fopen("contact.dat", "r");
	if (fp == NULL)
	{	
		perror("fopen");
		return 1;
	}
	//读文件
	CourseInfo tmp = { 0 };
	con->num = 0;
	memset(con->Data, 0, sizeof(CourseInfo));
	while(fread(&tmp, sizeof(CourseInfo), 1, fp))
	{
		con->Data[con->num] = tmp;
		con->num++;
	}
	//关闭文件
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