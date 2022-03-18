/*
	============================================
	chapter4. 변수와 자료형 - EXERCISE
	2022-03-18
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 02 . 자료형의 사이즈를 알아보자!
#if 0

int main() {
	printf("float의 사이즈는 : %d\n", sizeof(float)); //4
	printf("char의 사이즈는 : %d\n", sizeof(char)); //1
	printf("unsigned char의 사이즈는 : %d\n", sizeof(unsigned char)); //1
	printf("double의 사이즈는 : %d\n", sizeof(double)); //8
	printf("int의 사이즈는 : %d\n", sizeof(int)); //4
	printf("long의 사이즈는 : %d\n", sizeof(long)); //4
	printf("short의 사이즈는 : %d\n", sizeof(short)); //2

	return 0;
}

#endif


// 15. 코드 고치기
#if 0
int main() {
	int x = 0, y = 0;
	char grade = 'A';
	double rate = 0;
	float profit = 75.0;
	int salary = 2000000;

}
#endif


// 16. 출력 결과 살펴보기
#if 0
int main() {

	int x = 10;

	printf("8진수 = %o\n", x);  // 12
	printf("10진수 = %d\n", x); // 10
	printf("16진수 = %x\n", x); // a


	// ===================================

	int a = 100;
	char b = 'x';
	float c = 1.2345;

	printf("\a"); //경보를 울림
	printf("예제\t프로그램\n");
	printf("%d, %c, %f\n", a,b,c);

	return 0;

}

#endif
