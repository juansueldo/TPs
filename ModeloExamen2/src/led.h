#ifndef LED_H_
#define LED_H_

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
#define ID_INCREMENTAL 0

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
	int id_tipo;
	float precio;
	int isEmpty;
} ePantalla;

typedef struct {
	int idPublicidad;
	int cuit;
	int dias;
	char video[MAX_CHARS_CADENAS];
	int idPantalla;
} ePublicacion;

typedef struct {
	int codigo;
	char descipcion[MAX_CHARS_CADENAS];
} eTipo;

int _ObtenerID();
void ePantalla_Inicializar(ePantalla arrayPantallaPantalla[], int TAM);
ePantalla ePantalla_CargarDatos(void);
int ePantalla_Alta(ePantalla arrayPantalla[], int TAM);
void ePantalla_MostrarUno (ePantalla arrayPantalla[],int tamanio,eTipo arrayTipo[],int cant);
int ePantalla_MostrarTodos(ePantalla arrayPantalla[], int TAM);
int ePantalla_Modificacion(ePantalla arrayPantalla[], int TAM);
int ePantalla_BuscarPorID(ePantalla arrayPantalla[], int TAM, int ID);
ePantalla ePantalla_ModificarUno(ePantalla arrayPantalla);
int ePantalla_Baja (ePantalla arrayPantalla[], int TAM);
int ePantalla_ObtenerNombre (eTipo arrayTipo[],int cant,int codigo,char detalle[MAX_CHARS_CADENAS]);





#endif /* LED_H_ */
