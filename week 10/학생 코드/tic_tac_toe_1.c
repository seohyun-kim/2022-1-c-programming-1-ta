#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// 색상 타입 지정
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

// 게임판의 가로 세로 지정
#define Width 3
#define Height 3

void textcolor(int colorNum);
int whoWinCPU(int sum);
int isWinCPU(int b[Width][Height]);
int whoWin1vs1(int sum);
int isWin1vs1(int b[Width][Height]);
void Disp(int b[Width][Height]);

// 메인 함수
int main(void)
{
	srand(time(NULL));
	textcolor(White);

	// 게임 설명
	int ans;
	printf("게임 진행에 관한 설명을 들으시겠습니까? (Yes : 1, No : Other) : ");
	scanf("%d", &ans);
	if (ans == 1)
	{
		printf("\n============================== < HELP > ==============================\n");
		printf("Tic-Tac-Toe 게임은 가로 세로 대각선 역대각선 상관없이\n");
		printf("먼저 한줄을 만드는 플레이어가 승리하는 게임입니다.\n");
		printf("좌표값 입력은 [가로][세로] 형식으로 입력하고, \n");
		printf("왼쪽 상단부터 [0][0], 오른쪽 하단이 [2][2] 순으로 구성되어 있습니다.\n");
		printf("======================================================================\n");
	}

	// 게임 모드 선택
	int modSelect;
	printf("\n게임 모드를 선택하십시오. : \n");
	printf("(1) : 1 vs 1\n");
	printf("(2) : 1 vs CPU\n");
	printf("선택 : ");
	scanf("%d", &modSelect);

	if (modSelect == 1)
	{
		int board[Width][Height];
		int count = 0;
		int turn;
		int draw;
		int modSelect;

		// 게임 순서 정하기
		printf("\n첫 순서를 정하십시오. (1은 플레이어 1, -1은 플레이어 2) : ");
		scanf("%d", &turn);
		while (1)
		{
			if (abs(turn) != 1)
			{
				printf("잘못된 입력입니다. 다시 입력하십시오. : ");
				scanf("%d", &turn);
			}
			else if (abs(turn) == 1)
				break;
		}

		// 게임판 초기화
		for (int i = 0; i < Width; i++)
			for (int j = 0; j < Height; j++)
				board[i][j] = 0;

		// 게임 시작
		printf("\n======================\n");
		textcolor(Yellow);
		printf("Start Tic-Tac-Toe Game\n");
		textcolor(White);
		printf("======================\n\n");
		printf("< Current Board (%d) >\n", count);
		Disp(board); // 초기화 된 게임판 출력

		// 게임 진행
		do
		{
			int r, c;

			if (turn == 1)
			{
				textcolor(Sky_Blue);
				printf("\nPlayer 1 's turn : ");
				textcolor(White);
				scanf("%d %d", &r, &c); // 좌표 입력받기
				while (1)
				{
					if (((r < 0) || (r > Width - 1)) || ((c < 0) || (c > Height - 1)))
					{
						printf("잘못된 입력입니다. 다시 입력하십시오. : ");
						scanf("%d %d", &r, &c);
					}
					else if (((r >= 0) && (r <= Width - 1)) && ((c >= 0) && (c <= Height - 1)))
						break;
				}

				if (board[r][c] != 0) // 이미 채워진 부분 검증
				{
					printf("이미 채워진 부분입니다. 다시 입력하십시오.\n");
					continue;
				}

				count++; // 턴 수 세기

				board[r][c] = 1; // 게임판에 값 할당
				turn = -1; // 턴 변환
			}

			else if (turn == -1)
			{
				textcolor(Red);
				printf("\nPlayer 2 's turn : ");
				textcolor(White);
				scanf("%d %d", &r, &c); // 좌표 입력받기
				while (1)
				{
					if (((r < 0) || (r > Width - 1)) || ((c < 0) || (c > Height - 1)))
					{
						printf("잘못된 입력입니다. 다시 입력하십시오. : ");
						scanf("%d %d", &r, &c);
					}
					else if (((r >= 0) && (r <= Width - 1)) && ((c >= 0) && (c <= Height - 1)))
						break;
				}

				if (board[r][c] != 0) // 이미 채워진 부분 검증
				{
					printf("이미 채워진 부분입니다. 다시 입력하십시오.\n");
					continue;
				}

				count++; // 턴 수 세기

				board[r][c] = -1; // 게임판에 값 할당
				turn = 1; // 턴 변환
			}
			printf("< Current Board (%d) >\n", count);
			Disp(board); // 턴 이후 게임판 출력
			draw = !isWin1vs1(board); // 아무도 이기지 않음 == 무승부

		} while (draw && count < Width * Height);

		// 무승부 출력
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

		// 게임 순서 정하기
		printf("\n첫 순서를 정하십시오. (1은 플레이어, -1은 CPU) : ");
		scanf("%d", &turn);
		while (1)
		{
			if (abs(turn) != 1)
			{
				printf("잘못된 입력입니다. 다시 입력하십시오. : ");
				scanf("%d", &turn);
			}
			else if (abs(turn) == 1)
				break;
		}

		// 게임판 초기화
		for (int i = 0; i < Width; i++)
			for (int j = 0; j < Height; j++)
				board[i][j] = 0;

		// 게임 시작
		printf("\n======================\n");
		textcolor(Yellow);
		printf("Start Tic-Tac-Toe Game\n");
		textcolor(White);
		printf("======================\n\n");
		printf("< Current Board (%d) >\n", count);
		Disp(board); // 초기화 된 게임판 출력

		// 게임 진행
		do
		{
			int r, c;

			if (turn == 1)
			{
				textcolor(Sky_Blue);
				printf("\nPlayer's turn : ");
				textcolor(White);
				scanf("%d %d", &r, &c); // 좌표 입력받기
				while (1)
				{
					if (((r < 0) || (r > Width - 1)) || ((c < 0) || (c > Height - 1)))
					{
						printf("잘못된 입력입니다. 다시 입력하십시오. : ");
						scanf("%d %d", &r, &c);
					}
					else if (((r >= 0) && (r <= Width - 1)) && ((c >= 0) && (c <= Height - 1)))
						break;
				}

				if (board[r][c] != 0) // 이미 채워진 부분 검증
				{
					printf("이미 채워진 부분입니다. 다시 입력하십시오.\n");
					continue;
				}

				count++; // 턴 수 세기

				board[r][c] = 1; // 게임판에 값 할당
				turn = -1; // 턴 변환
			}

			else if (turn == -1)
			{
				int rR = rand() % Width; // 난수를 통해 cpu의 좌표 결정
				int rC = rand() % Height;

				if (board[rR][rC] != 0) // 이미 채워진 부분 검증
					continue;

				textcolor(Red);
				printf("\nCPU's turn : ");
				textcolor(White);
				printf("%d %d\n", rR, rC);

				count++; // 턴 수 세기

				board[rR][rC] = -1; // 게임판에 값 할당
				turn = 1; // 턴 변환
			}
			printf("< Current Board (%d) >\n", count);
			Disp(board); // 턴 이후 게임판 출력
			draw = !isWinCPU(board); // 아무도 이기지 않음 == 무승부

		} while (draw && count < Width * Height);

		// 무승부 출력
		if (draw && count == Width * Height)
			printf("\nNobody wins.\n");
	}
	
}

// 텍스트 색상 지정
void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// 승패 출력 및 값 반환 (CPU)
int whoWinCPU(int sum)
{
	if (sum == Width) // 플레이어 우승
	{
		textcolor(Sky_Blue);
		printf("\nPlayer wins.\n");
		textcolor(White);
		return 1;
	}
	else if (sum == -Width) // CPU 우승
	{
		textcolor(Red);
		printf("\nCPU wins.\n");
		textcolor(White);
		return 1;
	}

	return 0; // 무승부
}

// 행렬의 합을 통해 승패 검출 (CPU)
int isWinCPU(int b[Width][Height])
{
	int sum = 0;

	// 가로
	for (int i = 0; i < Width; i++)
	{
		sum = 0;

		for (int j = 0; j < Height; j++)
			sum += b[i][j];

		if (whoWinCPU(sum) == 1)
			return 1;
	}

	// 세로
	for (int j = 0; j < Height; j++)
	{
		sum = 0;

		for (int i = 0; i < Width; i++)
			sum += b[i][j];

		if (whoWinCPU(sum) == 1)
			return 1;
	}

	// 대각
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][i];
	}
	if (whoWinCPU(sum) == 1)
		return 1;

	// 역대각
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][Width - 1 - i];
	}
	if (whoWinCPU(sum) == 1)
		return 1;

	// 아무도 이기지 않음
	return 0;
}

// 승패 출력 및 값 반환 (1vs1)
int whoWin1vs1(int sum)
{
	if (sum == Width) // 플레이어 우승
	{
		textcolor(Sky_Blue);
		printf("\nPlayer 1 wins.\n");
		textcolor(White);
		return 1;
	}
	else if (sum == -Width) // CPU 우승
	{
		textcolor(Red);
		printf("\nPlayer 2 wins.\n");
		textcolor(White);
		return 1;
	}

	return 0; // 무승부
}

// 행렬의 합을 통해 승패 검출 (1vs1)
int isWin1vs1(int b[Width][Height])
{
	int sum = 0;

	// 가로
	for (int i = 0; i < Width; i++)
	{
		sum = 0;

		for (int j = 0; j < Height; j++)
			sum += b[i][j];

		if (whoWin1vs1(sum) == 1)
			return 1;
	}

	// 세로
	for (int j = 0; j < Height; j++)
	{
		sum = 0;

		for (int i = 0; i < Width; i++)
			sum += b[i][j];

		if (whoWin1vs1(sum) == 1)
			return 1;
	}

	// 대각
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][i];
	}
	if (whoWin1vs1(sum) == 1)
		return 1;

	// 역대각
	sum = 0;
	for (int i = 0; i < Width; i++)
	{
		sum += b[i][Width - 1 - i];
	}
	if (whoWin1vs1(sum) == 1)
		return 1;

	// 아무도 이기지 않음
	return 0;
}

// 게임판의 출력 함수
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
