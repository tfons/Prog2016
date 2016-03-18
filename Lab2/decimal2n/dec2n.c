#include <stdio.h>
#include <string.h>
#define PATH "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
/*
	Convierte un numero en base 10 a otra base n recursivamente
	by: Tonys Fonseca
*/

void dec2n(int num, int base);

int main()
{
	int num, base;

	scanf("%d %d", &num, &base);
	while(num > 0 && base > 0)
	{
		dec2n(num, base);
		printf("\n");
		scanf("%d %d", &num, &base);
	}
	return 0;
}

void dec2n(int num, int base)
{
	char x, z[5];
	int l, i;

	if ((base >= 2) && (base <= 36) && (num >= 0) && (num <=50000))//validaciones necesarias
	{
		if (num != 0)
		{
			dec2n(num / base, base);
			x = PATH[num % base];
			printf("%c", x);
		}
	}
	else//num invalido, ingresa '*' en lugar del digito
	{
		sprintf(z, "%d", num);
		l=strlen(z);
		for (i = 0; i < l; i++)
		{
			printf("*");
		}
	}
}