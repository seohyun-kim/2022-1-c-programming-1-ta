#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



#if 1
int main() {

	char board[3][3];   //---> ���� ������
	int x, y, k, i;
	int count = 0;
	srand(time(NULL));

	//�÷��̾�
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';


	//�÷��̾�� ��ǻ�Ͱ� �Է��ϴ� ������ �ִ´�.
	for (k = 0; k < 9; k++) {

		if (k % 2 == 0) {

			printf("����� �����Դϴ�.\n���� ���� ��ġ�� �Է��ϼ���.(�� ��): ");
		player:
			scanf("%d %d", &x, &y);

			if (board[x][y] != ' ') {
				printf("�װ����� �� �� �����ϴ�.\n���� ���� ��ġ�� �Է��ϼ���.(�� ��): ");
				goto player;
			}
			board[x][y] = 'O';
			count += 1;
		}

		if (k % 2 != 0) {

			printf("��ǻ���� �����Դϴ�.\n");
		computer:
			int x = (rand() % 3 + 1);
			int y = (rand() % 3 + 1);

			if (board[x][y] != ' ') {
				goto computer;
			}
			board[x][y] = 'X';
			count += 1;
		}

		//���� ȭ�鿡 ǥ���Ѵ�.
		for (i = 0; i < 3; i++) {
			printf("---|---|---\n");
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---\n");

		//�÷��̾� �¸� ����
		if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
			printf("����� �¸�!");
			break;
		}

		if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
			printf("����� �¸�!");
			break;
		}

		if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
			printf("����� �¸�!");
			break;
		}

		if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
			printf("����� �¸�!");
			break;
		}

		if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
			printf("����� �¸�!");
			break;
		}

		if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
			printf("����� �¸�!");
			break;
		}

		if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
			printf("����� �¸�!");
			break;
		}

		if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
			printf("����� �¸�!");
			break;
		}

		//��ǻ�� �¸� ����
		if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
			printf("��ǻ�� ��! ���ݸ� �� �����ϰ� ������~");
			break;
		}

		//���º� ����
		if (count == 9) {
			printf("���º�!");
			break;
		}
	}
	return 0;
}
#endif