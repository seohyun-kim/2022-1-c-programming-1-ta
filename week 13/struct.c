#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


enum gameMode { EXIT , COM, PLAYER};

//int 
//char 
//float
//struct student ��


// ����ü ����
struct student { // 
	int id;      // 4byte
	char name[10];  // 
	int score;   // 4
}; // �����ݷ� �ʼ�


// ��ȸ�� ����ü(�̸����� ����ü)
struct {
	char title[10] ;
	int price;
} x;//x�� ��������


int main() {

	printf("hahahaha : %d\n", x.price);
	struct student A = { 1, "karina", 90 };

	// ����ü�� ������
	printf("%d", sizeof(struct student)); // 20 byte
	printf("%d", sizeof(A));

	// ����ü ���� ������ �ʱ�ȭ
	struct student A = { 1, "karina", 90 };
	struct student B = { 2, "winter", 100 };
	struct student C = A;  // ����ü ������ ����

	if (A.id == C.id) {
		printf("����!!");
	}

	if ((A.id == C.id) && (strcmp(A.name, C.name ) == 0)) {

	}


	// ����ü ��� ����
	printf("%d\n", A.score );
	printf("%s\n", A.name);


	// ����ü ����� �� ����
	A.score = 50;
	//A.name = "ningning"; // XXXXX ������!!!!
	strcpy(A.name, "ningning");

	printf("%d\n", A.score);
	printf("%s\n", A.name);

	printf("C: %d\n", C.score);
	printf("C: %s\n", C.name);



	// ��ȸ�� ����ü
	strcpy(x.title, "ant");
	x.price = 10000;
	printf("%s %d", x.title, x.price);

	// ����ü �迭
	struct student classa[10];


	classa[0].id = 1;
	strcpy(classa[0].name, "gissle");

	classa[1].id = 2;

	enum gamemode g;
	int mode = EXIT;

	if (mode == EXIT) {
		// ��������
	}
	else if (mode == PLAYER) {
		// 2p���
	}



	int arr[10];
	//(��ȯ���� ����) �Լ��̸�(input ����);
	//void* malloc(size);

	int* p = (int*)malloc(4*sizeof(int)); // 4*4
	// 4��¥�� int ������ �迭���� ���� ����Ԥ���!!!

	//dddddd

	free(p);





	return 0;
}