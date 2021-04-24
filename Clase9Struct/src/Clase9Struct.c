/*
 ============================================================================
 Name        : Clase9Struct.c
 Author      : 
Desarrollar un programa que permita guardar los datos de 5 alumnos.
Los datos a guardar para cada alumno: legajo, sexo, edad, nota1, nota2, promedio, apellido.
1-Inicializar
2-cargar datos
3-Mostrar1Estudiante
4-mostrarEstudiantes
5-Ordenar por legajo
6-Ordenar por Apellido
7-Ordenar por Promedio, si se repite ordenar por legajo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define MAX 5

int main(void) {
	setbuf(stdout, NULL);
	datosAlumnos alumno[MAX];

	int i;
	int opcion;
	int auxNum;
	char auxChar;
	char auxString[30];

	inicializarStruct (alumno, MAX);

	do
	{
	if(utn_menu (&opcion,"\n1. Carga de datos.\n2. Mostrar un estudiante. \n3. Mostrar todos los estudiantes. \n4. Ordenar por legajo. \n5. Ordenar por apellido.\n6. Ordenar por promedio.\n7. Salir.","\nNo es una opción válida.", 1, 7, 7) == 0)
	{
		switch(opcion)
		{
		case 1:
			for(i=0; i< MAX; i++)
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

			}
			break;
		case 2:
			utn_getMostarSoloUno(alumno, MAX);
			break;
		case 3:
			utn_getMostar(alumno, MAX);
			break;
		case 4:
			utn_getOrdenarLeg (alumno, MAX);
			printf("\nSe ordeno por legajo");
			break;
		case 5:
			utn_getOrdenarApellido (alumno, MAX);
			printf("\nSe ordeno por apellido");
			break;
		case 6:
			utn_getOrdenarProm (alumno, MAX);
			printf("\nSe ordeno por promedio");
			break;
		case 7:
			printf("\nFin.");
			break;
		default:
			printf("\nError. Opcion no valida");
		}
	}
 }while(opcion != 7);


	return EXIT_SUCCESS;
}
