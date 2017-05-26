#include <stdio.h>

int main()
{
	int a;
	int *arr = (int *)malloc(41);
	a = malloc_usable_size (arr);
	printf("aaaaaaaaaaaaaaa %d\n", a);
	return 0;
}
