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
// �ܾ� ���	�޸� �Ҵ�? �׷� ������ �������� ����
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
	char a[50];		// �ܾ� �������� �����ϰ� ���� �ܾ�
	char b[50];		// �츮�� ���簡�� �ܾ�
	char cmp[50];	// ���� ������ b�� ���� ������ b �񱳿�
	char c;		// ���ĺ� �Է�
	char list[26] = { 0, };	// ���ĺ� �ߺ� �񱳿�
	int x = 0;	// �ߺ� �񱳿�
	int t = 0;	// �ߺ� �񱳿�
	char s = 0;	// ���� ����

	srand(time(0));

	start_message();	// ���� �޼���

	s = _getch();	// '����'�� ���� %d ���� %c��

	strcpy(a, dict(s));

	strcpy(b, a);

	system("cls");
	
	printf("\n\n");

	for (int i = 0; i < strlen(b); i++)	// b�� �����ؼ� �ʱ�ȭ
	{
		if (b[i] != ' ')
		{
			b[i] = '_';
		}
	}

	for (int j = 1; j < 11; j++)	// 10���� ��ȸ�� �־���
	{

		printf("���� ���� ��� : %d\n\n", 11 - j);
		hangman_img(j - 1);		// hangman �׸� �׸��� �Լ�

		printf("%s\n", b);	// ������ھ� ó���� ���ڿ�

		printf("���ĺ��� �Է����ּ���.\n");
		c = _getch();	// c�� ���ĺ� �Է¹ޱ�

		system("cls");

		if (isalpha(c) == 1)	// c �Է� ���� �빮���̸� �ҹ��ڷ� ����
		{
			c = tolower(c);
		}
		else if (isalpha(c) == 0)	// c �Է� ���� ���ĺ��� �ƴϸ� �ٽ�
		{
			printf("���� ����� ���ĺ� : ");
			for (int i = 0; i < t; i++)		// ���� ����� ���ĺ� ���
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
			printf("���ĺ��� �Է����ּ���.\n");
			j--;
			continue;
		}

		for (int i = 0; i < strlen(list); i++)	// ���ĺ��� �ߺ��� ��� �ٽ�
		{
			if (list[i] == c)
			{
				printf("�̹� ����� ���ĺ��Դϴ�.\n");
				x = 1;
				break;
			}
		}

		if (x == 1)
		{
			printf("���� ����� ���ĺ� : ");
			for (int i = 0; i < t; i++)		// ���� ����� ���ĺ� ���
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

		list[t] = c;	// list�� ���ĺ� ���� ; �ҹ��ڷ� ����
		t++;

		printf("\n���� ����� ���ĺ� : ");
		for (int i = 0; i < t; i++)		// ���� ����� ���ĺ� ���
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

		strcpy(cmp, b);		// �񱳱��� ����� ��ȸ ������ ����

		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] == c)
			{
				b[i] = c;
			}
		}

		if (strcmp(b, cmp) != 0)
		{
			j--;	// ���߸� ��ȸ�� ��������
		}

		if (strcmp(a, b) == 0)	// ��ȸ ���� ���� �� ���
		{
			system("cls");
			happy_hangman();	// �����ϴ� ���
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("      ��                           ��       \n");
			printf("           Hangman�� ���ϼ̱���!            \n");
			printf("               �����մϴ�!!!                \n");
			printf("      ��                           ��       \n");
			break;
		}
		else if (j == 10)	// ��ȸ�� �� ������� �� ���
		{
			system("cls");
			die_hangman();	// ���������ϴ� ���
			printf("\n����� �׿���...\n");
			printf("�� %s�� �𸥰���...?\n", a);
			printf("����� Hangman�� ���ΰž�\n");
			printf("������ ������\n");
			break;
		}
	}
	return 0;
}


// ���� �ܾ� ����
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
// ���� �޼���
void start_message() {
	printf("�� ������ Hangman�� ������ ��Ģ�Դϴ�.\n");
	printf("���� �ܾ� ������ �������� ���� �ܾ '_'���� ���ɴϴ�.\n");
	printf("�ڸ����� Ȯ���ϰ� �ܾ �����ּ���.\n");
	printf("�Է�â�� �� �� Ű���������� �̿��� ���ĺ��� ���ּ���.\n");
	printf("��ҹ��ڿ� �����ϰ� ������ �̿��� �Է��� ���� �ʽ��ϴ�.\n");
	printf("����� �� 10��\n");
	printf("Hangman�� ����ּ���.\n\n");
	printf("������ ���� �پ��� �ܾ �ֽ��ϴ�.\n");
	printf("������ ������ ����ּ���.\n");
	printf("fruit�� 1, sport�� 2, country�� 3, cocktail�� 4\n");
	printf("�� �ܴ� �����ϰ� ������ ���õ˴ϴ�.\n");
}
// Hangman �׸���
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
	printf("����������                          \n");
}
void hangman_img_2() {
	printf("                                            \n");
	printf("                                            \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_3() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_4() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_5() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_6() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_7() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ���                \n");
	printf("        ��            ��  ��                \n");
	printf("        ��          ��    ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_8() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ��  ��  ��            \n");
	printf("        ��          ��    ��    ��          \n");
	printf("        ��                ��                \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_9() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ��  ��  ��            \n");
	printf("        ��          ��    ��    ��          \n");
	printf("        ��                ��                \n");
	printf("        ��              ��                  \n");
	printf("        ��            ��                    \n");
	printf("        ��          ��                      \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void hangman_img_10() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ��  ��  ��            \n");
	printf("        ��          ��    ��    ��          \n");
	printf("        ��                ��                \n");
	printf("        ��              ��  ��              \n");
	printf("        ��            ��      ��            \n");
	printf("        ��          ��          ��          \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
// ���ǿ���
void happy_hangman() {
	happy_hangman_1();
	Sleep(300); // ms ����
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
	printf("                     ��                     \n");
	printf("                   ����                   \n");
	printf("                 ������                 \n");
	printf("                   ����                   \n");
	printf("                     ��                     \n");
	printf("                   ����                   \n");
	printf("                 ��  ��  ��                 \n");
	printf("               ��    ��    ��               \n");
	printf("                     ��                     \n");
	printf("                   ��  ��                   \n");
	printf("                 ��      ��                 \n");
	printf("               ��          ��               \n");
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
	printf("                     ��                     \n");
	printf("                   ����                   \n");
	printf("                 ������                 \n");
	printf("                   ����                   \n");
	printf("                     ��                     \n");
	printf("                   ����                   \n");
	printf("               ���  ��  ���               \n");
	printf("                     ��                     \n");
	printf("                     ��                     \n");
	printf("                   ��  ��                   \n");
	printf("                 ��      ��                 \n");
	printf("               ��          ��               \n");
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
	printf("                     ��                     \n");
	printf("                   ����                   \n");
	printf("                 ������                 \n");
	printf("                   ����                   \n");
	printf("               ���  ��  ���               \n");
	printf("                   ����                   \n");
	printf("                     ��                     \n");
	printf("                     ��                     \n");
	printf("                     ��                     \n");
	printf("                   ��  ��                   \n");
	printf("                 ��      ��                 \n");
	printf("               ��          ��               \n");
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
	printf("                     ��                     \n");
	printf("                   ����                   \n");
	printf("                 ������                 \n");
	printf("               ��  ����  ��               \n");
	printf("                 ��  ��  ��                 \n");
	printf("                   ����                   \n");
	printf("                     ��                     \n");
	printf("                     ��                     \n");
	printf("                     ��                     \n");
	printf("                   ��  ��                   \n");
	printf("                 ��      ��                 \n");
	printf("               ��          ��               \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
	printf("                                            \n");
}
// ���忣��
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
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ��  ��  ��            \n");
	printf("        ��          ��    ��    ��          \n");
	printf("        ��                ��                \n");
	printf("        ��              ��  ��              \n");
	printf("        ��            ��      ��            \n");
	printf("        ��          ��          ��          \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void die_hangman_2() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ��  ��  ��            \n");
	printf("        ��            ��  ��  ��            \n");
	printf("        ��                ��                \n");
	printf("        ��              ��  ��              \n");
	printf("        ��            ��      ��            \n");
	printf("        ��            ��      ��          \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void die_hangman_3() {
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��              ����              \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��              ��  ��              \n");
	printf("        ��              ��  ��              \n");
	printf("        ��              ��  ��              \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}
void die_hangman_4() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("                                            \n");
	printf("    ��������������              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��              ����              \n");
	printf("        ��            ������            \n");
	printf("        ��              ����              \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��                ��                \n");
	printf("        ��               ���              \n");
	printf("        ��               ���              \n");
	printf("        ��               ���              \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("        ��                                  \n");
	printf("����������                          \n");
}