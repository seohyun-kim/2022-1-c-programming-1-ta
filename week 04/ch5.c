/*
	============================================
	chapter5. 수식과 연산자
	2022-03-25
	=============================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#if 0
int main() {

	// 산술 연산자



	// 증감연산자
	int x = 10;
	int y = 20;

	y = ++x; // 증가 된 값이 y에 대입됨
	y = x++; // y에 대입 후 증가됨
	printf("x= %d  y=%d", x, y); 


}
#endif


// ===================================================================================
// 거스름돈 계산하기 p.180
// 편의점에서 물건을 구입하고 만원을 냈을 때, 지급해야할 거스름돈의 화폐와 동전 수를 계산하는 프로그램
// 1. 사용자로부터 물건 값을 입력받음(물건 값은 100원단위로 떨어진다고 가정)
// 2. 점원이 내주어야 할 오천원권, 천원권, 오백원짜리 동전, 백원짜리 동전의 갯수를 출력
#if 0
int main() {

	int price = 0;
	scanf("%d", &price);

	int change = 10000 - price; 

	printf("거슬러 줘야할 돈: %d\n", change);

	int c5000 = change / 5000; // 5000원권 갯수
	change = change % 5000; // 남은 잔돈

	int c1000 = change / 1000;
	change = change % 1000;

	int c500 = change / 500;
	change = change % 500;

	int c100 = change / 100;


	printf("5천원권 : %d장\n천원권 : %d장\n오백원 : %d개\n백원 : %d개", c5000, c1000, c500, c100);

	return 0;
}
#endif
// ======================================================================


// 관계연산자
#if 0
int main() {
	int x = 10, y = 20;

	printf("%d\n", x != y);

	return 0;
}
#endif


// 논리연산자
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
// 윤년판단
// 연도가 4로 나누어 떨어진다
// 100으로 나누어 떨어지는 연도는 제외
// 400으로 나누어 떨어지는 연도는 윤년임

#if 0
int main() {

	int year;
	scanf("%d", &year);

	printf("%d\n", (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));


	return 0;
}
#endif
// ===============================================



// 조건연산자(삼항연산자)
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



// 비트 연산자
#if 0
int main() {

	int x = 4; //00000100

	x = x << 1;

	printf("%d", x);


	return 0;
}
#endif




// ===================================
// 10진수를 2진수로 출력하기 (0~127 까지만 고려)
// 아직은 반복문 사용 안하고 노가다로~
// 힌트 : 비트 연산
#if 0
int main() {

	unsigned int x = 32;
	unsigned int mask = 1 << 7; // 10000000
	printf("10진수 : %d\n", x);

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
// XOR 암호화
#if 0
int main() {

	char data = 'a';
	char key = 0xff;

	char encrypted_data = data ^ key;

	printf("암호화된 문자 : %c\n", encrypted_data);

	char origin_data = encrypted_data ^ key;

	printf("원래 데이터 : %c", origin_data);

	return 0;
}
#endif

//=================================================================



// 형변환
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


