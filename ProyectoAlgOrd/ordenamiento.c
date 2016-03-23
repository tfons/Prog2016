#include "stdio.h"
#include <stdlib.h>
#include <time.h>
/*Estructuras*/

/*Prototipos*/
int *copiar(int const *v, int tam);
void intercambiar(int *a, int *b);
void llenarVectorMenoraMayor(int *v, int n);
int *genRndArray(int size);
void bubbleSort(int *v, int n);
/*Principal*/
int main()
{
	int *v, *x, *z, *aux, tam, i;
	double tiempo;
	struct timeval tv1, tv2;

	/*Array de 10000*/
	v = (int *) malloc(10000 * sizeof(int));
	v = genRndArray(10000);
	/*Array de 100000*/
	x = (int *) malloc(100000 * sizeof(int));
	x = genRndArray(100000);
	/*Array de 1000000*/
	z = (int *) malloc(1000000 * sizeof(int));
	z = genRndArray(1000000);

	gettimeofday(&tv1, NULL);
	bubbleSort(v, 10000); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);

	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);

	printf("Vector de 10000. Tiempo de ordenamiento por burbuja: %f", tiempo);

	return 0;
}
/*Funciones*/
/*Retorna la copia de un array "v" */
int *copiar(int const *v, int tam)
{
	int *p = (int *) malloc(tam * sizeof(int)); //Asigna memoria para "tam" elementos
	memcpy(p, v, tam * sizeof(int)); //copia los "tam * sizeof(int)" elementos apuntados por "v" a "p"
	return p;
}
/*Intercambiar dos elementos del array*/
void intercambiar(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
/*Llena un array con valores desde 1 hasta n*/
void llenarVectorMenoraMayor(int *v, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		v[i] = i+1;
	}
}
/*Genera un array con valores aleatorios desde 1 hasta size*/
int *genRndArray(int size)
{
	int *v, i, j;

	v = (int *) malloc(size * sizeof(int)); //Asigna memoria para "size" elementos
	llenarVectorMenoraMayor(v, size); // llena el array con enteros desde 1 hasta size 
	srand(time(NULL)); //

	for (i = 0; i < size-2; i++)// desordena el array
	{
		j = rand()%(size-i);
		intercambiar(&v[i], &v[i+j]);
	}

	return v;
}
/*Ordenamiento tipo burbuja*/
void bubbleSort(int *v, int n)
{
	int i, j, band;

	i = n-1;
	band = 1;

	while(i > 0 && band)
	{
		band = 0;
		for (j = 0; j < i; j++)
		{
			if (v[j] > v[j+1])
			{
				intercambiar(&v[j], &v[j+1]);
				band = 1;
			}
		}
	}
}