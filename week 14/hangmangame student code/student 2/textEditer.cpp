#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//���� ����Ʈ�� ������ �� �� ã�Ƽ�
//���ڿ��� �ٵ�� �ڵ带 �ۼ��߽��ϴ�.

int main() {
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("country.txt", "rt");
	fp2 = fopen("country2.txt", "wt");
	char s[200];
//	country���� �ٺ��� �о�� ���� �̸��� ����.
	for (int k = 0; k < 255; k++) {
		fgets(s, 99, fp1);
		int i = 0;
		for (i = 3; i < strlen(s); i++) {
			if (isascii(s[i]))
				if (isalpha(s[i]))
					break;
		}
		fprintf(fp2, "%s", _strlwr(&s[i]));
	}
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}