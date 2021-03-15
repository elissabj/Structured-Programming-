/* INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO
ALGORITMIA Y PROGRAMACION
INTEGRANTES: DELGADILLO ARRENDODO MELVIN IVAN 
             RAMOS GOMEZ ELISA 
GRUPO: 1CV2
*/

#include<stdio.h>		
#include<stdlib.h>		
#include<string.h>		
#include<time.h>		
#define TAM 40			// Define el tamaño de la sopa de letras 
#define NUM 10			// Define el numero de palabras que estaran presentes en la sopa de letras 
#define PAL 21			// Define el numero de palabras que seran declaradas 


void sopa(int a);
void coloca_palabras(char sopa[TAM][TAM][2],char palabras[PAL][20],char temp[NUM][20]);
void rellena_espacios(char sopa[TAM][TAM][2]);
void muestra_sopa(char sopa[TAM][TAM][2],char temp[NUM][20]);

int main() 
{
	int a;
	srand(time(NULL));
	printf("Este programa muestra una sopa de letras\n");
	printf("Seleccione una de las dos tematicas\n");
	printf("1.- Nombres de Princesas Disney\n");
	printf("2.- Paises\n");
	scanf("%d",&a);			
	system("cls"); 			// Funcion que limpia la pantalla

	sopa(a);				// Funcion de la sopa de letras
	
	system("pause>null"); 	
	
	return 0;			
}

void sopa(int a)			// Palabras que se verán en la sopa de letras 
{
	int i;
	char temp[NUM][20];
	
	char sopa[TAM][TAM][2];	// Se guarda la sopa de letras y las respuestas
	char palabras[PAL][20]; 	// Aqui se guardan las palabras que estaran en la sopa de letras
	char palabras1[PAL][20]= {{"blancanieves"},{"cenicienta"},{"bella"},{"aurora"},{"pocahontas"},
							{"ariel"},{"jazmin"},{"mulan"},{"tiana"},{"rapunzel"},
							{"merida"},{"anna"},{"elsa"},{"moana"},{"alicia"},
							{"esmeralda"},{"janeporter"},{"kidagakash"},{"kiara"},{"mia"},{"diana"}}; // Nombres de princesas Disney y Lady Dee
							
	char palabras2[PAL][20]= {{"mexico"},{"francia"},{"canada"},{"venezuela"},{"chile"},
							{"argentina"},{"peru"},{"bolivia"},{"italia"},{"españa"},
							{"alemania"},{"inglaterra"},{"rusia"},{"japon"},{"china"},{"iran"},
							{"turquia"},{"australia"},{"belgica"},{"dinamarca"},{"eslovenia"}}; // Paises
	
	if (a==1)				// Si el usuario ingreso 1 entonces la sopa tratara de princesas disney
	{
		for (i=0;i<=PAL;i++)
		{
			strcpy(palabras[i],palabras1[i]); // Copiara todas las palabras de la tematica de las princesas en un arreglo 
		}
	}
	else if (a==2)			// Si el usuario ingreso 2 entonces la sopa tratara de los paises
	{
		for(i=0;i<=PAL;i++)
		{
			strcpy(palabras[i],palabras2[i]); // Copiara todas las palabras de la tematica de los paises en un arreglo 
		}
	}
	else			// Si el usuario no pone el valor valido, regresara al menu de nuevo
	{
		printf("Ingrese un valor valido\n");
		main();
	}
	
	coloca_palabras(sopa,palabras,temp);		// Llama una funcion que se encarga de seleccionar palabras aleatorias y colocarlas en la sopa y las respuestas
	rellena_espacios(sopa);						// Rellena los espacios que faltaban
	muestra_sopa(sopa,temp);					// Funcion para que muestre la sopa de letras 
	return;
}

void coloca_palabras(char sopa[TAM][TAM][2],char palabras[PAL][20],char temp[NUM][20])		// Esta funcion coloca palabras en las matrices
{
	int i,j,k,al1[NUM],aux=0;
	
	for(i=0;i<TAM;i++)					// Primero limpiamos las matrices completamente 
	{
		for(j=0;j<TAM;j++)
		{
			sopa[i][j][0]='-';			// Limpiar matriz de sopa de letras
			sopa[i][j][1]=' ';			// Limpiar matriz de respuestas 
		}
	}
	
	for(i=0;i<NUM;i++)					// Genera cierto numero de numeros aleatorios 
	{
		al1[i]=rand()%PAL;				// Puede tomar hasta 20 valores ya que son los valores declarados
		
		for(j=0;j<i;j++)				// El for sirve de comparativo
		{
			if(al1[i]==al1[j])			// Si el nuevo numero que se genero aleatoriamente es igual a cualquier elemento que ya estuviese dentro del arreglo, entonces
			{
				i--;					// Se decrementa i para que sobreescriba el ultimo elemento(el repetido)
			}
		}
		
		strcpy(temp[i],palabras[al1[i]]);	// Una vez comprobado que no es un numero repetido este se usa para seleccionar una palabra del arreglo "Palabras"
	}										// Luego lo copia tal cual en el arreglo temp (Que será usado para colocar las palabras en la sopa)
	
	for(k=0;k<NUM;k++)						// Este irá seleccionando cada una de las palabras aleatorias 
	{
		al1[0]=rand()%2;			// Selecciona si se pondra vertical (1) u horizontal (0), aleatoriamente
		al1[1]=strlen(temp[k]);		// Guarda el tamaño de la palabra n 
		al1[2]=TAM-al1[1];			// Le resta al tamaño de la sopa el de la palabra para que no se salga 
		al1[3]=rand()%al1[2]+1;		// Selecciona aleatoriamente la posicion en donde empezara a escribir la palabra 
		al1[4]=rand()%TAM;			// selecciona la fila o columna de cada palabra
			
		if (al1[0]==0)				// Si es 0 la posiciona horizontalmente 
		{
			aux=0;					// Inicializa la bandera auxiliar por si fue prendida en algun momento
			for(j=al1[3];j<al1[3]+al1[1];j++)	// Lo hace para probar si hay alguna letra dentro del rango de escritura
			{
				if(sopa[al1[4]][j][0]!='-')		// Si hay una letra entonces
				{
					aux=1;						// Mandar a 1 la bandera auxiliar
				}
			}
			
			if (aux==1)							// Si se prendio la bandera entonces.....
			{
				k--;							// Decrementar k para que elija otra nueva posicion aleatoria
			}
			else 								// Si no se prendio entonces quiere decir que puede escribir la palabra libremente
			{
				for(j=al1[3];j<al1[3]+al1[1];j++)	//	Iniciara a escribir apartir de una celda aleatoria que al terminar de escribir la palabra esta no se salga de la matriz
				{
					sopa[al1[4]][j][0]=temp[k][j-al1[3]];	//En la matriz de sopa [0] en las posiciones aleatorias se guarda una letra de la palabra que hay en temp
					sopa[al1[4]][j][1]=temp[k][j-al1[3]];	//En la matriz de respuestas [1[ en las posiciones aleatorias se guarda una letra de la palabra que hay en temp
				}
			}
		}
		
		else if (al1[0]==1)					// Para las posiciones verticales
		{
			aux=0;							// Un poco de lo mismo, bandera se inicializa en 0
			for(i=al1[3];i<al1[3]+al1[1];i++)		// Checa las posiciones 
			{
				if(sopa[i][al1[4]][0]!='-')			// Checa si hay alguna letra estorbando :V
				{
					aux=1;							// Si la hay manda la bandera a 1
				}
			}
			
			if (aux==1)								// Si la bandera fue prendida no puede escribir en esta posicion
			{
				k--;								// Por lo que decrementa k para que elija otra posicion para esta palabra 
			}
			
			else									// Si la bandera no se prendio entonces .....
			{
				for(i=al1[3];i<al1[3]+al1[1];i++)	
				{
					sopa[i][al1[4]][0]=temp[k][i-al1[3]]; //En la matriz de sopa [0] en las posiciones aleatorias se guarda una letra de la palabra que hay en temp
					sopa[i][al1[4]][1]=temp[k][i-al1[3]]; //En la matriz de respuestas [1] en las posiciones aleatorias se guarda una letra de la palabra que hay en temp
				}
			}	
		}
	}
	
	return;
}

void rellena_espacios(char sopa[TAM][TAM][2])
{
	int i,j;
	
	for(i=0;i<TAM;i++)
	{
		for(j=0;j<TAM;j++)
		{
			if(sopa[i][j][0]=='-')
			{
				sopa[i][j][0]=(97+rand()%26);
			}
		}
	}
	return;
}
void muestra_sopa(char sopa[TAM][TAM][2],char temp[NUM][20])		// Esta funcion mostrara la sopa de letras en pantalla y luego las respuestas
{
	int i,j,n;
	
	printf("Esta es la sopa de letras\n\n");
	
	for(i=0;i<TAM;i++)						// Recorre elemento por elemento la matriz de la sopa de letras
	{
		for(j=0;j<TAM;j++)
		{
			printf("%c ",sopa[i][j][0]);	// Imprime elemento por elemento 
		}
		
		if (i<NUM)							// Si i es menor que 10 entonces
		{
			printf("\t %s",temp[i]);		// Mostrara las palabras que fueron guardadas en el arreglo xD 
		}
		printf("\n");						// Salto de linea para darle caracter de matriz :3
	}
	
	printf("\nIngresa 1 si ya encontraste todas las respuestas\n");
	scanf("%d",&n);
	system("cls");
	
	if(n==1)											//Si el usuario ingresa 1 entonces mostrara las respuestas
	{
		printf("Estas son las respuestas\n\n");
		
		for(i=0;i<TAM;i++)								// Recorre elemnto por elemento la matriz de las respuestas
		{
			for(j=0;j<TAM;j++)
			{
				printf("%c ",sopa[i][j][1]);			// Imprime la matriz de las respuestas elemento por elemento
			}
			
			if (i<NUM)									// Si i es menor que 10 
			{	
				printf("\t %s",temp[i]);				// Mostrar las palabras a un costado 
			}
			printf("\n");								// Salto de linea para darle caracter de matriz 
		}
	}
	else
	{
		muestra_sopa(sopa,temp);								// Si el usuario ingresa otra cosa entonces no hace nada 
	}
		
	return;												// Sale de la subrutina
}

