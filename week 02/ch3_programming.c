/*
	============================================
	chapter3. C프로그램 구성요소 - PROGRAMMING
	2022-03-11
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS



// 01] 세개의 실수를 입력받은 후, 합계와 평균을 계산하여 출력
#if 0
#include <stdio.h>

int main(void) {
	float a, b, c;

	printf("실수를 입력하시오: ");
	scanf("%f", &a);

	printf("실수를 입력하시오: ");
	scanf("%f", &b);

	printf("실수를 입력하시오: ");
	scanf("%f", &c);

	printf("합은 %f이고 평균은 %f입니다.", a + b + c, (a + b + c) / 3);

	return 0;

}
#endif


// 02] 마일 -> 미터 환상 프로그램
//	 마일을 입력받아 변수에 저장하고, 1609를 곱해 미터로 변환
#if 0
#include <stdio.h>

int main(void) {

	float mile, meter;

	scanf("%f", &mile);

	meter = mile * 1609;

	printf("%f마일은 %f미터 입니다.", mile, meter);

	return 0;

}
#endif


// 03] 삼각형의 높이와 밑변을 받아 넓이를 계산하여 출력(모두 실수)
#if 0
#include <stdio.h>

int main(void) {

	float base, height, area;

	printf("삼각형의 밑변: ");
	scanf("%f", &base);

	printf("삼각형의 높이: ");
	scanf("%f", &height);

	area = 0.5 * height * base;

	printf("삼각형의 넓이: %f",area );


	return 0;

}
#endif


// 04] 화씨온도를 받아 섭씨온도로 환산하여 출력 (실수형)
//	   섭씨온도 = (5/9)*(화씨온도 - 32)
#if 0
#include <stdio.h>

int main(void) {

	float F, C;

	printf("화씨값을 입력하시오: ");
	scanf("%f", &F);

	C = (5.0 / 9.0) * (F - 32);

	printf("섭씨값은 %f도 입니다.", C);
	
	return 0;

}
#endif



// 05] 다항식 계산 프로그램
//	   3* X^2 + 7*x + 11
//	   x값은 실수, 사용자에게 입력받음
#if 0
#include <stdio.h>

int main(void) {

	float x, result;

	scanf("%f", &x);

	result = 3 * x * x + 7 * x + 11;


	printf("다항식의 값은 %f 입니다.", result);

	return 0;

}
#endif




// 06] 달에서의 몸무게 계산 (지구 중력의 17%)

#if 1
#include <stdio.h>

int main(void) {

	float weightOnEarth, weightOnMoon;

	scanf("%f", &weightOnEarth);

	weightOnMoon = 0.17 * weightOnEarth;

	printf("달에서의 몸무게는 %f 입니다.", weightOnMoon);

	return 0;

}
#endif