/*
 ============================================================================
 Name        : Tp2-Empleados.c
 Author      : Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "utn.h"

#define MAX 5
#define CANT 4

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int espacioLibre = 0;
	int bufferAlta = 0;
	int idMod;
	char confirmar;
	int opcion2;

	eEmployee empleados[MAX];
	eSector sector[CANT];

	initEmployees (empleados, MAX);
	initSector (sector, CANT);

	do
	{
		utn_menu(&opcion, "1. Alta \n2. Modificar \n3. Baja \n4. Listar \n5. Salir \nIngrese:", "\nNO ES VALIDO\n", 1, 5,5);
		switch(opcion)
		{
		case 1:
			if(buscarLibre (empleados, MAX) != -1)
			{
				espacioLibre = 1;
			}
			if(espacioLibre == 1)
			{
			if(utn_Alta (empleados, MAX))
			{
				bufferAlta = 1;
				printf("\nAlta exitosa.\n");
			}
			}
			break;
		case 2:
			if(bufferAlta != 0)
			{
			printf("\nIngrese el ID a buscar para modificar");
			idMod = buscarId(empleados,MAX);
			printf("%d",idMod);
			if(idMod != -1)
			{
				printf("\nEmpleado solicitado");
				printf("\nID \t NOMBRE \t APELLIDO \t SUELDO \t SECTOR \t DETALLE\n");
				printf("***********************************************************\n");
				mostrarEmpleados(empleados,idMod,sector);
				fflush(stdin);
				utn_getChar(&confirmar,"\nDesea modificar a este empleado\t s/n","\nError, ingrese solo s/n. Desea modificar al alumno?\t s/n",'a','z',3);
				if(confirmar == 's')
				{
					utn_menu(&opcion2, "1. Nombre \n2. Apellido \n3. Sueldo \n4. Sector \n5. Salir \nIngrese:", "\nNO ES VALIDO\n", 1, 5,5);
					if(modificarEmpleados(empleados,idMod,opcion2) == 0)
					{
						printf("\nSe ha modificado con exito el alumno");
					}
					else
					{
						printf("\nNo se ha podido modificar el alumno solicitado");
					}

					}
					else
					{
						printf("\nSe a cancelado la modificacion del alumno");
					}
					}
			}
			else
			{
				printf("\nPrimero debe realizar un alta para modificar\n");
			}
			break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}

