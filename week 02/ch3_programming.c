/*
	============================================
	chapter3. C���α׷� ������� - PROGRAMMING
	2022-03-11
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS



// 01] ������ �Ǽ��� �Է¹��� ��, �հ�� ����� ����Ͽ� ���
#if 0
#include <stdio.h>

int main(void) {
	float a, b, c;

	printf("�Ǽ��� �Է��Ͻÿ�: ");
	scanf("%f", &a);

	printf("�Ǽ��� �Է��Ͻÿ�: ");
	scanf("%f", &b);

	printf("�Ǽ��� �Է��Ͻÿ�: ");
	scanf("%f", &c);

	printf("���� %f�̰� ����� %f�Դϴ�.", a + b + c, (a + b + c) / 3);

	return 0;

}
#endif


// 02] ���� -> ���� ȯ�� ���α׷�
//	 ������ �Է¹޾� ������ �����ϰ�, 1609�� ���� ���ͷ� ��ȯ
#if 0
#include <stdio.h>

int main(void) {

	float mile, meter;

	scanf("%f", &mile);

	meter = mile * 1609;

	printf("%f������ %f���� �Դϴ�.", mile, meter);

	return 0;

}
#endif


// 03] �ﰢ���� ���̿� �غ��� �޾� ���̸� ����Ͽ� ���(��� �Ǽ�)
#if 0
#include <stdio.h>

int main(void) {

	float base, height, area;

	printf("�ﰢ���� �غ�: ");
	scanf("%f", &base);

	printf("�ﰢ���� ����: ");
	scanf("%f", &height);

	area = 0.5 * height * base;

	printf("�ﰢ���� ����: %f",area );


	return 0;

}
#endif


// 04] ȭ���µ��� �޾� �����µ��� ȯ���Ͽ� ��� (�Ǽ���)
//	   �����µ� = (5/9)*(ȭ���µ� - 32)
#if 0
#include <stdio.h>

int main(void) {

	float F, C;

	printf("ȭ������ �Է��Ͻÿ�: ");
	scanf("%f", &F);

	C = (5.0 / 9.0) * (F - 32);

	printf("�������� %f�� �Դϴ�.", C);
	
	return 0;

}
#endif



// 05] ���׽� ��� ���α׷�
//	   3* X^2 + 7*x + 11
//	   x���� �Ǽ�, ����ڿ��� �Է¹���
#if 0
#include <stdio.h>

int main(void) {

	float x, result;

	scanf("%f", &x);

	result = 3 * x * x + 7 * x + 11;


	printf("���׽��� ���� %f �Դϴ�.", result);

	return 0;

}
#endif




// 06] �޿����� ������ ��� (���� �߷��� 17%)

#if 1
#include <stdio.h>

int main(void) {

	float weightOnEarth, weightOnMoon;

	scanf("%f", &weightOnEarth);

	weightOnMoon = 0.17 * weightOnEarth;

	printf("�޿����� �����Դ� %f �Դϴ�.", weightOnMoon);

	return 0;

}
#endif