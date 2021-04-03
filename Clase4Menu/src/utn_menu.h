/*
 * utn_prueba.h
 *
 *  Created on: 2 abr. 2021
 *      Author: operador
 */

#ifndef UTN_PRUEBA_H_
#define UTN_PRUEBA_H_

int utn_menu (int* opcion, char* mensaje,char* mensajeError, int min, int max, int salir);
int utn_getLogueo (char* mensaje);
int utn_getComprar (int menu, char* mensaje, char* mensajeError);
int utn_getVerComprar (int menu,int comprar, char* mensaje, char* mensajeError, char* mensajeError2);
int utn_getVender (int menu,int comprar, char* mensaje, char* mensajeError, char* mensajeError2);
int utn_getFacturar (int menu, char* mensaje, char* mensajeError);
#endif /* UTN_PRUEBA_H_ */
