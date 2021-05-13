/*
 * Publicidad.h
 *
 *  Created on: 13 may. 2021
 *      Author: operador
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_
#include "Pantallas.h"

ePublicidad ePublicidad_cargarPublicidad (void);
int ePublicidad_obtenerNombre (ePantalla arrayPantalla[] , int tam, int codigo , ePublicidad arrayPublicidad[] , ePantalla auxArray[]);
int ePublicidad_alta (ePantalla arrayPantalla [],int tam, ePublicidad arrayPublicidad[], eTipo arrayTipo[],int cant, int *pCont);
void ePublicidad_mostrarUno (ePublicidad arrayPublicidad[] ,int tam, ePantalla arrayPantalla[], int cant);
int ePublicidad_mostrarTodos (ePantalla arrayPublicidad[],int tam, ePantalla arrayPantalla[], int cant);
ePublicidad ePublicidad_modificarUno (ePublicidad arrayPublicidad, int campoModificar);
int ePublicidad_modificarPantallas (ePublicidad arrayPublicidad[], int tam, ePantalla arrayPantalla[], int cant);
#endif /* PUBLICIDAD_H_ */
