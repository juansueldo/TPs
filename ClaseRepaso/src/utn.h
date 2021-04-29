/*
 * utn.h
 *
 *  Created on: 29 abr. 2021
 *      Author: operador
 */

#ifndef UTN_H_
#define UTN_H_

typedef struct{
	int idEmpleado;
	float sueldo;
	char puesto[40];
	char nombre[40];
}datosEmpleados;

int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir);
void inicializarStruct (datosEmpleados empleado[], int tamanio);
void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void utn_getFloat(float* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
void utn_ordenarPuesto (datosEmpleados empleado[], int tamanio);
void utn_mostar(datosEmpleados empleado[], int tamanio, int i);

#endif /* UTN_H_ */
