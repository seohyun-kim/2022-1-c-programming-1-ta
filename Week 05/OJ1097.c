/*
�¶��� ���� 1097: [����-����] 3�� ����� ���?
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1097
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n ; i++)
	{
		if (i % 3 == 0) {
			continue;
		}
		printf("%d ", i);
	}
	return 0;
}