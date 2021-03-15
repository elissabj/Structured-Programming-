/* INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO
ALGORITMIA Y PROGRAMACION
INTEGRANTES: RAMOS GOMEZ ELISA 
GRUPO: 1CV2
*/

#include <string.h> 
#include <stdlib.h>
#define TAM 1000

int main(int argc, char** argv) 
{

char cad[TAM]; char histograma[256]={0};
int i,j;

printf ("Ingresa una cadena\n");
	gets (cad);
 
 for( i = 0 ; i < strlen(cad) ; ++i )
 {
  histograma[cad[i]]++;
 }
 
 for( i = 0 ; i < 256 ; ++i )
 {
  std::cout << (char) i << ": ";
  for(j = 0 ; j < histograma[i]; ++j)
  {
   std::cout << "*";
  }
  
  std::cout << std::endl;
 }
  
 system("pause");
 
 return 0;
}
	
	
