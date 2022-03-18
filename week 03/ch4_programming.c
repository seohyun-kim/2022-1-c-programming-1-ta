/*
	============================================
	chapter4. 변수와 자료형 - PROGRAMMING
	2022-03-18
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 01. 하나의 실수를 입력받아 소수점 표기방법과 지수표기방법으로 동시에 출력하는 프로그램 작성
#if 0
	int main() {
		float a;
		scanf("%f", &a); // 실수 입력 받음
		printf("실수 형식으로는 : %f\n", a);
		printf("실수 형식으로는 : %e\n", a);

		return 0;
	}
#endif


// 02. 정수를 16진수로 입력받아서 8진수, 10진수, 16진수 형태로 출력하는 프로그램 작성
#if 0
	int main() {
		int a;
		scanf("%x", &a); // 16진수 정수 입력받음

		printf("8진수로는 : %o\n", a);
		printf("10진수로는 : %d\n", a);
		printf("16진수로는 : %#x\n", a);

		return 0;
	}
#endif


// 03. int형의 변수  x와 y의 값을 서로 교환하는 프로그램을 작성
// 별도의 변수가 필요하면 정의해서 사용
// 변수 x와 y는 10,20의 값으로 초기화 하라.
#if 0
	int main() {
		int x = 10, y = 20;
		int temp;

		printf("x=%d y=%d\n", x, y);

		temp = x;
		x = y;
		y = temp;

		printf("x=%d y=%d\n", x, y);
		return 0;
	}
#endif


// 04. 상자의 부피를 구하는 프로그램
// double형의 실수로 길이, 너비, 높이를 입력받아 부피를 출력
#if 0
	int main() {
		double d, w, h;
		scanf("%lf %lf %lf", &d, &w, &h);

		printf("상자의 부피는 : %lf\n", d*w*h);

		return 0;
	}
#endif


// 08. 아스키 코드값(숫자) 입력하면 해당 '문자'를 출력하는 프로그램을 작성
#if 0
	int main() {
		int ascii_num;
		scanf("%d", &ascii_num);
		printf("%c", (char*)ascii_num);
	}
#endif
