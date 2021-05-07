/*
 ============================================================================
 Name        : Clase12.c
 Author      : Juan Sueldo
 Division    : 1 E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

typedef struct{
	int idProducto;
	char descripcion[30];
	float precio;
	int idProveedor;
	int isEmpty;
}producto;

typedef struct{
	char calle[20];
	int numero;
	char localidad[20];
	int isEmpty;
}direccion;

typedef struct{
	int idProveedor;
	char razonSocial[30];
	direccion direccion;
	int isEmpty;
}proveedor;





int main(void) {

	return EXIT_SUCCESS;
}
