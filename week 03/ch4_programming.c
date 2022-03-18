/*
	============================================
	chapter4. ������ �ڷ��� - PROGRAMMING
	2022-03-18
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 01. �ϳ��� �Ǽ��� �Է¹޾� �Ҽ��� ǥ������ ����ǥ�������� ���ÿ� ����ϴ� ���α׷� �ۼ�
#if 0
	int main() {
		float a;
		scanf("%f", &a); // �Ǽ� �Է� ����
		printf("�Ǽ� �������δ� : %f\n", a);
		printf("�Ǽ� �������δ� : %e\n", a);

		return 0;
	}
#endif


// 02. ������ 16������ �Է¹޾Ƽ� 8����, 10����, 16���� ���·� ����ϴ� ���α׷� �ۼ�
#if 0
	int main() {
		int a;
		scanf("%x", &a); // 16���� ���� �Է¹���

		printf("8�����δ� : %o\n", a);
		printf("10�����δ� : %d\n", a);
		printf("16�����δ� : %#x\n", a);

		return 0;
	}
#endif


// 03. int���� ����  x�� y�� ���� ���� ��ȯ�ϴ� ���α׷��� �ۼ�
// ������ ������ �ʿ��ϸ� �����ؼ� ���
// ���� x�� y�� 10,20�� ������ �ʱ�ȭ �϶�.
#if 0
	int main() {
		int x = 10, y = 20;
		int temp;

		printf("x=%d y=%d\n", x, y);

		temp = x;
		x = y;
		y = temp;

		printf("x=%d y=%d\n", x, y);
		return 0;
	}
#endif


// 04. ������ ���Ǹ� ���ϴ� ���α׷�
// double���� �Ǽ��� ����, �ʺ�, ���̸� �Է¹޾� ���Ǹ� ���
#if 0
	int main() {
		double d, w, h;
		scanf("%lf %lf %lf", &d, &w, &h);

		printf("������ ���Ǵ� : %lf\n", d*w*h);

		return 0;
	}
#endif


// 08. �ƽ�Ű �ڵ尪(����) �Է��ϸ� �ش� '����'�� ����ϴ� ���α׷��� �ۼ�
#if 0
	int main() {
		int ascii_num;
		scanf("%d", &ascii_num);
		printf("%c", (char*)ascii_num);
	}
#endif
