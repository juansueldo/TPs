#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "utn.h"

typedef struct {
	int legajo;
	char sexo;
	int edad;
	int nota1;
	int nota2;
	float promedio;
	char apellido[30];
	int isEmpty;
} datosAlumnos;

int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,
		int salir) {

	int retorno = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max && salir != 0) {
		printf("%s", mensaje);
		scanf("%d", &bufferMenu);

		if (bufferMenu >= min && bufferMenu <= max) {
			*opcion = bufferMenu;
			retorno = 0;
		} else {
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
int inicializarIsEmpty (datosAlumnos alumno[], int tamanio)
{
	int i;
	int retorno = -1;
	if (alumno != NULL && tamanio != 0)
	{
	for (i = 0; i < tamanio; i++)
	{
		alumno[i].isEmpty = 1;
	}
	retorno = 0;
	}
	return retorno;
}
int buscarLibre (datosAlumnos alumno[], int tamanio)
{
	int retorno = -1;
	int i;
	if(alumno != NULL && tamanio != 0)
	{
	for(i = 0; i < tamanio; i++)
	{
		if(alumno[i].isEmpty == 1)
		{
			retorno = i;
		}
	}
	}
	return retorno;
}
void inicializarStruct (datosAlumnos alumno[], int tamanio)
{
	int i;
	for(i = 0; i < tamanio; i++)
	{
		alumno[i].legajo = 0;
		alumno[i].edad = 0;
		alumno[i].promedio = 0;
		alumno[i].nota1 = 0;
		alumno[i].nota2 = 0;
		alumno[i].sexo = ' ';
		strcpy(alumno[i].apellido," ");
	}
}
void utn_getMostar(datosAlumnos alumno[], int tamanio, int i)
{

	printf("\nAlumno %d:",i+1);
	printf("\nLegajo: %d",alumno[i].legajo);
	printf(" Sexo: %c", alumno[i].sexo);
	printf(" Edad: %d", alumno[i].edad);
	printf(" Nota 1: %d", alumno[i].nota1);
	printf(" Nota 2: %d", alumno[i].nota2);
	printf(" Promedio: %.2f", alumno[i].promedio);
	printf(" Apellido: %s\n",alumno[i].apellido);
	printf("\nIs Empty %d", alumno[i].isEmpty);
}
void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pNumero=bufferInt;

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}
void utn_getChar (char* pCaracter,char* mensaje,char* mensajeError, int reintentos)
{

	char bufferChar;
	if(pCaracter != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(bufferChar=='f'|| bufferChar=='m')
			{
				*pCaracter = bufferChar;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}
void utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	char bufferString[30];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferString);

			if(strlen(bufferString) < 30)
			{
				strcpy(aux, bufferString);

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}
void utn_ordenarLeg (datosAlumnos alumno[], int tamanio)
{
	int i;
	int j;
	datosAlumnos aux;
	for(i = 0; i < tamanio -1;i++)
	{
		for(j = i+1; j < tamanio; j++)
		{
			if(alumno[i].legajo > alumno[j].legajo)
			{
				aux = alumno[i];
				alumno[i] = alumno[j];
				alumno[j] = aux;

			}
		}
	}
}
void utn_ordenarApellido (datosAlumnos alumno[], int tamanio)
{
	int i;
	int j;
	datosAlumnos aux;
	for(i = 0; i < tamanio -1;i++)
		{
			for(j = i+1; j < tamanio; j++)
			{
				if(strcmp(alumno[i].apellido,alumno[j].apellido)>0)
				{
					aux = alumno[i];
					alumno[i] = alumno[j];
					alumno[j] = aux;
				}
				}
			}
}
void utn_ordenarProm (datosAlumnos alumno[], int tamanio)
{
	int i;
	int j;
	datosAlumnos aux;
	for(i = 0; i < tamanio -1;i++)
	{
		for(j = i+1; j < tamanio; j++)
		{
			if(alumno[i].promedio > alumno[j].promedio)
			{
				aux = alumno[i];
				alumno[i]= alumno[j];
				alumno[j] = aux;


			}
			else if(alumno[i].promedio == alumno[j].promedio)
			{
				if(alumno[i].legajo > alumno[j].legajo)
					{
					aux = alumno[i];
					alumno[i]= alumno[j];
					alumno[j] = aux;
					}
			}
		}
	}
}
int buscarLegajo (datosAlumnos alumno[], int tamanio)
{
	int retorno = -1;
	int legajo;
	int i;
	char respuesta;
	if(alumno != NULL && tamanio != 0)
	{
	printf("\nQue legajo desea borrar:");
	scanf("%d",&legajo);
	for(i = 0; i < tamanio; i++)
	{

		if(alumno[i].legajo == legajo)
		{
			utn_getMostar(alumno,tamanio,i);

				printf("Desea dar la baja? s/n");
				fflush(stdin);
				scanf("%c",&respuesta);
				while(respuesta == 's' && respuesta == 'n')
				{
					printf("Desea dar la baja? s/n");
					fflush(stdin);
					scanf("%c",&respuesta);
				}
				if(respuesta == 's')
				{
					retorno = i;
					alumno[i].isEmpty =1;
				}

			break;
		}
	}
	}
	return retorno;
}
/*void mostrarEstudiantes (datosAlumnos alumno[], int tamanio)
{
	int i;
	printf("\nLegajo  Sexo   Edad  Nota 1  Nota 2  Promedio  Apellido");
	for(i = 0; i < tamanio; i++)
	{
		if(alumno[i].isEmpty == 1)
			continue;
		else
		{
			mostrarEstudiante (alumno);
		}
	}
}
void mostrarEstudiante (datosAlumnos estudiante)
{
	printf("%d  %c %d %d %d %f %s",estudiante.legajo,estudiante.sexo,estudiante.edad,estudiante.nota1,estudiante.nota2,estudiante.promedio,estudiante.apellido);
}*/
