/*
 ============================================================================
 Name        : Clase10.c
 Author      : Juan Sueldo
 Desarrollar un programa que permita guardar los datos de 5 alumnos.
 Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.
 Se debe utilizar estructuras, permitiendo al usuario trabajar con los datos a trav�s de un ABM.
Hacer con estructuras - Crear un men�
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define MAX 2

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int i;
	int auxNum;
	char auxChar;
	char auxString[30];
	int opcionSub;

	datosAlumnos alumno[MAX];

	inicializarStruct (alumno, MAX);

	if(inicializarIsEmpty (alumno, MAX)==0)
	{
	printf("Hay espacio");
	}
	else
	{
		printf("No hay espacio");
	}
	for(i = 0; i < MAX; i++)
	{
		utn_getMostar(alumno, MAX, i);
	}
	do
	{

		if( utn_menu (&opcion,"\n1. Alta.\n2. Listar. \n3. Baja. \n4. Modificar. \n5. Ordenar.\n6. Salir.","\nNo es una opci�n v�lida.", 1, 6,6) == 0)
		{
			switch(opcion)
			{
				case 1:
					for(i = 0; i < MAX; i++)
					{
					if(buscarLibre (alumno, MAX) >= 0)
					{
						utn_getNumber (&auxNum,"\nIngrese el legajo(entre 0 y 1000):\n","\nError legajo. Ingrese el numero de legajo(entre 0 y 1000):\n",0,1000,3);
						if(auxNum != 0)
						{
							alumno[i].legajo = auxNum;
						}
						utn_getChar (&auxChar, "\nIngrese el sexo(f o m):\n","\nError dato no valido. Ingrese el sexo(f o m):\n",3);
						{
							alumno[i].sexo = auxChar;
						}
						utn_getNumber (&auxNum, "\nIngrese la edad(18 a 99):\n","\nError edad. Ingrese la edad(18 a 99):\n",18,99,3);
						if(auxNum != 0)
						{
							alumno[i].edad = auxNum;
						}
						utn_getNumber (&auxNum,"\nIngrese la primer nota(1 a 10):\n","\nError nota. Ingrese la primer nota(1 a 10):\n",1,10,3);
						if(auxNum != 0)
						{
							alumno[i].nota1 = auxNum;
						}
						utn_getNumber (&auxNum,"\nIngrese la segunda nota(1 a 10):\n","\nError nota. Ingrese la segunda nota(1 a 10):\n",1,10,3);
						if(auxNum != 0)
						{
							alumno[i].nota2 = auxNum;
						}
						utn_getString (auxString,"\nIngrese el apellido(hasta 30 caracteres):\n","\nError apellido. Ingrese el apellido (hasta 30 caracteres):",3);
						{
							strcpy(alumno[i].apellido,auxString);
						}
						alumno[i].promedio = ((float)alumno[i].nota1 +alumno[i].nota2)/2;

						alumno[i].isEmpty = 0;
					}
					else
					{
						printf("\nNo hay espacio libre");
					}
					}
					break;
				case 2:
					if(utn_menu (&opcionSub,"\n1. Ordenar por legajo. \n2. Odenar por apellido. \n3. Ordenar por promedio \n4. Voler al menu anterior","\n No es una opci�n v�lida.", 1, 4,4) == 0)
					switch(opcionSub)
					{
					case 1:
						utn_ordenarLeg (alumno, MAX);
						printf("\nSe ordeno por legajo");
						break;
					case 2:
						utn_ordenarApellido (alumno, MAX);
						printf("\nSe ordeno por apellido");
						break;
					case 3:
						utn_ordenarProm (alumno, MAX);
						printf("\nSe ordeno por promedio");
						break;
					}
					break;
					}

			}

	} while(opcion != 7);
	return EXIT_SUCCESS;
}
