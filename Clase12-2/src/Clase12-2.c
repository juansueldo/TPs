/*
 ============================================================================
 Name        : Clase12.c
 Author      : Juan Sueldo
 Version     : 1 F
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
	int idLocalidad;
	char descripcion[30];
	int codigoPostal;
	int isEmpty;
}localidad;

typedef struct{
	int idAlumno;
	char nombre[30];
	int idLocalidad;
	int isEmpty;
}alumno;

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
