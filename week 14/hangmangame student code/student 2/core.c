#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>
#include <stdbool.h>

#define space 32
#define max_len 100
typedef unsigned int uint;
//콘솔에서 x,y로 커서위치를 변경
extern void gotoxy(int x, int y);
//1~10까지 단계별로 그림.
extern void draw(int n);
//메인 창을 띄운다. 
extern void init();
//도입 창을 띄운다.
extern void start();

int main() {
	//단어 선정에 쓰일 랜덤시드 설정
	srand(time(NULL));

	//시작 화면을 띄워줍니다.
	init();

	//스페이스가 입력될 때까지 대기
	while (_getch() != space) {
		printf(".");
	}
	system("cls");

	//게임 시작 화면
	//카테고리 선택을 하려다 우선 보류
	//안내문을 3초간 띄우고 게임 시작
	start();

	//파일에서 랜덤번째 국가를 가져옵니다.
	FILE* fp;
	fp = fopen("country2.txt", "rt");
	char answer[max_len] = { 0, };
	//총 255개의 데이터가 있음
	//각 국가는 줄바꿈으로 구분되어 적혀있다.
	uint cnt = rand() / 255 + 1;
	fgets(answer, max_len, fp);
	for (int i = 1; i < cnt; i++) {
		fgets(answer, max_len, fp);
	}
	fclose(fp);
	//한국어가 있는 답안. 게임이 끝나고 보여줄것.
	fp = fopen("country.txt", "rt");
	char answer_kr[max_len] = { 0, };
	fgets(answer_kr, max_len, fp);
	for (int i = 1; i < cnt; i++) {
		fgets(answer_kr, max_len, fp);
	}
	fclose(fp);

	system("cls");
	//대기중에 입력된 버퍼를 비워 오류를 방지한다.
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	//플레이어의 답안을 저장.
	char player[max_len] = { 0, };
	//적절한 위치에 단어의 정보를 띄운다.
	for (int i = 0; i < strlen(answer); i++) {
		if (isalpha(answer[i])) {
			answer[i] = tolower(answer[i]);
			player[i] = '_';
		}
		else {
			player[i] = answer[i];
		}
	}
	gotoxy(35, 10);
	printf("%s", player);

	//알파벳 중복입력 체크용 불 배열
	bool check[26] = { 0, };

	for (int i = 0; i < 10; i++) {
		gotoxy(0, 0);
		char c = _getch();
		//입력 검사
		while (!isalpha(c)) {
			c = _getch();
		}
		//중복 검사
		if (check[c - 'a']) { 
			i--;
			continue; 
		}
		check[c - 'a'] = true;
		gotoxy(35, 7);
		printf("입력한 알파벳:");
		gotoxy(35, 8);
		for (int i = 0; i < 26; i++) {
			if (check[i])
				printf("%c ", i + 'a');
		}
		char* cp = strchr(answer, c);
		if (cp != NULL) {
			while (cp != NULL) {
				player[cp - answer] = c;
				cp = strchr(cp + 1, c);
			}
			gotoxy(35, 10);
			printf("%s", player);
			if (strcmp(player, answer) == 0) {
				gotoxy(35, 12);
				printf("우승!! ");
				gotoxy(35, 13);
				printf("%s", answer_kr);
				gotoxy(0, 31);
				return 0;
			}
			i--;
		}
		else {
			draw(i + 1);
		}
	}

	draw(11);
	gotoxy(35, 12);
	printf("정답: %s", answer_kr);

	gotoxy(0, 31);
	return 0;
}