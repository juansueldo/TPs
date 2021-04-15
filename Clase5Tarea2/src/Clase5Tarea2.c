/*
 ============================================================================
 Name        : Clase5Tarea2.c
 Author      : 
 Ejercicio 5-2:Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 Determinar:Cantidad de positivos y negativos.Sumatoria de los pares.El mayor de los impares.
 Listado de los números ingresados.Listado de los números pares.
 Listado de los números de las posiciones impares.  Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 4

int ingresoNumero (int num[], int size, char*mensaje, char* mensajeError, int min, int max);
void contSigno (int num[],int size, int*pPositivos, int*pNegativos);
void sumaPares (int num[], int size, int* acumPares);

int main(void) {
	    setbuf(stdout, NULL);
		int numero[CANTIDAD];
		int validar;
		int i;
		int contPositivos = 0;
		int contNegativos = 0;
		int acumPares = 0;


		for(i = 0; i < CANTIDAD; i++)
		{
			validar = ingresoNumero (numero,i,"Ingrese un numero:\n", "Error. Ingrese un numero:\n", -1000, 1000);
			if(validar == 0)
			{
				contSigno (numero,i, &contPositivos, &contNegativos);
				sumaPares (numero, i,&acumPares);
			}
		}


			printf("\nLa cantidad de positivos es: %d",contPositivos);
			printf("\nLa cantidad de negativos es: %d",contNegativos);
			printf("\nLa suma de los pares es: %d",acumPares);



		/*printf("\nLa suma de los pares es: %d",acumPares);
		for(i=0;i<5;i++)
		{
	    printf("Se ingreso en la posicion %d: %d\n",i, numero[i]);
		}
		printf("\nLa suma es: %d\n",suma);*/
	return EXIT_SUCCESS;
}
int ingresoNumero (int num[], int size, char*mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	if(mensaje != NULL && mensajeError != NULL && min <= max)
	{
		printf("%s",mensaje);
		scanf("%d",&num[size]);
		while(num[size] > 1000 || num[size] < -1000)
		{
			printf("%s",mensajeError);
			scanf("%d",&num[size]);
			retorno = 0;
		}

	}
	return retorno;
}
void contSigno (int num[],int size, int*pPositivos, int*pNegativos)
{
	int contPositivos = 0;
	int contNegativos = 0;

	if(pPositivos != NULL && pNegativos != NULL)
	{
	if(num[size] > 0)
	{
		contPositivos ++;
		*pPositivos = contPositivos;
	}
	else
	{
		contNegativos ++;
		*pNegativos = contNegativos;
	}
	}

}
void sumaPares (int num[], int size, int* acumPares)
{
	int i = size;
	*acumPares = 0;
	if(num[i] % 2 == 0)
	{
		*acumPares += num [i];
	}

}

