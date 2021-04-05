/*
 * utn_calculos.c
 *
 *  Created on: 5 abr. 2021
 *      Author: operador
 */

#include <stdio.h>
#include <stdlib.h>

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
		(*retorno) = resul;
		error = 1;
	}
	else
	{
		error = 0;
	}
	return error;
}
