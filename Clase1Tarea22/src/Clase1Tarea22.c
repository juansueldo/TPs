/*
 ============================================================================
 Name        : Clase1Tarea22.c
 Author      : Juan Sueldo

Ejercicio 1-2:ingresar 3 números y mostrar el mayor de los tres.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	system("cls");
	setbuf (stdout, NULL);
	int numero;
	int mayor;
	int flag = 1;
	int i;

	for(i = 0; i < 3; i++)
	{
		printf("Ingrese un numero:\n");
		scanf("%d",&numero);

		if(flag || numero > mayor)
		{
			mayor = numero;
			flag = 0;
		}
	}
	printf("El numero %d es el mayor",mayor);

	return EXIT_SUCCESS;
}
