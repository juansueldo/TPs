/*
 ============================================================================
 Name        : Clase7Tarea1.c
 Author      : 
Ejercicio 7-1:Pedirle al usuario su nombre y apellido
(en variables separadas, una para el nombre y otra para el apellido).
Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo: Si el nombre es juan ignacio y el apellido es gOmEz,
la salida debería ser:Gomez, Juan Ignacio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

int main(void) {
	setbuf(stdout, NULL);
	char nombre[MAX];
	char apellido[MAX];
	char segundo[MAX];
	char nomApe [90];
	int i;

	printf("Ingrese el nombre: \n");
	gets(nombre);
	strlwr(nombre);



	printf("Ingrese el apellido: \n");
	gets(apellido);

	for(i = 0; i < MAX; i++)
	{
		strcpy(segundo,nombre[i]);
	}
	strlwr(nombre);
	strlwr(segundo);
	strlwr(apellido);



	nombre[0] = toupper(nombre[0]);
	apellido[0] = toupper(apellido[0]);
	segundo[0] = toupper(segundo[0]);
	strcpy(nomApe, apellido);
	strcat(nomApe,", ");
	strcat(nomApe, nombre);
	strcat(nomApe, segundo);

	printf("\nNombre y apellido: %s",nomApe);
	return EXIT_SUCCESS;
}
