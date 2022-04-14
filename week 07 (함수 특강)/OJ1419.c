#include <stdio.h>

int func(int a, int b)
{	
	/* 이 안을 채워 넣으시오 */
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