#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <Windows.h>

const char* dict(int s);
void start_message();
void hangman_img(int a);
void hangman_img_0();
void hangman_img_1();
void hangman_img_2();
void hangman_img_3();
void hangman_img_4();
void hangman_img_5();
void hangman_img_6();
void hangman_img_7();
void hangman_img_8();
void hangman_img_9();
void hangman_img_10();
void happy_hangman();
void happy_hangman_1();
void happy_hangman_2();
void happy_hangman_3();
void happy_hangman_4();
void die_hangman();
void die_hangman_1();
void die_hangman_2();
void die_hangman_3();
void die_hangman_4();
// 단어 목록	메모리 할당? 그런 문제로 전역으로 선언
char fruit[][100] = {
	"persimmon", "kyoho grape", "guarana", "guava",
	"oriental melon", "water melon", "grape", "plum",
	"peach","avocado", "apple", "dragon fruit",
	"pear", "kiwi", "strawberry", "pomegranate",
	"tangerine", "fig", "jujube", "mandarin",
	"apricot", "grapefruit", "orange", "rime",
	"blueberry","strawberry", "cherry", "banana",
	"pineapple", "quince", "tomato", "cherry tomato",
	"shine muscat", "blackberry", "lemon", "mango"
};
char sport[][100] = {
"baseball", "softball", "football", "basketball",
"handball", "beach volleyball", "badminton", "table tennis",
"golf", "atheletics", "swimming", "marathon swimming",
"synchronized swimming", "diving", "water polo", "judo",
"karate", "boxing", "wrestling", "gymnastics artistic",
"gymnastics rhythmic", "archery", "fencing", "cycling",
"skateboard", "equestrian", "modern pentathlon", "shooting",
"triathlon", "sport climbing", "weightlifting", "taekwondo",
"trampoline", "surfing", "canoe", "sailing"
};
char country[][100] = {
	"ghana", "guam", "georgia", "greece", "antarctica",
	"republic of south africa", "nederland", "nepal", "niger", "korea",
	"danmark", "dominica", "germany", "laos", "republic of liberia",
	"russia", "lebanon", "romania", "libya", "malaysia",
	"mali", "mexico", "monaco", "united states of america", "mongolia",
	"malta", "holy see", "bangladesh", "viet nam", "belgium",
	"bolivia", "bhutan", "brazil", "saudi arabia", "senegal",
	"somalia", "sudan", "sweden", "switzerland", "spain",
	"syrian arab republic", "singapore", "afghanistan", "angola", "ecuador",
	"ethiopia", "yemen", "oman", "australia", "uzbekistan",
	"ukraine", "iraq", "egypt", "indonesia", "jamaica",
	"japan", "zambia", "taiwan", "china", "gibraltar",
	"zimbabwe", "czechia", "chile", "canada", "qatar",
	"cambodia", "colombia", "congo", "kuwait", "cook islands",
	"thailand", "turkey", "tunisia", "pakistan", "peru",
	"poland", "france", "finland", "philippines", "hungary",
	"hong kong", "heard island and mcdonald islands", "tonga", "togo", "cjibouti"
};
char cocktail[][100] = {
	"cosmopolitan", "martini", "rusian blue", "monkey brain",
	"jack cock", "silver bullet", "gintonic", "midori sour",
	"old fashioned", "sex on the beach", "angels kiss","june bug",
	"tequila sunrise", "malibu", "hot buttered rum", "screw driver",
	"sidecar", "singapore sling", "black velvet", "gin sour",
	"stinger", "orgasm", "gin fizz", "mangattan",
	"gibson", "gimlet", "mai tai", "pina colada",
	"cojito", "earthquake", "hurricane", "bacardi",
	"painkiller", "tequila sour", "margarita", "irish",
	"black russian", "bloody mary", "kamikaze", "gimlet"
};

int main() {
	char a[50];		// 단어 사전에서 랜덤하게 뽑힌 단어
	char b[50];		// 우리가 맞춰가는 단어
	char cmp[50];	// 이전 상태의 b와 현재 상태의 b 비교용
	char c;		// 알파벳 입력
	char list[26] = { 0, };	// 알파벳 중복 비교용
	int x = 0;	// 중복 비교용
	int t = 0;	// 중복 비교용
	char s = 0;	// 주제 선택

	srand(time(0));

	start_message();	// 시작 메세지

	s = _getch();	// '문자'를 받음 %d 말고 %c로

	strcpy(a, dict(s));

	strcpy(b, a);

	system("cls");
	
	printf("\n\n");

	for (int i = 0; i < strlen(b); i++)	// b로 복사해서 초기화
	{
		if (b[i] != ' ')
		{
			b[i] = '_';
		}
	}

	for (int j = 1; j < 11; j++)	// 10번의 기회가 주어짐
	{

		printf("현재 남은 목숨 : %d\n\n", 11 - j);
		hangman_img(j - 1);		// hangman 그림 그리는 함수

		printf("%s\n", b);	// 언더스코어 처리된 문자열

		printf("알파벳을 입력해주세요.\n");
		c = _getch();	// c에 알파벳 입력받기

		system("cls");

		if (isalpha(c) == 1)	// c 입력 값이 대문자이면 소문자로 변경
		{
			c = tolower(c);
		}
		else if (isalpha(c) == 0)	// c 입력 값이 알파벳이 아니면 다시
		{
			printf("현재 사용한 알파벳 : ");
			for (int i = 0; i < t; i++)		// 여태 사용한 알파벳 목록
			{
				printf("%c", list[i]);
				if (i != t - 1)
				{
					printf(", ");
				}
				else {
					break;
				}
			}
			printf("\n");
			printf("알파벳을 입력해주세요.\n");
			j--;
			continue;
		}

		for (int i = 0; i < strlen(list); i++)	// 알파벳이 중복일 경우 다시
		{
			if (list[i] == c)
			{
				printf("이미 사용한 알파벳입니다.\n");
				x = 1;
				break;
			}
		}

		if (x == 1)
		{
			printf("현재 사용한 알파벳 : ");
			for (int i = 0; i < t; i++)		// 여태 사용한 알파벳 목록
			{
				printf("%c", list[i]);
				if (i != t - 1)
				{
					printf(", ");
				}
				else {
					break;
				}
			}
			printf("\n");
			j--;
			x = 0;
			continue;
		}

		list[t] = c;	// list에 알파벳 저장 ; 소문자로 저장
		t++;

		printf("\n현재 사용한 알파벳 : ");
		for (int i = 0; i < t; i++)		// 여태 사용한 알파벳 목록
		{
			printf("%c", list[i]);
			if (i != t - 1)
			{
				printf(", ");
			}
			else {
				break;
			}
		}
		printf("\n");

		strcpy(cmp, b);		// 비교군을 만들어 기회 차감을 정함

		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] == c)
			{
				b[i] = c;
			}
		}

		if (strcmp(b, cmp) != 0)
		{
			j--;	// 맞추면 기회가 남아있음
		}

		if (strcmp(a, b) == 0)	// 기회 내에 성공 시 출력
		{
			system("cls");
			happy_hangman();	// 만세하는 행맨
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("      ┌                           ┐       \n");
			printf("           Hangman을 구하셨군요!            \n");
			printf("               축하합니다!!!                \n");
			printf("      └                           ┘       \n");
			break;
		}
		else if (j == 10)	// 기회를 다 사용했을 시 출력
		{
			system("cls");
			die_hangman();	// 교수형당하는 행맨
			printf("\n당신이 죽였어...\n");
			printf("왜 %s를 모른거지...?\n", a);
			printf("당신이 Hangman을 죽인거야\n");
			printf("더러운 살인자\n");
			break;
		}
	}
	return 0;
}


// 주제 단어 고르기
const char* dict(int s) {

	srand(time(0));

	while (1)
	{
		switch (s)
		{
		case '1':
			return fruit[rand() % 36];
			break;
		case '2':
			return sport[rand() % 36];
			break;
		case '3':
			return country[rand() % 85];
			break;
		case '4':
			return cocktail[rand() % 40];
			break;
		default:
			s = rand() % 4 + 1;
		}
	}

}
// 시작 메세지
void start_message() {
	printf("본 게임은 Hangman과 동일한 규칙입니다.\n");
	printf("영어 단어 맞히기 게임으로 맞힐 단어가 '_'으로 나옵니다.\n");
	printf("자리수를 확인하고 단어를 맞춰주세요.\n");
	printf("입력창이 뜬 후 키보드자판을 이용해 알파벳을 써주세요.\n");
	printf("대소문자와 무관하게 써지고 이외의 입력은 받지 않습니다.\n");
	printf("목숨은 총 10개\n");
	printf("Hangman을 살려주세요.\n\n");
	printf("주제에 따라 다양한 단어가 있습니다.\n");
	printf("적용할 주제를 골라주세요.\n");
	printf("fruit은 1, sport는 2, country는 3, cocktail은 4\n");
	printf("그 외는 랜덤하게 주제가 선택됩니다.\n");
}
// Hangman 그리기
void hangman_img(int a) {
	switch (a)
	{
	case 1:
		hangman_img_1();
		break;
	case 2:
		hangman_img_2();
		break;
	case 3:
		hangman_img_3();
		break;
	case 4:
		hangman_img_4();
		break;
	case 5:
		hangman_img_5();
		break;
	case 6:
		hangman_img_6();
		break;
	case 7:
		hangman_img_7();
		break;
	case 8:
		hangman_img_8();
		break;
	case 9:
		hangman_img_9();
		break;
	case 10:
		hangman_img_10();
		break;
	default:
		hangman_img_0();
		break;
	}
}
void hangman_img_0() {
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
}
void hangman_img_1() {
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_2() {
	printf("                                            \n");
	printf("                                            \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_3() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_4() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_5() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_6() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_7() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■                \n");
	printf("        ■            ■  ■                \n");
	printf("        ■          ■    ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_8() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■  ■  ■            \n");
	printf("        ■          ■    ■    ■          \n");
	printf("        ■                ■                \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_9() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■  ■  ■            \n");
	printf("        ■          ■    ■    ■          \n");
	printf("        ■                ■                \n");
	printf("        ■              ■                  \n");
	printf("        ■            ■                    \n");
	printf("        ■          ■                      \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void hangman_img_10() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■  ■  ■            \n");
	printf("        ■          ■    ■    ■          \n");
	printf("        ■                ■                \n");
	printf("        ■              ■  ■              \n");
	printf("        ■            ■      ■            \n");
	printf("        ■          ■          ■          \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
// 해피엔딩
void happy_hangman() {
	happy_hangman_1();
	Sleep(300); // ms 단위
	system("cls");
	happy_hangman_2();
	Sleep(300);
	system("cls");
	happy_hangman_3();
	Sleep(300);
	system("cls");
	happy_hangman_4();
}
void happy_hangman_1() {
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                     ■                     \n");
	printf("                   ■■■                   \n");
	printf("                 ■■■■■                 \n");
	printf("                   ■■■                   \n");
	printf("                     ■                     \n");
	printf("                   ■■■                   \n");
	printf("                 ■  ■  ■                 \n");
	printf("               ■    ■    ■               \n");
	printf("                     ■                     \n");
	printf("                   ■  ■                   \n");
	printf("                 ■      ■                 \n");
	printf("               ■          ■               \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
}
void happy_hangman_2() {
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                     ■                     \n");
	printf("                   ■■■                   \n");
	printf("                 ■■■■■                 \n");
	printf("                   ■■■                   \n");
	printf("                     ■                     \n");
	printf("                   ■■■                   \n");
	printf("               ■■  ■  ■■               \n");
	printf("                     ■                     \n");
	printf("                     ■                     \n");
	printf("                   ■  ■                   \n");
	printf("                 ■      ■                 \n");
	printf("               ■          ■               \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
}
void happy_hangman_3() {
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                     ■                     \n");
	printf("                   ■■■                   \n");
	printf("                 ■■■■■                 \n");
	printf("                   ■■■                   \n");
	printf("               ■■  ■  ■■               \n");
	printf("                   ■■■                   \n");
	printf("                     ■                     \n");
	printf("                     ■                     \n");
	printf("                     ■                     \n");
	printf("                   ■  ■                   \n");
	printf("                 ■      ■                 \n");
	printf("               ■          ■               \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
}
void happy_hangman_4() {
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                     ■                     \n");
	printf("                   ■■■                   \n");
	printf("                 ■■■■■                 \n");
	printf("               ■  ■■■  ■               \n");
	printf("                 ■  ■  ■                 \n");
	printf("                   ■■■                   \n");
	printf("                     ■                     \n");
	printf("                     ■                     \n");
	printf("                     ■                     \n");
	printf("                   ■  ■                   \n");
	printf("                 ■      ■                 \n");
	printf("               ■          ■               \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
}
// 새드엔딩
void die_hangman() {
	{
		die_hangman_1();
		Sleep(300);
		system("cls");
		die_hangman_2();
		Sleep(300);
		system("cls");
		die_hangman_3();
		Sleep(300);
		system("cls");
		die_hangman_4();
	}
}
void die_hangman_1() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■  ■  ■            \n");
	printf("        ■          ■    ■    ■          \n");
	printf("        ■                ■                \n");
	printf("        ■              ■  ■              \n");
	printf("        ■            ■      ■            \n");
	printf("        ■          ■          ■          \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void die_hangman_2() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■  ■  ■            \n");
	printf("        ■            ■  ■  ■            \n");
	printf("        ■                ■                \n");
	printf("        ■              ■  ■              \n");
	printf("        ■            ■      ■            \n");
	printf("        ■            ■      ■          \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void die_hangman_3() {
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■              ■■■              \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■              ■  ■              \n");
	printf("        ■              ■  ■              \n");
	printf("        ■              ■  ■              \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}
void die_hangman_4() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("                                            \n");
	printf("    ■■■■■■■■■■■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■              ■■■              \n");
	printf("        ■            ■■■■■            \n");
	printf("        ■              ■■■              \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■                ■                \n");
	printf("        ■               ■■              \n");
	printf("        ■               ■■              \n");
	printf("        ■               ■■              \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("        ■                                  \n");
	printf("■■■■■■■■■                          \n");
}