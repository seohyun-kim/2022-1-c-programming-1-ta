#include <stdio.h>

int main() {

	int a = 10;
	char b = 'A';


	int* pa = &a;
	char* pb = &b;

	printf("a: %d | &a: %X | *pa: %d | pa: %X | &pa: %X \n", a, &a, *pa, pa, &pa);

	printf("pa size: %d Byte | pb size : %d Byte \n", sizeof(pa), sizeof(pb));

	printf("pa + 1 : %X , pb+1 : %x \n", pa + 1, pb + 1);

	int arr[5] = { 10,20,30,40,50 };
	int* p = arr;

	printf("arr : %X,  &arr:%d \n", arr, &arr);
	printf("* arr: % d, arr[0] : % d \n", *arr, arr[0]);
	printf("arr + 1 : % X,  *(arr + 1) : % d \narr[1] : % d\n", arr + 1, *(arr + 1), arr[1]);

	printf("p : %X,  &p:%X, *p: %d, *(p+1):%d \n", p, &p, *p, *(p + 1));


	return 0;
}