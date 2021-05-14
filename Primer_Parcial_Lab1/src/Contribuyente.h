

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

#include "utn.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30

#define MAX 50

typedef struct {
	char nombre [MAX_CHARS_CADENAS];
	char apellido [MAX_CHARS_CADENAS];
	int idContribuyente;
	char cuil [14];
	int isEmpty;
} eContribuyente;

int eContribuyente_inicializar (eContribuyente arrayContribuyentes[],int tam);
int eContribuyente_buscarLibre (eContribuyente arrayContribuyentes[],int tam);
int eContribuyente_buscarId (eContribuyente arrayContribuyentes[],int tam,int id);
eContribuyente eContribuyente_cargarPantalla (void);
int eContribuyente_alta (eContribuyente arrayContribuyentes[], int tam, int *pIdContador);
int eContribuyente_baja (eContribuyente arrayContribuyentes[], int tamanio);
int eContribuyente_modificar (eContribuyente arrayContribuyentes[], int tamanio);
eContribuyente eContribuyente_modificarUno (eContribuyente arrayContribuyentes, int campoModificar);
int eContribuyente_mostrarTodos (eContribuyente arrayContribuyentes[],int tamanio);
void eContribuyente_mostrarUno (eContribuyente arrayContribuyentes[],int tamanio);


#endif /* CONTRIBUYENTE_H_ */
