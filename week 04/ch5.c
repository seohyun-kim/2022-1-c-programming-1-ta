/*
	============================================
	chapter5. ���İ� ������
	2022-03-25
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#if 0
int main() {

	// ��� ������



	// ����������
	int x = 10;
	int y = 20;

	y = ++x; // ���� �� ���� y�� ���Ե�
	y = x++; // y�� ���� �� ������
	printf("x= %d  y=%d", x, y); 


}
#endif


// ===================================================================================
// �Ž����� ����ϱ� p.180
// ���������� ������ �����ϰ� ������ ���� ��, �����ؾ��� �Ž������� ȭ��� ���� ���� ����ϴ� ���α׷�
// 1. ����ڷκ��� ���� ���� �Է¹���(���� ���� 100�������� �������ٰ� ����)
// 2. ������ ���־�� �� ��õ����, õ����, �����¥�� ����, ���¥�� ������ ������ ���
#if 0
int main() {

	int price = 0;
	scanf("%d", &price);

	int change = 10000 - price; 

	printf("�Ž��� ����� ��: %d\n", change);

	int c5000 = change / 5000; // 5000���� ����
	change = change % 5000; // ���� �ܵ�

	int c1000 = change / 1000;
	change = change % 1000;

	int c500 = change / 500;
	change = change % 500;

	int c100 = change / 100;


	printf("5õ���� : %d��\nõ���� : %d��\n����� : %d��\n��� : %d��", c5000, c1000, c500, c100);

	return 0;
}
#endif
// ======================================================================


// ���迬����
#if 0
int main() {
	int x = 10, y = 20;

	printf("%d\n", x != y);

	return 0;
}
#endif


// ��������
#if 0
int main() {
	int x = 1, y = 0;

	//printf("%d", x &&y);


	int age, score;
	scanf("%d %d", &age, &score);

	printf("%d", (age >= 20) && (score > 80));


}
#endif



// =============================================
// �����Ǵ�
// ������ 4�� ������ ��������
// 100���� ������ �������� ������ ����
// 400���� ������ �������� ������ ������

#if 0
int main() {

	int year;
	scanf("%d", &year);

	printf("%d\n", (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));


	return 0;
}
#endif
// ===============================================



// ���ǿ�����(���׿�����)
#if 0
int main() {
	
	int bigger;
	int x = 10, y = 20;

	bigger = (x > y) ? x : y;

	printf("%d", bigger);


	int a = (2 * 3, 5 - 2);
	printf("%d", a);

	return 0;
}
#endif



// ��Ʈ ������
#if 0
int main() {

	int x = 4; //00000100

	x = x << 1;

	printf("%d", x);


	return 0;
}
#endif




// ===================================
// 10������ 2������ ����ϱ� (0~127 ������ ���)
// ������ �ݺ��� ��� ���ϰ� �밡�ٷ�~
// ��Ʈ : ��Ʈ ����
#if 0
int main() {

	unsigned int x = 32;
	unsigned int mask = 1 << 7; // 10000000
	printf("10���� : %d\n", x);

	((x & mask) == 0) ? printf("0") : printf("1"), mask >>= 1;
	((x & mask) == 0) ? printf("0") : printf("1"), mask >>= 1;
	((x & mask) == 0) ? printf("0") : printf("1"), mask >>= 1;
	((x & mask) == 0) ? printf("0") : printf("1"), mask >>= 1;
	((x & mask) == 0) ? printf("0") : printf("1"), mask >>= 1;
	((x & mask) == 0) ? printf("0") : printf("1"), mask >>= 1;
	((x & mask) == 0) ? printf("0") : printf("1"), mask >>= 1;
	((x & mask) == 0) ? printf("0") : printf("1");


	return 0;

}
#endif
//===============================================================




// =============================================================
// XOR ��ȣȭ
#if 0
int main() {

	char data = 'a';
	char key = 0xff;

	char encrypted_data = data ^ key;

	printf("��ȣȭ�� ���� : %c\n", encrypted_data);

	char origin_data = encrypted_data ^ key;

	printf("���� ������ : %c", origin_data);

	return 0;
}
#endif

//=================================================================



// ����ȯ
#if 0
int main() {

	double data;
	data= 5/ 4;

	//data = (double)5 / 4;
	//data = 5.0 / 4;
	//data = 5.0 / 4.0;
	printf("%f", data);

	return 0;
}
#endif


