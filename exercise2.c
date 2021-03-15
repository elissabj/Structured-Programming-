/* INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO
ALGORITMIA Y PROGRAMACION
INTEGRANTES: RAMOS GOMEZ ELISA 
GRUPO: 1CV2
*/

#include <stdio.h>
int parte1(int);
void parte2(int);
void Rombo();
void Entero();
int conver(int);

int main ()
{
int z;
	
printf ("Este programa muestra un menu que implementa los siguientes ejercicios\n");
printf ("¿Que desea hacer?\n");
printf ("1.Programa que muestra la figura de un rombo dentro de un rectangulo\n");
printf ("2.Programa para mostrar un entero positivo de base 10 a base 2-9\n");
scanf("%d",&z);

switch(z)
 {
	case 1: Rombo();
	       break;
	
	case 2: Entero();
	       break;
	      
	default:
	main();
	
 }
 return 0;
}

int parte1(int dMw)
{ 
	for (int i = 1; i <= dMw; i++)
	{

        for (int j = dMw-1; j >= i; j--) 
		{
            printf("*");
        }

        for (int k = 1; k <= i; k++)
		 {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
		 {
            printf(" ");
        }
 	    for (int j = dMw-1; j >= i; j--) 
		{
            printf("*");
        }
        printf("\n");
    }


    for (int i = dMw-1; i >= 1; i--) 
	{

        for (int j = i; j < dMw; j++) 
		{
            printf("*");
        }

        for (int k = 1; k <= i; k++) 
		{
            printf(" ");
        }
        
		for (int k = 1; k <= i; k++) 
		{
            printf(" ");
        }
        
        for (int j = i; j < dMw; j++) 
		{
            printf("*");
        }

        printf("\n");
    }
    return 0;
}


void Rombo()
{

int x;
	
printf ("Programa que muestra la figura de un rombo dentro de un rectangulo\n");
printf ("Ingrese un valor entero\n");
scanf ("%d",&x);
printf("El rombo es: %d", parte1(x));

}

int conver (int n, int base)
{
	int n_total =0, coef=1;
		while(n!=0)
		{
			n_total+=coef*(n%base);
			coef*=10;
			n/=base;
		} 
		return n_total;
}

void Entero ()
{
	int num=0, base=0;
	printf ("Programa que convierte un numero de dos cifras en base 10 a cualquier base entre 1-9\n");
	printf ("Ingrese el numero decimal de dos crifras que desea convertir\n");
	scanf ("%d",&num);
	printf ("Ingresa la base al que desea convertirlo\n");
	scanf ("%d",&base);
		printf ("El numero en base 10 equivale al numero: %d de la base ingresada ", conver(num, base));
		
} 



