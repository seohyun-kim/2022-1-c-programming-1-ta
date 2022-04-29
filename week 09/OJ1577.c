// �¶��� ���� 1577 (�߰���� ����)
// "��ȯȣ��"�� Ǯ���
// http://eseoj.inu.ac.kr/JudgeOnline/problem.php?id=1577

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdio.h>

/*
	�Լ� myfibo��
	0 �Ǵ� ���� ���� int argument 1���� �Է����� �޾�,
	�ش� ��ġ�� fibonacci ���ڸ� ��ȯ.
	Fibonacci ������ �տ� ��ġ�� �� ���� ���� ���� ���� �ȴ�.
	0 ��° : 0
	1 ��° : 1
	2 ��° : 1
	3 ��° : 2
	4 ��° : 3
*/

int myfibo(int arg) {
	int result = 0;

	if (arg == 0) {
		return 0;
	}
	else if (arg == 1 || arg == 2) {
		return 1;
	}

	return myfibo(arg - 2) + myfibo(arg - 1);
}

//-------------  �Ʒ��δ� ��ġ�� ������ ----------

int main(void) {

	int a;
	scanf("%d", &a);

	printf("%d", myfibo(a));

	return 0;
}