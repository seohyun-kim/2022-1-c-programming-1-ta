/*
�¶��� ���� 1309��: �� ���� ���� �Է�
http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1309
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", & a, &b, &c);

    printf("%d %d %d", a % 2, b % 2, c % 2);
    return 0;
}