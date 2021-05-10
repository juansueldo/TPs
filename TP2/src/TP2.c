/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Empleados.h"



int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcion2;
	int bufferAlta =0;

	eEmployee empleados[MAX];
	inicializarStruct (empleados,MAX);

	do{
	utn_menu(&opcion, "1. Dar alta.\n2. Modificar. \n3. Dar baja. \n4. Informar. \n5. Salir. \n**********************\nIngrese la opcion:","\nNo es una opcion valida." , 1, 5,5);
	switch(opcion)
	{
	case 1:
		if(utn_Alta(empleados, MAX))
		{
			printf("\nSE DIO DE ALTA UN EMPLEADO.\n");
			bufferAlta =1;
		}
		break;
	case 2:
		if(bufferAlta ==1)
		{
			if(utn_Modificacion(empleados, MAX))
			{
				printf("\nSE MODIFICO UN EMPLEADO.\n");

			}
		}
		else
		{
			printf("\nPRIMERO DEBE DAR UN ALTA\n");
		}
		break;
	case 3:
		if(bufferAlta == 1)
		{
			if(utn_Baja(empleados, MAX)==1)
			{
				printf("\nSE DIO LA BAJA\n");
			}
		}
		break;
	case 4:
		do
		{
		utn_menu(&opcion2, "1. Ordenar por apellido y sector.\n2. Promedio de salarios y cuantos superan el promedio. \n3. Volver atras.\n**********************\nIngrese la opcion:","\nNo es una opcion valida." , 1, 5,5);
		switch(opcion2)
		{
		case 1:
			utn_ordenarApellido (empleados, MAX);
			utn_MostrarTodos (empleados, MAX);
			break;
		case 2:
			get_promedio (empleados, MAX);
			break;
		}
		}while(opcion !=3);
		break;
	}
	}while(opcion !=5);

	return EXIT_SUCCESS;
}
