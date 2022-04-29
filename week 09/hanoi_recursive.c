// 하노이탑 순환호출
// https://vidkidz.tistory.com/649 시뮬레이션 게임

#if 1
// 하노이탑 count를 global 변수로!

int count = 0;

void hanoi(int n, char from, char tmp, char to) {

	if (n == 1) {
		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
		count++;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);
		count++;
		hanoi(n - 1, tmp, from, to);
	}
}

int main() {

	hanoi(5, 'A', 'B', 'C');
	printf(" count = %d", count);
	return 0;
}
#endif




#if 0
// 하노이탑 count를 static 변수로!

int hanoi(int n, char from, char tmp, char to) {
	static int count = 0;
	if (n == 1) {
		printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
		count++;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);
		count++;
		hanoi(n - 1, tmp, from, to);
	}
	return count;
}

int main() {
	
	printf("count = %d", hanoi(5, 'A', 'B', 'C'));
	return 0;
}
#endif



