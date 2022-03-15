/*
온라인 저지 1308번: 두 개의 숫자를 입력받아 첫 번째 숫자에서 두 번째 숫자를 뺀 값을 출력
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1308
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", a-b);
    return 0;
}