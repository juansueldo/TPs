/*
 * movie.h
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */

#ifndef SALA_H_
#define SALA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#define MAX_NOMBRE 70
//id_partida, fecha, tipo_juego, cantidad_jugadores, duracion_partida

typedef struct{
	int id_partida;
	char fecha[MAX_NOMBRE];
	int tipo;
	int cantidad;
	int duracion;
	float costo;
}eSala;


eSala* eSala_new();
eSala* eSala_newParametros (char* idStr,char* fechaStr,char* tipoStr, char* cantidadStr, char* duracionStr);

int eSala_setId(eSala* this,int id);
int eSala_getId(eSala* this,int* id);

int eSala_setFecha(eSala* this,char* fecha);
int eSala_getFecha(eSala* this,char* fecha);


int eSala_setTipo(eSala* this,int tipo);
int eSala_getTipo(eSala* this,int* tipo);


int eSala_setCantidad(eSala* this,int cantidad);
int eSala_getCantidad(eSala* this,int* cantidad);

int eSala_setDuracion(eSala* this,int duracion);
int eSala_getDuracion(eSala* this,int* duracion);
/*
int eSala_setCantidad(eSala* this,int cantidad);

int eSala_getCantidad(eSala* this,int* cantidad);
int eSala_getDays (eDias* arrayDias,int dia,char* detalleDia);
int eSala_setMonto(eSala* this,float monto);
int eSala_getMonto(eSala* this,float* monto);
int eSala_getMontoGenrado (eSala* this, int dia,int cantidad, float* monto);
eSala* eSala_newParametrosInt(int id,char* nombre,int dia, char* horario, int sala, int cantidad, float monto);
void calcularMonto(void* this);
int eSala_compareBynombre(void* pThis1, void* pThis2);*/
#endif /* SALA_H_ */
