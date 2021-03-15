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
typedef struct cliente
{
	char nombre[50];
	int edad;
	char direccion[100];
	char pieza[30];
	float adeudo;
	int estado;
}CLIENTE;

void ingresa_cliente(CLIENTE *);
void mostrar_cliente(CLIENTE);
void registro();
void opciones(int a);

int main (void)
{
	int z;
	registro();
}


void ingresa_cliente(CLIENTE *C)
{
	printf("\nIngresa Nombre Completo:");
	fflush(stdin);
	gets(C->nombre);
	printf("Ingresa edad: ");
	fflush(stdin);
	scanf("%d", &(C->edad));
	printf("Ingresa direccion:");
	fflush(stdin);
	gets(C->direccion);
	printf("Ingresa la pieza empenada:");
	fflush(stdin);
	gets(C->pieza);
	printf("Ingresa el adeudo:");
	fflush(stdin);
	scanf("%f", &(C->adeudo));
	printf("Ingresa el estado:");
	fflush(stdin);
	scanf("%d", &(C->estado));
	printf("\n");
}
void mostrar_cliente(CLIENTE C)
{
	printf("\n Nombre: %s \n \n", C.nombre);
	printf("Edad: %d \n \n", C.edad);
	printf("Direccion: %s \n \n", C.direccion);
	printf("Pieza empenada: %s \n \n ", C.pieza);
	printf("Adeudo: %f \n \n", C.adeudo);
	printf("Estado: %d \n \n", C.estado);
}

void registro()
{
	int k;
	int opcion;
	int n;
	int r=0;
	char find[50];
	char find2[50];
	int r2=0;
	float pago;
	CLIENTE *P;
	printf("Cuantos registros de clientes desea ingresar: \n");
	scanf("%d", &k);
	P=(CLIENTE*) malloc(k*sizeof(CLIENTE));
	printf("Ingresa los datos: ");
	for(n=0; n<k; n++)
	ingresa_cliente(&P[n]);

	printf(" \t Seleccione la opcion que desea realizar:  \n");
	printf("1.- Mostrar tabla de registros\n");
	printf("2.- Buscar un cliente en particular \n");
	printf("3.- Modificar el pago de un cliente \n");
	printf("4.- Salir \n");
	scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				{
					printf("\n Los registros son: \n");
					for(n=0; n<k; n++)
					mostrar_cliente(P[n]);
				break;
				}
			case 2:
				{
					printf("\n Ingresa el cliente que deseas buscar: \n");
					fflush(stdin);
					gets(find);
					for (r=0; r<k; r++)
					{
						if (strcmp (find, P[r].nombre)==0)
							{
								mostrar_cliente(P[r]);
							}
					}
				break;
				}
			case 3:
				{
					printf("\n Dame el cliente que deseas modificar \n");
					fflush(stdin);
					gets(find2);
					for (r2=0; r2<k; r2++)
					{
						if (strcmp (find2, P[r2].nombre)==0)
							{
								printf("El adeudo es de:  %f \n", P[r2].adeudo);
								printf("Ingrese el monto que pagara: \n");
								scanf("%f", &pago);
								P[r2].adeudo-=pago;
								printf("\n El adeudo ahora es de: %f \n", P[r2].adeudo);
							}
					}
				break;
				}
		}
	free(P);
}



