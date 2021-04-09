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

int main(void) {
	    setbuf(stdout, NULL);
		int numero[10];
		int i;
		int contPositivos = 0;
		int contNegativos = 0;
		int acumPares = 0;


		for(i=0;i<10;i++)
		{
			printf("Ingrese un numero:\n");
			scanf("%d",&numero[i]);

			if(numero[i] % 2 == 0)
			{
				acumPares += numero[i];
			}
			if(numero[i] >= 0)
			{
				contPositivos ++;
			}
			else
			{
				contNegativos ++;
			}

		}
		printf("La cantidad de positivos es: %d",contPositivos);
		printf("La cantidad de negativos es: %d",contNegativos);
		printf("La suma de los pares es: %d",acumPares);
		/*for(i=0;i<5;i++)
		{
	    printf("Se ingreso en la posicion %d: %d\n",i, numero[i]);
		}
		printf("\nLa suma es: %d\n",suma);*/
	return EXIT_SUCCESS;
}
