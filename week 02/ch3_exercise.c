/*
	============================================
	chapter3. C���α׷� ������� - EXERCISE
	2022-03-11
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS



// 07] inch�� mm�� ��ȯ�ϴ� ���α׷�
#if 0
#include <stdio.h>

int main(void) {
	float inch, mm;
	printf("��ġ ������ �Է�:");
	scanf("%f", &inch);
	mm = inch * 25.4;
	printf("%f ��ġ = %f mm", inch, mm);

	return 0;

}
#endif


// 08] �ΰ��� ������ �޾� ������ �Ͽ� ���
#if 0

#include <stdio.h>

int main(void) {
	int x;
	int y;
	int prod;

	scanf("%d", &x);
	scanf("%d", &y);

	prod = x * y;

	printf("������ ��� = %d", prod);


	return 0;
}
#endif



// 09] printf ȭ�� ��� ����
#if 0
#include <stdio.h>

int main(void) {

	int x = 10;
	int y = 20;

	printf("It's never too late.\n It never rains but it pours");

	printf("%d", x);

	printf("%d", x + y);

	printf("%d + %d = %d", x, y, x + y);

	printf("%d * %d = %d", x, y, x * y);

	printf("*\n**\n***\n****\n");


	return 0;
}
#endif