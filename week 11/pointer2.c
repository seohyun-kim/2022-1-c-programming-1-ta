#include <stdio.h>

int main() {

	int a = 10;
	char c = 'A';

	printf("a�� ������ : %d\n", sizeof(a)); // 4
	printf("c�� ������ : %d\n", sizeof(c)); // 1

	int* pa = &a;
	char* pc = &c;

	printf("pa�� ������ : %d\n", sizeof(pa)); // 4 or 8  (����)
	printf("pc�� ������ : %d\n", sizeof(pc)); // 4 or 8
	// �ּ� ü�迡 ���� �ٸ�

	
	printf("pa : %d  | pa+1 : %d\n", pa, pa+1);  // 100 104
	printf("pc : %d  | pc+1 : %d\n", pc, pc + 1); // 200 201




	return 0;

}