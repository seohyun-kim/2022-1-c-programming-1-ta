#define _CRT_SECURE_NO_WARNINGS
#define BOARDSIZE 3
  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(char board[BOARDSIZE][BOARDSIZE]);
int checkSum(char board[BOARDSIZE][BOARDSIZE]);
int isCompleted(int sum);


int main() {

	int turn = 0; 
	int round = 1;
	char board[BOARDSIZE][BOARDSIZE];

	int x = 0, y = 0; // current index

	// �ʱ�ȭ
	for (int i = 0; i < BOARDSIZE; i++)
		for (int j = 0; j < BOARDSIZE; j++) board[i][j] = ' ';


	srand(time(NULL)); // Set Seed for Computer

	printf("========================\n TIC TAC TOE ���� \n========================\n\n");

	// Set turn
	printf("���� ���� �ұ��? (1: You | others : Computer) : ");
	scanf("%d", &turn);


	while (round <= (BOARDSIZE* BOARDSIZE)) {
		printf("\n [ Round %d ]\n", round);
		if (turn == 1) { // User's Turn
			printf("Your Turn : ");			
			scanf("%d %d", &x, &y);

			// �Է� ����ó��
			if ((x < 0) || (x >= BOARDSIZE) || (y < 0) || (y >= BOARDSIZE)) {
				printf("0~%d ������ ��ǥ�� �Է����ּ���!\n", BOARDSIZE-1);
				continue;
			}

			// ������̸� �Ҵ�
			if (board[x][y] == ' ') board[x][y] = 'O'; 
			else {
				printf("�� �ű⿣ ���� �� �����!\n");
				continue;
			}

			turn = 0; // User ���� ���� �� Computer turn���� �Ѱ���
		}
		else { // Computer's Turn
			printf("Computer's Turn\n");
			x = rand() % BOARDSIZE; // 0~2 ����
			y = rand() % BOARDSIZE; // 0~2 ����
			
			if (board[x][y] == ' ') { // �� �������� �˻� �� �Ҵ�
				printf("Computer Input : %d %d\n", x, y);
				board[x][y] = 'X';
			}
			else continue;

			turn = 1; // Computer ���� ���� �� User turn���� �Ѱ���
		}
		printBoard(board);

		if (checkSum(board)) { // 1�̸� ������ �̱��
			printf("Game Over\n");
			return 0;
		}
		round++;
	}
	printBoard(board);
	printf("���º� -_- !\n");

	return 0;
}



// ���� ȭ���� �ֿܼ� ����ϴ� �Լ�
void printBoard(char board[BOARDSIZE][BOARDSIZE]) {
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) printf(" %c |", board[i][j]);
		printf("\n");
	}
}

// ������ �������� �˻� (�º� ����)
// return �� (1 : ���� �� | 0 : ���� ���� ����)
int isCompleted(int sum) {
	if (sum == 'O' * BOARDSIZE) { // 'O' �� �� �߻�
		printf("You Win!!\n");
		return 1;
	}
	else if (sum == 'X' * BOARDSIZE) { // 'X' �� �� �߻�
		printf("Computer Win!!\n");
		return 1;
	}
	return 0;
}

// �� ���� ������ ���� �˻�
int checkSum(char board[BOARDSIZE][BOARDSIZE]) {
	int sum = 0;
	// ���� ��
	for (int i = 0; i < BOARDSIZE; i++) {
		sum = 0;
		for (int j = 0; j < BOARDSIZE; j++)	sum += board[i][j];
		if (isCompleted(sum)) return 1;
	}

	// ���� ��
	for (int i = 0; i < BOARDSIZE; i++) {
		sum = 0;
		for (int j = 0; j < BOARDSIZE; j++)	sum += board[j][i];
		if (isCompleted(sum)) return 1;
	}

	// �밢��
	sum = 0;
	for (int i = 0; i < BOARDSIZE; i++) sum += board[i][i];
	if (isCompleted(sum)) return 1;

	// ���밢
	sum = 0;
	for (int i = 0; i < BOARDSIZE; i++) sum += board[i][BOARDSIZE - 1 - i];
	if (isCompleted(sum)) return 1;

	return 0;
}