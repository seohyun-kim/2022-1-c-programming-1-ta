/*
온라인 저지 1022: [문법-입출력] 시간 입력받아 그대로 출력하기
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1022
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int hour, minute;

	scanf("%d:%d", &hour, &minute);
	printf("%d:%d", hour, minute);

	return 0;
}