#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EGEN_H_
#define EGEN_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

//*** ESTRUCTURA
typedef struct{
	int legajo;
	char sexo;
	int edad;
	int nota1;
	int nota2;
	float promedio;
	char apellido[30];
	int idCarrera;
	int isEmpty;
}datosAlumnos;

typedef struct{
	int idCarrera;
	char descripcionCarrera[30];
	int isEmpty;
}eCarrera;
//***

/** INICIO CABECERAS DE FUNCION*/
void inicializarStruct (datosAlumnos alumno[], int tamanio);
int utn_getId(void);
int utn_buscarPorID(datosAlumnos alumno[], int tamanio, int ID);
void utn_MostrarUno(datosAlumnos alumno);
int utn_MostrarTodos(datosAlumnos alumno[], int tamanio);
int utn_MostrarDadosDeBaja(datosAlumnos alumno[], int tamanio);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int utn_ordenar (datosAlumnos alumno[], int tamanio, int criterio);

//ABM
datosAlumnos utn_CargarDatos(void);
datosAlumnos utn_ModificarUno(datosAlumnos alumno);
int utn_Alta(datosAlumnos alumno[], int tamanio);
int utn_Baja(datosAlumnos alumno[], int tamanio);
int utn_Modificacion(datosAlumnos alumno[], int tamanio);
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir);
void utn_ordenarLeg (datosAlumnos alumno[], int tamanio);
void utn_ordenarApellido (datosAlumnos alumno[], int tamanio);
void utn_ordenarProm (datosAlumnos alumno[], int tamanio);
void utn_carrera (datosAlumnos alumno[], int tamanio, eCarrera carrera[], int cantidad);
int utn_getDescripcionCarrera (eCarrera carrera[], int tamanio,char descripcion[30], int*id);
int utn_buscarPorIdCarrera(datosAlumnos alumno[], int tamanio, int ID);
int utn_MostrarIdCarrera(datosAlumnos alumno[], int tamanio,int*ID);
/** FIN CABECERAS DE FUNCION*/
#endif
