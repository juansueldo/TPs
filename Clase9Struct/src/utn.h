/*
 * utn.h
 *
 *  Created on: 24 abr. 2021
 *      Author: operador
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
}datosAlumnos;

int utn_menu (int* opcion, char* mensaje,char* mensajeError, int min, int max, int salir);
void inicializarStruct (datosAlumnos alumno[], int tamanio);
void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void utn_getChar (char* pCaracter,char* mensaje,char* mensajeError, int reintentos);
void utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
void utn_getMostar(datosAlumnos alumno[], int tamanio);
void utn_getMostarSoloUno(datosAlumnos alumno[], int tamanio);
void utn_getOrdenarLeg (datosAlumnos alumno[], int tamanio);
void utn_getOrdenarApellido (datosAlumnos alumno[], int tamanio);
void utn_getOrdenarProm (datosAlumnos alumno[], int tamanio);
#endif /* UTN_H_ */
