#include "stdio.h"
#define N 50
#define M 50

typedef char matriz[N][M];

void leerMatriz(matriz entrada);
void escribirMatriz(matriz x, int n, int m);

int main()
{
	matriz x;

	leerMatriz(x);

	return 0;
}
/*subprogramas*/
/*Lee una matriz de caracteres*/
void leerMatriz(matriz entrada)
{
	int i, j, z, n, m;
	char a, b, t;

	i=0;
	n=0;
	z=2;
	j = 0;
	t='%';
	
	while(z > 1)
	{
		z = scanf("%c%c", &a, &b);
		entrada[i][j] = a;
		j++;	
		while(a != '%' && z > 1)
		{
			if (b == '\n')
			{
				i++;
				n=i;
				m=j;
				j=0;
			}
			z = scanf("%c%c", &a, &b);
			entrada[i][j] = a;
			j++;
		}
		//escribirMatriz(entrada, n, m);
		
		printf("%c\n", t);
		i=0;
		j=0;
	}
}
/*Escribe una matriz de caracteres*/
void escribirMatriz(matriz x, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%c ", x[i][j]);
		}
		printf("\n");
	}
}

void monos(matriz e, matriz s, int n, int m)
{
	int i, j, fam;

	fam = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			s[i][j] = fam++;
			soltarMonos(e, s, n, m, e[i][j], fam);
		}
	}
}
void soltarMonos(matriz e, matriz s, int n, int m, char arbol, int familia)
{
	if (arbol == e[i][j])

	else

}