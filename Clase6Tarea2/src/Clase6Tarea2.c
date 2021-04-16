/*
 ============================================================================
 Name        : Clase6Tarea2.c
 Author      : 
 Ejercicio 6-2:Realizar un programa que permita el ingreso de 10 números enteros
 (positivos y negativos). Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente.
 (Como máximo 4 for)
 Ejemplo: Listado 1 : 4, 5, 6, 10, 18, 29 Listado 2 : -1,-5,-9,-12
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 4
void ordenar (int numPos[], int numNeg[], int cantidad);
void mostrar (int num[], int cantidad, char*mensaje);

int main(void) {
	system("cls");
	setbuf(stdout, NULL);
	int numero[MAX];
	int numeroPos[MAX];
	int numeroNeg[MAX];
	int contPositivos = 0;
	int contNegativos = 0;
	int i;


	for(i = 0; i < MAX; i++)
	{
		printf("Ingrese un numero: \n");
		scanf("%d",&numero[i]);
		if(numero[i] >= 0)
		{
			numeroPos[i] = numero[i];
			contPositivos ++;

		}
		else
		{
			numeroNeg[i] = numero[i];
			contNegativos ++;
		}
	}
	ordenar (numeroPos, numeroNeg, MAX);
	mostrar (numeroPos, contPositivos, "El orden creciente de los positivos es:\n");
	mostrar (numeroNeg, contNegativos, "\nEl orden decreciente de los negativos es:\n");

	return EXIT_SUCCESS;
}
void ordenar (int numPos[], int numNeg[], int cantidad)
{
	int i;
	int j;
	int aux;
	int aux2;

	for(i = 0; i < cantidad-1; i++)
	{
		for(j = i+1; j < cantidad ;j++)
		{
		   if(numPos[i] > numPos[j])
		   {
			   aux = numPos[i];
			   numPos[i] = numPos[j];
			   numPos[j] = aux;
		    }
		   	if(numNeg[i] < numNeg[j])
		    {
		    	aux2 = numNeg[i];
		    	numNeg[i] = numNeg[j];
		    	numNeg[j] = aux2;
		    }
		   }
	}
}
void mostrar (int num[], int cantidad, char*mensaje)
{
	int i;
	if(cantidad)
		{
		printf("%s", mensaje);
		for(i = 0; i < cantidad; i++)
		{
				printf("%d,",num[i]);
		}
	}
}
