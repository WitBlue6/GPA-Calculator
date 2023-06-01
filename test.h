#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct CourseInfo//课程信息
{
	char name[40]; //课程名字
	int grade;//期末成绩
	double score;//学分

}CourseInfo;

typedef struct Contact//当前列表
{
	CourseInfo Data[N];//存放数据
	int num;//数据总数

}Contact;

void menu();//菜单
void Add(Contact* con);//添加课程
void Delete(Contact* con);//删除课程
void Print(Contact* con);//打印课程
void Culculate(Contact* con);//计算学分加权平均分
void InitContact(Contact* con);//初始化列表
void SaveContact(Contact* con);//保存列表
void DestroyContact(Contact* con);//销毁列表