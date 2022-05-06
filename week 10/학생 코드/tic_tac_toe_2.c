#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int win = 0;
int lose = 0;
int none = 0;

void play_p2p(void) {
	printf("게임을 시작합니다\n");
	printf("Good Luck\n\n");

	char game[3][3];					//좌표계 생성

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//초기화

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer 코드복사/무시
	for (int i = 1; i <= 9; i++) {			//게임시작
														//사람 직접 입력
		mark = (i % 2 == 0) ? 'X' : 'O';
						//OX입력순서 지정 및 입력

		printf("%c의 차례입니다\n좌표를 입력해 주세요\n", mark);
		scanf("%d %d", &y, &x);
		while (game[y][x] != ' ') {
			printf("이미 선택한 좌표입니다\n다른 좌표를 입력해주세요\n");
			scanf("%d %d", &y, &x);		//좌표입력
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//현재 진행상황 출력

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//승패결정
	}									//게임종료
	switch (checkwinner) {
	case 'n':
		printf("이번 게임은 무승부 입니다\n");
		break;
	case 'h':
		printf("O가 이겼습니다\n");
		break;
	case 'c':
		printf("X가 이겼습니다\n");
		break;
	}
	printf("게임을 종료합니다\n\n");
}
				//1. 두명이서 플레이 코드
				//단순히 순서 번갈아가면서 플레이
				//승률을 계산하지 않는 모드
void play_with_computer_hfirst_easy(void) {
	printf("게임을 시작합니다\n");
	printf("Good Luck\n\n");

	char game[3][3];					//좌표계 생성

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//초기화

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//게임시작
															//컴퓨터랑 대결
		mark = (i % 2 == 0) ? 'X' : 'O';
						//OX입력순서 지정 및 입력

		switch (i % 2) {
		case 1:
			printf("좌표를 입력해 주세요\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("이미 선택한 좌표입니다\n다른 좌표를 입력해주세요\n");
				scanf("%d %d", &y, &x);		//좌표입력
			}
			break;
		case 0:
			srand(time(0));
			x = rand() % 3;
			y = rand() % 3;
			while (game[y][x] != 32) {
				x = rand() % 3;
				y = rand() % 3;
			}
			break;
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n",game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//현재 진행상황 출력

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//승패결정
	}									//게임종료
	switch (checkwinner){
	case 'n':
		printf("이번 게임은 무승부 입니다\n");
		none++;
		break;
	case 'h':
		printf("참여자가 이겼습니다\n");
		win++;
		break;
	case 'c':
		printf("컴퓨터가 이겼습니\n");
		lose++;
		break;
	}
	printf("게임을 종료합니다\n\n");
}
				//2. 사람 선공 컴퓨터와 대결
				//단순 랜덤시드로 좌표값 설정
void play_with_computer_cfirst_easy(void) {
	printf("게임을 시작합니다\n");
	printf("Good Luck\n\n");

	char game[3][3];					//좌표계 생성

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//초기화

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//게임시작
															//컴퓨터랑 대결
		mark = (i % 2 == 0) ? 'O' : 'X';
		//OX입력순서 지정 및 입력

		switch (i % 2) {
		case 0:
			printf("좌표를 입력해 주세요\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("이미 선택한 좌표입니다\n다른 좌표를 입력해주세요\n");
				scanf("%d %d", &y, &x);		//좌표입력
			}
			break;
		case 1:
			srand(time(0));
			x = rand() % 3;
			y = rand() % 3;
			while (game[y][x] != 32) {
				x = rand() % 3;
				y = rand() % 3;
			}
			break;
		}

		game[y][x] = mark;

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//현재 진행상황 출력

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//승패결정
	}									//게임종료
	switch (checkwinner) {
	case 'n':
		printf("이번 게임은 무승부 입니다\n");
		none++;
		break;
	case 'h':
		printf("참여자가 이겼습니다\n");
		win++;
		break;
	case 'c':
		printf("컴퓨터가 이겼습니다\n");
		lose++;
		break;
	}
	printf("게임을 종료합니다\n\n");
}
				//3. 컴퓨터 선공 컴퓨터와 대결
				//단순 랜덤시드로 좌표값 설정
void play_with_computer_hfirst_hard(void) {
	printf("게임을 시작합니다\n");
	printf("Good Luck\n\n");

	char game[3][3];					//좌표계 생성

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//초기화
	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//게임시작
															//컴퓨터랑 대결
		mark = (i % 2 == 0) ? 'X' : 'O';
		//OX입력순서 지정 및 입력

		switch (i % 2) {
		case 1:
			printf("좌표를 입력해 주세요\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("이미 선택한 좌표입니다\n다른 좌표를 입력해주세요\n");
				scanf("%d %d", &y, &x);		//좌표입력
			}
			game[y][x] = mark;
			break;
		case 0:
			switch (game[1][1]) {
			case 32:
				game[1][1] = 'X';
				break;
			case 88:					//컴퓨터가 가운데 선점하고 방어적인 성격을 띄면서 공격적임
				if (((game[0][0] + game[2][0] == 158) && (game[1][0] == 32)) ||
					((game[0][2] + game[2][2] == 158) && (game[1][2] == 32)) ||
					((game[0][0] + game[0][2] == 158) && (game[0][1] == 32)) ||
					((game[2][0] + game[2][2] == 158) && (game[2][1] == 32))) {
					if ((game[0][0] + game[2][0] == 158) && (game[1][0] == 32)) {
						game[1][0] = 88;
					}
					else if ((game[0][2] + game[2][2] == 158) && (game[1][2] == 32)) {
						game[1][2] = 88;
					}
					else if ((game[0][0] + game[0][2] == 158) && (game[0][1] == 32)) {
						game[0][1] = 88;
					}
					else {
						game[2][1] = 88;
					}
				}
				else if (y == x) {									// \자가 채워졌을때
					if (game[y][1] == ' ') {
						game[y][1] = 'X';
					}
					else if (game[1][x] == ' ') {
						game[1][x] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				else if ((y % 2 == 0) && (x % 2 == 0)) {		// /자가 채워졌을때
					if (game[y][1] == ' ') {
						game[y][1] = 'X';
					}
					else if (game[1][x] == ' ') {
						game[1][x] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				else if ((y == 1) && (x % 2 == 0)) {			// -자가 채워졌을떄
					if (game[0][x] == ' ') {
						game[0][x] = 'X';
					}
					else if (game[2][x] == ' ') {
						game[2][x] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				else if ((y % 2 == 0) && (x == 1)) {			// |자가 채워졌을때
					if (game[y][0] == ' ') {
						game[y][0] = 'X';
					}
					else if (game[y][2] == ' ') {
						game[y][2] = 'X';
					}
					else {
						srand(time(0));
						x = rand() % 3;
						y = rand() % 3;
						while (game[y][x] != 32) {
							x = rand() % 3;
							y = rand() % 3;
						}
						game[y][x] = mark;
					}
				}
				break;
			case 79:			//가운데를 선점하지 못했을때
				if (i == 2) {
					game[0][0] = 'X';						//임의로 0,0에 값 집어넣음
				}
				else if ((game[0][0] + game[1][0] + game[2][0] == 208) ||
					(game[0][0] + game[0][1] + game[0][2] == 208) ||
					(game[0][2] + game[1][2] + game[2][2] == 208) ||
					(game[2][0] + game[2][1] + game[2][2] == 208)) {
					for (int j = 0; j <= 2; j = j + 2) {
						if (game[0][j] + game[1][j] + game[2][j] == 208) {
							for (int n = 0; n < 3; n++) {
								game[n][j] == 'X';
							}
							break;
						}
						else if (game[j][0] + game[j][1] + game[j][2] == 208) {
							for (int n = 0; n < 3; n++) {
								game[j][n] == 'X';
							}
							break;
						}
					}										//컴퓨터픽 2개인 줄 비어있으면 픽하고 게임종료
				}
				else if ((game[0][1] + game[1][1] + game[2][1] == 190) ||
					(game[1][0] + game[1][1] + game[1][2] == 190) ||
					(game[0][2] + game[1][2] + game[2][2] == 190) ||
					(game[2][0] + game[2][1] + game[2][2] == 190) ||
					(game[0][2] + game[1][1] + game[2][0] == 190)) {
					if ((game[2][2] == 79) &&
						((game[2][0] + game[2][1] == 111) || (game[0][2] + game[1][2] == 111))) {
						if (game[2][0] + game[2][1] == 111) {
							if (game[2][0] == 79) {
								game[2][1] = 88;
							}
							else {
								game[2][0] = 88;
							}
						}
						else {
							if (game[0][2] == 79) {
								game[1][2] = 88;
							}
							else {
								game[0][2] = 88;
							}
						}
					}
					else if (game[1][1] == 79) {
						if (game[2][0] + game[0][2] == 111) {
							if (game[2][0] == 79) {
								game[0][2] = 88;
							}
							else {
								game[2][0] = 88;
							}
						}
						else if (game[0][1] + game[2][1] == 111) {
							if (game[0][1] == 79) {
								game[2][1] = 88;
							}
							else {
								game[0][1] = 88;
							}
						}
						else if (game[1][0] + game[1][2] == 111) {
							if (game[1][0] == 79) {
								game[2][1] = 88;
							}
							else {
								game[1][0] = 88;
							}
						}
					}
				}
				else if ((game[1][0] + game[2][0] == 64) || (game[0][1] + game[0][2] == 64)) {
					if (game[1][0] + game[2][0] == 64) {
						game[2][0] = 88;
					}
					else {
						game[0][2] = 88;
					}
				}
				else if ((game[2][2] == 32) && ((game[2][1] == 32) || (game[1][2] == 32))) {
					if (game[2][1] == 32) {
						game[2][1] = 88;
					}
					else {
						game[1][2] = 88;
					}
				}
				break;
			}
		default:
			break;
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//현재 진행상황 출력

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//승패결정
	}									//게임종료
	switch (checkwinner) {
	case 'n':
		printf("이번 게임은 무승부 입니다\n");
		none++;
		break;
	case 'h':
		printf("참여자가 이겼습니다\n");
		win++;
		break;
	case 'c':
		printf("컴퓨터가 이겼습니다\n");
		lose++;
		break;
	}
	printf("게임을 종료합니다\n\n");
}
				//4. 사람 선공 컴퓨터와 대결
				//(1,1)을 사람이 먼저 선점하지 않았다면
				//6번 코드 처럼 (1,1) 선점하고 공격적으로 플레이
				//하지만 몇몇 케이스에서 방어적인 케이스를 취하기도 함
				//하지만 (1,1)을 사람이 선점하면 게임 쉽게 풀림
void play_with_computer_cfirst_hard(void) {
	printf("게임을 시작합니다\n");
	printf("Good Luck\n\n");

	char game[3][3];					//좌표계 생성

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//초기화

	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//게임시작
															//컴퓨터랑 대결
		mark = (i % 2 == 0) ? 'O' : 'X';
		//OX입력순서 지정 및 입력

		switch (i % 2) {
		case 0:
			printf("좌표를 입력해 주세요\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("이미 선택한 좌표입니다\n다른 좌표를 입력해주세요\n");
				scanf("%d %d", &y, &x);		//좌표입력
			}
			game[y][x] = mark;
			break;
		case 1:
			if (game[1][1] == ' ') {
				game[1][1] = 'X';
			}									//가운데가 비었을때
			else {
					if (y == x) {									// \자가 채워졌을때
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x % 2 == 0)) {		// /자가 채워졌을때
						if (game[y][1] == ' ') {
							game[y][1] = 'X';
						}
						else if (game[1][x] == ' ') {
							game[1][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y == 1) && (x % 2 == 0)) {			// -자가 채워졌을떄
						if (game[0][x] == ' ') {
							game[0][x] = 'X';
						}
						else if (game[2][x] == ' ') {
							game[2][x] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
					else if ((y % 2 == 0) && (x == 1)) {			// |자가 채워졌을때
						if (game[y][0] == ' ') {
							game[y][0] = 'X';
						}
						else if (game[y][2] == ' ') {
							game[y][2] = 'X';
						}
						else {
							srand(time(0));
							x = rand() % 3;
							y = rand() % 3;
							while (game[y][x] != 32) {
								x = rand() % 3;
								y = rand() % 3;
							}
							game[y][x] = mark;
						}
					}
			}
			break;
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//현재 진행상황 출력

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//승패결정
	}									//게임종료
	switch (checkwinner) {
	case 'n':
		printf("이번 게임은 무승부 입니다\n");
		none++;
		break;
	case 'h':
		printf("참여자가 이겼습니다\n");
		win++;
		break;
	case 'c':
		printf("컴퓨터가 이겼습니다\n");
		lose++;
		break;
	}
	printf("게임을 종료합니다\n\n");
}
				//5. 컴퓨터 선공 컴퓨터와 대결
				//컴퓨터의 방어위주 플레이
				//컴퓨터는 이기기 보다는 지지않는데에 집중
				//(1,1)선점 후 나머지 연결 안되게 차단하는데 집중
void play_with_computer_hardcore(void) {
	printf("게임을 시작합니다\n");
	printf("Good Luck\n\n");

	char game[3][3];					//좌표계 생성

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = ' ';
		}
	}									//초기화
	int x, y;
	char mark;

	char checkwinner = 'n';//none,human,computer
	for (int i = 1; i <= 9; i++) {			//게임시작
															//컴퓨터랑 대결
		mark = (i % 2 == 0) ? 'O' : 'X';
		//OX입력순서 지정 및 입력

		switch (i % 2) {
		case 0:
			printf("좌표를 입력해 주세요\n");
			scanf("%d %d", &y, &x);
			while (game[y][x] != 32) {
				printf("이미 선택한 좌표입니다\n다른 좌표를 입력해주세요\n");
				scanf("%d %d", &y, &x);		//좌표입력
			}
			game[y][x] = mark;
			break;
		case 1:
			switch (game[1][1]) {
			case 32:
				game[1][1] = 'X';
				break;
			case 88:
				if ((game[1][0] + game[1][2] == 120) || (game[0][1] + game[2][1] == 120) ||
					(game[0][0] + game[2][2] == 120) || (game[0][2] + game[2][0] == 120)) {
					if (game[1][0] + game[1][2] == 120) {
						game[1][0] = 88;
						game[1][2] = 88;
					}
					else if (game[0][1] + game[2][1] == 120) {
						game[0][1] = 88;
						game[2][1] = 88;
					}
					else if (game[0][0] + game[2][2] == 120) {
						game[0][0] = 88;
						game[2][2] = 88;
					}
					else {
						game[0][2] = 88;
						game[2][0] = 88;
					}										//중앙 기준으로 2개가 차고 하나가 빈 경우
				}
				else if ((game[0][0] + game[2][0] + game[1][0] == 208) ||
					(game[0][2] + game[2][2] + game[1][2] == 208) ||
					(game[0][0] + game[0][2] + game[0][1] == 208) ||
					(game[2][0] + game[2][2] + game[2][1] == 208)) {
					if (game[0][0] + game[2][0] + game[1][0] == 208) {
						game[0][0] = 88;
						game[2][0] = 88;
						game[1][0] = 88;
					}
					else if (game[0][2] + game[2][2] + game[1][2] == 208) {
						game[0][2] = 88;
						game[2][2] = 88;
						game[1][2] = 88;
					}
					else if (game[0][0] + game[0][2] + game[0][1] == 208) {
						game[0][0] = 88;
						game[0][2] = 88;
						game[0][1] = 88;
					}
					else {
						game[2][0] = 88;
						game[2][2] = 88;
						game[2][1] = 88;
					}
				}											//중앙 제외 2개가 차고 하나가 빈 경우
				else if (((game[0][0] + game[2][0] + game[1][0] == 190)) ||
					((game[0][2] + game[2][2] + game[1][2] == 190)) ||
					((game[0][0] + game[0][2] + game[0][1] == 190)) ||
					((game[2][0] + game[2][2] + game[2][1] == 190))) {
					if (game[0][0] + game[2][0] + game[1][0] == 190) {
						if (game[0][0] == 32) game[0][0] = 88;
						else if (game[2][0] == 32) game[2][0] = 88;
						else if (game[0][0] == 32) game[1][0] = 88;
					}
					else if (game[0][2] + game[2][2] + game[1][2] == 190) {
						if (game[0][2] == 32) game[0][2] = 88;
						else if (game[2][2] == 32) game[2][2] = 88;
						else if (game[1][2] == 32) game[1][2] = 88;
					}
					else if (game[0][0] + game[0][2] + game[0][1] == 190) {
						if (game[0][0] == 32) game[0][0] = 88;
						else if (game[0][2] == 32) game[0][2] = 88;
						else if (game[0][1] == 32) game[0][1] = 88;
					}
					else {
						if (game[2][0] == 32) game[2][0] = 88;
						else if (game[2][2] == 32) game[2][2] = 88;
						else if (game[2][1] == 32) game[2][1] = 88;
					}
				}											//참여자가 2개를 두고 하나가 빈 경우 방어
				else if ((game[1][0] + game[1][2] + game[0][1] + game[2][1] == 128) &&
					(game[0][0] + game[2][2] + game[0][2] + game[2][0] == 175)) {
					if (game[0][0] == 79)  game[1][0] = 88;
					else if (game[0][2] == 79) game[0][1] = 88;
					else if (game[2][0] == 79) game[2][1] = 88;
					else if (game[2][2] == 79) game[1][2] = 88;
				}										//참여자가 첫번째로 대각선픽시 바로 옆 선택
				else if ((game[1][0] + game[1][2] + game[0][1] + game[2][1] == 175) &&
					(game[0][0] + game[2][2] + game[0][2] + game[2][0] == 128)) {
					if (game[1][0] == 79) game[2][0] = 88;
					else if (game[1][2] == 79) game[0][2] = 88;
					else if (game[0][1] == 79) game[0][0] = 88;
					else if (game[2][1] == 79) game[2][2] = 88;
				}										//참여자가 첫번째로 수직수평 선택 시 바로 옆 선택
				else if ((game[0][0] + game[2][0] + game[1][0] == 96) ||
					(game[0][2] + game[2][2] + game[1][2] == 96) ||
					(game[0][0] + game[0][2] + game[0][1] == 96) ||
					(game[2][0] + game[2][2] + game[2][1] == 96)) {
					if (game[0][0] + game[2][0] + game[1][0] == 96) {
						/////////////////////////////////////////////////////////////////////////
					}
				}


				////////////////////////////////////////////////////////////////////////////////


				else {
					srand(time(0));
					x = rand() % 3;
					y = rand() % 3;
					while (game[y][x] != 32) {
						x = rand() % 3;
						y = rand() % 3;
					}
					game[y][x] = mark;
				}
				break;
			}
		default:
			break;
		}

		printf("\n   0   1   2\n");
		printf(" |---|---|---|\n");
		printf("0| %c | %c | %c |\n", game[0][0], game[0][1], game[0][2]);
		printf(" |---|---|---|\n");
		printf("1| %c | %c | %c |\n", game[1][0], game[1][1], game[1][2]);
		printf(" |---|---|---|\n");
		printf("2| %c | %c | %c |\n", game[2][0], game[2][1], game[2][2]);
		printf(" |---|---|---|\n\n");		//현재 진행상황 출력

		if (((game[0][0] == 88) && (game[0][1] == 88) && (game[0][2] == 88)) ||
			((game[1][0] == 88) && (game[1][1] == 88) && (game[1][2] == 88)) ||
			((game[2][0] == 88) && (game[2][1] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][0] == 88) && (game[2][0] == 88)) ||
			((game[0][1] == 88) && (game[1][1] == 88) && (game[2][1] == 88)) ||
			((game[0][2] == 88) && (game[1][2] == 88) && (game[2][2] == 88)) ||
			((game[0][0] == 88) && (game[1][1] == 88) && (game[2][2] == 88)) ||
			((game[0][2] == 88) && (game[1][1] == 88) && (game[2][0] == 88))) {
			checkwinner = 'c';
			break;
		}
		else if (((game[0][0] == 79) && (game[0][1] == 79) && (game[0][2] == 79)) ||
			((game[1][0] == 79) && (game[1][1] == 79) && (game[1][2] == 79)) ||
			((game[2][0] == 79) && (game[2][1] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][0] == 79) && (game[2][0] == 79)) ||
			((game[0][1] == 79) && (game[1][1] == 79) && (game[2][1] == 79)) ||
			((game[0][2] == 79) && (game[1][2] == 79) && (game[2][2] == 79)) ||
			((game[0][0] == 79) && (game[1][1] == 79) && (game[2][2] == 79)) ||
			((game[0][2] == 79) && (game[1][1] == 79) && (game[2][0] == 79))) {
			checkwinner = 'h';
			break;
		}								//승패결정
	}									//게임종료
	switch (checkwinner) {
	case 'n':
		printf("이번 게임은 무승부 입니다\n");
		none++;
		break;
	case 'h':
		printf("참여자가 이겼습니다\n");
		win++;
		break;
	case 'c':
		printf("컴퓨터가 이겼습니다\n");
		lose++;
		break;
	}
	printf("게임을 종료합니다\n\n");
}
				//6. 컴퓨터 선공 컴퓨터와 대결
				//컴퓨터 공격적 플레이
				//컴퓨터는 이길수 있으면 빠르게 이기는데에 포커스
				//(1,1)을 선점하고 (1,1)을 포함하는 한줄을 만드는데에 포커스
				//두개가 연결된 케이스를 찾았다면 한줄에 마지막 칸이 남아있는지 확인,
				//마지막 칸이 비어있다면 채우고 게임 종료,
void help(void) {
	printf("-------------------------------------------------\n");
	printf("참여자는 O, 컴퓨터/게스트는 X로 표시하며\n");
	printf("입력값 'a b'는 a번째 줄 b번째 칸을 의미합니다\n\n");
	printf("예시");
	printf("\n   0   1   2\n");
	printf(" |---|---|---|\n");
	printf("0|   |   |   |\n");
	printf(" |---|---|---|\n");
	printf("1|   |   |   |\n");
	printf(" |---|---|---|\n");
	printf("2|   |   |   |\n");
	printf(" |---|---|---|\n\n");
	printf("a와 b는 0부터 2 중의 숫자입니다\n");
	printf("컴퓨터와 플레이 할 경우\n");
	printf("참여자가 좌표를 설정하는 즉시\n");
	printf("컴퓨터도 다음 좌표를 설정합니다\n");
	printf("-------------------------------------------------\n");
	printf("메인페이지로 돌아가려면 '0'를 입력하고 Enter를 쳐주세요\n숫자 Zero 입니다\n");
	int check = 1;
	scanf("%d", &check);
	while (check != 0) {
		printf("\n유효하지 않은 숫자입니다\n다시 입력해주세요\n");
		scanf("%d", &check);
	}
}

int main() {
	printf("Tic-Tac-Toe 게임에 오신것을 환영합니다\n\n");

	while (1) {
		printf("새로운 게임\n\n");
		printf("컴퓨터와의 게임은 승패를 기록합니다\n");
		printf("현재 승패 : %d승 %d무 %d패\n",win,none,lose);
		float percent_h = (win == 0) ? 0 : (float)win / (win + none + lose) * 100;//승률
		printf("참여자 현재 승률 : %.2f%% \n", percent_h);
		float percent_c = (lose == 0) ? 0 : (float)lose / (win + none + lose) * 100;
		printf("컴퓨터 현재 승률 : %.2f%% \n\n", percent_c);
		printf("옵션을 선택해주세요\n\n");
		printf("1. 두명이서 플레이\n");
						//단순히 순서 번갈아가면서 플레이
		printf("2. 컴퓨터와 플레이(난이도 하/참여자가 시작합니다)\n");
						//랜덤시드로 좌표 설정 및 베팅
		printf("3. 컴퓨터와 플레이(난이도 하/컴퓨터가 시작합니다)\n");
						//랜덤시드로 좌표 설정 및 베팅
		printf("4. 컴퓨터와 플레이(난이도 중상/참여자가 시작합니다/머리 조금만 굴리면 난이도 하)\n");
						//(1,1)을 먼저 선점하면 유리해지는 게임
		printf("5. 컴퓨터와 플레이(난이도 상/컴퓨터가 시작합니다/잘해야 무승부)\n");
						//컴퓨터는 방어포지션, 컴퓨터가 이기기 보다는 무승부를 만드는데 초점을 둠
		printf("6 (제작중). 컴퓨터와 플레이(난이도 최상/컴퓨터가 시작합니다/컴퓨터가 승률이 압도적으로 높습니다)\n");
						//컴퓨터가 공격적인 포지션으로 바뀜, 2개가 이루어진 곳이 있다면 체크하고 게임 종료를 유도
		printf("7. 도움말\n");
		printf("8. 게임 종료\n\n");
		int o;//option
		scanf("%d", &o);
		while (o <= 0 || o >= 9) {
			printf("잘못된 입력값입니다\n다시 입력해주세요\n");
			scanf("%d", &o);
		}
		
		switch (o) {
		case 1:
			play_p2p();
			break;
		case 2:
			play_with_computer_hfirst_easy();
			break;
		case 3:
			play_with_computer_cfirst_easy();
			break;
		case 4:
			play_with_computer_hfirst_hard();
			break;
		case 5:
			play_with_computer_cfirst_hard();
			break;
		case 6:
			printf("코드가 완성되지 않은 모드입니다\n메인페이지로 이동합니다\n\n");
			//play_with_computer_hardcore();
			break;
		case 7:
			help();
			break;
		default:
			break;
		}
		if (o == 8) {
			printf("게임을 종료합니다\n\n");
			break;
		}

	}
}