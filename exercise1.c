/*Instituto Politecnico Nacional
Escuela Superior de Computo
Algoritmia y Programacion Estructurada
	Ramos Gomez Elisa
		1CV2 */

#include<stdio.h>
#include<stdlib.h>

int Horas(int);
int Error(int);

int main (){
	int hrs, min, hrs_1;
	printf("Este programa convierte las horas en formato 24 hrs a formato 12 hrs\n");
	printf("Ingresa la hora (formato 24 hrs) que desees convertir: "); scanf("%d", &hrs); printf(":"); scanf("%d",&min);
	
	if (hrs>=25)
	{
		printf("Error, introduce la hora correctamente");
		system("pause");
	}
	hrs_1 = Horas(hrs);
	
	printf("La hora es %d:%d",hrs_1, min);
	return 0;
}
int Horas (int x)
{
	if (x>12 && x<=24)
	return x-12;
	else if(x>0 && x<=12)
	return x;
}
