/*
	============================================
	chapter4. ������ �ڷ��� - EXERCISE
	2022-03-18
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 02 . �ڷ����� ����� �˾ƺ���!
#if 0

int main() {
	printf("float�� ������� : %d\n", sizeof(float)); //4
	printf("char�� ������� : %d\n", sizeof(char)); //1
	printf("unsigned char�� ������� : %d\n", sizeof(unsigned char)); //1
	printf("double�� ������� : %d\n", sizeof(double)); //8
	printf("int�� ������� : %d\n", sizeof(int)); //4
	printf("long�� ������� : %d\n", sizeof(long)); //4
	printf("short�� ������� : %d\n", sizeof(short)); //2

	return 0;
}

#endif


// 15. �ڵ� ��ġ��
#if 0
int main() {
	int x = 0, y = 0;
	char grade = 'A';
	double rate = 0;
	float profit = 75.0;
	int salary = 2000000;

}
#endif


// 16. ��� ��� ���캸��
#if 0
int main() {

	int x = 10;

	printf("8���� = %o\n", x);  // 12
	printf("10���� = %d\n", x); // 10
	printf("16���� = %x\n", x); // a


	// ===================================

	int a = 100;
	char b = 'x';
	float c = 1.2345;

	printf("\a"); //�溸�� �︲
	printf("����\t���α׷�\n");
	printf("%d, %c, %f\n", a,b,c);

	return 0;

}

#endif
