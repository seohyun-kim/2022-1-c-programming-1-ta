#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 전역변수 , 지역변수
// auto, static, volatile, extern




// 팩토리얼을 순환호출(Recursion)로 해보기
#if 0

long factorial(int n) {

	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int main() {
	int n = 5;

	printf("%d! 은 %d 입니다.\n", n, factorial(n));

	return 0;
}


#endif



// 1~n 까지 합을 더하는 프로그램 (1+2+3+ ... +n) 
// 순환호출 이용
// p. 411 프로그래밍 문제 5번
#if 0
int sum(int n) {

	if (n <= 1) {
		return 1;
	}
	else {
		return n + sum(n - 1);
	}
	
}

int main() {

	int n = 10;

	printf("%d", sum(n));
	return 0;
}
#endif








