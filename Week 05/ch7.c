/*
	============================================
	chapter7. 반복문
	2022-04-01
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//  while 에서 더망쳐~
#if 0
int main() {
	int i = 0;

	while (i < 10) {
		printf("i는 %d!\n", i);
		i++;
	}

	return 0;
}
#endif




// 두 수를 입력받아 최대공약수 찾기 (p.276)
// 큰 수가 먼저 입력된다고 가정한다!
#if 0
int main() {
	int x, y; //입력받을 두 수 ( x >= y 라고 가정)
	int r;

	scanf("%d %d", &x, &y);

	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}

	printf("최대 공약수는 %d\n", x);
	return 0;
}
#endif


// do-while
#if 0
int main() {
	int i = 1000;

	do {
		//printf("일단 한번은 실행해준다!\n");
		printf("i의 값은 %d\n", i);
		i++;
	} while (i < 3);

	return 0;
}
#endif


// for 문
// 정수 하나를 입력받아 팩토리얼 값 계산하기
// n! = 1*2*3* ...* n
#if 0
int main() {

	double fact = 1;
	int n; // 입력받을 정수

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}

	printf("%d!은 %d입니다.\n", n, fact);

	return 0;
}
#endif


// break, continue
int main() {

	for (int i = 1; i < 10; i++)
	{
		if (i % 3 == 0) {
			printf("%d 는 3의 배수입니다\n", i);
			//break;
			//continue;
		}
		printf("%d는 3의배수가 아닙니다!\n", i);
	}
}