/*
 ============================================================================
 Name        : Clase.c
 Author      : Juan Sueldo
b-Entrada/salida
Pedir el sueldo al usuario. Sumarle un 10% e informarle cuál será su sueldo con aumento.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	system("cls");
	setbuf(stdout, NULL);
	float sueldo;
	float amuento = 1.1;
	float nuevoSueldo;

	printf("Ingrese su sueldo:\n");
	scanf("%f",&sueldo);

	nuevoSueldo = sueldo * amuento;

	printf("El sueldo con el amuento es: $%.2f", nuevoSueldo);
	return EXIT_SUCCESS;
}
