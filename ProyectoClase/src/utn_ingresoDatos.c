#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
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
void utn_getMostar(int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio)
{
	int i;


	for(i = 0; i < tamanio; i++)
	{
	printf("\nAlumno %d:",i+1);
	printf("\nLegajo: %d",legajo[i]);
	printf(" Sexo: %c", sexo[i]);
	printf(" Edad: %d", edad[i]);
	printf(" Nota 1: %d", nota1[i]);
	printf(" Nota 2: %d", nota2[i]);
	printf(" Promedio: %.2f", promedio[i]);
	printf(" Apellido: %s\n",apellido[i]);
	}
}
void utn_getMostarSoloUno (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio)
{
	int flag = 0;
	int i;
	int aux;
	printf("\nIngrese el numero de legajo del alumno a mostrar:");
	scanf("%d",&aux);
	for(i = 0; i < tamanio; i++)
	{
	if(aux==legajo[i])
	{
	printf("\nAlumno %d:",i+1);
	printf("\nLegajo: %d",legajo[i]);
	printf(" Sexo: %c", sexo[i]);
	printf(" Edad: %d", edad[i]);
	printf(" Nota 1: %d", nota1[i]);
	printf(" Nota 2: %d", nota2[i]);
	printf(" Promedio: %.2f", promedio[i]);
	printf(" Apellido: %s\n",apellido[i]);
	flag = 1;
	}
	}
	if(flag == 0)
	{
		printf("\nNo es un numero de legajo.");
	}
}
void utn_getOrdenarLeg (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio)
{
	int i;
	int j;
	int auxNum;
	float auxFloat;
	char auxSexo;
	char auxChar[30];
	for(i = 0; i < tamanio -1;i++)
	{
		for(j = i+1; j < tamanio; j++)
		{
			if(legajo[i] > legajo[j])
			{
				auxNum = legajo[i];
				legajo[i] = legajo[j];
				legajo[j] = auxNum;

				auxSexo = sexo[i];
				sexo[i] = sexo[j];
				sexo[j] = auxSexo;

				auxNum = edad[i];
				edad[i] = edad[j];
				edad[j] = auxNum;

				auxNum = nota1[i];
				nota1[i] = nota1[j];
				nota1[j] = auxNum;

				auxNum = nota2[i];
				nota2[i] = nota2[j];
				nota2[j] = auxNum;

				auxFloat = promedio[i];
				promedio[i] = promedio[j];
				promedio[j] = auxFloat;

				strcpy(auxChar,apellido[i]);
				strcpy(apellido[i],apellido[j]);
				strcpy(apellido[j],auxChar);
			}
		}
	}
}
void utn_getOrdenarApellido (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio)
{
	int i;
	int j;
	int auxNum;
	float auxFloat;
	char auxSexo;
	char auxChar[30];
	for(i = 0; i < tamanio -1;i++)
		{
			for(j = i+1; j < tamanio; j++)
			{
				if(strcmp(apellido[i],apellido[j])>0)
				{
					auxNum = legajo[i];
					legajo[i] = legajo[j];
					legajo[j] = auxNum;

					auxSexo = sexo[i];
					sexo[i] = sexo[j];
					sexo[j] = auxSexo;

					auxNum = edad[i];
					edad[i] = edad[j];
					edad[j] = auxNum;

					auxNum = nota1[i];
					nota1[i] = nota1[j];
					nota1[j] = auxNum;

					auxNum = nota2[i];
					nota2[i] = nota2[j];
					nota2[j] = auxNum;

					auxFloat = promedio[i];
					promedio[i] = promedio[j];
					promedio[j] = auxFloat;

					strcpy(auxChar,apellido[i]);
					strcpy(apellido[i],apellido[j]);
					strcpy(apellido[j],auxChar);
				}
				}
			}
}
void utn_getOrdenarProm (int legajo[], char sexo[],int edad[],int nota1[],int nota2[],float promedio[], char apellido[][30],int tamanio)
{
	int i;
	int j;
	int auxNum;
	float auxFloat;
	char auxSexo;
	char auxChar[30];
	for(i = 0; i < tamanio -1;i++)
	{
		for(j = i+1; j < tamanio; j++)
		{
			if(promedio[i] > promedio[j])
			{
				auxNum = legajo[i];
				legajo[i] = legajo[j];
				legajo[j] = auxNum;

				auxSexo = sexo[i];
				sexo[i] = sexo[j];
				sexo[j] = auxSexo;

				auxNum = edad[i];
				edad[i] = edad[j];
				edad[j] = auxNum;

				auxNum = nota1[i];
				nota1[i] = nota1[j];
				nota1[j] = auxNum;

				auxNum = nota2[i];
				nota2[i] = nota2[j];
				nota2[j] = auxNum;

				auxFloat = promedio[i];
				promedio[i] = promedio[j];
				promedio[j] = auxFloat;

				strcpy(auxChar,apellido[i]);
				strcpy(apellido[i],apellido[j]);
				strcpy(apellido[j],auxChar);
			}
			else if(promedio[i] == promedio[j])
			{
				if(legajo[i] > legajo[j])
					{
						auxNum = legajo[i];
						legajo[i] = legajo[j];
						legajo[j] = auxNum;

						auxSexo = sexo[i];
						sexo[i] = sexo[j];
						sexo[j] = auxSexo;

						auxNum = edad[i];
						edad[i] = edad[j];
						edad[j] = auxNum;

						auxNum = nota1[i];
						nota1[i] = nota1[j];
						nota1[j] = auxNum;

						auxNum = nota2[i];
						nota2[i] = nota2[j];
						nota2[j] = auxNum;

						auxFloat = promedio[i];
						promedio[i] = promedio[j];
						promedio[j] = auxFloat;

						strcpy(auxChar,apellido[i]);
						strcpy(apellido[i],apellido[j]);
						strcpy(apellido[j],auxChar);
				}
			}
		}
	}
}
