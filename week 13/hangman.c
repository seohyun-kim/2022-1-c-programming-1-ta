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
	// �ҹ��ڿ� ���ؼ��� ó���մϴ�.

	char solution1[100]= "meet at midnight";
	char solution2[100] = "no idea";
	char solution3[100] = "fucking exam";
	char solution4[100] = "so sleeeeepy";
	char solution5[100] = "haha happy day";

	char* solutionArray[5] = { solution1, solution2 , solution3 , solution4 , solution5 };
	char solution[100]; // ����� �� ���ڿ�

	srand(time(NULL));
	int randomNumber = rand() % 5;

	strcpy(solution, solutionArray[randomNumber]);

	// printf("solution : %s\n", solution);

	char yourAnswer[100]; // ������� ����ڰ� ���� ���ڿ��� ����ִ� ���� �迭
	char usableAlphabets[27]; // ��밡���� ���ĺ� ���
	char triedAlphabets[27] ={NULL, }; // �õ��� ���ĺ���
	char checkAlphabet; // üũ�ϰ��� �ϴ� ���ĺ�
	int chance = 6; // �� ��ȸ 7�� (0���� ����)
	int round = 0; // ���� �� �õ� Ƚ��

	printf("> ��ȸ�� �� 7�� �Դϴ�.\n");

	makeAlphabetArray(usableAlphabets);
	makeUnderbarforSolution(solution, yourAnswer);
	printf("yourAnswer: %s\n", yourAnswer);

	while (chance > 0) {
		printf("���ĺ� ��� : %s\n", usableAlphabets);
		printf("\n > ���ĺ��� �ϳ� �����ϼ��� : ");
		checkAlphabet = getchar();

		if (strchr(triedAlphabets, checkAlphabet) == NULL) { // ���� ���� ������
			usableAlphabets[checkAlphabet - 'a'] = '*';  // ���� ���Ǿ����� ǥ��
			triedAlphabets[round] = checkAlphabet;       // �õ��� ���� append

			if (checkIfAlphabetIncluded(solution, yourAnswer, checkAlphabet) == 0) { // ���ԾȵȰ��
				chance--;
			}
		}else {
			printf("�̹� �õ��� �����Դϴ�.\n");
			continue;
		}

		// display board
		printf("\n ====================\n     HANGMAN BOARD \n ====================\n");
		displayHangman(chance);
		printf("\n");


		round++; // round count

		//printf("solution : %s\n", solution);
		printf("yourAnswer: %s\n", yourAnswer);

		if (strcmp(solution, yourAnswer) == 0) { // �� ���ڿ��� ������
			printf("YOU WIN!!\n");
			return 0; // ����
		}
		getchar();
	}

	printf(" > ��� ��ȸ�� �� �����߽��ϴ�. GAME OVER!! \n ===============================\n");
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
			yourAnswer[i] = '_'; // ���� �ҹ����ΰ�� ����ٷ� ����
		}
		else if (solution[i] == ' ' || solution[i] == NULL) {
			yourAnswer[i] = solution[i];
		}
		else yourAnswer[i] = '?';
	}
}


int checkIfAlphabetIncluded(char solution[], char yourAnswer[], char checkAlphabet) {
	int isIncluded = 0;

	// checkAlphabet �� �ش��ϴ� ���ĺ��� solution�� ���ԵǾ������� yourAnswer���� ���̰���
	for (int i = 0; i < strlen(solution); i++)
	{
		if (solution[i] == checkAlphabet) {
			yourAnswer[i] = checkAlphabet;
			isIncluded = 1;
		}
	}
	return isIncluded;
}


void displayHangman(int remainChance) { // remainChance �� 0~6 (7��)
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
		printf(" �� ");
		break;
	case 6:
		displayHangman(5);
		printf("�� \n");
		break;
	}

	return;

}