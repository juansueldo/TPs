/*
 ============================================================================
 Name        : Clase5Tarea1.c
 Author      : 
 Ejercicio 5-1:Pedir el ingreso de 5 números.
 Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numero[5];
	int i;
	int suma = 0;

	for(i=0;i<5;i++)
	{
		printf("Ingrese un numero:\n");
		scanf("%d",&numero[i]);
		suma += numero[i];
	}
	for(i=0;i<5;i++)
	{
    printf("Se ingreso en la posicion %d: %d\n",i, numero[i]);
	}
	printf("\nLa suma es: %d\n",suma);

	return EXIT_SUCCESS;
}
