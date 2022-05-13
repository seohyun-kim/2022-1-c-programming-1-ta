#include <stdio.h>

int main() {

	int a = 10;

	printf("%d\n", a);
	printf("%d\n", &a); // 100 번지

	int* p = NULL;

	p = &a; // 100번지
	printf("%d\n", p); // 100번지
	printf("%d\n", *p); // 10 (a랑 같더라!)
	printf("%d\n", &p); // 500번지
	// & - 주소 . * - 값

	a = 20;
	printf("%d\n", a); // 20 
	printf("%d\n", p); // 100번지
	printf("%d\n", *p); // 20


	*p = 50;
	printf("%d\n", a); // 50
	printf("%d\n", p); // 
	printf("%d\n", *p); // 


	// a = 50 , *p = 50
	// p만 이용해서 a의 값을 2배 시켜라
	// =================================
	*p = (*p) * 2;
	// ================================

	printf("2배 된 a의 값 : %d\n", a); // 100


	// ========================================


	a = 10;
	int b = 20;

	p = &b; //200

	printf("%d\n", *p); // 20

	b = 40;
	printf("%d\n", *p); // 40








	return 0;
}