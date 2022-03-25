/*
온라인 저지 1053: [문법-비교연산] 두 정수 입력받아 비교하기1
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1053
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d", a > b);
	//printf("%d",(a > b) ? 1: 0);
	//(a > b) ? printf("1") : printf("0");

	return 0;
}