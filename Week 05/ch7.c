/*
	============================================
	chapter7. �ݺ���
	2022-04-01
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//  while ���� ������~
#if 0
int main() {
	int i = 0;

	while (i < 10) {
		printf("i�� %d!\n", i);
		i++;
	}

	return 0;
}
#endif




// �� ���� �Է¹޾� �ִ����� ã�� (p.276)
// ū ���� ���� �Էµȴٰ� �����Ѵ�!
#if 0
int main() {
	int x, y; //�Է¹��� �� �� ( x >= y ��� ����)
	int r;

	scanf("%d %d", &x, &y);

	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}

	printf("�ִ� ������� %d\n", x);
	return 0;
}
#endif


// do-while
#if 0
int main() {
	int i = 1000;

	do {
		//printf("�ϴ� �ѹ��� �������ش�!\n");
		printf("i�� ���� %d\n", i);
		i++;
	} while (i < 3);

	return 0;
}
#endif


// for ��
// ���� �ϳ��� �Է¹޾� ���丮�� �� ����ϱ�
// n! = 1*2*3* ...* n
#if 0
int main() {

	double fact = 1;
	int n; // �Է¹��� ����

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}

	printf("%d!�� %d�Դϴ�.\n", n, fact);

	return 0;
}
#endif


// break, continue
int main() {

	for (int i = 1; i < 10; i++)
	{
		if (i % 3 == 0) {
			printf("%d �� 3�� ����Դϴ�\n", i);
			//break;
			//continue;
		}
		printf("%d�� 3�ǹ���� �ƴմϴ�!\n", i);
	}
}