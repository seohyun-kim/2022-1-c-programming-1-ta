// =============================
// 2022-04-14 함수특강(via Zoom)
// =============================

/* 질문

- 위에 함수에서 return을 주지 않으면 add함수 내에는 정보가 없는 건가요?
  : "함수 내"에서만 유효한 정보들입니다. main함수에서는 정보가 없습니다.

- 그럼 함수 앞에있는 자료형은 반환할때 return의 자료형으로 반환되는건가요
  : return 하는 변수 또는 값의 자료형을 지정해 주는 것이 함수 이름 앞에 정의된 자료형 입니다.

- 만약에 저지에 double형이 나오면 지금 스튜디오에서 int 와 double이 동일하게 나오는데 int로 써도 상관없나요?
  : 저지에서 주어진 자료형을 사용하세요! 프로그램 환경에 따라 사이즈는 달라질 수 있습니다.

- 그럼 void ~(){} 은 return을 안쓰고 int ~(){}은 return 을 써야하는건가요 ??
  : void로 반환값이 없는 경우는 return 뒤에 적지 않으셔도 되고, 반환되는 값이 있다면 적어주셔야 합니다.

*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>




#if 0

void print_hello(void); // 함수의 선언


int add(int a, int b) {

	int result = a + b;

	return result;
}



int main(void) {


	// 함수의 호출
	//print_hello();
	//print_hello();

	int a = 10, b = 20;

	//scanf("%d %d", &a, &b);

	int x = add(a, b);


	printf("%d", add(a, b));


	return 0;
}



// 함수를 정의
void print_hello(void) {

	printf("hello\n");

	return;
}


#endif





// for 문 수업시간에 했던 팩토리얼 문제를 함수로 만들어보자!
// 정수 하나를 입력받아 팩토리얼 값 계산하기
// n! = 1*2*3* ...* n
#if 0
int main() {

	int fact = 1;
	int n; // 입력받을 정수

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}

	printf("%d!은 %d입니다.\n", n, fact);

	return 0;
}
#endif



// =====================================
// 팩토리얼 함수를 만들어보자
// 함수를 for문을 통해 여러번 호출해보자
// 함수의 입력 인자를 변수로 줘보자
#if 0
int factorial(int p);



int main() {

	int n; // 입력받을 정수
	//scanf("%d", &n);  //4

	int x = factorial(4);

	for (int i = 1; i < 5; i++)
	{
		printf("결과는 : %d\n", factorial(i));
	}


	return 0;
}


int factorial(int p) {
	int fact = 1;
	for (int i = 1; i <= p; i++)
	{
		fact = fact * i;
	}
	return fact;
}

#endif

