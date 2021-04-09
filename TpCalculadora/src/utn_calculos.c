/*
 * utn_calculos.c
 *
 *  Created on: 5 abr. 2021
 *      Author: operador
 */

#include <stdio.h>
#include <stdlib.h>


int utn_getSuma (int operador1, int operador2, int*resultado,char*mensaje)
{
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL)
	{
		if(operador1 > 0 || operador2 >0)
		{
			*resultado = operador1 + operador2;
			retorno = 0;
		}
		else
		{
			printf("%s",mensaje);
		}

	}
	return retorno;

}
int utn_getResta (int operador1, int operador2, int*resultado,char*mensaje)
{
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL)
	{
		if(operador1 > 0 || operador2 >0)
		{
			*resultado = operador1 - operador2;
			retorno = 0;
		}
		else
		{
			printf("%s",mensaje);
		}

	}
	return retorno;

}
float utn_getDividir (int operador1, int operador2,char*mensaje, float* resultado)
{
	float resul;
	int retorno = -1;
	if(mensaje != NULL && resultado != NULL)
	{
	if(operador2 != 0)
	{
		resul = (float)operador1 / operador2;
		*resultado = resul;
		retorno = 0;
	}
	else
	{
		printf("%s",mensaje);
		retorno = 1;
	}
	}
	return retorno;
}
int utn_getMultiplicar (int operador1, int operador2, int*resultado)
{
	int retorno = -1;

	if(resultado != NULL)
		{
			if(operador1 > 0 || operador2 >0)
			{
				*resultado = operador1 * operador2;
				retorno = 0;
			}


		}
		return retorno;
}
int utn_getFactorial (int operador, long unsigned int * resultado , char*mensaje)
{
	int retorno = -1;
	long unsigned int bufferResultado = 1;

	if(mensaje != NULL && resultado != NULL )
	{
		if(operador <= 0)
		{
			printf("%s",mensaje);
		}
		else
		{
			while(operador > 1)
			{
				bufferResultado *= operador;
				operador --;
				*resultado = bufferResultado;
				retorno = 0;
			}
		}
	}
	return retorno;
}
