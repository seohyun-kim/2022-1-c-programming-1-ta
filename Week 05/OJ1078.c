/*
온라인 저지 1078: [문법-조건/선택실행구조] 달 입력 받아 계절 출력하기
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1078
*/

#define _CRT_SECURE_NO_WARNINGS

#if 1
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	switch (n) {
	case 3:
	case 4:
	case 5:
		printf("spring");
		break;

	case 6:
	case 7:
	case 8:
		printf("summer");
		break;

	case 9:
	case 10:
	case 11:
		printf("fall");
		break;

	case 12:
	case 1:
	case 2:
		printf("winter");
		break;

	}

	return 0;
}
#endif


//#include <stdio.h>
//
//int main() {
//	int n;
//	scanf("%d", &n);
//
//	if (n == 12 || n == 1 || n == 2) {
//		printf("winter");
//	}
//	else if (n == 3 || n == 4 || n == 5) {
//		printf("spring");
//	}
//	else if (n == 6 || n == 7 || n == 8) {
//		printf("summer");
//	}
//	else if (n == 9 || n == 10 || n == 11) {
//		printf("fall");
//	}
//
//	return 0;
//}