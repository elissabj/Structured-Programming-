#include <stdio.h>
int mcd(int a, int b);

int main()
{
	int x,y;
	printf("Este programa calcula el maximo comun divisor de dos numeros\n");
	printf("Ingresa el numero mayor:\n");
	scanf("%d", &x);
	printf("Ingresa el numero menor:\n");
	scanf("%d", &y);
	printf("El MCD es  %d:", mcd(x,y));
	return 0;
}

int mcd (int a, int b)
{ 
	int r;
	r=a%b;
	while (r != 0)
	{ 
			a= b;
			b = r;
			r = a%b;
					
	}	
	return b;
}
