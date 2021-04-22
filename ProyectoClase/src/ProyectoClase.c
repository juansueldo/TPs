/*
 ============================================================================
 Name        : ProyectoClase.c
 Author      : 
Desarrollar un programa que permita guardar los datos de 5 alumnos.
Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "utn_ingresoDatos.h"

#define MAX 3

int main(void) {
	setbuf(stdout,NULL);
	int legajo[MAX];
	char sexo[MAX];
	int edad[MAX];
	int nota1[MAX];
	int nota2[MAX];
	float promedio[MAX];
	char apellido [MAX][30];


	inicializarNumEntero (legajo, MAX);
	inicializarChar (sexo, MAX);
	inicializarNumEntero (edad, MAX);
	inicializarNumEntero (nota1, MAX);
	inicializarNumEntero (nota2, MAX);
	inicializarNumFloat (promedio, MAX);
	inicializarString (apellido, MAX);


	utn_getNumero (legajo, MAX, "\nIngrese el numero de legajo:\n","\nError numero ingresado no válido. Ingrese el numero de legajo:\n",0,1000);
	utn_getChar (sexo, MAX, "\nIngrese el sexo(f o m):\n","\nError dato no valido. Ingrese el sexo(f o m):\n");
	utn_getNumero (edad, MAX, "\nIngrese la edad:\n","\nError la edad no es válida. Ingrese la edad:\n",0,150);
	utn_getNumero (nota1, MAX, "\nIngrese la nota primer nota:\n","\nError la nota no es válida. Ingrese la nota:\n",0,11);
	utn_getNumero (nota2, MAX, "\nIngrese la segunda nota:\n","\nError la nota no es válida. Ingrese la nota:\n",0,11);
	utn_getString (apellido,MAX,"\nIngrese el apellido:\n");

	return EXIT_SUCCESS;
}
