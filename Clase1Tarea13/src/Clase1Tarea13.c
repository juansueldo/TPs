/*
 ============================================================================
 Name        : Clase1Tarea13.c
 Author      : Juan Sueldo

c-Control de Flujo
Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)
Si ingresa una edad menor a 18 años y un estado civil distinto a "Soltero",
mostrar el siguiente mensaje: 'Es muy pequeño para NO ser soltero.'
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("cls");
	setbuf(stdout, NULL);
	int edad;
	char estado;

	printf("Ingrese su edad:\n");
	scanf("%d",&edad);

	printf("Ingrese su estado civil('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado):\n");
	fflush(stdin);
	scanf("%c",&estado);
	while(estado != 's' && estado != 'c' && estado != 'v' && estado != 'd')
	{
		printf("Error. Ingrese su estado civil('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado):\n");
		fflush(stdin);
		scanf("%c",&estado);
	}

	if(edad < 18 && estado != 's')
	{
		printf("Es muy pequeño para NO ser soltero");
	}
	return EXIT_SUCCESS;
}
