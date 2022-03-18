/*
온라인 저지 1020: [문법-입출력] 실수 한 개 입력받아 둘째 자리까지 출력하기
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1020
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	float input;
	scanf("%f", &input);
	printf("%.2f", input);

	return 0;
}