/*
 ============================================================================
 Name        : Juan Sueldo
 Author      : 
 Ejercicio 6-1:

Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio de valores de dichas variables.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swapeo (int* operador1, int* operador2);

int main(void) {
	int num1 = 5;
	int num2 = 9;


	printf("\nEl numero 1 es: %d",num1);
	printf("\nEl numero 2 es: %d\n",num2);

	swapeo (&num1, &num2);

	printf("\nEl numero 1 es: %d",num1);
	printf("\nEl numero 1 es: %d",num2);

	return EXIT_SUCCESS;
}
void swapeo (int* operador1, int* operador2)
{
	int auxiliar;
	auxiliar = *operador1;
	*operador1 = *operador2;
	*operador2 = auxiliar;

}
