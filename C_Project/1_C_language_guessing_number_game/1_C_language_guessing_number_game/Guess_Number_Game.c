// 猜数字小游戏基础版本
#define _CRT_SECURE_NO_WARNINGS 1
// 要求如下：
// 游戏要求：
// 1. 电脑⾃动⽣成1~100的随机数
// 2. 玩家猜数字，猜数字的过程中，
// 根据猜测数据的⼤⼩给出⼤了或⼩了的反馈，直到猜对，游戏结束
// 我们还可以根据这个1. 中的基础版本，添加更多的功能，比如2、3、4：
// 1. 设置猜测最多的次数，超过次数游戏结束(基础版本的功能)
// 2. 记录玩家的猜测次数
// 3. 设置不同的难度级别，难度级别越高，随机数范围越大
// 4. 添加排行榜，记录玩家的最佳成绩
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成随机数
// rand函数是伪随机数，每次运行程序生成的随机数都一样，因为种子都是1
// 所以我们需要srand函数来设置随机数种子，通常使用当前时间作为随机数种子

// 菜单函数
void menu() {
	printf("欢迎来到猜数字游戏！\n");
	printf("1. 开始游戏\n");
	printf("0. 退出游戏\n");
	printf("请输入你的选择：");
}

void menu1()
{
	printf("***********************\n");
	printf("****** 1. play ******\n");
	printf("****** 0. exit ******\n");
	printf("***********************\n");
}

// 游戏函数
void game()
{
	int number = rand() % 100 + 1; // 生成1~100的随机数
	int guess = 0; // 玩家猜测的数字
	int attempts = 10; // 猜测次数
	while (attempts)
	{
		printf("你还有%d次机会,请猜数字:", attempts);
		//printf("请猜数字：");
		scanf("%d", &guess);
		if (guess < number)
		{
			printf("猜小了！\n");
		}
		else if (guess > number)
		{
			printf("猜大了！\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n\n");
			break;
		}
		attempts--;
	}
	if(attempts == 0)
	{
		printf("很遗憾，你没有猜对，正确的数字是%d\n\n", number);
	}
}

void game1()
{
	int r = rand() % 100 + 1;
	int guess = 0;
	while (1)
	{
		printf("请猜数字>:");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("猜⼩了\n");
		}
		else if (guess > r)
		{
			printf("猜⼤了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}

// 主函数
int main()
{
	int choice = 0;
	// srand((unsigned int)time(NULL)); // 设置随机数种子
	srand((unsigned int)time(NULL));
	do
	{
		// 先打印菜单
		menu();
		printf("请输入你的选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏成功，游戏结束，欢迎下次再来！\n");
			break;
		default:
			printf("无效的选择/输入错误，请重新输入！\n");
			break;
		}
	} while (choice);
	return 0; 
}



//int  main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("游戏结束\n");
//			break;
//		default:
//			printf("选择错误，重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}