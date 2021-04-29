/*
 * utn.c
 *
 *  Created on: 29 abr. 2021
 *      Author: operador
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int idEmpleado;
	float sueldo;
	char puesto[40];
	char nombre[40];
}datosEmpleados;

int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir)
{

	int retorno = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max && salir != 0) {
		printf("%s", mensaje);
		scanf("%d", &bufferMenu);

		if (bufferMenu >= min && bufferMenu <= max) {
			*opcion = bufferMenu;
			retorno = 0;
		} else {
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
void inicializarStruct (datosEmpleados empleado[], int tamanio)
{
	int i;
	if(empleado != NULL && tamanio != 0)
	{
	for(i = 0; i < tamanio; i++)
	{
		empleado[i].idEmpleado = 0;
		empleado[i].sueldo = 0;
		strcpy(empleado[i].puesto, " ");
		strcpy(empleado[i].nombre, " ");

	}
	}
}
void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pNumero=bufferInt;

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}
void utn_getFloat(float* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	float bufferFloat;
	if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pNumero=bufferFloat;

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}
void utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	char bufferString[40];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferString);

			if(strlen(bufferString) < 40)
			{
				strcpy(aux, bufferString);

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}
void utn_ordenarPuesto (datosEmpleados empleado[], int tamanio)
{
	int i;
	int j;
	datosEmpleados aux;
	for(i = 0; i < tamanio -1;i++)
		{
			for(j = i+1; j < tamanio; j++)
			{
				if(strcmp(empleado[i].puesto,empleado[j].puesto)>0)
				{
					aux = empleado[i];
					empleado[i] = empleado[j];
					empleado[j] = aux;
				}
				}
			}
}
void utn_mostar(datosEmpleados empleado[], int tamanio, int i)
{

	printf("\ID empleado: %d",empleado[i].idEmpleado);
	printf(" Sueldo: %f", empleado[i].sueldo);
	printf(" Puesto: %s", empleado[i].puesto);
	printf(" Nombre: %s", empleado[i].nombre);


}
