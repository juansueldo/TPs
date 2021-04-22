/*
 * utn_ingresoDatos.c
 *
 *  Created on: 21 abr. 2021
 *      Author: juan-
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void utn_getNumero (int numero[], int tamanio, char*mensaje, char*mensajeError,int min, int max)
{
	int i;
	if(mensaje != NULL && mensajeError != NULL && min <= max)
	{
		for(i = 0; i < tamanio; i++)
		{
		printf("%s",mensaje);
		scanf("%d",&numero[i]);
		while(numero[i] < min || numero[i] > max)
		{
			printf("%s",mensajeError);
			scanf("%d",&numero[i]);
		}
		}
	}

}
void utn_getChar (char letra[], int tamanio, char*mensaje)
{
	int i;
		if(mensaje != NULL)
		{
			for(i = 0; i < tamanio; i++)
			{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&letra[i]);
			}
		}
}
void utn_getString (char string[][30], int tamanio, char*mensaje)
{
	int i;
		if(mensaje != NULL)
		{
			for(i = 0; i < tamanio; i++)
			{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%s",&string[i][30]);
			}
		}
}

