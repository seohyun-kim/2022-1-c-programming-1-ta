#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


enum gameMode { EXIT , COM, PLAYER};

//int 
//char 
//float
//struct student 형


// 구조체 정의
struct student { // 
	int id;      // 4byte
	char name[10];  // 
	int score;   // 4
}; // 세미콜론 필수


// 일회용 구조체(이름없는 구조체)
struct {
	char title[10] ;
	int price;
} x;//x는 변수ㅇ름


int main() {

	printf("hahahaha : %d\n", x.price);
	struct student A = { 1, "karina", 90 };

	// 구조체의 사이즈
	printf("%d", sizeof(struct student)); // 20 byte
	printf("%d", sizeof(A));

	// 구조체 변수 생성과 초기화
	struct student A = { 1, "karina", 90 };
	struct student B = { 2, "winter", 100 };
	struct student C = A;  // 구조체 통으로 복사

	if (A.id == C.id) {
		printf("같다!!");
	}

	if ((A.id == C.id) && (strcmp(A.name, C.name ) == 0)) {

	}


	// 구조체 멤버 접근
	printf("%d\n", A.score );
	printf("%s\n", A.name);


	// 구조체 멤버에 값 대입
	A.score = 50;
	//A.name = "ningning"; // XXXXX 오류남!!!!
	strcpy(A.name, "ningning");

	printf("%d\n", A.score);
	printf("%s\n", A.name);

	printf("C: %d\n", C.score);
	printf("C: %s\n", C.name);



	// 일회용 구조체
	strcpy(x.title, "ant");
	x.price = 10000;
	printf("%s %d", x.title, x.price);

	// 구조체 배열
	struct student classa[10];


	classa[0].id = 1;
	strcpy(classa[0].name, "gissle");

	classa[1].id = 2;

	enum gamemode g;
	int mode = EXIT;

	if (mode == EXIT) {
		// 게임종료
	}
	else if (mode == PLAYER) {
		// 2p모드
	}



	int arr[10];
	//(반환값의 형태) 함수이름(input 형태);
	//void* malloc(size);

	int* p = (int*)malloc(4*sizeof(int)); // 4*4
	// 4개짜리 int 형태의 배열같은 것을 만들게ㅆ다!!!

	//dddddd

	free(p);





	return 0;
}