// �ϳ���ž ��ȯȣ��
// https://vidkidz.tistory.com/649 �ùķ��̼� ����

#if 1
// �ϳ���ž count�� global ������!

int count = 0;

void hanoi(int n, char from, char tmp, char to) {

	if (n == 1) {
		printf("���� 1�� %c���� %c�� �ű��.\n", from, to);
		count++;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c�� �ű��.\n", n, from, to);
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
// �ϳ���ž count�� static ������!

int hanoi(int n, char from, char tmp, char to) {
	static int count = 0;
	if (n == 1) {
		printf("���� 1�� %c���� %c�� �ű��.\n", from, to);
		count++;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c�� �ű��.\n", n, from, to);
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



