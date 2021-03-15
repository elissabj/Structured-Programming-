/* INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO
ALGORITMIA Y PROGRAMACION
INTEGRANTES: DELGADILLO ARRENDODO MELVIN IVAN 
             RAMOS GOMEZ ELISA 
GRUPO: 1CV2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find (char* cadena, char* palabra);
void buscar ();
int pascal();

int main ()
{
int z;
	
printf ("Este programa muestra un menu que implementa los siguientes ejercicios\n");
printf ("¿Que desea hacer?\n");
printf ("1.Programa que ubica la palabra de una cadena\n");
printf ("2.Triangulo de Pascal\n");
scanf("%d",&z);

switch(z)
 {
	case 1: buscar();
	       break;
	
	case 2: pascal();
	       break;
	      
	default:
	main();
	
 }
 return 0;
}
 
int find(char* cadena, char* palabra)
{
 
    int i, j = 0;
 
    for(i = 0; i < strlen(cadena); i++)
	{
        if(palabra[j] == cadena[i])
		{
            ++j;
 
            if(j == strlen(palabra))
                return (2 + i - j);
        }
 
        else j = 0;
    }
 
    return -1;
}
 
 
void buscar()
{ 
 int ch;
    int pos;
    char cadena[50],palabra[50];
 		
 		while ((ch = getchar()) != EOF && ch != '\n'); /* desechamos los caracteres restantes de la linea */
    printf("Ingrese la cadena: ");
    gets(cadena);
 
    printf("Ingrese la palabra a buscar: ");
    gets(palabra);
 
    pos = find(cadena, palabra);
 
    if(pos == -1)
        printf("La cadena no esta.!\n");
 
    else
        printf("La cadena empieza en la posicion %d.!\n", pos);
 
    system("Pause");
 
   // return 0;
}

int pascal()
{
 	int z;
	printf("Ingresa un numero para la magnitud del triangulo: ");
	scanf("%i", &z);
	
   int pasc[z];
   int x, i, j;
 
   x=0;
 
   for (i=1; i<=z ; i++)
   {
         for (j=x; j>=0; j--)
         {
             if(j==x || j==0)
             {
                  pasc[j] = 1;
             }
             else
             {
                  pasc[j] = pasc[j] + pasc[j-1];
             }
         }
 
        x++;
        printf("\n");
        for (j=1; j<=z-i; j++)
             printf("   ");
 
        for(j=0; j<x; j++)
        {
             printf("%3d   ", pasc[j]);
        }
   }
return 0;
}
