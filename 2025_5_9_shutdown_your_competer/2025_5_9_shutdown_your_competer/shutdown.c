#define _CRT_SECURE_NO_WARNINGS 1
//这是一个关机程序,程序运行之后就会在十分钟（可以自由控制）内关闭，除非输入一些特定的内容
//This is a shutdown program. After it runs, the system will shut down within ten minutes
// (which can be freely controlled), unless some specific content is entered.
//system  --库函数，可以执行系统的命令
//The library function can execute system commands.
//两个字符串比较的时候，不能使用==，而是需要使用strcmp
//When comparing two strings, you cannot use ==; instead, you need to use strcmp.
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input[20] = {0};
	system("shutdown -s -t 600");
begin:
	printf("请注意，你的电脑将在十分钟之后关机，如果取消该操作，请输入“取消关机”！\n");
	printf("Please note that your computer will shut down in ten minutes. To cancel this operation, please enter 'Cancel Shutdown'!\n");
	scanf("%s", input);//将输入的东西输入到数组当中
	if (strcmp("取消关机", input) == 0|| strcmp("Cancel Shutdown", input) == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto begin;
	}
	return 0;
}