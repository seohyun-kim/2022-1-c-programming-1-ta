#include <stdio.h>

int main() {

	int a = 10, b = 20;
	printf("전 ] a = %d  | b = %d\n", a, b); // 10 20

	// ===============================
	// 포인터 변수 선언

	int* pa = &a;
	int* pb = &b;

	int temp = *pa;

	// 포인터 변수를 이용해서 a와 b의 값을 서로 바꾸기
	*pa = *pb;
	*pb = temp;


	// ===============================
	printf("후 ] a = %d  | b = %d\n", a, b); // 20 10


	return 0;
}
