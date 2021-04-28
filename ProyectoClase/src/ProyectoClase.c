/*
 ============================================================================
 Name        : ProyectoClase.c
 Author      : Juan Sueldo
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
#include "utn_ingresoDatos.h"

#define MAX 5

int main(void) {
	setbuf(stdout,NULL);
	int legajo[MAX];
	char sexo[MAX];
	int edad[MAX];
	int nota1[MAX];
	int nota2[MAX];
	float promedio[MAX];
	char apellido [MAX][30];
	int i;
	int auxNum;
	char auxChar;
	char auxString[30];
	int aux;

	inicializarNumEntero (legajo, MAX);
	inicializarChar (sexo, MAX);
	inicializarNumEntero (edad, MAX);
	inicializarNumEntero (nota1, MAX);
	inicializarNumEntero (nota2, MAX);
	inicializarNumFloat (promedio, MAX);
	inicializarString (apellido, MAX);

	for(i = 0; i < MAX; i++)
	{
	utn_getNumber (&auxNum,"\nIngrese el legajo(entre 0 y 1000):\n","\nError legajo. Ingrese el numero de legajo(entre 0 y 1000):\n",0,1000,3);
	if(auxNum != 0)
	{
		legajo[i] = auxNum;
	}
	utn_getChar (&auxChar, "\nIngrese el sexo(f o m):\n","\nError dato no valido. Ingrese el sexo(f o m):\n",3);

	{
		sexo[i] = auxChar;
	}
	utn_getNumber (&auxNum, "\nIngrese la edad(18 a 99):\n","\nError edad. Ingrese la edad(18 a 99):\n",18,99,3);
	if(auxNum != 0)
	{
		edad[i] = auxNum;
	}
	utn_getNumber (&auxNum,"\nIngrese la primer nota(1 a 10):\n","\nError nota. Ingrese la primer nota(1 a 10):\n",1,10,3);
	if(auxNum != 0)
	{
		nota1[i] = auxNum;
	}
	utn_getNumber (&auxNum,"\nIngrese la segunda nota(1 a 10):\n","\nError nota. Ingrese la segunda nota(1 a 10):\n",1,10,3);
	if(auxNum != 0)
	{
		nota2[i] = auxNum;
	}
	utn_getString (auxString,"\nIngrese el apellido(hasta 30 caracteres):\n","\nError apellido. Ingrese el apellido (hasta 30 caracteres):",3);
	{
		strcpy(apellido[i],auxString);
	}

	}
	for(i = 0; i < MAX; i++)
	{
		promedio[i] = ((float)nota1[i] + nota2[2])/2;
	}

	printf("\nIngrese el numero de legajo del alumno a mostrar:");// Se muestra un solo alumno
	fflush(stdin);
	scanf("%d",&aux);
	printf("\nEl alumno solicitado es:\n");
	for(i = 0; i < MAX; i++)
	{
	if(aux==legajo[i])
	{
		utn_getMostar(legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX,i);
	}
	}
	printf("\nTodos los alumnos ingresados:\n");//Se muestra todos los alumnos ingresados
	for(i = 0; i < MAX; i++)
	{
		utn_getMostar(legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX,i);
	}


	utn_getOrdenarLeg (legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX);//Se ordenan por legajo
	printf("\nOrdenados por legajo:\n"); //Se muestran ordenados
	for(i = 0; i < MAX; i++)
	{
		utn_getMostar(legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX,i);
	}

	utn_getOrdenarApellido (legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX);//Se ordenan por apellido
	printf("\nOrdenados por apellido:\n");//Se muestran ordenados
	for(i = 0; i < MAX; i++)
	{
		utn_getMostar(legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX,i);
	}

	utn_getOrdenarProm (legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX);//Se ordenan por promedio, en caso que el promedio sea igual, se ordena por legajo
	printf("\nOrdenados por promedio:\n");//Se muestran ordenados
	for(i = 0; i < MAX; i++)
	{
		utn_getMostar(legajo, sexo,edad,nota1,nota2,promedio,apellido,MAX,i);
	}

	return EXIT_SUCCESS;
}
