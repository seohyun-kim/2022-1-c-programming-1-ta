#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �������� , ��������
// auto, static, volatile, extern




// ���丮���� ��ȯȣ��(Recursion)�� �غ���
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

	printf("%d! �� %d �Դϴ�.\n", n, factorial(n));

	return 0;
}


#endif



// 1~n ���� ���� ���ϴ� ���α׷� (1+2+3+ ... +n) 
// ��ȯȣ�� �̿�
// p. 411 ���α׷��� ���� 5��
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








