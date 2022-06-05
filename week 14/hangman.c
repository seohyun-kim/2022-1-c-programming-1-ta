#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define ALPHABETSIZE 26
void makeUnderbarforSolution(char* solution, char* yourAnswer);
void displayHangman(int remainChance);
void makeUnderbarforSolution(char* solution, char* yourAnswer);
int checkIfAlphabetIncluded(char solution[], char yourAnswer[], char checkAlphabet);
void makeAlphabetArray(char usableAlphabets[]);



int main() {
	// 소문자에 대해서만 처리합니다.

	char solution1[100]= "meet at midnight";
	char solution2[100] = "no idea";
	char solution3[100] = "fucking exam";
	char solution4[100] = "so sleeeeepy";
	char solution5[100] = "haha happy day";

	char* solutionArray[5] = { solution1, solution2 , solution3 , solution4 , solution5 };
	char solution[100]; // 맞춰야 할 문자열

	srand(time(NULL));
	int randomNumber = rand() % 5;

	strcpy(solution, solutionArray[randomNumber]);

	// printf("solution : %s\n", solution);

	char yourAnswer[100]; // 현재까지 사용자가 맞춘 문자열이 들어있는 문자 배열
	char usableAlphabets[27]; // 사용가능한 알파벳 목록
	char triedAlphabets[27] ={NULL, }; // 시도한 알파벳들
	char checkAlphabet; // 체크하고자 하는 알파벳
	int chance = 6; // 총 기회 7번 (0부터 시작)
	int round = 0; // 현재 총 시도 횟수

	printf("> 기회는 총 7번 입니다.\n");

	makeAlphabetArray(usableAlphabets);
	makeUnderbarforSolution(solution, yourAnswer);
	printf("yourAnswer: %s\n", yourAnswer);

	while (chance > 0) {
		printf("알파벳 목록 : %s\n", usableAlphabets);
		printf("\n > 알파벳을 하나 추측하세요 : ");
		checkAlphabet = getchar();

		if (strchr(triedAlphabets, checkAlphabet) == NULL) { // 사용된 적이 없으면
			usableAlphabets[checkAlphabet - 'a'] = '*';  // 문자 사용되었음을 표기
			triedAlphabets[round] = checkAlphabet;       // 시도한 문자 append

			if (checkIfAlphabetIncluded(solution, yourAnswer, checkAlphabet) == 0) { // 포함안된경우
				chance--;
			}
		}else {
			printf("이미 시도한 문자입니다.\n");
			continue;
		}

		// display board
		printf("\n ====================\n     HANGMAN BOARD \n ====================\n");
		displayHangman(chance);
		printf("\n");


		round++; // round count

		//printf("solution : %s\n", solution);
		printf("yourAnswer: %s\n", yourAnswer);

		if (strcmp(solution, yourAnswer) == 0) { // 두 문자열이 같으면
			printf("YOU WIN!!\n");
			return 0; // 종료
		}
		getchar();
	}

	printf(" > 모든 기회를 다 소진했습니다. GAME OVER!! \n ===============================\n");
	printf("solution : %s\n", solution);
	return 0;
}


void makeAlphabetArray(char usableAlphabets[]) {
	for (int i = 0; i < ALPHABETSIZE; i++)
	{
		usableAlphabets[i] = 'a' + i;
	}
	usableAlphabets[ALPHABETSIZE] = NULL;
}


void makeUnderbarforSolution(char solution[], char yourAnswer[]) {
	char* checkChar = yourAnswer;


	for (int i = 0; i <= strlen(solution); i++)
	{
		if (( solution[i] >= 'a') && (solution[i] <= 'z')) {
			yourAnswer[i] = '_'; // 영문 소문자인경우 언더바로 변경
		}
		else if (solution[i] == ' ' || solution[i] == NULL) {
			yourAnswer[i] = solution[i];
		}
		else yourAnswer[i] = '?';
	}
}


int checkIfAlphabetIncluded(char solution[], char yourAnswer[], char checkAlphabet) {
	int isIncluded = 0;

	// checkAlphabet 에 해당하는 알파벳이 solution에 포함되어있으면 yourAnswer에서 보이게함
	for (int i = 0; i < strlen(solution); i++)
	{
		if (solution[i] == checkAlphabet) {
			yourAnswer[i] = checkAlphabet;
			isIncluded = 1;
		}
	}
	return isIncluded;
}


void displayHangman(int remainChance) { // remainChance 는 0~6 (7번)
	switch (remainChance) {
	case 0:
		printf("   O   \n");
		break;
	case 1:
		displayHangman(0);
		printf("   |   \n");
		break;
	case 2:
		displayHangman(1);
		printf(" -- ");
		break;
	case 3:
		displayHangman(2);
		printf("--\n");
		break;
	case 4:
		displayHangman(3);
		printf("   |   \n");
		break;
	case 5:
		displayHangman(4);
		printf(" ↙ ");
		break;
	case 6:
		displayHangman(5);
		printf("↘ \n");
		break;
	}

	return;

}