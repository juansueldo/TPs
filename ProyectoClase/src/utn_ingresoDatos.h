/*
 * utn_ingresoDatos.h
 *
 *  Created on: 21 abr. 2021
 *      Author: juan-
 */

#ifndef UTN_INGRESODATOS_H_
#define UTN_INGRESODATOS_H_

void utn_getNumero (int numero[], int tamanio, char*mensaje, char*mensajeError,int min, int max);
void utn_getChar (char letra[], int tamanio, char*mensaje,char*mensajeError);
void utn_getString (char string[][30], int tamanio, char*mensaje);
void utn_getMostar(int legajo[], char sexo[],int edad[],int nota1[],int nota2[], char apellido[][30],int tamanio);
#endif /* UTN_INGRESODATOS_H_ */
