#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 둘 중 큰 수를 리턴하는 함수
int big(int x, int y) {
	return (x > y) ? x : y;
}

// 셋 중 가장 큰 수를 리턴하는 함수
int bigger(int x, int y, int z) {
	int max = (x > y) ? x : y;
	max = (max > z) ? max : z;
	return max;
}

// 소수인지 판단하는 함수
int isPrime(int n) {
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) {
			return 0; // 소수 아님
		}
	}
	return 1; // 소수임
}




// 난수
#if 0
#include <stdlib.h>
#include <time.h>

int main() {


	//printf("%d ", rand());

	srand((unsigned)time(NULL)); // 시드 값 설정

	printf("%d ", rand());
	return 0;
}
#endif




// 동전 던지기 게임 (p.344)
// coin_toss 라는 난수를 생성하는 함수를 작성한다.
// coin_toss 100 번 호출하여 짝수와 홀수의 횟수를 출력
// 난수발생기의 seed는 현재시각으로 한다.


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

	printf("짝수 : %d회\n홀수 : %d회", even, odd);

	return 0;
}

#endif




// 불규칙하게 점 그리기 (p.347)
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
// 수학함수 (p.349)
#include <math.h>

int main() {

	double result, value = 1.6;

	result = floor(value); // 내림
	printf("floor : %lf\n", result);

	result = ceil(value); // 올림
	printf("ceil : %lf\n", result);

	printf("절댓값 : %f\n", fabs(-12.0)); //절댓값

	printf("10의 3승은 %.0f\n", pow(10.0, 3.0)); // power

	printf("16의 제곱근은(루트 16) : %.0f\n", sqrt(16)); // 루트 16

	
	// 삼각함수
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
	system("dir"); // dir 명령어 실행
	printf("아무키나 치세요\n");

	_getch();
	system("cls"); // 화면을 지움

	return 0;
}
#endif




