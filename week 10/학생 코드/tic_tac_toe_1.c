#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// ���� Ÿ�� ����
enum ColorType {
	Black,  	//0
	Dark_Blue,	//1
	Dark_Green,	//2
	Dark_Sky_Blue,    //3
	Dark_Red,  	//4
	Dark_Purple,	//5
	Dark_Yellow,	//6
	Gray,		//7
	Dark_Gray,	//8
	Blue,		//9
	Green,		//10
	Sky_Blue,	//11
	Red,		//12
	Purple,		//13
	Yellow,		//14
	White		//15
} COLOR;

// �������� ���� ���� ����
#define Width 3
#define Height 3

// �ؽ�Ʈ ���� ����
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// ���� ��� �� �� ��ȯ
int whoWin(int sum)
{
	if (sum == 3) // �÷��̾� ���
	{
		textcolor(Sky_Blue);
		printf("\nPlayer wins.\n");
		textcolor(White);
		return 1;
	}
	else if (sum == -3) // CPU ���
	{
		textcolor(Red);
		printf("\nCPU wins.\n");
		textcolor(White);
		return 1;
	}

	return 0; // ���º�
}

// ����� ���� ���� ���� ����
int isWin(int b[Width][Height])
{
	int sum = 0;

	// ����
	for (int i = 0; i < Width; i++)
	{
		sum = 0;

		for (int j = 0; j < Height; j++)
			sum += b[i][j];

		if (whoWin(sum) == 1)
			return 1;
	}

	// ����
	for (int j = 0; j < Height; j++)
	{
		sum = 0;

		for (int i = 0; i < Width; i++)
			sum += b[i][j];

		if (whoWin(sum) == 1) 
			return 1;
	}

	// �밢
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][i];
	}
	if (whoWin(sum) == 1) 
		return 1;

	// ���밢
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][Width - 1 - i];
	}
	if (whoWin(sum) == 1) 
		return 1;

	// �ƹ��� �̱��� ����
	return 0;
}

// �������� ��� �Լ�
void Disp(int b[Width][Height])
{
	char ch;

	for (int j = 0; j < Height; j++)
	{
		printf(" -  -  - \n");
		for (int i = 0; i < Width; i++)
		{
			if (b[i][j] == 1)
			{
				textcolor(White);
				printf("|");
				textcolor(Sky_Blue);
				printf("O");
				textcolor(White);
				printf("|");
			}
			else if (b[i][j] == -1)
			{
				textcolor(White);
				printf("|");
				textcolor(Red);
				printf("X");
				textcolor(White);
				printf("|");
			}
			else
			{
				textcolor(White);
				printf("| |");
			}
		}
		printf("\n -  -  - \n");
	}
}

// ���� �Լ�
int main(void)
{
	srand(time(NULL));
	textcolor(White);

	int board[3][3];
	int count = 0;
	int turn;
	int draw;

	// ���� ����
	int ans;
	printf("���� ���࿡ ���� ������ �����ðڽ��ϱ�? (Yes : 1, No : Other) : ");
	scanf("%d", &ans);
	if (ans == 1)
	{
		printf("\n============================== < HELP > ==============================\n");
		printf("Tic-Tac-Toe ������ ���� ���� �밢�� ���밢�� �������\n");
		printf("���� ������ ����� �÷��̾ �¸��ϴ� �����Դϴ�.\n");
		printf("��ǥ�� �Է��� [����][����] �������� �Է��ϰ�, \n");
		printf("���� ��ܺ��� [0][0], ������ �ϴ��� [2][2] ������ �����Ǿ� �ֽ��ϴ�.\n");
		printf("======================================================================\n");
	}

	// ���� ���� ���ϱ�
	printf("\nù ������ ���Ͻʽÿ�. (1�� �÷��̾�, -1�� CPU) : ");
	scanf("%d", &turn);
	while (1)
	{
		if (abs(turn) != 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�. : ");
			scanf("%d", &turn);
		}
		else if (abs(turn) == 1)
			break;
	}

	// ������ �ʱ�ȭ
	for (int i = 0; i < Width; i++)
		for (int j = 0; j < Height; j++)
			board[i][j] = 0;

	// ���� ����
	printf("\n======================\n");
	textcolor(Yellow);
	printf("Start Tic-Tac-Toe Game\n");
	textcolor(White);
	printf("======================\n\n");
	printf("< Current Board (%d) >\n", count);
	Disp(board); // �ʱ�ȭ �� ������ ���

	// ���� ����
	do
	{
		int r, c;

		if (turn == 1) 
		{
			textcolor(Sky_Blue);
			printf("\nPlayer's turn : ");
			textcolor(White);
			scanf("%d %d", &r, &c); // ��ǥ �Է¹ޱ�
			while (1)
			{
				if (((r < 0) || (r > 2)) || ((c < 0) || (c > 2)))
				{
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�. : ");
					scanf("%d %d", &r, &c);
				}
				else if (((r >= 0) && (r <= 2)) && ((c >= 0) && (c <= 2)))
					break;
			}

			if (board[r][c] != 0) // �̹� ä���� �κ� ����
			{
				printf("�̹� ä���� �κ��Դϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
				continue;
			}

			count++; // �� �� ����

			board[r][c] = 1; // �����ǿ� �� �Ҵ�
			turn = -1; // �� ��ȯ
		}

		else if (turn == -1)
		{
			int rR = rand() % 3; // ������ ���� cpu�� ��ǥ ����
			int rC = rand() % 3;

			if (board[rR][rC] != 0) // �̹� ä���� �κ� ����
				continue;

			textcolor(Red);
			printf("\nCPU's turn : ");
			textcolor(White);
			printf("%d %d\n", rR, rC);

			count++; // �� �� ����

			board[rR][rC] = -1; // �����ǿ� �� �Ҵ�
			turn = 1; // �� ��ȯ
		}
		printf("< Current Board (%d) >\n", count);
		Disp(board); // �� ���� ������ ���
		draw = !isWin(board); // �ƹ��� �̱��� ���� == ���º�

	} while (draw && count < 9);

	// ���º� ���
	if (draw && count == 9)
		printf("\nNobody wins.\n");
}