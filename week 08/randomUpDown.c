

/*
	< Up Down 게임 만들기 >
	현재 시간을 시드(seed)로 1~100 범위의 난수를 하나 생성한다. (맞춰야 할 숫자)

	사용자에게 몇 번의 기회(chance)를 줄 것인지 입력받는다.

	사용자로부터 chance 만큼 숫자를 테스트 해 볼 수 있는 기회를 준다.
	- 입력받은 숫자가 1~100 사이의 숫자가 아니라면 범위에 벗어난 숫자임을 알려주고(콘솔에 출력) 다시한번 기회를 준다.(기회 차감 X)
	- 입력받은 숫자가 난수와 같다면 이겼다고 출력한다.
	- 입력받은 숫자보다 난수가 크다면 Up, 작다면 Down을 출력한다.

	기회를 모두 다 썼는데 아직 맞추지 못했다면 졌다고 출력하고 맞추고자 했던 난수의 값을 알려준다.


*/

















#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {

	int randNum; // 랜덤 값 저장
	int mynum = 0;

	srand((unsigned)time(NULL));

	randNum = 1 + (rand() % 100); // 1~100 까지의 수로 난수 생성

	int chance = 5;
	printf("기회를 몇 번 줄까요? ");
	scanf("%d", &chance);
	printf("Up Down 게임을 시작합니다.\n==========================\n\n");

	while (chance > 0) {

		printf("숫자를 입력하세요(1~100) : ");
		scanf("%d", &mynum);

		if (mynum <= 0 || mynum > 100) {
			printf("범위에 벗어난 숫자입니다. 다시 입력하세요.\n\n");
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

	printf("YOU LOSE! 바보ㅋㅋ 정답은 %d 였지롱\n", randNum);



	return 0;
}