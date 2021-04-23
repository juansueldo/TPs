/*
 ============================================================================
 Name        : Clase9.c
 Author      : Juan Sueldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales{
	int numero;
	char nombre[20];
	char apellido[20];
	char calle[20];
};

int main(void) {
	setbuf(stdout,NULL);
	struct datosPersonales agenda[3];
	int i;

	for(i=0;i<3;i++)
	{
	printf("Ingrese el nombre:\n");
	gets(agenda[i].nombre);
	fflush(stdin);

	printf("Ingrese el apellido:\n");
	gets(agenda[i].apellido);
	fflush(stdin);
	}
	for(i=0;i<3;i++)
		{
	printf("Su apellido es %s y el nombre %s\n",agenda[i].apellido,agenda[i].nombre);
		}
	return EXIT_SUCCESS;
}
