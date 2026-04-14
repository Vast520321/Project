// C语言猜数字小游戏持续更新版本
// 游戏要求：
// 1. 应玩家要求，电脑会随机生成一个指定难度区间的整数，玩家需要猜这个数字。
// 2. 玩家每次输入一个数字，电脑会告诉玩家这个数字是太大了、太小了还是猜对了。
// 3. 玩家可以选择继续玩或者退出游戏。
// 4. 游戏会有的猜测次数上限，如果玩家在规定次数内没有猜对，游戏结束并显示正确答案。
// 5. 游戏会记录玩家的猜测次数，并在游戏结束时显示玩家的表现。
// 6. 游戏会提供一个排行榜，记录玩家的最佳成绩。
// 7. 游戏会有一个简单的界面，显示游戏状态和玩家的输入。
// 8. 游戏会有一个帮助菜单，解释游戏规则和操作方法。
// 9. 游戏会有一个设置菜单，允许玩家调整游戏难度和猜测次数上限。
// 10. 游戏会有一个退出确认，防止玩家误操作退出游戏.
// 更多功能可以根据需要添加，例如增加不同的难度级别、提供多种游戏模式（如限时模式、挑战模式等）。
// 或者增加一些有趣的动画效果来提升游戏体验。后续功能持续更新中，请尽情期待！
// 下面是一个持续更新版本的C语言猜数字小游戏的代码实现：
#define _CRT_SECURE_NO_WARNINGS 1

// 包含必要的头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义游戏的选择难度函数
void Choice() {
	printf("请选择游戏难度：\n");
	printf("1. 简单（1-10）\n");
	printf("2. 中等（1-100）\n");
	printf("3. 困难（1-1000）\n");
	printf("请输入你的选择：");
}

// 定义游戏的开始与退出菜单函数
void Begin_End()
{
	printf("欢迎来到猜数字游戏！\n");
	printf("1. 开始游戏\n");
	printf("0. 退出游戏\n");
	printf("请输入你的选择：");
}

// 定义游戏数字的大小判断函数
void Game(int a ,int b)
{
	int number = a + rand() % (b - a + 1);
	int guess = 0;// 玩家猜测的数字
	int attempts = 0;// 玩家已经猜测的次数
	int max_attempts = 10;// 玩家猜测的次数上限
	do
	{
		attempts++;// 增加玩家已经猜测的次数
		printf("请输入你猜的数字：");
		scanf("%d", &guess);
		if (guess < number)
		{
			printf("猜小了！请再试一次：\n");
		}
		else if (guess > number)
		{
			printf("猜大了！请再试一次：\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			printf("你总共猜了%d次。\n", attempts);
		    // break;
			// 结束游戏！
			exit(0);
		}
		max_attempts--;// 减少玩家剩余的猜测次数
	} while (max_attempts);
	if(max_attempts == 0)
	{
		printf("很遗憾，你没有在规定次数内猜对。正确答案是%d。\n", number);
	}
}

// 主函数
int main()
{
	srand((unsigned int)time(NULL)); // 初始化随机数生成器
	int choice = 0;
	Begin_End();
	scanf("%d", &choice);
	if (choice == 0)
	{
		printf("退出游戏结束！感谢你的游玩，我们下次再见！\n");
	}
	while(choice)
	{
		printf("请再次输入你的选择：");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("游戏开始！\n");
		tryagain:
			Choice();
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				Game(1, 10);
				break;
			case 2:
				Game(1, 100);
				break;
			case 3:
				Game(1, 1000);
				break;
			default:
				printf("无效的选择，请重新输入。\n");
				goto tryagain;
			}
		}
		else
		{
			printf("无效的选择，请重新输入。\n");
			continue;
		}
	}
	return 0;
}