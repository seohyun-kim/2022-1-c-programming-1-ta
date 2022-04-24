

/*
	< Up Down ���� ����� >
	���� �ð��� �õ�(seed)�� 1~100 ������ ������ �ϳ� �����Ѵ�. (����� �� ����)

	����ڿ��� �� ���� ��ȸ(chance)�� �� ������ �Է¹޴´�.

	����ڷκ��� chance ��ŭ ���ڸ� �׽�Ʈ �� �� �� �ִ� ��ȸ�� �ش�.
	- �Է¹��� ���ڰ� 1~100 ������ ���ڰ� �ƴ϶�� ������ ��� �������� �˷��ְ�(�ֿܼ� ���) �ٽ��ѹ� ��ȸ�� �ش�.(��ȸ ���� X)
	- �Է¹��� ���ڰ� ������ ���ٸ� �̰�ٰ� ����Ѵ�.
	- �Է¹��� ���ں��� ������ ũ�ٸ� Up, �۴ٸ� Down�� ����Ѵ�.

	��ȸ�� ��� �� ��µ� ���� ������ ���ߴٸ� ���ٰ� ����ϰ� ���߰��� �ߴ� ������ ���� �˷��ش�.


*/

















#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {

	int randNum; // ���� �� ����
	int mynum = 0;

	srand((unsigned)time(NULL));

	randNum = 1 + (rand() % 100); // 1~100 ������ ���� ���� ����

	int chance = 5;
	printf("��ȸ�� �� �� �ٱ��? ");
	scanf("%d", &chance);
	printf("Up Down ������ �����մϴ�.\n==========================\n\n");

	while (chance > 0) {

		printf("���ڸ� �Է��ϼ���(1~100) : ");
		scanf("%d", &mynum);

		if (mynum <= 0 || mynum > 100) {
			printf("������ ��� �����Դϴ�. �ٽ� �Է��ϼ���.\n\n");
			continue;
		}

		if (mynum == randNum) {
			printf("YOU WIN!\n");
			return 0;
		}
		else if (mynum > randNum) printf("Down\n\n");
		else printf("Up\n\n");

		chance--;
	}

	printf("YOU LOSE! �ٺ����� ������ %d ������\n", randNum);



	return 0;
}