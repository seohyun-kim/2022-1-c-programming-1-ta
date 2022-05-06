#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



#if 1
int main() {

	char board[3][3];   //---> 판은 문자형
	int x, y, k, i;
	int count = 0;
	srand(time(NULL));

	//플레이어
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';


	//플레이어와 컴퓨터가 입력하는 내용을 넣는다.
	for (k = 0; k < 9; k++) {

		if (k % 2 == 0) {

			printf("당신의 차례입니다.\n돌을 놓을 위치를 입력하세요.(행 열): ");
		player:
			scanf("%d %d", &x, &y);

			if (board[x][y] != ' ') {
				printf("그곳에는 둘 수 없습니다.\n돌을 놓을 위치를 입력하세요.(행 열): ");
				goto player;
			}
			board[x][y] = 'O';
			count += 1;
		}

		if (k % 2 != 0) {

			printf("컴퓨터의 차례입니다.\n");
		computer:
			int x = (rand() % 3 + 1);
			int y = (rand() % 3 + 1);

			if (board[x][y] != ' ') {
				goto computer;
			}
			board[x][y] = 'X';
			count += 1;
		}

		//판을 화면에 표시한다.
		for (i = 0; i < 3; i++) {
			printf("---|---|---\n");
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---\n");

		//플레이어 승리 조건
		if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
			printf("당신의 승리!");
			break;
		}

		if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
			printf("당신의 승리!");
			break;
		}

		if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
			printf("당신의 승리!");
			break;
		}

		if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
			printf("당신의 승리!");
			break;
		}

		if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
			printf("당신의 승리!");
			break;
		}

		if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
			printf("당신의 승리!");
			break;
		}

		if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
			printf("당신의 승리!");
			break;
		}

		if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
			printf("당신의 승리!");
			break;
		}

		//컴퓨터 승리 조건
		if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
			printf("컴퓨터 승! 조금만 더 연습하고 오세요~");
			break;
		}

		//무승부 조건
		if (count == 9) {
			printf("무승부!");
			break;
		}
	}
	return 0;
}
#endif