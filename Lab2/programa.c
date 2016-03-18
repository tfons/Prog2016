#include <stdio.h>

void aumentar(int *a);

int main()
{
	int a;

	a = 1;
	aumentar(&a);
	printf("Valor de a: %d\n", a);
	return 0;
}

void aumentar(int *a)
{
	(*a)++;
}
