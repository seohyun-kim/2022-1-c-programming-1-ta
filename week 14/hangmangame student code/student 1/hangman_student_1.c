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
            printf("\n행맨(Hangman)는 상대방이 생각하는 단어를 맞춰가는 게임입니다.\n");
            printf("단어에 들어가는 알파벳을 유추하여 입력하는 방식으로 진행됩니다.\n");
            printf("기회는 총 10번이 주어지고, 맞출 경우 기회는 차감되지 않습니다.\n");
            Sleep(1000);
            printf("\n5초 후 메뉴 화면으로 돌아갑니다...");
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

    // fopen 을 통해 hangman_words.txt 에 있는 단어의 주소를 가져옴.
    FILE* fp = fopen("hangman_words.txt", "r");

    // 파일이 존재하지 않거나, 잘못된 경로에 있을 때
    if (fp == NULL)
    {
        printf("단어 파일을 읽어들이는데 실패했습니다. \n");
        return -1;
    }

    // hangman_words.txt 에서 가져온 단어들을 저장.
    char guessWords[MAXNUMWORDS][MAXLENWORD + 1] = { 0 };
    // fgets 를 사용할 때 guesswords 에 단어를 저장하기 위한 임시 배열.
    char input[MAXLENWORD + 1] = { 0 };
    // 읽어들인 단어의 수. guesswords 에 단어 저장할 때 인덱스로도 사용.
    int WordsRead = 0;

    // fgets 는 더이상 읽어올 문자열이 없다면 NULL 을 반환.
    while (fgets(input, MAXLENWORD, fp) != NULL)
    {
        strcpy(guessWords[WordsRead], input);
        WordsRead++;
    }

    printf("파일 로드 성공. \n");
    printf("읽어드린 총 단어 수 : %d\n", WordsRead);

    fclose(fp);

    // 불러온 단어들 중 무작위로 가져오기 위해 무작위 인덱스 생성.
    int randomIndex = rand() % WordsRead;

    // 무작위로 가져온 단어를 guess 배열에 저장.
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
    printf("             1. 게임 시작              \n");
    printf("             2. 게임 설명              \n");
    printf("             3. 게임 종료              \n");
    textcolor(White);
    printf("=======================================\n");
    printf("\n");
    printf("메뉴를 선택하세요 : ");
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
        printf("    |     ↙|  \n");
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
        printf("    |     ↙|↘ \n");
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
        printf("    |     ↙|↘ \n");
        printf("    |       |  \n");
        printf("    |     ↙   \n");
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
        printf(" ♡       ♥ \n");
        printf("   ↖ O ↗   \n");
        printf("      |   ♬ \n");
        printf(" ♪   |      \n");
        printf("    ↙ ↘    \n");
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

    printf("\n단어를 로딩합니다. \n");
    load_RandomWord(guess);
    guess[strlen(guess) - 1] = 0;
    printf("로딩된 단어 : %s\n", guess);

    char current[MAXLENWORD + 1] = { 0 };
    int remainAlpha[26] = { 0 };

    textcolor(Purple);
    printf("\n잠시 후 게임을 시작합니다. \n");
    textcolor(White);
    Sleep(3000);

    for (;;)
    {
        system("cls");

        printf("\nHangman 의 상태 :\n");
        print_hangman(tries);

        if (tries >= 7)
            textcolor(Red);
        else if (tries >= 5)
            textcolor(Yellow);
        else
            textcolor(White);

        printf("\n남은 횟수 : %d \n", 10 - tries);
        textcolor(White);

        printf("\n");
        print_currentGuess(current, guess);

        printf("\n남은 알파벳 : ");
        print_remainAlpha(remainAlpha);
        printf("\n");

        printf("알파벳을 입력하세요 : ");
        scanf(" %c", &guessAlpha);

        while (remainAlpha[guessAlpha - 'a'] == 1 || (guessAlpha < 'a' || guessAlpha > 'z'))
        {
            if (remainAlpha[guessAlpha - 'a'] == 1)
            {
                printf("이미 입력한 알파벳입니다. 다른 알파벳을 입력하십시오. : ");
                scanf(" %c", &guessAlpha);
            }
            else if (guessAlpha < 'a' || guessAlpha > 'z')
            {
                printf("잘못된 입력입니다. 다시 입력하십시오. : ");
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
            printf("오답입니다. \n");
            textcolor(White);
            remainAlpha[guessAlpha - 'a'] = 1;
            tries++;
        }
        else
        {
            textcolor(Green);
            printf("정답입니다. \n");
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
        printf("\n정답 : %s\n", guess);
        printf("\n");
        print_hangman(777);
        textcolor(Sky_Blue);
        printf("\n축하합니다. 승리하셨습니다!\n");
        textcolor(White);
    }
    else
    {
        system("cls");
        printf("\n정답 : %s\n", guess);
        printf("\n");
        print_hangman(tries);
        textcolor(Red);
        printf("\n안타깝지만 패배하셨습니다...\n");
        textcolor(White);
    }
}