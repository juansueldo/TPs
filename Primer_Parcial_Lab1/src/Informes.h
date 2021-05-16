
#ifndef INFORMES_H_
#define INFORMES_H_

#include "Recaudaciones.h"
#include "Contribuyente.h"

int informe_ContribuyentesIdRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, int* auxId);
//int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo, int* indexId);
int eRecaudacion_estadoRefinanciar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
int eRecaudacion_estadoSaldado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
int eRecaudacion_obtenerNombreEstado (eEstado arrayEstado[],int cant,int estado,char detalle[20]);
int informe_ContribuyentesRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
int mostrarTodos (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
#endif /* INFORMES_H_ */
