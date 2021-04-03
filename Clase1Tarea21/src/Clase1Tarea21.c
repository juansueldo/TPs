/*
 ============================================================================
 Name        : Clase1Tarea21.c
 Author      : Juan Sueldo

Ejercicio 1-1: Ingresar dos números enteros, sumarlos y mostrar el resultado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	system("cls");
	setbuf (stdout, NULL);
	int num1;
	int num2;
	int resultado;

	printf("Ingrese un numero:\n");
	scanf("%d",&num1);

	printf("Ingrese otro numero:\n");
	scanf("%d",&num2);

	resultado = num1 + num2;

	printf("El resultado de la suma es: %d", resultado);


	return EXIT_SUCCESS;
}
