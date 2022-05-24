#include <stdio.h>
#include <string.h>

int main() {

	char a[100];
	char b[100];

	scanf("%s", a); 
	scanf("%s", b);

	for (int i = 0; i < strlen(b); i++)
	{
		*strchr(a, b[i]) = '_';
	}

	printf("%s", a);

	return 0;
}
