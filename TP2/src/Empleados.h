
#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include "Bibliotecas_utn.h"

#define MAX 2

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;

void inicializarStruct (eEmployee empleados[], int tamanio);
int utn_getIdLibre (eEmployee empleados[], int tamanio);
int utn_getId();
int utn_buscarPorID (eEmployee empleados[], int tamanio, int ID);
void utn_MostrarUno(eEmployee empleados);
int utn_MostrarTodos(eEmployee empleados[], int tamanio);
eEmployee utn_CargarDatos(void);
eEmployee utn_ModificarUno(eEmployee empleados);
int utn_Alta(eEmployee empleados[], int tamanio);
int utn_Modificacion(eEmployee empleados[], int tamanio);
int utn_Baja(eEmployee empleados[], int tamanio);
void utn_ordenarApellido (eEmployee empleados[], int tamanio);
void get_promedio (eEmployee empleados[], int tamanio);

#endif /* EMPLEADOS_H_ */
