#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void word_select(char num, char word[]);
void game(char word[]);
void loading(void);
void win(void);

int main() {

	char num = 0;
	char word[51] = "";
	char start = 'a';

	printf(">-------W==oOo==W-------<\n\n");
	printf("   >--<| HANGMAN |>--<\n\n\t게임시작(Y)\n\t게임종료(N)\n\n");
	printf(">-------M==oOo==M-------<\n\n");

	start = _getch();

	if (start == 'y') {
		system("cls");

		printf(">-------<==oOo==>-------<\n\n");
		printf("  카테고리를 선택하세요\n\n\t1. 국가\n\t2. 음식\n\n");
		printf(">-------<==oOo==>-------<\n\n");

		num = _getch();
		loading();
		word_select(num, word);
		game(word);

	}
	else {
		system("cls");
		printf(">-------<==oOo==>-------<\n\n");
		printf("    게임을 종료합니다.\n\n");
		printf(">-------<==oOo==>-------<\n\n");
		Sleep(1000);
		return 0;
	}

	return 0;
 }

void game(char word[]) {
	int len = strlen(word); // 답의 길이
	char ans_word[100] = "";
	int life = 10; // 목슴 10개
	char A; // 입력받는 알파벳
	char con[] = "bcdfghjklmnpqrstvwxyz";
	char vow[] = "aeiou";
	int z = 0;
	int cnt = 0;
	int l = life;


	system("cls");
	


	char draw[20][10] = {" "}; // 그림

	for (int i = 0; i < 20; i++) { // 그림 그림
		for (int j = 0; j < 10; j++) {
			draw[i][j] = ' ';
		}
		printf("\n");
	}

	strcpy(ans_word, word); // ans_word에 word의 단어를 붙여넣음

	for (int i = 0; i < len; i++) { // 정답을 ans_word에 언더스코어로 저장
		if (word[i] == ' ') {
			ans_word[i] = ' ';
		}
		else {
			ans_word[i] = '_';
		}
	}

	for (l = 10; l > 0; l--) { // 목숨 10개

		system("cls");

		printf(">---------M---------<>>-o0o-<<>----------M---------<\n");
		printf("                      <-Y^Y->\n");

		if (l > 10) {
			l = 10;
		}

		if (l == 10) {
			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 9) {

			for (int f = 2; f < 8; f++) {
				draw[17][f] == 'm';
			}

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 8) {

			for (int s = 4; s < 16; s++) {
				draw[s][2] = 'l';
			}

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 7) {

			for (int f = 2; f < 7; f++) {
				draw[4][f] = 'm';
			}

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 6) {

			for (int s = 5; s < 6; s++) {
				draw[s][6] = 'l';
			}

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 5) {

			draw[7][6] = '_';
			draw[8][5] = '(';
			draw[8][7] = ')';
			draw[9][6] = '-';

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 4) {

			draw[10][5] = '|';

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 3) {

			draw[10][7] = '|';

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 2) {

			draw[10][6] = '|';
			draw[11][6] = '|';

			for (int i = 0; i < 20; i++) { // 그림 그림
				for (int j = 0; j < 10; j++) {
					printf("%c", draw[i][j]);
				}
				printf("\n");
			}
		}
		else if (l == 1) {

		draw[12][5] = '|';

		for (int i = 0; i < 20; i++) { // 그림 그림
			for (int j = 0; j < 10; j++) {
				printf("%c", draw[i][j]);
			}
			printf("\n");
		}
		}
	
		int under = 0;
		under = (53 - len)/2;
		for (int m = 0; m < under; m++) {
			printf(" ");
		}

		for (int i = 0; i < len; i++) { // 언더스코어 출력
			printf("%c", ans_word[i]);
		}


		printf("\n");
		printf(" -=< ");
		for (int i = 0; i < strlen(con); i++) { // 자음 알파벳 출력
			printf("%c ", con[i]);
		}
		printf(" >=-");
		printf("\n");

		printf("                 -=< ");
		for (int i = 0; i < strlen(vow); i++) { // 모음 알파벳 출력
			printf("%c ", vow[i]);
		}
		printf(" >=-");
		printf("\n");

		printf("남은 기회: %d\n", l);

		printf("                      <--^-->\n");
		printf(">---------M---------<>>-o0o-<<>----------M---------<\n");

		printf("\n단어를 입력하세요: ");
		A = _getche();
		printf("\n");

		for (int n = 0; n < strlen(con); n++) {
			if (con[n] == A) {
				if (con[n] = '_') {
					printf("already use");
				}
			}
		}
		for (int n = 0; n < strlen(vow); n++) {
			if (vow[n] == A) {
				if (vow[n] = '_') {
					printf("already use");
				}
			}
		}

		for (int j = 0; j < len; j++) {
			if (A == word[j]) {
				l++;
				z = 1;
				ans_word[j] = A;
			}
		}
		if (z == 0) {
			z = 0;
			cnt++;
		}

		if (strcmp(ans_word, word) == 0) {
			win();
			break;
		}

		for (int n = 0; n < strlen(con); n++) {
			if (con[n] == A) {
				con[n] = '_';
			}
		}
		for (int n = 0; n < strlen(vow); n++) {
			if (vow[n] == A) {
				vow[n] = '_';
			}
		}


	}
	if (l == 0) {
		system("cls");

		printf("                      <--^-->\n");
		printf(">---------M---------<>>-o0o-<<>----------M---------<\n");
		printf("                      <-Y^Y->\n");

		draw[12][7] = '|';

		for (int i = 0; i < 20; i++) { // 그림 그림
			for (int j = 0; j < 10; j++) {
				printf("%c", draw[i][j]);
			}
			printf("\n");
		}
		printf("문제를 틀렸습니다....\n");
		printf("                      <--^-->\n");
		printf(">---------M---------<>>-o0o-<<>----------M---------<\n");
		printf("                      <-Y^Y->\n");
	}
}

void word_select(char num, char word[]) {
	srand(time(NULL));
	int N = (rand() % 10) + 1;
	if (num == '1') {
		if (N == 1) {
			strcpy(word, "ethiopia");
		}
		else if (N == 2) {
			strcpy(word, "australia");
		}
		else if (N == 3) {
			strcpy(word, "japan");
		}
		else if (N == 4) {
			strcpy(word, "france");
		}
		else if (N == 5) {
			strcpy(word, "egypt");
		}
		else if (N == 6) {
			strcpy(word, "sweden");
		}
		else if (N == 7) {
			strcpy(word, "chile");
		}
		else if (N == 8) {
			strcpy(word, "vietnam");
		}
		else if (N == 9) {
			strcpy(word, "pakistan");
		}
		else if (N == 10) {
			strcpy(word, "democratic republic of congo");
		}
	}
	else if (num == '2') {
		if (N == 1) {
			strcpy(word, "pasta");
		}
		else if (N == 2) {
			strcpy(word, "tteokbokki");
		}
		else if (N == 3) {
			strcpy(word, "chocolate");
		}
		else if (N == 4) {
			strcpy(word, "salad");
		}
		else if (N == 5) {
			strcpy(word, "gambas");
		}
		else if (N == 6) {
			strcpy(word, "roll cake");
		}
		else if (N == 7) {
			strcpy(word, "shanghai spicy chicken combo");
		}
		else if (N == 8) {
			strcpy(word, "french fries");
		}
		else if (N == 9) {
			strcpy(word, "buldalgbokkeummyeon");
		}
		else if (N == 10) {
			strcpy(word, "purrinkle");
		}
	}
}

void loading(void) {
	system("cls");
	printf(">-------<==oOo==>-------<\n\n\n");
	printf("            O\n\n\n");
	printf(">-------<==oOo==>-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("           { }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("          { L }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("         { L O }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("        { L O A }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("       { L O A D }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("      { L O A D I }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("     { L O A D I N }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("    { L O A D I N G }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("   { L O A D I N G . }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("  { L O A D I N G . . }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf(" { L O A D I N G . . . }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------<==oOo==>-------<\n\n\n");
	printf("            O\n\n\n");
	printf(">-------<==oOo==>-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("           { }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("          { L }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("         { L O }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("        { L O A }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("       { L O A D }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("      { L O A D I }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("     { L O A D I N }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("    { L O A D I N G }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("   { L O A D I N G . }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("  { L O A D I N G . . }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf(" { L O A D I N G . . . }\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(200);

	system("cls");
	printf(">-------W==oOo==W-------<\n\n\n");
	printf("     단어 선정 완료!\n\n\n");
	printf(">-------W==oOo==W-------<\n\n");

	Sleep(500);
}

void win(void) {
	system("cls");
	printf(">---I><I----NM=====<o0o>=====MN----I><I---<\n\n\n");
	printf("휴.. 죽을 뻔 했는걸\n\n");
	Sleep(2000);
	printf("단어를 맞춰준 덕분에 내가 살아남을 수 있었어.\n\n");
	Sleep(2000);
	printf("내 목숨을 구해준 은인! 너무 고마워\n\n");
	Sleep(2000);
	printf("앞으로 다른 사람들을 이렇게 구해주길 바랄게\n\n");
	Sleep(2000);
	printf("나의 영웅... God bay...\n\n");
	Sleep(3000);
	printf("- 게임이 끝났습니다 - \n\n\n");
	printf(">---I><I----NM=====<o0o>=====MN----I><I---<\n\n\n");
}