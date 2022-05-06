#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



#if 0
// 전역변수 , 지역변수
// auto, static, volatile, register, extern

int x = 10; // 전역변수(global)

void abc() {
	static int count = 0; // static 변수는 이전의 값 유지
	count++;
	printf("count : %d", count);
}


int main() {
	int a; // 지역변수(local)
	int x = 20; // 변수 이름 같으면 로컬변수 우선
	printf("%d", x);

	abc();
	abc();
	abc();
	abc();
	abc();

	volatile int n = 0; // volatile 변수는 최적화를 하지 않음

	for (int i = 0; i < 10; i++)
	{
		n = i;
	}

	return 0;
}
#endif


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








