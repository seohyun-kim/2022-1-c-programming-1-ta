#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>
//�ܾ� ��ġ���� �ϳ� ����, �� �ܾ�� ��ǰ���
//�� ��ȸ�� 10���̴�.
//�Ŵ޸� ����� �ϼ��Ű��� �׸��� ����Ѵ�.
//�̹� �Է��ߴ� ���ڸ� ó���Ѵ�.
//���� ������ ���� ���ڴ� '_'�� ���
//���� ���ڴ� �� ���ڸ� ����Ѵ�.

// �ʿ��� �Լ��� ��������.
// �׸��� ���� �Լ�.
// init <== �� ó�� ȭ���� �׸�.
// draw <== �� �ܰ躰�� ����� �׸�.
// 
// �۾��� ���� ���� �Լ�.
// start <== ������ ���۵� �� �ȳ����� ���.
// setting <== ���� ���۵ǰ� ����, ���ĺ� ���� �����.
// 
// ���� ������ ���� �Լ�.
//

#define pi 3.141592
#define space 32

void gotoxy(int x, int y);//�ֿܼ��� x,y�� Ŀ����ġ�� ����
void draw(int n);//1~10���� �ܰ躰�� �׸�.
void init();//���� â�� ����. 
void start();//���� ������ ����.

void start() {
	gotoxy(20, 10);
	printf("�ܾ��� ī�װ��� �����Դϴ�.");
	gotoxy(20, 11);
	printf("����� 10���̸�, �ߺ��Է��� ī��Ʈ���� �ʽ��ϴ�.");
	gotoxy(20, 12);
	printf("3�ʵ� �����մϴ�.");
	gotoxy(20, 13);
	printf("��� ���ڴ� �ҹ����Դϴ�.");
	gotoxy(20, 15);
	//printf("�� ���� �Է��� �� �� �߿� �������� ���õ˴ϴ�.");
	//gotoxy(20, 18);
	printf("3 ");
	Sleep(1000);
	printf("2 ");
	Sleep(1000);
	printf("1 ");
	Sleep(1000);
	printf("����!");
	Sleep(1000);
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw(int n) {
	if (n == 1) {
		gotoxy(0, 30);
		printf("------------");
	}
	else if (n == 2) {
		for (int i = 3; i < 30; i++) {
			gotoxy(5, i);
			printf("||");
		}
	}
	else if (n == 3) {
		gotoxy(6, 2);
		printf("_______________");
	}
	else if (n == 4) {
		gotoxy(20, 2);
		printf(".");
		for (int i = 3; i < 7; i++) {
			gotoxy(20, i);
			printf("|");
		}
	}
	else if (n == 5) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if ((i == 0 || i == 4) && (j == 0 || j == 4)) continue;
				gotoxy(j + 18, i + 7);
				printf("*");
			}
		}
	}
	else if (n == 6) {
		for (int i = 0; i < 7; i++) {
			gotoxy(20, i + 12);
			printf("|");
		}
	}
	else if (n == 7) {
		gotoxy(19, 13);
		printf("-");
		gotoxy(18, 13);
		printf("_");
		for (int i = 0; i < 4; i++) {
			gotoxy(18, i + 14);
			printf("|");
		}
		gotoxy(18, 18);
		printf("o");
	}
	else if (n == 8) {
		gotoxy(21, 13);
		printf("-");
		gotoxy(22, 13);
		printf("_");
		for (int i = 0; i < 4; i++) {
			gotoxy(22, i + 14);
			printf("|");
		}
		gotoxy(22, 18);
		printf("o");
	}
	else if (n == 9) {
		gotoxy(20, 19);
		printf("^");
		for (int i = 0; i < 5; i++) {
			gotoxy(19, i + 19);
			printf("|");
		}
		gotoxy(18, 24);
		printf("==");
	}
	else if (n == 10) {
		for (int i = 0; i < 5; i++) {
			gotoxy(21, i + 19);
			printf("|");
		}
		gotoxy(21, 24);
		printf("==");
	}
	else if (n == 11) {
		gotoxy(35, 14);
		printf("He(She) is dead...");
	}
	else {
		gotoxy(0, 0);
		printf("drawError!");
	}
}

void init() {
	system("mode con cols=92 lines=36");
	//H
	{
		for (int i = 0; i < 7; i++) {
			gotoxy(40, i + 3);
			printf("*");
			gotoxy(45, i + 3);
			printf("*");
		}
		for (int i = 0; i < 4; i++) {
			gotoxy(41 + i, 6);
			printf("*");
		}
	}
	//a
	{
		gotoxy(48, 8);
		printf("*   *");
		gotoxy(48, 7);
		printf("*   *");
		gotoxy(52, 5);
		printf("*");
		gotoxy(49, 4);
		printf("***");
		gotoxy(49, 6);
		printf("****");
		gotoxy(49, 9);
		printf("****");
	}
	//n
	{
		gotoxy(55, 6);
		printf("* ***");
		gotoxy(55, 7);
		printf("**   *");
		gotoxy(55, 8);
		printf("*    *");
		gotoxy(55, 9);
		printf("*    *");
	}
	//g
	{
		gotoxy(64, 6);
		printf("****");
		gotoxy(63, 7);
		printf("*   *");
		gotoxy(63, 8);
		printf("*   *");
		gotoxy(64, 9);
		printf("****");
		gotoxy(67, 10);
		printf("*");
		gotoxy(67, 11);
		printf("*");
		gotoxy(64, 12);
		printf("***");
	}
	//M
	{
		for (int i = 0; i < 7; i++) {
			gotoxy(47, 13 + i);
			if (i == 1) printf("**   **");
			else if (i == 2) printf("* * * *");
			else if (i == 3) printf("*  *  *");
			else printf("*     *");
		}
	}
	//a
	{
		gotoxy(56, 17);
		printf("*   *");
		gotoxy(56, 18);
		printf("*   *");
		gotoxy(60, 15);
		printf("*");
		gotoxy(57, 14);
		printf("***");
		gotoxy(57, 16);
		printf("****");
		gotoxy(57, 19);
		printf("****");
	}
	//n
	{
		gotoxy(64, 16);
		printf("* ***");
		gotoxy(64, 17);
		printf("**   *");
		gotoxy(64, 18);
		printf("*    *");
		gotoxy(64, 19);
		printf("*    *");
	}
	draw(1);
	draw(2);
	draw(3);
	draw(4);
	draw(5);
	draw(6);
	draw(7);
	draw(8);
	draw(9);
	draw(10);
	gotoxy(35, 23);
	printf("�����Ϸ��� �����̽��� �����ʽÿ�...");
}