#include <stdio.h>

int func(int a, int b)
{	
	/* �� ���� ä�� �����ÿ� */
	int result = a + b;
	return result;
}

void main()
{
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);

	printf("%d", func(a, b) + func(a, b));
	return;
}