/*
 * movie.h
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */

#ifndef MOVIE_H_
#define MOVIE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#define MAX_NOMBRE 70

typedef struct{
	int id_venta;
	char nombre_pelicula[MAX_NOMBRE];
	int dia;
	char horario[MAX_NOMBRE];
	int sala;
	int cantidad_entradas;
	float monto;
}eMovie;

typedef struct{
	int dia;
	char diaSemana[MAX_NOMBRE];
}eDias;

eMovie* eMovie_new();
eMovie* eMovie_newParametros(char* idStr,char* nombreStr,char* diaStr, char* horarioStr, char* salaStr, char* cantidadStr);
int eMovie_setId(eMovie* this,int id);
int eMovie_getId(eMovie* this,int* id);

int eMovie_setNombre(eMovie* this,char* nombre);

int eMovie_getNombre(eMovie* this,char* nombre);


int eMovie_setDia(eMovie* this,int dia);

int eMovie_getDia(eMovie* this,int* dia);


int eMovie_setSala(eMovie* this,int sala);

int eMovie_getSala(eMovie* this,int* sala);

int eMovie_setHora(eMovie* this,char* horario);

int eMovie_getHora(eMovie* this,char* horario);

int eMovie_setCantidad(eMovie* this,int cantidad);

int eMovie_getCantidad(eMovie* this,int* cantidad);
int eMovie_getDays (eDias* arrayDias,int dia,char* detalleDia);
int eMovie_setMonto(eMovie* this,float monto);
int eMovie_getMonto(eMovie* this,float* monto);
int eMovie_getMontoGenrado (eMovie* this, int dia,int cantidad, float* monto);
eMovie* eMovie_newParametrosInt(int id,char* nombre,int dia, char* horario, int sala, int cantidad, float monto);
void calcularMonto(void* this);
int eMovie_compareBynombre(void* pThis1, void* pThis2);
#endif /* MOVIE_H_ */
