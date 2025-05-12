#define _CRT_SECURE_NO_WARNINGS 1
//ʹ��C����дһ��������С��Ϸ / Write a number guessing game in C language
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//���� / Function
//void ��ʾ�����������κ�ֵ / void means the function doesn't return any value
void menu()
{
	//�±�ֻ���ҵĴ����ʽ�ͷ�񣬴�ҿ��԰����Լ����뷨�޸�
	//The following is just my coding style, you can modify it as you prefer
	printf("************************\n");
	printf("****** 1. play   *******\n");
	printf("****** 0. exit   *******\n");
	printf("************************\n");
}

void game()
{
	//��Ϸ���߼� / Game logic
	//1. ��������� / 1. Generate random number
	int r = rand() % 100 + 1; //�������1��100��������ȻҲ���Ը���ʵ���������
	//Randomly generate a number between 1-100, can be adjusted as needed

//2. ������ / 2. Guess the number
	int guess = 0;
	int count = 5; //����5�λ��ᣬ���������ö�λ��ᣬ����ʵ��������ü���
	//Set 5 attempts, can be adjusted to more attempts as needed

	while (count)
	{
		printf("����%d�λ��� / You have %d attempts left\n", count);
		printf("������� / Please guess the number:");
		scanf("%d", &guess); //����µ����� / Input your guess

		if (guess > r)
		{
			printf("�´��� / Too big!\n");
		}
		else if (guess < r)
		{
			printf("��С�� / Too small!\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��� / Congratulations! You guessed it right!\n");
			break;
		}
		count--;
	}

	if (count == 0)
	{
		printf("���������еĻ��ᣬ������ʧ��,��ȷ��ֵ��:%d\nYou've used all attempts. Game over! The correct number was: %d\n", r);
		//You've used all attempts. Game over! The correct number was: %d\n
	}
}

int main()
{
	int input = 0;
	//������������������ / Set random number generator seed
	//����������ֻ�õ���һ�ξͿ����� / Only needs to be called once in the entire program
	srand((unsigned int)time(NULL));

	do
	{
		//��ӡ�˵� / Print menu
		menu();
		//ѡ�� / Make selection
		printf("��ѡ�� / Please choose:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//����Ϸ���߼� / Gameplay logic
			game();
			break;
		case 0:
			printf("�˳���Ϸ / Exiting game...\n");
			break;
		default:
			printf("ѡ���������ѡ�� / Invalid choice, please try again\n");
			break;
		}
	} while (input);

	return 0;
}