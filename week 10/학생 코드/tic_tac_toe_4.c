#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ƽ���� ���� �ڵ� ���� ����

//���� ĭ �� ������°�� ĭ�� �д�. r�� ���� ĭ.
int randCom(const char board[3][3], int r) {
	//���� ĭ �� t��°�� ĭ�� ���� �д�.
	//t�� �������� ����.
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

//���� �ε����� ���� �� ĭ�� ���� �д�.
int com(const char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				return i * 10 + j;
		}
	}
	return 0;
}

//������ �¸��� �ڰ� �ִ��� �˻��Ѵ�.
char check(const char board[3][3]) {
	int i;
	char c = ' ';
	//���� Ȯ��
	for (i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}
	//���� Ȯ��
	for (i = 0; i < 3; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	//�밢�� Ȯ��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];
	return ' ';
}

int main() {
	//������ �ʱ�ȭ
	char board[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	//���� ��ǻ�͸� ���� �õ弳��
	srand(time(0));
	char mode;
	printf("���� ��ǻ�ͷ� �Ͻðڽ��ϱ�?(y/n): ");
	scanf("%c", &mode);
	printf("%c\n", mode);
	//��� ĭ�� 9ĭ�̴�.
	for (int k = 0; k < 9; k++) {
		int x, y;
		//��ȿ�� �Է��� ���� ������ �ݺ�
		while (1) {
			//��ǻ�Ϳ� �Ѵٸ�, ��ǻ���� ���� �����´�.
			if (k % 2 == 1 && mode == 'y') {
				int temp = randCom(board, 9 - k);
				x = temp / 10;
				y = temp % 10;
				break;
			}
			printf("\n��ǥ �Է�(x y): ");
			scanf("%d %d", &x, &y);
			//�ε��� ���� Ȯ��
			if (x < 0 || x>2 || y < 0 || y>2) {
				printf("��ǥ�� �ε����� �Ѿ.(0~2)\n\n");
			}
			//��ĭ���� Ȯ��
			else if (board[x][y] == ' ') {
				break;
			}
			//���� �� �� �ƴ϶��, �̹� ���� �ִ� ���̴�.
			else {
				printf("�̹� ���� �ִ� ��ǥ.\n\n");
			}
		}
		//���ʿ� �°� ���� ���´�.
		board[x][y] = k % 2 ? 'X' : 'O';
		//������ ��Ȳ ���
		printf("\n---|---|---\n");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf(" %c |", board[i][j]);
			}
			printf("\n---|---|---\n");
		}
		//�¸� Ȯ��
		char c = check(board);
		//�¸��ߴٸ�, ���� ��
		if (c != ' ') {
			printf("\n%c �� �̰���ϴ�.\n", c);
			return 0;
		}
	}
	printf("\n���º��Դϴ�.\n");
	return 0;
}

