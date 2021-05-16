
#ifndef INFORMES_H_
#define INFORMES_H_

#include "Recaudaciones.h"
#include "Contribuyente.h"

int informe_ContribuyentesRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
int informe_ContribuyentesIdRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, int* auxId);
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
int eRecaudacion_cambiarEstadoSaldar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
#endif /* INFORMES_H_ */
