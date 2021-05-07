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

typedef struct
{
    int idDuenio;
    char nombre[30];
    int edad;
    char sexo;
    int isEmpty;
}duenio;

typedef struct
{
    char especie[30];
    char raza[30];
    int isEmpty;
}eRaza;

typedef struct
{
    int idMascota;
    char nombre[30];
    eRaza raza;
    char sexo;
    int idDuenio;
    int isEmpty;
}mascota;

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
