#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define DM 10000
#define CM 100000
#define UM 1000000
/*Prototipos*/
int *copiar(int const *v, int tam);
void intercambiar(int *a, int *b);
void llenarVectorMenoraMayor(int *v, int n);
int *genRndArray(int size);
void bubbleSort(int *v, int n);
void selectionSort(int *v, int n);
void insertionSort(int *v, int n);
void escribir(int *v, int n);
/*Principal*/
int main()
{
	int *v, *x, *z, *aux, tam, i;
	double tiempo;
	struct timeval tv1, tv2;

	/*Array de 10000*/
	v = genRndArray(DM);
	/*Array de 100000*/
	x = genRndArray(CM);
	/*Array de 1000000*/
	z = genRndArray(UM);

	/*Array de 10000*/
	aux = copiar(v, DM);
	gettimeofday(&tv1, NULL);
	selectionSort(aux, DM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 10000. Tiempo de ordenamiento por seleccion: %f\n", tiempo);

	aux = copiar(v, DM);
	gettimeofday(&tv1, NULL);
	bubbleSort(aux, DM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 10000. Tiempo de ordenamiento por burbuja: %f\n", tiempo);

	aux = copiar(v, DM);
	gettimeofday(&tv1, NULL);
	insertionSort(aux, DM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 10000. Tiempo de ordenamiento por insercion: %f\n", tiempo);
	/*Array de 100000*/
	aux = copiar(x, CM);
	gettimeofday(&tv1, NULL);
	selectionSort(aux, CM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 100000. Tiempo de ordenamiento por seleccion: %f\n", tiempo);

	aux = copiar(x, CM);
	gettimeofday(&tv1, NULL);
	bubbleSort(aux, CM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 100000. Tiempo de ordenamiento por burbuja: %f\n", tiempo);

	aux = copiar(x, CM);
	gettimeofday(&tv1, NULL);
	insertionSort(aux, CM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 100000. Tiempo de ordenamiento por insercion: %f\n", tiempo);
	/*Array de 1000000*/
	aux = copiar(z, UM);
	gettimeofday(&tv1, NULL);
	selectionSort(aux, UM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 1000000. Tiempo de ordenamiento por seleccion: %f\n", tiempo);

	aux = copiar(z, UM);
	gettimeofday(&tv1, NULL);
	bubbleSort(aux, UM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 1000000. Tiempo de ordenamiento por burbuja: %f\n", tiempo);

	aux = copiar(z, UM);
	gettimeofday(&tv1, NULL);
	insertionSort(aux, UM); //llamada al metodo de ordenamiento
	gettimeofday(&tv2, NULL);
	tiempo = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);
	printf("Vector de 1000000. Tiempo de ordenamiento por insercion: %f\n", tiempo);

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
	#ifdef DEBUG
	int comp = 0;
	int inter = 0;
	#endif

	i = n-1;
	band = 1;

	while(i > 0 && band)
	{
		band = 0;
		for (j = 0; j < i; j++)
		{
			#ifdef DEBUG
			comp++;
			#endif
			if (v[j] > v[j+1])
			{
				intercambiar(&v[j], &v[j+1]);
				band = 1;
				#ifdef DEBUG
				inter++;
				#endif
			}
		}
	}
	#ifdef DEBUG
	printf("Burbuja -- Comparaciones: %d -- Intercambios: %d\n", comp, inter);
	#endif
}
/*Metodo de ordenamiento por seleccion*/
void selectionSort(int *v, int n)
{
	int i, j, posMenor;
	#ifdef DEBUG
	int comp = 0;
	int inter = 0;
	#endif

	for (i = 0; i < n-1; i++)
	{
		posMenor = i;
		for(j = i+1; j<n; j++)
		{
			#ifdef DEBUG
			comp++;
			#endif
			if (v[j] < v[posMenor])
				posMenor = j;
		}
		if (posMenor != i)
		{
			intercambiar(&v[i], &v[posMenor]);
			#ifdef DEBUG
			inter++;
			#endif
		}
	}
	#ifdef DEBUG
	printf("Seleccion -- Comparaciones: %d -- Intercambios: %d\n", comp, inter);
	#endif
}
/*Metodo de ordenamiento por inserción*/
void insertionSort(int *v, int n)
{
	int i, j, aux;
	#ifdef DEBUG
	int comp = 0;
	int inter = 0;
	#endif

	for (i = 1; i < n; i++)
	{
		j = i;
		aux = v[j];
		#ifdef DEBUG
		comp++;
		#endif
		while(j > 0 && aux < v[j-1])
		{
			v[j] = v[j-1];
			j--;
			#ifdef DEBUG
			comp++;
			inter++;
			#endif
		}
		v[j] = aux;
	}
	#ifdef DEBUG
	printf("Insercion -- Comparaciones: %d -- Intercambios: %d\n", comp, inter);
	#endif
}
void escribir(int *v, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}