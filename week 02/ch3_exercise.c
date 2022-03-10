/*
	============================================
	chapter3. C프로그램 구성요소 - EXERCISE
	2022-03-11
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS



// 07] inch를 mm로 변환하는 프로그램
#if 0
#include <stdio.h>

int main(void) {
	float inch, mm;
	printf("인치 단위로 입력:");
	scanf("%f", &inch);
	mm = inch * 25.4;
	printf("%f 인치 = %f mm", inch, mm);

	return 0;

}
#endif


// 08] 두개의 정수를 받아 곱셈을 하여 출력
#if 0

#include <stdio.h>

int main(void) {
	int x;
	int y;
	int prod;

	scanf("%d", &x);
	scanf("%d", &y);

	prod = x * y;

	printf("곱셈의 결과 = %d", prod);


	return 0;
}
#endif



// 09] printf 화면 출력 내용
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