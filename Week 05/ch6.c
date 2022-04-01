/*
	============================================
	chapter6. 조건문
	2022-04-01
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// 정수 하나를 입력받아 홀수와 짝수를 구별하는 프로그램 
// p.234
#if 0
int main() {
	int number;

	scanf("%d", &number);

	// ==============================
	if (number % 2 == 0) {
		printf("짝수입니다\n");
	}
	else {
		printf("홀수입니다.\n");
	}
	// ==============================

	return 0;
}
#endif




// 연속 if문 p.239
// 정수 타입의 성적을 입력받아 학점을 결정하는 프로그램
#if 0
int main() {
	int score;

	scanf("%d", &score);

	// ==============================
	if (score >= 90) {
		printf("당신의 학점은 A\n");
	}
	else if (score >= 80) {
		printf("당신의 학점은 B\n");
	}
	else {
		printf("아악 귀찮으니까 이 아래는 그냥 F받아!\n");
	}
	// ==============================

	return 0;
}
#endif



// 문자 분류 프로그램 p.240
// char 타입의 문자를 하나 입력받아 대문자, 소문자, 숫자, 기타문자로 구분하기
#if 0
int main() {
	char ch;

	scanf("%c", &ch);

	// ==============================
	if (ch >= 'A' && ch <= 'Z') {
		printf("대문자에오!");
	}
	else if (ch >= 'a' && ch <= 'z') {
		printf("소문자에오!");
	}
	else if (ch >= '0' && ch <= '9') {
		printf("숫자에오!");
	}
	else {
		printf("기타문자에오!");
	}
	// ==============================

	return 0;
}
#endif



// switch 문으로 산술계산기 만들기 p.251
#if 1
int main() {
	char op;
	int x, y, result = 0;

	printf("수식을 입력하시오 (예: 2+5) : \n >>");

	// ==================================================
	scanf("%d %c %d", &x, &op, &y);

	switch (op) {
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;
		default:
			printf("지원되지 않는 연산자 입니다.\n");
			break;

	}
	printf("%d %c %d = %d", x, op, y, result);

	// ==================================================
	return 0;
}
#endif


// switch 문으로 산술계산기 만들기 p.251
#if 1
int main() {
	char op;
	int x, y, result = 0;

	printf("수식을 입력하시오 (예: 2+5) : \n >>");

	// ==================================================
	scanf("%d %c %d", &x, &op, &y);

	switch (op) {
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
			break;
		case '/':
			result = x / y;
			break;
		default:
			printf("지원되지 않는 연산자 입니다.\n");
			break;

	}
	printf("%d %c %d = %d", x, op, y, result);

	// ==================================================
	return 0;
}
#endif