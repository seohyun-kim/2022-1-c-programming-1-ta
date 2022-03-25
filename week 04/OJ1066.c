/*
온라인 저지 1066: [문법-비트단위논리연산] 비트단위로 and 하여 출력하기
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1066
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", a & b);
	return 0;
}