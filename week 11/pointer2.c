#include <stdio.h>

int main() {

	int a = 10;
	char c = 'A';

	printf("a의 사이즈 : %d\n", sizeof(a)); // 4
	printf("c의 사이즈 : %d\n", sizeof(c)); // 1

	int* pa = &a;
	char* pc = &c;

	printf("pa의 사이즈 : %d\n", sizeof(pa)); // 4 or 8  (같다)
	printf("pc의 사이즈 : %d\n", sizeof(pc)); // 4 or 8
	// 주소 체계에 따라서 다름

	
	printf("pa : %d  | pa+1 : %d\n", pa, pa+1);  // 100 104
	printf("pc : %d  | pc+1 : %d\n", pc, pc + 1); // 200 201




	return 0;

}