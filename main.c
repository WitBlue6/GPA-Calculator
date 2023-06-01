#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

int main()
{
	int	input = 0;
	//创建列表
	Contact con;
	InitContact(&con);//初始化

	do
	{	
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:Add(&con);
			break;
		case 2:Delete(&con);
			break;
		case 3:Print(&con);
			break;
		case 4:Culculate(&con);
			break;
		case 0:SaveContact(&con);
			DestroyContact(&con);
			break;

		default:printf("请重新输入\n");
			break;
		}
	} while (input);

	
	return 0;
}