/*
 ============================================================================
 Name        : FuncionArray.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 4

int getNumero (int num[],char*mensaje, char* mensajeError, int min, int max);
void sumaPares (int num[], int size);

int main(void) {
	setbuf(stdout, NULL);
	int numero[CANTIDAD];
	int validar;
	int i;

	for(i = 0; i < CANTIDAD; i++)
	{
	validar = getNumero (numero,"Ingrese un numero:\n", "Error. Ingrese un numero:\n", -1000, 1000);
	sumaPares (numero,i);
	}
	return EXIT_SUCCESS;
}
int getNumero (int num[],char*mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	if(mensaje != NULL && mensajeError != NULL && min <= max)
	{
		printf("%s",mensaje);
		scanf("%d",&num);
		while(num > 1000 || num < -1000)
		{
			printf("%s",mensajeError);
			scanf("%d",&num);
			retorno = 0;
		}
	}
	return retorno;
}
void sumaPares (int num[], int size)
{
	int i = size;
	int acumPares = 0;
	if(num[i] % 2 == 0)
	{
		acumPares += num [i];
	}
	printf("La suma de pares es %d",acumPares);
}
