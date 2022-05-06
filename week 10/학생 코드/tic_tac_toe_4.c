#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//틱택토 게임 코드 제작 과제

//남은 칸 중 랜덤번째의 칸에 둔다. r은 남은 칸.
int randCom(const char board[3][3], int r) {
	//남은 칸 중 t번째의 칸에 수를 둔다.
	//t는 랜덤으로 결정.
	int t = (rand() % r) + 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				t--;
			if (t == 0)
				return i * 10 + j;
		}
	}
}

//가장 인덱스가 빠른 빈 칸에 돌을 둔다.
int com(const char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				return i * 10 + j;
		}
	}
	return 0;
}

//누군가 승리한 자가 있는지 검사한다.
char check(const char board[3][3]) {
	int i;
	char c = ' ';
	//가로 확인
	for (i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}
	//세로 확인
	for (i = 0; i < 3; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	//대각선 확인
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];
	return ' ';
}

int main() {
	//게임판 초기화
	char board[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	//랜덤 컴퓨터를 위한 시드설정
	srand(time(0));
	char mode;
	printf("상대는 컴퓨터로 하시겠습니까?(y/n): ");
	scanf("%c", &mode);
	printf("%c\n", mode);
	//모든 칸은 9칸이다.
	for (int k = 0; k < 9; k++) {
		int x, y;
		//유효한 입력이 들어올 때까지 반복
		while (1) {
			//컴퓨터와 한다면, 컴퓨터의 수를 가져온다.
			if (k % 2 == 1 && mode == 'y') {
				int temp = randCom(board, 9 - k);
				x = temp / 10;
				y = temp % 10;
				break;
			}
			printf("\n좌표 입력(x y): ");
			scanf("%d %d", &x, &y);
			//인덱스 범위 확인
			if (x < 0 || x>2 || y < 0 || y>2) {
				printf("좌표의 인덱스를 넘어섬.(0~2)\n\n");
			}
			//빈칸인지 확인
			else if (board[x][y] == ' ') {
				break;
			}
			//위의 둘 다 아니라면, 이미 돌이 있는 곳이다.
			else {
				printf("이미 돌이 있는 좌표.\n\n");
			}
		}
		//차례에 맞게 돌을 놓는다.
		board[x][y] = k % 2 ? 'X' : 'O';
		//게임판 현황 출력
		printf("\n---|---|---\n");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf(" %c |", board[i][j]);
			}
			printf("\n---|---|---\n");
		}
		//승리 확인
		char c = check(board);
		//승리했다면, 게임 끝
		if (c != ' ') {
			printf("\n%c 가 이겼습니다.\n", c);
			return 0;
		}
	}
	printf("\n무승부입니다.\n");
	return 0;
}

