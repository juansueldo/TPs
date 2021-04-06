/*
 * utn_calculos.c
 *
 *  Created on: 5 abr. 2021
 *      Author: operador
 */

#include <stdio.h>
#include <stdlib.h>

int utn_menu (int* opcion, char* mensaje,char* mensajeError, int min, int max, int salir)
{

	int retorno = -1;
	int bufferMenu;
	if(mensaje != NULL && mensajeError != NULL && min <= max && salir != 0)
	{
		printf("%s",mensaje);
		scanf("%d",&bufferMenu);

		if(bufferMenu >= min && bufferMenu <= max)
		{
		  *opcion = bufferMenu;
		  retorno = 0;
		}
		else
		{
		  printf("%s",mensajeError);
	    }

	}
	return retorno;
}
int utn_getSuma (int operador1, int operador2)
{
	int resul;
	resul = operador1 + operador2;
	return resul;
}
int utn_getResta (int operador1, int operador2)
{
	int resul;
	resul = operador1 - operador2;
	return resul;
}
int utn_getMultiplicar (int operador1, int operador2)
{
	int resul;
	resul = operador1 * operador2;
	return resul;
}
float utn_getDividir (int operador1, int operador2, float* retorno)
{
	float resul;
	int error;

	if(operador2 != 0)
	{
		resul = (float)operador1 / operador2;
		*retorno = resul;
		error = 1;
	}
	else
	{
		error = 0;
	}
	return error;
}
