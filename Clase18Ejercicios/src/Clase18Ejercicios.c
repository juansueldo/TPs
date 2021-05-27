/*
 ============================================================================
 Name        : Clase18Ejercicios.c
 Author      : 
1. Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia
del primer carácter recibido,por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error.

2-Utilizar aritmética de punteros.
Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
La función calculará el valor máximo de ese array
y utilizará el valor por referencia para retornar ese valor.

3-Utilizar aritmética de punteros.
Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
Realizar una función que cargue un array de 3 estudiantes.
Recibe un entero. Retorna el estudiante dado de alta
y por parámetro 0 si funcionó correctamente -1 mal.
Una vez devuelto el estudiante cargarlo en una posición del array.
Al final mostrar el array cargado

4-Utilizar aritmética de punteros.
Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
Realizar una función que cargue un array de 3 estudiantes.
Recibe un puntero al array de estudiantes, lo carga y retorna 0 si funcionó correctamente -1 mal.
Una vez cargados los estudiantes mostrar el array cargado
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

typedef struct{
	int legajo;
	char nombre[TAM];
	int edad;
}eEstudiante;

int primerFuncion (char*pResultado, char letra1, char letra2);
int segundaFuncion(int arrayInt[], int*pPuntero);
eEstudiante terceraFuncion (int *pNum);
int cuartaFuncion (eEstudiante* arrayEstudiante);

int main(void) {
	setbuf(stdout, NULL);

				//DECLARO LAS VARIABLES PARA EL PRIMER EJERCICIO
	char cadena[TAM];
	char letra1;
	char letra2 = 'e';
	int contador;

				//SOLICITO EL INGRESO DE LA CADENA
	printf("\nIngrese la cadena: ");
	gets(cadena);
	letra1 = cadena[0];

				//LLAMADO A LA PRIMER FUNCION

	contador=primerFuncion(cadena, letra1, letra2);
	printf("%s el contador es %d", cadena, contador);

				//DECLADO LAS VARIABLES PARA EL SEGUNDO EJERCICIO

	int arrayNum[4];
	int resultado;
	int i;

				//LLAMADO A LA SEGUNDA FUNCION
	for(i = 0; i < 4; i++)
	{
		printf("\nIngrese un numero: ");
		scanf("%d",&(*(arrayNum+i)));
	}
	segundaFuncion(arrayNum,&resultado);
	printf("\nEl mayor es %d",resultado);

	eEstudiante arrayEstudiante;
	int retorno;
	for(i = 0; i < 3; i++)
	{
		arrayEstudiante = terceraFuncion(&retorno);
		 if(retorno == 0)
		 {
			 continue;
		 }
		 else
		 {
		 	printf("error en carga");
		 	break;
		 }
	}

	for(int i=0; i<3; i++)
	{
		printf("\nEl nombre es: %s, la edad es: %d, el legajo es: %d", arrayEstudiante.nombre, arrayEstudiante.edad, arrayEstudiante.legajo);
	}

	eEstudiante arrayEstudiantes[3];
	int rtn;
	for(i = 0; i < 3; i++)
		{
			rtn = cuartaFuncion(arrayEstudiantes+i);
			 if(rtn == 0)
			 {
				 continue;
			 }
			 else
			 {
			 	printf("error en carga");
			 	break;
			 }
		}
		for(int i=0; i<3; i++)
		{
			printf("\nEl nombre es: %s, la edad es: %d, el legajo es: %d", (*(arrayEstudiantes+i)).nombre, (*(arrayEstudiantes+i)).edad, (*(arrayEstudiantes+i)).legajo);
		}


	return EXIT_SUCCESS;
}
int primerFuncion(char* pResultado, char letra1, char letra2)
{
	int contador=-1;
	int len;
	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		contador=0;
		len = strlen(pResultado);
		for(int i=0; i<len; i++)
		{
			if(*(pResultado+i)==letra1)
			{
				*(pResultado+i)=letra2;
				contador++;
			}
		}
	}

	return contador;
}
int segundaFuncion(int arrayInt[], int*pPuntero)
{
	int i;
	int mayor;
	int flag = 1;
	int len = 4;
	if(arrayInt != NULL && pPuntero != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(flag || *(arrayInt+i) > mayor)
			{
				mayor = *(arrayInt+i);
				*pPuntero = mayor;
				flag = 0;
			}
		}

	}
	return 0;
}
eEstudiante terceraFuncion (int *pNum)
{
	eEstudiante estudiante;
	*pNum=-1;
	if(pNum!=NULL)
	{
		printf("\nIngrese nombre");
		fflush(stdin);
		gets(estudiante.nombre);

		printf("\nIngrese edad");
		scanf("%d", &estudiante.edad);

		printf("\nIngrese legajo");
		scanf("%d", &estudiante.legajo);

		*pNum=0;
	}
	return estudiante;
}
int cuartaFuncion (eEstudiante* arrayEstudiante)
{
	int retorno = -1;
	if(arrayEstudiante != NULL)
	{
	printf("\nIngrese el legajo: ");
	scanf("%d",&(*arrayEstudiante).legajo);

	printf("\nIngrese el nombre: ");
	fflush(stdin);
	gets((*arrayEstudiante).nombre);

	printf("\nIngrese la edad: ");
	scanf("%d",&(*arrayEstudiante).edad);
	retorno = 0;
	}
	return retorno;
}
