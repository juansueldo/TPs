/*
 ============================================================================
 Name        : Clase1Tarea14.c
 Author      : Juan Sueldo
d-Operadores Logicos
Aplicando el concepto de Operadores Lógicos con valores booleanos en el condicional:
Solicitar un número al usuario
Informar si el mismo es par o impar.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	system("cls");
	setbuf(stdout, NULL);
	int numero;

	printf("Ingrese un numero:\n");
	scanf("%d",&numero);

	if(numero % 2 == 0)
	{
		printf("El numero %d es par",numero);
	}
	else
	{
		printf("El numero %d es impar",numero);
	}
	return EXIT_SUCCESS;
}
