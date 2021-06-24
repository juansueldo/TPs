/*
 ============================================================================
 Name        : PruebaClase20.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	float precio;
	char nombre[30];
	int isEmpty;
}eProducto;

int main(void) {
	setbuf(stdout, NULL);
	eProducto auxProducto;
	int cantidadEscrita;
	FILE *pArchivo;

	strcpy(auxProducto.nombre, "HP");
	auxProducto.id = 1001;
	auxProducto.precio = 65900.80;
	auxProducto.isEmpty = 0;

		printf("%d--%s--$%.2f--%d", auxProducto.id,auxProducto.nombre,auxProducto.precio,auxProducto.isEmpty);

	pArchivo = fopen("banco.txt","w");
	if (pArchivo != NULL)
	{
	cantidadEscrita=fwrite(&auxProducto, sizeof(eProducto), 1, pArchivo);
	if (cantidadEscrita < 1)
	{
		printf("\nError al escribir el archivo");
	}
	}
	fclose(pArchivo);
	return EXIT_SUCCESS;
}
