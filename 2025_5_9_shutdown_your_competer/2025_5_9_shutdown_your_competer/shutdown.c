#define _CRT_SECURE_NO_WARNINGS 1
//����һ���ػ�����,��������֮��ͻ���ʮ���ӣ��������ɿ��ƣ��ڹرգ���������һЩ�ض�������
//This is a shutdown program. After it runs, the system will shut down within ten minutes
// (which can be freely controlled), unless some specific content is entered.
//system  --�⺯��������ִ��ϵͳ������
//The library function can execute system commands.
//�����ַ����Ƚϵ�ʱ�򣬲���ʹ��==��������Ҫʹ��strcmp
//When comparing two strings, you cannot use ==; instead, you need to use strcmp.
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input[20] = {0};
	system("shutdown -s -t 600");
begin:
	printf("��ע�⣬��ĵ��Խ���ʮ����֮��ػ������ȡ���ò����������롰ȡ���ػ�����\n");
	printf("Please note that your computer will shut down in ten minutes. To cancel this operation, please enter 'Cancel Shutdown'!\n");
	scanf("%s", input);//������Ķ������뵽���鵱��
	if (strcmp("ȡ���ػ�", input) == 0|| strcmp("Cancel Shutdown", input) == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto begin;
	}
	return 0;
}