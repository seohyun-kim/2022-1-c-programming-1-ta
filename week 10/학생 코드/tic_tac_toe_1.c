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

void textcolor(int colorNum);
int whoWinCPU(int sum);
int isWinCPU(int b[Width][Height]);
int whoWin1vs1(int sum);
int isWin1vs1(int b[Width][Height]);
void Disp(int b[Width][Height]);

// ���� �Լ�
int main(void)
{
	srand(time(NULL));
	textcolor(White);

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

	// ���� ��� ����
	int modSelect;
	printf("\n���� ��带 �����Ͻʽÿ�. : \n");
	printf("(1) : 1 vs 1\n");
	printf("(2) : 1 vs CPU\n");
	printf("���� : ");
	scanf("%d", &modSelect);

	if (modSelect == 1)
	{
		int board[Width][Height];
		int count = 0;
		int turn;
		int draw;
		int modSelect;

		// ���� ���� ���ϱ�
		printf("\nù ������ ���Ͻʽÿ�. (1�� �÷��̾� 1, -1�� �÷��̾� 2) : ");
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
				printf("\nPlayer 1 's turn : ");
				textcolor(White);
				scanf("%d %d", &r, &c); // ��ǥ �Է¹ޱ�
				while (1)
				{
					if (((r < 0) || (r > Width - 1)) || ((c < 0) || (c > Height - 1)))
					{
						printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�. : ");
						scanf("%d %d", &r, &c);
					}
					else if (((r >= 0) && (r <= Width - 1)) && ((c >= 0) && (c <= Height - 1)))
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
				textcolor(Red);
				printf("\nPlayer 2 's turn : ");
				textcolor(White);
				scanf("%d %d", &r, &c); // ��ǥ �Է¹ޱ�
				while (1)
				{
					if (((r < 0) || (r > Width - 1)) || ((c < 0) || (c > Height - 1)))
					{
						printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�. : ");
						scanf("%d %d", &r, &c);
					}
					else if (((r >= 0) && (r <= Width - 1)) && ((c >= 0) && (c <= Height - 1)))
						break;
				}

				if (board[r][c] != 0) // �̹� ä���� �κ� ����
				{
					printf("�̹� ä���� �κ��Դϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
					continue;
				}

				count++; // �� �� ����

				board[r][c] = -1; // �����ǿ� �� �Ҵ�
				turn = 1; // �� ��ȯ
			}
			printf("< Current Board (%d) >\n", count);
			Disp(board); // �� ���� ������ ���
			draw = !isWin1vs1(board); // �ƹ��� �̱��� ���� == ���º�

		} while (draw && count < Width * Height);

		// ���º� ���
		if (draw && count == Width * Height)
			printf("\nNobody wins.\n");
	}
	else if (modSelect == 2)
	{
		int board[Width][Height];
		int count = 0;
		int turn;
		int draw;
		int modSelect;

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
					if (((r < 0) || (r > Width - 1)) || ((c < 0) || (c > Height - 1)))
					{
						printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�. : ");
						scanf("%d %d", &r, &c);
					}
					else if (((r >= 0) && (r <= Width - 1)) && ((c >= 0) && (c <= Height - 1)))
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
				int rR = rand() % Width; // ������ ���� cpu�� ��ǥ ����
				int rC = rand() % Height;

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
			draw = !isWinCPU(board); // �ƹ��� �̱��� ���� == ���º�

		} while (draw && count < Width * Height);

		// ���º� ���
		if (draw && count == Width * Height)
			printf("\nNobody wins.\n");
	}
	
}

// �ؽ�Ʈ ���� ����
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// ���� ��� �� �� ��ȯ (CPU)
int whoWinCPU(int sum)
{
	if (sum == Width) // �÷��̾� ���
	{
		textcolor(Sky_Blue);
		printf("\nPlayer wins.\n");
		textcolor(White);
		return 1;
	}
	else if (sum == -Width) // CPU ���
	{
		textcolor(Red);
		printf("\nCPU wins.\n");
		textcolor(White);
		return 1;
	}

	return 0; // ���º�
}

// ����� ���� ���� ���� ���� (CPU)
int isWinCPU(int b[Width][Height])
{
	int sum = 0;

	// ����
	for (int i = 0; i < Width; i++)
	{
		sum = 0;

		for (int j = 0; j < Height; j++)
			sum += b[i][j];

		if (whoWinCPU(sum) == 1)
			return 1;
	}

	// ����
	for (int j = 0; j < Height; j++)
	{
		sum = 0;

		for (int i = 0; i < Width; i++)
			sum += b[i][j];

		if (whoWinCPU(sum) == 1)
			return 1;
	}

	// �밢
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][i];
	}
	if (whoWinCPU(sum) == 1)
		return 1;

	// ���밢
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][Width - 1 - i];
	}
	if (whoWinCPU(sum) == 1)
		return 1;

	// �ƹ��� �̱��� ����
	return 0;
}

// ���� ��� �� �� ��ȯ (1vs1)
int whoWin1vs1(int sum)
{
	if (sum == Width) // �÷��̾� ���
	{
		textcolor(Sky_Blue);
		printf("\nPlayer 1 wins.\n");
		textcolor(White);
		return 1;
	}
	else if (sum == -Width) // CPU ���
	{
		textcolor(Red);
		printf("\nPlayer 2 wins.\n");
		textcolor(White);
		return 1;
	}

	return 0; // ���º�
}

// ����� ���� ���� ���� ���� (1vs1)
int isWin1vs1(int b[Width][Height])
{
	int sum = 0;

	// ����
	for (int i = 0; i < Width; i++)
	{
		sum = 0;

		for (int j = 0; j < Height; j++)
			sum += b[i][j];

		if (whoWin1vs1(sum) == 1)
			return 1;
	}

	// ����
	for (int j = 0; j < Height; j++)
	{
		sum = 0;

		for (int i = 0; i < Width; i++)
			sum += b[i][j];

		if (whoWin1vs1(sum) == 1)
			return 1;
	}

	// �밢
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][i];
	}
	if (whoWin1vs1(sum) == 1)
		return 1;

	// ���밢
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][Width - 1 - i];
	}
	if (whoWin1vs1(sum) == 1)
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
		for (int p = 0; p < Width; p++)
			printf(" - ");
		printf("\n");
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
		printf("\n");
		for (int p = 0; p < Width; p++)
			printf(" - ");
		printf("\n");
	}
}
