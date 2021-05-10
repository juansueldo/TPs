/*
 * Bibliotecas_utn.h
 *
 *  Created on: 9 may. 2021
 *      Author: Juan
 */

#ifndef BIBLIOTECAS_UTN_H_
#define BIBLIOTECAS_UTN_H_

int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir);
void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void utn_getChar (char* pCaracter,char* mensaje,char* mensajeError, int reintentos);
void utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos);
void utn_getFloat(float* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int validarInt (char *pDato);

#endif /* BIBLIOTECAS_UTN_H_ */
