// =============================
// 2022-04-14 �Լ�Ư��(via Zoom)
// =============================

/* ����

- ���� �Լ����� return�� ���� ������ add�Լ� ������ ������ ���� �ǰ���?
  : "�Լ� ��"������ ��ȿ�� �������Դϴ�. main�Լ������� ������ �����ϴ�.

- �׷� �Լ� �տ��ִ� �ڷ����� ��ȯ�Ҷ� return�� �ڷ������� ��ȯ�Ǵ°ǰ���
  : return �ϴ� ���� �Ǵ� ���� �ڷ����� ������ �ִ� ���� �Լ� �̸� �տ� ���ǵ� �ڷ��� �Դϴ�.

- ���࿡ ������ double���� ������ ���� ��Ʃ������� int �� double�� �����ϰ� �����µ� int�� �ᵵ ���������?
  : �������� �־��� �ڷ����� ����ϼ���! ���α׷� ȯ�濡 ���� ������� �޶��� �� �ֽ��ϴ�.

- �׷� void ~(){} �� return�� �Ⱦ��� int ~(){}�� return �� ����ϴ°ǰ��� ??
  : void�� ��ȯ���� ���� ���� return �ڿ� ���� �����ŵ� �ǰ�, ��ȯ�Ǵ� ���� �ִٸ� �����ּž� �մϴ�.

*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>




#if 0

void print_hello(void); // �Լ��� ����


int add(int a, int b) {

	int result = a + b;

	return result;
}



int main(void) {


	// �Լ��� ȣ��
	//print_hello();
	//print_hello();

	int a = 10, b = 20;

	//scanf("%d %d", &a, &b);

	int x = add(a, b);


	printf("%d", add(a, b));


	return 0;
}



// �Լ��� ����
void print_hello(void) {

	printf("hello\n");

	return;
}


#endif





// for �� �����ð��� �ߴ� ���丮�� ������ �Լ��� ������!
// ���� �ϳ��� �Է¹޾� ���丮�� �� ����ϱ�
// n! = 1*2*3* ...* n
#if 0
int main() {

	int fact = 1;
	int n; // �Է¹��� ����

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}

	printf("%d!�� %d�Դϴ�.\n", n, fact);

	return 0;
}
#endif



// =====================================
// ���丮�� �Լ��� ������
// �Լ��� for���� ���� ������ ȣ���غ���
// �Լ��� �Է� ���ڸ� ������ �ຸ��
#if 0
int factorial(int p);



int main() {

	int n; // �Է¹��� ����
	//scanf("%d", &n);  //4

	int x = factorial(4);

	for (int i = 1; i < 5; i++)
	{
		printf("����� : %d\n", factorial(i));
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

