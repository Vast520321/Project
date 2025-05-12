#define _CRT_SECURE_NO_WARNINGS 1
//使用C语言写一个猜数字小游戏 / Write a number guessing game in C language
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//函数 / Function
//void 表示函数不返回任何值 / void means the function doesn't return any value
void menu()
{
	//下边只是我的代码格式和风格，大家可以按照自己的想法修改
	//The following is just my coding style, you can modify it as you prefer
	printf("************************\n");
	printf("****** 1. play   *******\n");
	printf("****** 0. exit   *******\n");
	printf("************************\n");
}

void game()
{
	//游戏的逻辑 / Game logic
	//1. 生成随机数 / 1. Generate random number
	int r = rand() % 100 + 1; //随机生成1到100的数，当然也可以根据实际情况设置
	//Randomly generate a number between 1-100, can be adjusted as needed

//2. 猜数字 / 2. Guess the number
	int guess = 0;
	int count = 5; //设置5次机会，还可以设置多次机会，根据实际情况设置即可
	//Set 5 attempts, can be adjusted to more attempts as needed

	while (count)
	{
		printf("还有%d次机会 / You have %d attempts left\n", count);
		printf("请猜数字 / Please guess the number:");
		scanf("%d", &guess); //输入猜的数字 / Input your guess

		if (guess > r)
		{
			printf("猜大了 / Too big!\n");
		}
		else if (guess < r)
		{
			printf("猜小了 / Too small!\n");
		}
		else
		{
			printf("恭喜你，猜对了 / Congratulations! You guessed it right!\n");
			break;
		}
		count--;
	}

	if (count == 0)
	{
		printf("用完了所有的机会，猜数字失败,正确的值是:%d\nYou've used all attempts. Game over! The correct number was: %d\n", r);
		//You've used all attempts. Game over! The correct number was: %d\n
	}
}

int main()
{
	int input = 0;
	//设置随机数的生成起点 / Set random number generator seed
	//整个工程中只用调用一次就可以了 / Only needs to be called once in the entire program
	srand((unsigned int)time(NULL));

	do
	{
		//打印菜单 / Print menu
		menu();
		//选择 / Make selection
		printf("请选择 / Please choose:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//玩游戏的逻辑 / Gameplay logic
			game();
			break;
		case 0:
			printf("退出游戏 / Exiting game...\n");
			break;
		default:
			printf("选择错误，重新选择 / Invalid choice, please try again\n");
			break;
		}
	} while (input);

	return 0;
}