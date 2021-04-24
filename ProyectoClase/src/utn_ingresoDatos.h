/*
 * utn_ingresoDatos.h
 *
 *  Created on: 21 abr. 2021
 *      Author: juan-
 */

#ifndef UTN_INGRESODATOS_H_
#define UTN_INGRESODATOS_H_

void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
void utn_getChar (char* pCaracter,char* mensaje,char* mensajeError, int reintentos);
void utn_getString (char aux[],char* mensaje,char* mensajeError, int reintentos);
void utn_getMostar(int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio);
void utn_getMostarSoloUno (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio);
void utn_getOrdenarLeg (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio);
void utn_getOrdenarApellido (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio);
void utn_getOrdenarProm (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio);

#endif
/* UTN_INGRESODATOS_H_ */
