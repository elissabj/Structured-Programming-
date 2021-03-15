/* INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO
ALGORITMIA Y PROGRAMACION
INTEGRANTES: DELGADILLO ARRENDODO MELVIN IVAN 
             RAMOS GOMEZ ELISA 
GRUPO: 1CV2
*/

#include <stdio.h>
#include <conio.h>
//#include <iostream>
#include <string.h> 
#include <stdlib.h>
#include <time.h>

#define TAM 1000
#define N 10


char txt[9];
char datos[N][20]={
"politecnico","programacion","perrito","nucelar",
"audifono","celular","desvelado","negro",
"goku","blanco"};
 
char muneco[9][7]={
  "____",
  "|  |",
  "|  |",
  "|",
  "|",
  "|",
  "|",
  "|",
  "------"
					};
 
struct pst
			{
  int pos;
  char part[5];
			}
			
parts[5]={{3,"  O"},{4,"  |"},
{5,"  |"},{6," /"},{6," \\"}};




int histo ();
int ahorcado();



int main ()
{
int z;
	
printf ("Este programa muestra un menu que implementa los siguientes ejercicios\n");
printf ("¿Que desea hacer?\n");
printf ("1.Programa que muestra un histograma\n");
printf ("2.Juego del ahorcado\n");
scanf("%d",&z);

switch(z)
 {
	case 1: histo( );
	       break;
	
	case 2: ahorcado();
	       break;
	      
	default:
	main();
	
 }
 return 0;
}

int histo (int argc, char** argv) 
{
 char cad[TAM]; 
 char histo[256]={0}; 
 int i; 
 int j;

printf ("Ingresa una cadena\n");
gets (cad);

 for( i=0;i<strlen(cad);i++ )
 {
  histo[cad[i]]++;
 }
 
 for( i=0; i<256; i++ )
 {
  printf("%s :", cad[i]);
  
  
  for(j=0; j<histo[i]; j++)
  {
   printf("*");
  }
  
     printf("\n");

 }
  
 system("pause");
 getch ();
 
 return 0;
}


int ahorcado(int argc, char *argv[])	
	
	{
  int n,m,o,p,i,j,r,eq=0;char lc,tmp[10];
 
  srand(time(NULL));
  o=rand()%N;
 
  m=strlen(datos[o]);
  p=m;
 
  txt[0]=datos[o][0];
  txt[m-1]=datos[o][m-1];
  for(n=0;n<m;n++)
  txt[n]='_';
  txt[m]=0;
  printf("Juego del ahorcado\n\n");
  tmp[0]=0;
  
  for(i=0;i<9;i++)
  printf("%s\n",muneco[i]);
 
  do{
 
    	for(j=0;j<strlen(tmp);j++)
		{
     	 lc=tmp[j];
	 	 r=p;
    		  for(n=0;n<m;n++)
      			  if(datos[o][n]==lc)
			{
        	  txt[n]=lc;
		 	 datos[o][n]='_';
			  p--;
      	    }
     			 if(r==p)
				  {
      			  strcat(muneco[parts[eq].pos],parts[eq].part);
        		  eq++;
     			 }
     		 for(i=0;i<9;i++)
	 		printf("%s\n",muneco[i]);
   	    }
 
   			 if(eq>=5)
			break;
 
    			if(p>0)
				{
      			printf("\nPalabra: %s - Descifra la palabra ",txt);
      			scanf("%10s",&tmp);
    			}
				lc=tmp[0]; 
   			 system("cls");
      }
	while(lc!='*'&&p);
 
  if(!p)
  printf("\nPalabra: %s - Ganaste, felicidades!!! \n\n",txt);
  else if(eq>=5)
  printf("\nPerdiste, lo siento!!!\n\n");
  else 
  printf("\Sigue intentando\n\n");
 
  system("PAUSE");	
  return 0;
}
	
