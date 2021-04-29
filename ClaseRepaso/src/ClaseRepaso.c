/*
 ============================================================================
 Name        : ClaseRepaso.c
 Author      : Juan Sueldo
 Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto (programador,
analista, tester).
Crear un menu con las siguientes opciones:
1. Cargar empleados. Carga secuencial.
2. Mostrar empleados. Ordenados por puesto.
3. Mostrar solo los empleados analistas.
4. Mostrar cuantos empleados tester hay.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define MAX 5

int main(void)
{
	setbuf(stdout, NULL);
	datosEmpleados empleados[MAX];
	int opcion;
	int auxNum;
	float auxFloat;
	char auxString[40];
	int i;

	inicializarStruct(empleados, MAX);

	do
	{
	if(utn_menu(&opcion,"\nIngrese: \n1. Cargar empleados. \n2. Mostrar empeados por puesto. \n3. Mostrar solo empleados analistas. \n4. Cantidad empleados tester \n5. Salir","\nNo es una opcion valida", 1, 5,5) == 0)
	{
		switch(opcion)
		{
		case 1:
			for(i = 0; i < MAX; i++)
			{
				utn_getNumber(&auxNum,"\nIngrese el Id del empleado:\n","\nNo es un numero valido",0,9999,3);
				if(auxNum)
				{
					empleados[i].idEmpleado = auxNum;
				}
				utn_getFloat(&auxFloat,"\nIngrese el sueldo:\n","\nNo es un sueldo valido",1000,9999999,3);
				if(auxFloat)
				{
					empleados[i].sueldo = auxFloat;
				}
				utn_getString(auxString,"\nIngrese el puesto:\n","\nPuesto no válido", 3);
				{
					strcpy(empleados[i].puesto,auxString);
				}
				utn_getString(auxString,"\nIngrese el nombre:\n","\nNombre no válido", 3);
				{
					strcpy(empleados[i].nombre,auxString);
				}
			}
			break;
		case 2:
			utn_ordenarPuesto (empleados, MAX);
			for(i = 0; i < MAX; i++)
			{
			utn_mostar(empleados, MAX, i);
			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printf("\nFin.")
			break;
		}
	}
	}while(opcion != 5);
	return EXIT_SUCCESS;
}
