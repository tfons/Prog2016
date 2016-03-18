#include <stdio.h>
/* 3n + 1 Version recursiva
	Version original por Kiara Ottogalli
	Modificada por Jorge Castellanos
*/
void f(int n);

int main()
{
    int n;

    scanf("%d", &n);
    while(n>0)
    {
        f(n);
        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}

void f(int n)
{
    if (n == 1)
        printf("%d\n", n);
    else
    {
        printf("%d ", n);
        if (n % 2) 			//n % 2 != 0 - impar
            f(3 * n + 1);
        else				//n % 2 == 0 - par
            f(n >> 1);		// n/2
    }
}