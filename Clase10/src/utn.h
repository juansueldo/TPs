/*
 * utn.h
 *
 *  Created on: 28 abr. 2021
 *      Author: Juan
 */

#ifndef UTN_H_
#define UTN_H_

typedef struct{
	int legajo;
	char sexo;
	int edad;
	int nota1;
	int nota2;
	float promedio;
	char apellido[30];
	int isEmpty;
}datosAlumnos;

int utn_menu (int* opcion, char* mensaje,char* mensajeError, int min, int max, int salir);
int inicializarIsEmpty (datosAlumnos alumno[], int tamanio);
void utn_getMostar(datosAlumnos alumno[], int tamanio, int i);
void inicializarStruct (datosAlumnos alumno[], int tamanio);
void utn_getChar (char* pCaracter,char* mensaje,char* mensajeError, int reintentos);
void utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int buscarLibre (datosAlumnos alumno[], int tamanio);
void utn_ordenarLeg (datosAlumnos alumno[], int tamanio);
void utn_ordenarApellido (datosAlumnos alumno[], int tamanio);
void utn_ordenarProm (datosAlumnos alumno[], int tamanio);
#endif /* UTN_H_ */

