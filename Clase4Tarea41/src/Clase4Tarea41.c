/*
 ============================================================================
 Name        : Clase4Tarea41.c
 Author      : Juan Sueldo
Ejercicio 4-1:
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
Por ejemplo:
5! = 5*4*3*2*1 = 120
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("cls");
	setbuf(stdout, NULL);

	int numero;
	int resultado = 1;

	printf("Ingrese un numero:\n");
	scanf("%d",&numero);

	while(numero > 1)
	{
		resultado *= numero;
		numero --;
	}
	printf("El factorial es: %d",resultado);

	return EXIT_SUCCESS;
}
