/*
	============================================
	chapter6. ���ǹ�
	2022-04-01
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// ���� �ϳ��� �Է¹޾� Ȧ���� ¦���� �����ϴ� ���α׷� 
// p.234
#if 0
int main() {
	int number;

	scanf("%d", &number);

	// ==============================
	if (number % 2 == 0) {
		printf("¦���Դϴ�\n");
	}
	else {
		printf("Ȧ���Դϴ�.\n");
	}
	// ==============================

	return 0;
}
#endif




// ���� if�� p.239
// ���� Ÿ���� ������ �Է¹޾� ������ �����ϴ� ���α׷�
#if 0
int main() {
	int score;

	scanf("%d", &score);

	// ==============================
	if (score >= 90) {
		printf("����� ������ A\n");
	}
	else if (score >= 80) {
		printf("����� ������ B\n");
	}
	else {
		printf("�ƾ� �������ϱ� �� �Ʒ��� �׳� F�޾�!\n");
	}
	// ==============================

	return 0;
}
#endif



// ���� �з� ���α׷� p.240
// char Ÿ���� ���ڸ� �ϳ� �Է¹޾� �빮��, �ҹ���, ����, ��Ÿ���ڷ� �����ϱ�
#if 0
int main() {
	char ch;

	scanf("%c", &ch);

	// ==============================
	if (ch >= 'A' && ch <= 'Z') {
		printf("�빮�ڿ���!");
	}
	else if (ch >= 'a' && ch <= 'z') {
		printf("�ҹ��ڿ���!");
	}
	else if (ch >= '0' && ch <= '9') {
		printf("���ڿ���!");
	}
	else {
		printf("��Ÿ���ڿ���!");
	}
	// ==============================

	return 0;
}
#endif



// switch ������ ������� ����� p.251
#if 1
int main() {
	char op;
	int x, y, result = 0;

	printf("������ �Է��Ͻÿ� (��: 2+5) : \n >>");

	// ==================================================
	scanf("%d %c %d", &x, &op, &y);

	switch (op) {
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;
		default:
			printf("�������� �ʴ� ������ �Դϴ�.\n");
			break;

	}
	printf("%d %c %d = %d", x, op, y, result);

	// ==================================================
	return 0;
}
#endif


// switch ������ ������� ����� p.251
#if 1
int main() {
	char op;
	int x, y, result = 0;

	printf("������ �Է��Ͻÿ� (��: 2+5) : \n >>");

	// ==================================================
	scanf("%d %c %d", &x, &op, &y);

	switch (op) {
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;
		default:
			printf("�������� �ʴ� ������ �Դϴ�.\n");
			break;

	}
	printf("%d %c %d = %d", x, op, y, result);

	// ==================================================
	return 0;
}
#endif