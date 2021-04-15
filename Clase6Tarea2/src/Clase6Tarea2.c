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

#define MAX 3

int main(void) {
	int numero[MAX];
	int i;
	int j;
	int aux;

	for(i = 0; i < MAX; i++)
	{
		printf("Ingrese un numero: \n");
		scanf("%d",&numero[i]);
	}
		if(numero[i] > 0)
		{
			for(i = 0; i < 2; i++)
			{
				printf("\nPosicion %d, elemento %d",i,numero[i]);
				for(j=i+1; j< MAX;j++)
				{
					if(numero[i]<numero[j])
					{
						aux = numero[i];
						numero[i] = numero[j];
						numero[j]= aux;
					}
				}
			}


		}
	return EXIT_SUCCESS;
}
