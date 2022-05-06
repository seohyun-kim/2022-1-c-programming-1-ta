#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int win = 0;
int lose = 0;
int none = 0;

void play_p2p(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer �ڵ庹��/����
	for (int i = 1; i <= 9; i++) {			//���ӽ���
														//��� ���� �Է�
		mark = (i % 2 == 0) ? 'X' : 'O';
						//OX�Է¼��� ���� �� �Է�

		printf("%c�� �����Դϴ�\n��ǥ�� �Է��� �ּ���\n", mark);
		scanf("%d %d", &y, &x);
		while (game[y][x] != ' ') {
			printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
			scanf("%d %d", &y, &x);		//��ǥ�Է�
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		break;
	case 'h':
		printf("O�� �̰���ϴ�\n");
		break;
	case 'c':
		printf("X�� �̰���ϴ�\n");
		break;
	}
	printf("������ �����մϴ�\n\n");
}
				//1. �θ��̼� �÷��� �ڵ�
				//�ܼ��� ���� �����ư��鼭 �÷���
				//�·��� ������� �ʴ� ���
void play_with_computer_hfirst_easy(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'X' : 'O';
						//OX�Է¼��� ���� �� �Է�

		switch (i % 2) {
		case 1:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);		//��ǥ�Է�
			}
			break;
		case 0:
			srand(time(0));
			x = rand() % 3;
			y = rand() % 3;
			while (game[y][x] != 32) {
				x = rand() % 3;
				y = rand() % 3;
			}
			break;
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n",game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner){
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰����\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
				//2. ��� ���� ��ǻ�Ϳ� ���
				//�ܼ� �����õ�� ��ǥ�� ����
void play_with_computer_cfirst_easy(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'O' : 'X';
		//OX�Է¼��� ���� �� �Է�

		switch (i % 2) {
		case 0:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);		//��ǥ�Է�
			}
			break;
		case 1:
			srand(time(0));
			x = rand() % 3;
			y = rand() % 3;
			while (game[y][x] != 32) {
				x = rand() % 3;
				y = rand() % 3;
			}
			break;
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰���ϴ�\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
				//3. ��ǻ�� ���� ��ǻ�Ϳ� ���
				//�ܼ� �����õ�� ��ǥ�� ����
void play_with_computer_hfirst_hard(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ
	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'X' : 'O';
		//OX�Է¼��� ���� �� �Է�

		switch (i % 2) {
		case 1:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);		//��ǥ�Է�
			}
			game[y][x] = mark;
			break;
		case 0:
			switch (game[1][1]) {
			case 32:
				game[1][1] = 'X';
				break;
			case 88:					//��ǻ�Ͱ� ��� �����ϰ� ������� ������ ��鼭 ��������
				if (((game[0][0] + game[2][0] == 158) && (game[1][0] == 32)) ||
					((game[0][2] + game[2][2] == 158) && (game[1][2] == 32)) ||
					((game[0][0] + game[0][2] == 158) && (game[0][1] == 32)) ||
					((game[2][0] + game[2][2] == 158) && (game[2][1] == 32))) {
					if ((game[0][0] + game[2][0] == 158) && (game[1][0] == 32)) {
						game[1][0] = 88;
					}
					else if ((game[0][2] + game[2][2] == 158) && (game[1][2] == 32)) {
						game[1][2] = 88;
					}
					else if ((game[0][0] + game[0][2] == 158) && (game[0][1] == 32)) {
						game[0][1] = 88;
					}
					else {
						game[2][1] = 88;
					}
				}
				else if (y == x) {									// \�ڰ� ä��������
					if (game[y][1] == ' ') {
						game[y][1] = 'X';
					}
					else if (game[1][x] == ' ') {
						game[1][x] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				else if ((y % 2 == 0) && (x % 2 == 0)) {		// /�ڰ� ä��������
					if (game[y][1] == ' ') {
						game[y][1] = 'X';
					}
					else if (game[1][x] == ' ') {
						game[1][x] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				else if ((y == 1) && (x % 2 == 0)) {			// -�ڰ� ä��������
					if (game[0][x] == ' ') {
						game[0][x] = 'X';
					}
					else if (game[2][x] == ' ') {
						game[2][x] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				else if ((y % 2 == 0) && (x == 1)) {			// |�ڰ� ä��������
					if (game[y][0] == ' ') {
						game[y][0] = 'X';
					}
					else if (game[y][2] == ' ') {
						game[y][2] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				break;
			case 79:			//����� �������� ��������
				if (i == 2) {
					game[0][0] = 'X';						//���Ƿ� 0,0�� �� �������
				}
				else if ((game[0][0] + game[1][0] + game[2][0] == 208) ||
					(game[0][0] + game[0][1] + game[0][2] == 208) ||
					(game[0][2] + game[1][2] + game[2][2] == 208) ||
					(game[2][0] + game[2][1] + game[2][2] == 208)) {
					for (int j = 0; j <= 2; j = j + 2) {
						if (game[0][j] + game[1][j] + game[2][j] == 208) {
							for (int n = 0; n < 3; n++) {
								game[n][j] == 'X';
							}
							break;
						}
						else if (game[j][0] + game[j][1] + game[j][2] == 208) {
							for (int n = 0; n < 3; n++) {
								game[j][n] == 'X';
							}
							break;
						}
					}										//��ǻ���� 2���� �� ��������� ���ϰ� ��������
				}
				else if ((game[0][1] + game[1][1] + game[2][1] == 190) ||
					(game[1][0] + game[1][1] + game[1][2] == 190) ||
					(game[0][2] + game[1][2] + game[2][2] == 190) ||
					(game[2][0] + game[2][1] + game[2][2] == 190) ||
					(game[0][2] + game[1][1] + game[2][0] == 190)) {
					if ((game[2][2] == 79) &&
						((game[2][0] + game[2][1] == 111) || (game[0][2] + game[1][2] == 111))) {
						if (game[2][0] + game[2][1] == 111) {
							if (game[2][0] == 79) {
								game[2][1] = 88;
							}
							else {
								game[2][0] = 88;
							}
						}
						else {
							if (game[0][2] == 79) {
								game[1][2] = 88;
							}
							else {
								game[0][2] = 88;
							}
						}
					}
					else if (game[1][1] == 79) {
						if (game[2][0] + game[0][2] == 111) {
							if (game[2][0] == 79) {
								game[0][2] = 88;
							}
							else {
								game[2][0] = 88;
							}
						}
						else if (game[0][1] + game[2][1] == 111) {
							if (game[0][1] == 79) {
								game[2][1] = 88;
							}
							else {
								game[0][1] = 88;
							}
						}
						else if (game[1][0] + game[1][2] == 111) {
							if (game[1][0] == 79) {
								game[2][1] = 88;
							}
							else {
								game[1][0] = 88;
							}
						}
					}
				}
				else if ((game[1][0] + game[2][0] == 64) || (game[0][1] + game[0][2] == 64)) {
					if (game[1][0] + game[2][0] == 64) {
						game[2][0] = 88;
					}
					else {
						game[0][2] = 88;
					}
				}
				else if ((game[2][2] == 32) && ((game[2][1] == 32) || (game[1][2] == 32))) {
					if (game[2][1] == 32) {
						game[2][1] = 88;
					}
					else {
						game[1][2] = 88;
					}
				}
				break;
			}
		default:
			break;
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰���ϴ�\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
				//4. ��� ���� ��ǻ�Ϳ� ���
				//(1,1)�� ����� ���� �������� �ʾҴٸ�
				//6�� �ڵ� ó�� (1,1) �����ϰ� ���������� �÷���
				//������ ��� ���̽����� ������� ���̽��� ���ϱ⵵ ��
				//������ (1,1)�� ����� �����ϸ� ���� ���� Ǯ��
void play_with_computer_cfirst_hard(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'O' : 'X';
		//OX�Է¼��� ���� �� �Է�

		switch (i % 2) {
		case 0:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);		//��ǥ�Է�
			}
			game[y][x] = mark;
			break;
		case 1:
			if (game[1][1] == ' ') {
				game[1][1] = 'X';
			}									//����� �������
			else {
					if (y == x) {									// \�ڰ� ä��������
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x % 2 == 0)) {		// /�ڰ� ä��������
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y == 1) && (x % 2 == 0)) {			// -�ڰ� ä��������
						if (game[0][x] == ' ') {
							game[0][x] = 'X';
						}
						else if (game[2][x] == ' ') {
							game[2][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x == 1)) {			// |�ڰ� ä��������
						if (game[y][0] == ' ') {
							game[y][0] = 'X';
						}
						else if (game[y][2] == ' ') {
							game[y][2] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
			}
			break;
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰���ϴ�\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
				//5. ��ǻ�� ���� ��ǻ�Ϳ� ���
				//��ǻ���� ������� �÷���
				//��ǻ�ʹ� �̱�� ���ٴ� �����ʴµ��� ����
				//(1,1)���� �� ������ ���� �ȵǰ� �����ϴµ� ����
void play_with_computer_hardcore(void) {
	printf("������ �����մϴ�\n");
	printf("Good Luck\n\n");

	char game[3][3];					//��ǥ�� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//�ʱ�ȭ
	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//���ӽ���
															//��ǻ�Ͷ� ���
		mark = (i % 2 == 0) ? 'O' : 'X';
		//OX�Է¼��� ���� �� �Է�

		switch (i % 2) {
		case 0:
			printf("��ǥ�� �Է��� �ּ���\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("�̹� ������ ��ǥ�Դϴ�\n�ٸ� ��ǥ�� �Է����ּ���\n");
				scanf("%d %d", &y, &x);		//��ǥ�Է�
			}
			game[y][x] = mark;
			break;
		case 1:
			switch (game[1][1]) {
			case 32:
				game[1][1] = 'X';
				break;
			case 88:
				if ((game[1][0] + game[1][2] == 120) || (game[0][1] + game[2][1] == 120) ||
					(game[0][0] + game[2][2] == 120) || (game[0][2] + game[2][0] == 120)) {
					if (game[1][0] + game[1][2] == 120) {
						game[1][0] = 88;
						game[1][2] = 88;
					}
					else if (game[0][1] + game[2][1] == 120) {
						game[0][1] = 88;
						game[2][1] = 88;
					}
					else if (game[0][0] + game[2][2] == 120) {
						game[0][0] = 88;
						game[2][2] = 88;
					}
					else {
						game[0][2] = 88;
						game[2][0] = 88;
					}										//�߾� �������� 2���� ���� �ϳ��� �� ���
				}
				else if ((game[0][0] + game[2][0] + game[1][0] == 208) ||
					(game[0][2] + game[2][2] + game[1][2] == 208) ||
					(game[0][0] + game[0][2] + game[0][1] == 208) ||
					(game[2][0] + game[2][2] + game[2][1] == 208)) {
					if (game[0][0] + game[2][0] + game[1][0] == 208) {
						game[0][0] = 88;
						game[2][0] = 88;
						game[1][0] = 88;
					}
					else if (game[0][2] + game[2][2] + game[1][2] == 208) {
						game[0][2] = 88;
						game[2][2] = 88;
						game[1][2] = 88;
					}
					else if (game[0][0] + game[0][2] + game[0][1] == 208) {
						game[0][0] = 88;
						game[0][2] = 88;
						game[0][1] = 88;
					}
					else {
						game[2][0] = 88;
						game[2][2] = 88;
						game[2][1] = 88;
					}
				}											//�߾� ���� 2���� ���� �ϳ��� �� ���
				else if (((game[0][0] + game[2][0] + game[1][0] == 190)) ||
					((game[0][2] + game[2][2] + game[1][2] == 190)) ||
					((game[0][0] + game[0][2] + game[0][1] == 190)) ||
					((game[2][0] + game[2][2] + game[2][1] == 190))) {
					if (game[0][0] + game[2][0] + game[1][0] == 190) {
						if (game[0][0] == 32) game[0][0] = 88;
						else if (game[2][0] == 32) game[2][0] = 88;
						else if (game[0][0] == 32) game[1][0] = 88;
					}
					else if (game[0][2] + game[2][2] + game[1][2] == 190) {
						if (game[0][2] == 32) game[0][2] = 88;
						else if (game[2][2] == 32) game[2][2] = 88;
						else if (game[1][2] == 32) game[1][2] = 88;
					}
					else if (game[0][0] + game[0][2] + game[0][1] == 190) {
						if (game[0][0] == 32) game[0][0] = 88;
						else if (game[0][2] == 32) game[0][2] = 88;
						else if (game[0][1] == 32) game[0][1] = 88;
					}
					else {
						if (game[2][0] == 32) game[2][0] = 88;
						else if (game[2][2] == 32) game[2][2] = 88;
						else if (game[2][1] == 32) game[2][1] = 88;
					}
				}											//�����ڰ� 2���� �ΰ� �ϳ��� �� ��� ���
				else if ((game[1][0] + game[1][2] + game[0][1] + game[2][1] == 128) &&
					(game[0][0] + game[2][2] + game[0][2] + game[2][0] == 175)) {
					if (game[0][0] == 79)  game[1][0] = 88;
					else if (game[0][2] == 79) game[0][1] = 88;
					else if (game[2][0] == 79) game[2][1] = 88;
					else if (game[2][2] == 79) game[1][2] = 88;
				}										//�����ڰ� ù��°�� �밢���Ƚ� �ٷ� �� ����
				else if ((game[1][0] + game[1][2] + game[0][1] + game[2][1] == 175) &&
					(game[0][0] + game[2][2] + game[0][2] + game[2][0] == 128)) {
					if (game[1][0] == 79) game[2][0] = 88;
					else if (game[1][2] == 79) game[0][2] = 88;
					else if (game[0][1] == 79) game[0][0] = 88;
					else if (game[2][1] == 79) game[2][2] = 88;
				}										//�����ڰ� ù��°�� �������� ���� �� �ٷ� �� ����
				else if ((game[0][0] + game[2][0] + game[1][0] == 96) ||
					(game[0][2] + game[2][2] + game[1][2] == 96) ||
					(game[0][0] + game[0][2] + game[0][1] == 96) ||
					(game[2][0] + game[2][2] + game[2][1] == 96)) {
					if (game[0][0] + game[2][0] + game[1][0] == 96) {
						/////////////////////////////////////////////////////////////////////////
					}
				}


				////////////////////////////////////////////////////////////////////////////////


				else {
					srand(time(0));
					x = rand() % 3;
					y = rand() % 3;
					while (game[y][x] != 32) {
						x = rand() % 3;
						y = rand() % 3;
					}
					game[y][x] = mark;
				}
				break;
			}
		default:
			break;
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//���� �����Ȳ ���

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//���а���
	}									//��������
	switch (checkwinner) {
	case 'n':
		printf("�̹� ������ ���º� �Դϴ�\n");
		none++;
		break;
	case 'h':
		printf("�����ڰ� �̰���ϴ�\n");
		win++;
		break;
	case 'c':
		printf("��ǻ�Ͱ� �̰���ϴ�\n");
		lose++;
		break;
	}
	printf("������ �����մϴ�\n\n");
}
				//6. ��ǻ�� ���� ��ǻ�Ϳ� ���
				//��ǻ�� ������ �÷���
				//��ǻ�ʹ� �̱�� ������ ������ �̱�µ��� ��Ŀ��
				//(1,1)�� �����ϰ� (1,1)�� �����ϴ� ������ ����µ��� ��Ŀ��
				//�ΰ��� ����� ���̽��� ã�Ҵٸ� ���ٿ� ������ ĭ�� �����ִ��� Ȯ��,
				//������ ĭ�� ����ִٸ� ä��� ���� ����,
void help(void) {
	printf("-------------------------------------------------\n");
	printf("�����ڴ� O, ��ǻ��/�Խ�Ʈ�� X�� ǥ���ϸ�\n");
	printf("�Է°� 'a b'�� a��° �� b��° ĭ�� �ǹ��մϴ�\n\n");
	printf("����");
	printf("\n   0   1   2\n");
	printf(" |---|---|---|\n");
	printf("0|   |   |   |\n");
	printf(" |---|---|---|\n");
	printf("1|   |   |   |\n");
	printf(" |---|---|---|\n");
	printf("2|   |   |   |\n");
	printf(" |---|---|---|\n\n");
	printf("a�� b�� 0���� 2 ���� �����Դϴ�\n");
	printf("��ǻ�Ϳ� �÷��� �� ���\n");
	printf("�����ڰ� ��ǥ�� �����ϴ� ���\n");
	printf("��ǻ�͵� ���� ��ǥ�� �����մϴ�\n");
	printf("-------------------------------------------------\n");
	printf("������������ ���ư����� '0'�� �Է��ϰ� Enter�� ���ּ���\n���� Zero �Դϴ�\n");
	int check = 1;
	scanf("%d", &check);
	while (check != 0) {
		printf("\n��ȿ���� ���� �����Դϴ�\n�ٽ� �Է����ּ���\n");
		scanf("%d", &check);
	}
}

int main() {
	printf("Tic-Tac-Toe ���ӿ� ���Ű��� ȯ���մϴ�\n\n");

	while (1) {
		printf("���ο� ����\n\n");
		printf("��ǻ�Ϳ��� ������ ���и� ����մϴ�\n");
		printf("���� ���� : %d�� %d�� %d��\n",win,none,lose);
		float percent_h = (win == 0) ? 0 : (float)win / (win + none + lose) * 100;//�·�
		printf("������ ���� �·� : %.2f%% \n", percent_h);
		float percent_c = (lose == 0) ? 0 : (float)lose / (win + none + lose) * 100;
		printf("��ǻ�� ���� �·� : %.2f%% \n\n", percent_c);
		printf("�ɼ��� �������ּ���\n\n");
		printf("1. �θ��̼� �÷���\n");
						//�ܼ��� ���� �����ư��鼭 �÷���
		printf("2. ��ǻ�Ϳ� �÷���(���̵� ��/�����ڰ� �����մϴ�)\n");
						//�����õ�� ��ǥ ���� �� ����
		printf("3. ��ǻ�Ϳ� �÷���(���̵� ��/��ǻ�Ͱ� �����մϴ�)\n");
						//�����õ�� ��ǥ ���� �� ����
		printf("4. ��ǻ�Ϳ� �÷���(���̵� �߻�/�����ڰ� �����մϴ�/�Ӹ� ���ݸ� ������ ���̵� ��)\n");
						//(1,1)�� ���� �����ϸ� ���������� ����
		printf("5. ��ǻ�Ϳ� �÷���(���̵� ��/��ǻ�Ͱ� �����մϴ�/���ؾ� ���º�)\n");
						//��ǻ�ʹ� ���������, ��ǻ�Ͱ� �̱�� ���ٴ� ���ºθ� ����µ� ������ ��
		printf("6 (������). ��ǻ�Ϳ� �÷���(���̵� �ֻ�/��ǻ�Ͱ� �����մϴ�/��ǻ�Ͱ� �·��� �е������� �����ϴ�)\n");
						//��ǻ�Ͱ� �������� ���������� �ٲ�, 2���� �̷���� ���� �ִٸ� üũ�ϰ� ���� ���Ḧ ����
		printf("7. ����\n");
		printf("8. ���� ����\n\n");
		int o;//option
		scanf("%d", &o);
		while (o <= 0 || o >= 9) {
			printf("�߸��� �Է°��Դϴ�\n�ٽ� �Է����ּ���\n");
			scanf("%d", &o);
		}
		
		switch (o) {
		case 1:
			play_p2p();
			break;
		case 2:
			play_with_computer_hfirst_easy();
			break;
		case 3:
			play_with_computer_cfirst_easy();
			break;
		case 4:
			play_with_computer_hfirst_hard();
			break;
		case 5:
			play_with_computer_cfirst_hard();
			break;
		case 6:
			printf("�ڵ尡 �ϼ����� ���� ����Դϴ�\n������������ �̵��մϴ�\n\n");
			//play_with_computer_hardcore();
			break;
		case 7:
			help();
			break;
		default:
			break;
		}
		if (o == 8) {
			printf("������ �����մϴ�\n\n");
			break;
		}

	}
}