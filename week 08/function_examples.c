#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// �� �� ū ���� �����ϴ� �Լ�
int big(int x, int y) {
	return (x > y) ? x : y;
}

// �� �� ���� ū ���� �����ϴ� �Լ�
int bigger(int x, int y, int z) {
	int max = (x > y) ? x : y;
	max = (max > z) ? max : z;
	return max;
}

// �Ҽ����� �Ǵ��ϴ� �Լ�
int isPrime(int n) {
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) {
			return 0; // �Ҽ� �ƴ�
		}
	}
	return 1; // �Ҽ���
}




// ����
#if 0
#include <stdlib.h>
#include <time.h>

int main() {


	//printf("%d ", rand());

	srand((unsigned)time(NULL)); // �õ� �� ����

	printf("%d ", rand());
	return 0;
}
#endif




// ���� ������ ���� (p.344)
// coin_toss ��� ������ �����ϴ� �Լ��� �ۼ��Ѵ�.
// coin_toss 100 �� ȣ���Ͽ� ¦���� Ȧ���� Ƚ���� ���
// �����߻����� seed�� ����ð����� �Ѵ�.


#if 0
#include <stdlib.h>
#include <time.h>


int coin_toss(void) {
	return rand();
}
int main() {

	int even = 0, odd = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 100; i++)
	{
		(coin_toss() % 2 == 0) ? even++ : odd++;
	}

	printf("¦�� : %dȸ\nȦ�� : %dȸ", even, odd);

	return 0;
}

#endif




// �ұ�Ģ�ϰ� �� �׸��� (p.347)
#if 0
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int x, y, red, green, blue;

	HDC hdc;
	hdc = GetWindowDC(GetForegroundWindow());
	srand((unsigned)time(NULL));
	 
	for (int i = 0; i < 10000; i++)
	{
		x = rand() % 300;
		y = rand() % 300;

		red = rand() % 256;
		green = rand() % 256;
		blue = rand() % 256;

		SetPixel(hdc, x, y, RGB(red, green, blue));

	}
	_getch();
	return 0;
}

#endif




#if 0
// �����Լ� (p.349)
#include <math.h>

int main() {

	double result, value = 1.6;

	result = floor(value); // ����
	printf("floor : %lf\n", result);

	result = ceil(value); // �ø�
	printf("ceil : %lf\n", result);

	printf("���� : %f\n", fabs(-12.0)); //����

	printf("10�� 3���� %.0f\n", pow(10.0, 3.0)); // power

	printf("16�� ��������(��Ʈ 16) : %.0f\n", sqrt(16)); // ��Ʈ 16

	
	// �ﰢ�Լ�
	double pi = 3.141592;
	double x = pi / 2;
	printf("sin(%f) : %f\n", x, sin(x));
	printf("cos(%f) : %f\n", x, cos(x));
	printf("tan(%f) : %f\n", x, tan(x));


	return 0;
}
#endif



#if 0
#include <stdlib.h>

int main()
{
	system("dir"); // dir ��ɾ� ����
	printf("�ƹ�Ű�� ġ����\n");

	_getch();
	system("cls"); // ȭ���� ����

	return 0;
}
#endif




