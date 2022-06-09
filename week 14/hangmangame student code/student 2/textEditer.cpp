#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//국가 리스트를 마땅한 걸 못 찾아서
//문자열을 다듬는 코드를 작성했습니다.

int main() {
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("country.txt", "rt");
	fp2 = fopen("country2.txt", "wt");
	char s[200];
//	country에서 줄별로 읽어와 영어 이름만 뗀다.
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