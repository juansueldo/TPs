/*
 * utn_calculos.h
 *
 *  Created on: 5 abr. 2021
 *      Author: operador
 */

#ifndef UTN_CALCULOS_H_
#define UTN_CALCULOS_H_

int utn_menu (int* opcion, char* mensaje,char* mensajeError, int min, int max, int salir);
int utn_getSuma (int operador1, int operador2);
int utn_getResta (int operador1, int operador2);
int utn_getMultiplicar (int operador1, int operador2);
float utn_getDividir (int operador1, int operador2, float* retorno);

#endif /* UTN_CALCULOS_H_ */
