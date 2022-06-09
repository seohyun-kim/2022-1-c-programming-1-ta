#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>
#include <stdbool.h>

#define space 32
#define max_len 100
typedef unsigned int uint;
//�ֿܼ��� x,y�� Ŀ����ġ�� ����
extern void gotoxy(int x, int y);
//1~10���� �ܰ躰�� �׸�.
extern void draw(int n);
//���� â�� ����. 
extern void init();
//���� â�� ����.
extern void start();

int main() {
	//�ܾ� ������ ���� �����õ� ����
	srand(time(NULL));

	//���� ȭ���� ����ݴϴ�.
	init();

	//�����̽��� �Էµ� ������ ���
	while (_getch() != space) {
		printf(".");
	}
	system("cls");

	//���� ���� ȭ��
	//ī�װ� ������ �Ϸ��� �켱 ����
	//�ȳ����� 3�ʰ� ���� ���� ����
	start();

	//���Ͽ��� ������° ������ �����ɴϴ�.
	FILE* fp;
	fp = fopen("country2.txt", "rt");
	char answer[max_len] = { 0, };
	//�� 255���� �����Ͱ� ����
	//�� ������ �ٹٲ����� ���еǾ� �����ִ�.
	uint cnt = rand() / 255 + 1;
	fgets(answer, max_len, fp);
	for (int i = 1; i < cnt; i++) {
		fgets(answer, max_len, fp);
	}
	fclose(fp);
	//�ѱ�� �ִ� ���. ������ ������ �����ٰ�.
	fp = fopen("country.txt", "rt");
	char answer_kr[max_len] = { 0, };
	fgets(answer_kr, max_len, fp);
	for (int i = 1; i < cnt; i++) {
		fgets(answer_kr, max_len, fp);
	}
	fclose(fp);

	system("cls");
	//����߿� �Էµ� ���۸� ��� ������ �����Ѵ�.
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	//�÷��̾��� ����� ����.
	char player[max_len] = { 0, };
	//������ ��ġ�� �ܾ��� ������ ����.
	for (int i = 0; i < strlen(answer); i++) {
		if (isalpha(answer[i])) {
			answer[i] = tolower(answer[i]);
			player[i] = '_';
		}
		else {
			player[i] = answer[i];
		}
	}
	gotoxy(35, 10);
	printf("%s", player);

	//���ĺ� �ߺ��Է� üũ�� �� �迭
	bool check[26] = { 0, };

	for (int i = 0; i < 10; i++) {
		gotoxy(0, 0);
		char c = _getch();
		//�Է� �˻�
		while (!isalpha(c)) {
			c = _getch();
		}
		//�ߺ� �˻�
		if (check[c - 'a']) { 
			i--;
			continue; 
		}
		check[c - 'a'] = true;
		gotoxy(35, 7);
		printf("�Է��� ���ĺ�:");
		gotoxy(35, 8);
		for (int i = 0; i < 26; i++) {
			if (check[i])
				printf("%c ", i + 'a');
		}
		char* cp = strchr(answer, c);
		if (cp != NULL) {
			while (cp != NULL) {
				player[cp - answer] = c;
				cp = strchr(cp + 1, c);
			}
			gotoxy(35, 10);
			printf("%s", player);
			if (strcmp(player, answer) == 0) {
				gotoxy(35, 12);
				printf("���!! ");
				gotoxy(35, 13);
				printf("%s", answer_kr);
				gotoxy(0, 31);
				return 0;
			}
			i--;
		}
		else {
			draw(i + 1);
		}
	}

	draw(11);
	gotoxy(35, 12);
	printf("����: %s", answer_kr);

	gotoxy(0, 31);
	return 0;
}