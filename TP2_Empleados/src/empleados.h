#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define CANT 4

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;
typedef struct
{
	int sector;
	char detalleSector[51];
	int isEmpty;
}eSector;

int initEmployees (eEmployee arrayEmpleados[],int tamanio);
int initSector (eSector arraySector[],int tamanio);
int buscarLibre(eEmployee arrayEmpleados[],int tamanio);
int cargarEmpleados(eEmployee arrayEmpleados[],int tamanio);
int buscarId (eEmployee arrayEmpleados[],int tamanio);
int modificarEmpleados(eEmployee arrayEmpleados[],int tamanio,int campoModificar);
int getNombreSector (eSector arraySector[],int cant,int sector,char detalleSector[]);
void mostrarEmpleado(eEmployee arrayEmpleados[],int tamanio,eSector arraySector[]);
int mostrarEmpleados (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[]);
int utn_getIdLibre (eEmployee empleados[], int tamanio);
int utn_Alta(eEmployee empleados[], int tamanio);
eEmployee utn_CargarDatos(void);
#endif /* EMPLEADOS_H_ */

