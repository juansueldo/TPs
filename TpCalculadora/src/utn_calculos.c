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
int utn_getMultiplicar (int operador1, int operador2, int*resultado,char*mensaje)
{
	int retorno = -1;

	if(resultado != NULL && mensaje != NULL)
		{
			if(operador1 > 0 || operador2 >0)
			{
				*resultado = operador1 * operador2;
				retorno = 0;
			}
			else
			{
				printf("%s",mensaje);
			}

		}
		return retorno;
}
int utn_getFactorial (int operador1, int operador2, int* resultado1, int* resultado2, char*mensaje)
{
	int retorno = -1;
	if(mensaje != NULL && resultado1 != NULL && resultado2 != NULL )
	{
		if(operador1 <= 0)
		{
			printf("%s",mensaje);
		}
		else
		{
			operador1 *= (operador1 - 1);
			retorno = 0;
		}
		if(operador2 <= 0)
		{
			printf("%s",mensaje);
		}
		else
		{
			operador2 *= (operador2 - 1);
			return operador2;
		}
	}

}
