#ifndef PANTALLAS_H_
#define PANTALLAS_H_

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30

#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

#define LCD 1
#define LED 2
#define MAX 1000
#define CANT 20

typedef struct {
	char calle [MAX_CHARS_CADENAS];
	int altura;
	char localidad [MAX_CHARS_CADENAS];
	int codigoPosta;
	int isEmpty;
} eDireccion;

typedef struct {
	int idPantalla;
	char nombre[MAX_CHARS_CADENAS];
	eDireccion direccion;
	int codigo;
	float precio;
	int isEmpty;
} ePantalla;

typedef struct {
	int idPublicidad;
	char cuit[14];
	int dias;
	char video[MAX_CHARS_CADENAS];
	int idPantalla;
	int isEmpty;
} ePublicidad;

typedef struct {
	int codigo;
	char descripcion[MAX_CHARS_CADENAS];
} eTipo;

int ePantalla_inicializar (ePantalla arrayPantalla[],int tam);
int eTipo_inicializar (eTipo arrayTipo[],int cant);
int ePantalla_obtenerNombre (eTipo arrayTipo[],int cant,int codigo,char detalle[20]);
int ePantalla_buscarLibre (ePantalla arrayPantalla[],int tam);
int ePantalla_buscarId (ePantalla arrayPantalla[],int tam,int id);
ePantalla ePantalla_cargarPantalla (void);
int ePantalla_alta (ePantalla arrayPantalla[], int tam, int *pIdContador);
int ePantalla_ObtenerID (void);
void ePantalla_mostrarUno (ePantalla arrayPantalla[],int tam,eTipo arrayTipo[],int cant);
int ePantalla_mostrarTodos (ePantalla arrayPantalla[],int tam, eTipo arrayTipo[], int cant);
ePantalla ePantalla_modificarUno (ePantalla arrayPantalla, int campoModificar);
int ePantalla_modificarPantallas (ePantalla arrayPantalla[], int tam, eTipo arrayTipo[], int cant);
int ePantalla_baja (ePantalla arrayPantalla[], int tam, eTipo arrayTipo[], int cant);


#endif /* LED_H_ */
