#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

enum ColorType {
    Black,  	//0
    Dark_Blue,	//1
    Dark_Green,	//2
    Dark_Sky_Blue,    //3
    Dark_Red,  	//4
    Dark_Purple,	//5
    Dark_Yellow,	//6
    Gray,		//7
    Dark_Gray,	//8
    Blue,		//9
    Green,		//10
    Sky_Blue,	//11
    Red,		//12
    Purple,		//13
    Yellow,		//14
    White		//15
} COLOR;

#define MAXNUMWORDS 854
#define MAXLENWORD 30

void textcolor(int colorNum);
int load_RandomWord(char guess[]);
int select_menu(void);
void print_hangman(int tries);
void print_remainAlpha(int remainAlpha[]);
void print_currentGuess(char current[], char guess[]);
void hangman(void);

int main(void)
{
    int select;

    do
    {
        system("cls");
        select = select_menu();

        switch (select)
        {
        case(1):
            hangman();
            break;
        case(2):
            printf("\n���(Hangman)�� ������ �����ϴ� �ܾ ���簡�� �����Դϴ�.\n");
            printf("�ܾ ���� ���ĺ��� �����Ͽ� �Է��ϴ� ������� ����˴ϴ�.\n");
            printf("��ȸ�� �� 10���� �־�����, ���� ��� ��ȸ�� �������� �ʽ��ϴ�.\n");
            Sleep(1000);
            printf("\n5�� �� �޴� ȭ������ ���ư��ϴ�...");
            Sleep(5000);
            break;
        case(3):
            return 0;
            break;
        }
    } while (select == 2);

    return 0;
}

void textcolor(int colorNum)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

int load_RandomWord(char guess[])
{
    srand(time(NULL));

    // fopen �� ���� hangman_words.txt �� �ִ� �ܾ��� �ּҸ� ������.
    FILE* fp = fopen("hangman_words.txt", "r");

    // ������ �������� �ʰų�, �߸��� ��ο� ���� ��
    if (fp == NULL)
    {
        printf("�ܾ� ������ �о���̴µ� �����߽��ϴ�. \n");
        return -1;
    }

    // hangman_words.txt ���� ������ �ܾ���� ����.
    char guessWords[MAXNUMWORDS][MAXLENWORD + 1] = { 0 };
    // fgets �� ����� �� guesswords �� �ܾ �����ϱ� ���� �ӽ� �迭.
    char input[MAXLENWORD + 1] = { 0 };
    // �о���� �ܾ��� ��. guesswords �� �ܾ� ������ �� �ε����ε� ���.
    int WordsRead = 0;

    // fgets �� ���̻� �о�� ���ڿ��� ���ٸ� NULL �� ��ȯ.
    while (fgets(input, MAXLENWORD, fp) != NULL)
    {
        strcpy(guessWords[WordsRead], input);
        WordsRead++;
    }

    printf("���� �ε� ����. \n");
    printf("�о�帰 �� �ܾ� �� : %d\n", WordsRead);

    fclose(fp);

    // �ҷ��� �ܾ�� �� �������� �������� ���� ������ �ε��� ����.
    int randomIndex = rand() % WordsRead;

    // �������� ������ �ܾ guess �迭�� ����.
    strcpy(guess, guessWords[randomIndex]);

    return 0;
}

int select_menu(void)
{
    int select;
    printf("==========");
    textcolor(Sky_Blue);
    printf(" < Hangman Game > ");
    textcolor(White);
    printf("==========\n");
    textcolor(Yellow);
    printf("             1. ���� ����              \n");
    printf("             2. ���� ����              \n");
    printf("             3. ���� ����              \n");
    textcolor(White);
    printf("=======================================\n");
    printf("\n");
    printf("�޴��� �����ϼ��� : ");
    scanf("%d", &select);
    return select;
}

void print_hangman(int tries)
{
    switch (tries)
    {
    case 0:
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        break;

    case 1:
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("_________      \n");
        break;

    case 2:
        printf("               \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 3:
        printf("     _______   \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 4:
        printf("     _______   \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 5:
        printf("     _______   \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |       O  \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 6:
        printf("     _______   \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |       O  \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 7:
        printf("     _______   \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |       O  \n");
        printf("    |     ��|  \n");
        printf("    |       |  \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 8:
        printf("     _______   \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |       O  \n");
        printf("    |     ��|�� \n");
        printf("    |       |  \n");
        printf("    |          \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 9:
        printf("     _______   \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |       O  \n");
        printf("    |     ��|�� \n");
        printf("    |       |  \n");
        printf("    |     ��   \n");
        printf("    |          \n");
        printf("____|____      \n");
        break;

    case 10:
        printf("     _______   \n");
        printf("    |       |  \n");
        printf("    |       |  \n");
        printf("    |       ");
        textcolor(Dark_Gray);
        printf("O  \n");
        textcolor(White);
        printf("    |     ");
        textcolor(Dark_Gray);
        printf("  ||| \n");
        textcolor(White);
        printf("    |       ");
        textcolor(Dark_Gray);
        printf(" | \n");
        textcolor(White);
        printf("    |     ");
        textcolor(Dark_Gray);
        printf("  | | \n");
        textcolor(White);
        printf("    |          \n");
        printf("____|____      \n");
        break;

    default:
        textcolor(Sky_Blue);
        printf(" ��       �� \n");
        printf("   �� O ��   \n");
        printf("      |   �� \n");
        printf(" ��   |      \n");
        printf("    �� ��    \n");
        textcolor(White);
    }
}

void print_remainAlpha(int remainAlpha[])
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (remainAlpha[i] == 0)
            printf("%c ", i + 'a');
    }
    printf("\n");
}

void print_currentGuess(char current[], char guess[])
{
    for (int i = 0; i < strlen(guess); i++)
    {
        if (current[i] == 0)
            printf("_ ");
        else
            printf("%c ", current[i]);
    }
    printf("\n");
}

void hangman(void)
{
    int tries = 0;
    char guess[MAXLENWORD + 1] = { 0 };
    char guessAlpha = 'A';

    printf("\n�ܾ �ε��մϴ�. \n");
    load_RandomWord(guess);
    guess[strlen(guess) - 1] = 0;
    printf("�ε��� �ܾ� : %s\n", guess);

    char current[MAXLENWORD + 1] = { 0 };
    int remainAlpha[26] = { 0 };

    textcolor(Purple);
    printf("\n��� �� ������ �����մϴ�. \n");
    textcolor(White);
    Sleep(3000);

    for (;;)
    {
        system("cls");

        printf("\nHangman �� ���� :\n");
        print_hangman(tries);

        if (tries >= 7)
            textcolor(Red);
        else if (tries >= 5)
            textcolor(Yellow);
        else
            textcolor(White);

        printf("\n���� Ƚ�� : %d \n", 10 - tries);
        textcolor(White);

        printf("\n");
        print_currentGuess(current, guess);

        printf("\n���� ���ĺ� : ");
        print_remainAlpha(remainAlpha);
        printf("\n");

        printf("���ĺ��� �Է��ϼ��� : ");
        scanf(" %c", &guessAlpha);

        while (remainAlpha[guessAlpha - 'a'] == 1 || (guessAlpha < 'a' || guessAlpha > 'z'))
        {
            if (remainAlpha[guessAlpha - 'a'] == 1)
            {
                printf("�̹� �Է��� ���ĺ��Դϴ�. �ٸ� ���ĺ��� �Է��Ͻʽÿ�. : ");
                scanf(" %c", &guessAlpha);
            }
            else if (guessAlpha < 'a' || guessAlpha > 'z')
            {
                printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻʽÿ�. : ");
                scanf(" %c", &guessAlpha);
            }
        }

        int count = 0;
        for (int i = 0; i < strlen(guess); i++)
        {
            if (guess[i] == guessAlpha)
            {
                current[i] = guessAlpha;
                count++;
            }
        }

        if (count == 0)
        {
            textcolor(Red);
            printf("�����Դϴ�. \n");
            textcolor(White);
            remainAlpha[guessAlpha - 'a'] = 1;
            tries++;
        }
        else
        {
            textcolor(Green);
            printf("�����Դϴ�. \n");
            textcolor(White);
            remainAlpha[guessAlpha - 'a'] = 1;
        }

        Sleep(1000);

        if (strcmp(guess, current) == 0 || tries == 10)
            break;
    }

    if (strcmp(guess, current) == 0)
    {
        system("cls");
        printf("\n���� : %s\n", guess);
        printf("\n");
        print_hangman(777);
        textcolor(Sky_Blue);
        printf("\n�����մϴ�. �¸��ϼ̽��ϴ�!\n");
        textcolor(White);
    }
    else
    {
        system("cls");
        printf("\n���� : %s\n", guess);
        printf("\n");
        print_hangman(tries);
        textcolor(Red);
        printf("\n��Ÿ������ �й��ϼ̽��ϴ�...\n");
        textcolor(White);
    }
}