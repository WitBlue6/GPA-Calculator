#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

int main()
{
	int	input = 0;
	//�����б�
	Contact con;
	InitContact(&con);//��ʼ��

	do
	{	
		menu();
		printf("������:>");
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

		default:printf("����������\n");
			break;
		}
	} while (input);

	
	return 0;
}