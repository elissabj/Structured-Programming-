/* INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO
ALGORITMIA Y PROGRAMACION
INTEGRANTES: RAMOS GOMEZ ELISA 
GRUPO: 1CV2
*/

#include <stdio.h>
#include<stdlib.h>

void euclides ();
int mcd (int a, int b);
int per ();
int perfecto (int a);

int main ()
{
int z;
	
printf ("Este programa muestra un menu que implementa los siguientes ejercicios\n");
printf ("Que desea hacer?\n");
printf ("1.Programa que muestra el maximo comun divisor (mcd)\n");
printf ("2.Programa para mostrar los primeros n numeros perfectos\n");
scanf("%d",&z);

switch(z)
 {
	case 1: euclides();
	       break;
	
	case 2: per();
	       break;
	      
	default:
		system ("cls");
		main();
	
 }
 
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

void euclides()
{

int x,y;
	
printf ("Programa que muestra el maximo comun divisor (mcd)\n");
printf ("Ingrese el primero valor entero\n");
scanf ("%d",&x);
printf ("Ingresa el segundo valor entero\n");
scanf ("%d", &y);
printf("El mcd es: %d", mcd(x,y));

}

int per ()
{
int x,num=0,i=1,j=1;
puts("Ingresa el numero de numeros perfectos que deseas desplegar" ) ;
scanf("%d",&x);
while(num<=x){
    num=num+perfecto(i);
    if(perfecto(i))
     {
       printf("el %d perfecto es %d \n",j,i ) ;
       j++;
       }
    i++;
   }
 system("pause") ;
}      
      
int perfecto(int x)
{
    int acum=0,y=1;
    while(y<x)
    {
              if(!(x%y))
              {
                 acum=acum+y;
              }
              y++;
    }
              if(acum==x)
              return 1;
              else
              return 0;
} 
