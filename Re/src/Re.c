/*
 ============================================================================
 Name        : Matriz-Ejercicio.c
 Author      : Ornela Curcio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 2

void inicializarNumEntero(int pArray[], int cantArray);
void inicializarChar(char pArray[], int cantArray);
void inicializarNumFloat(float pArray[], int cantArray);
void getString(char mensaje[], char imput[]);
void inicializarString(char pArray[][20], int cantidadDeArray);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
int utn_getMostrar(char pArray[][20], int limite, char sex[], int leg[], int not1[], int not2[], float prom[]);
int utn_getOrdenarLegajo(int legajo[],int cantArray);
int utn_getOrdenarApellido(char apellido[][20], int cantArray);
int utn_getOrdenarPromedio(float promedio[], int cantArray,int legajo);

int main(void) {
	setbuf(stdout, NULL);

	int legajo[MAX];
	int auxInt;
	int edad[MAX];
	char sexo[MAX];
	char auxChar;
	int nota1[MAX];
	int nota2[MAX];
	float promedio[MAX];
	char apellido[MAX][20];
	char auxApellido[20];
	int i;

	inicializarNumEntero (legajo, MAX);
	inicializarChar (sexo, MAX);
	inicializarNumEntero (edad, MAX);
	inicializarNumEntero (nota1, MAX);
	inicializarNumEntero (nota2, MAX);
	inicializarNumFloat (promedio, MAX);
	inicializarString (apellido, MAX);;

	for(i=0; i<MAX; i++)
	{
		if(utn_getNumero(&auxInt, "Ingrese el numero de legajo:\n", "Error. Reingrese entre 0000 y 9999\n:", 0000, 9999, 3)==0)
		{
			legajo[i]=auxInt;
		}
		if(utn_getCaracterSexo(&auxChar, "Ingrese el sexo: femenino(f), masculino(m), otre(o)", "Error. Reingrese el sexo: femenino(f), masculino(m), otre(o)", 3)==0)
		{
			sexo[i]=auxChar;
		}
		if(utn_getNumero(&auxInt, "Ingrese la edad:\n","Error. Reingrese la edad (entre 18 y 99)\n:" ,18, 99, 3)==0)
		{
					edad[i]=auxInt;
		}
		if(utn_getNumero(&auxInt, "Ingrese la primer nota:\n","Error. Reingrese la primer nota (entre 1 y 10)\n:" ,1, 10, 3)==0)
		{
			nota1[i]=auxInt;
		}
		if(utn_getNumero(&auxInt, "Ingrese la segunda nota:\n","Error, Reingrese la segunda nota (entre 1 y 10)\n:" ,1, 10, 3)==0)
		{
			nota2[i]=auxInt;
		}

		if(utn_getString(auxApellido, "Ingrese Apellido: ", "Error. Reingrese apellido ", 3)==0)
		{
			strcpy(apellido[i], auxApellido);
		}
	}

	for(i=0; i<MAX; i++)
	{
		promedio[i]=((float)nota1[i]+nota2[i])/2;
	}

	utn_getMostrar(apellido, MAX, sexo, legajo, nota1, nota2, promedio);

	utn_getOrdenarLegajo(legajo, MAX);

	utn_getMostrar(apellido, MAX, sexo, legajo, nota1, nota2, promedio);

	utn_getOrdenarApellido(apellido, MAX);

	utn_getMostrar(apellido, MAX, sexo, legajo, nota1, nota2, promedio);

	utn_getOrdenarPromedio(promedio,MAX,legajo);

	utn_getMostrar(apellido, MAX, sexo, legajo, nota1, nota2, promedio);

	return EXIT_SUCCESS;
}
void inicializarNumEntero(int pArray[], int cantArray)
{
	int i;

	for(i=0; i<cantArray; i++)
	{
		pArray[i]=0;
	}
}
void inicializarChar(char pArray[], int cantArray)
{
	int i;

	for(i=0; i<cantArray; i++)
	{
		pArray[i]=' ';
	}
}
void inicializarNumFloat(float pArray[], int cantArray)
{
	int i;

	for(i=0; i<cantArray; i++)
	{
		pArray[i]=0;
	}
}
void getString(char mensaje[], char imput[])
{
	printf("%s", mensaje);
	gets(imput);
}
void inicializarString(char pArray[][20], int cantArray)
{
	int i;

	for(i=0; i<cantArray; i++)
	{
		strcpy(pArray[i],"");
	}
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInterno);
			if(bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar=='f'|| bufferChar=='m' || bufferChar=='o')
			{
				*pResultado=bufferChar;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[40];


	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferString);

			if(strlen(bufferString)<20)
			{
				strcpy(aux, bufferString);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getMostrar(char pArray[][20], int limite, char sex[], int leg[], int not1[], int not2[], float prom[])
{
	int retorno = -1;
	int i;

	if(pArray != NULL && sex != NULL && leg != NULL && not1 != NULL && not2 != NULL && prom != NULL  && limite>0)
	{
		for(i=0; i<limite; i++)
		{
			printf("Datos ingresados: %s %c %d %d %d %.2f ", pArray[i], sex[i], leg[i], not1[i], not2[i], prom[i]);
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}
int utn_getOrdenarLegajo(int legajo[],int cantArray)
{
	int i;
	int j;
	int aux;
	int retorno = -1;
	for(i=0; i<cantArray-1; i++)
	{
		for(j=i+1; j<cantArray; j++)
		{
			if(legajo[i]>legajo[j])
			{
				aux=legajo[i];
				legajo[i]=legajo[j];
				legajo[j]=aux;
			}

		}
		retorno=0;
	}
	return retorno;
}
int utn_getOrdenarApellido(char apellido[][20], int cantArray)
{
	int flagDesordenado = -1;
	int i;
	char auxApellido[20];

	while(flagDesordenado==-1)
	{
		flagDesordenado=0;
		for(i=0; i<cantArray-1; i++)
		{
			if(strcmp(apellido[i],apellido[i+1])>0)// compara los array.
			{
				strcpy(auxApellido,apellido[i]);
				strcpy(apellido[i],apellido[i+1]);
				strcpy(apellido[i+1],auxApellido);

				flagDesordenado = -1;
			}
		}
	}
	return 0;
}
//Ordenar por Promedio, si se repite ordenar por legajo
int utn_getOrdenarPromedio(float promedio[], int cantArray,int legajo)
{
	int i;
	int j;
	float aux;
	int auxLegajo;
	int retorno = -1;
	for(i=0; i<cantArray-1; i++)
	{
		for(j=i+1; j<cantArray; j++)
		{
			if(promedio[i]>promedio[j])
			{
				aux=promedio[i];
				promedio[i]=promedio[j];
				promedio[j]=aux;
			}
			else if(promedio[i] == promedio[j])
			{
				if(legajo[i]>legajo[j])
				{
				auxLegajo = legajo[i];
				legajo[i]=legajo[j];
				legajo[j]=aux;
			}
			}

		}
		retorno=0;
	}
	return retorno;
}
