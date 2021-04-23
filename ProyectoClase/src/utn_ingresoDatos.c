#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void utn_getNumero (int numero[], int tamanio, char*mensaje, char*mensajeError,int min, int max)
{
	int i;
	if(mensaje != NULL && mensajeError != NULL && min <= max)
	{

		printf("%s",mensaje);
		scanf("%d",&numero[i]);
		while(numero[i] < min || numero[i] > max)
		{
			printf("%s",mensajeError);
			scanf("%d",&numero[i]);

		}
	}

}
void utn_getChar (char letra[], int tamanio, char*mensaje,char*mensajeError)
{
	int i;
		if(mensaje != NULL)
		{

			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&letra[i]);
			while(letra[i] != 'f' && letra[i] != 'm')
			{
				printf("%s",mensajeError);
				fflush(stdin);
				scanf("%c",&letra[i]);
			}

		}
}
void utn_getString (char string[][30], int tamanio, char*mensaje)
{
	int i;
		if(mensaje != NULL)
		{

			printf("%s",mensaje);
			fflush(stdin);
			gets(string[i][30]);

		}
}
void utn_getMostar(int legajo[], char sexo[],int edad[],int nota1[],int nota2[], char apellido[][30],int tamanio)
{
	printf("\nEl legajo ingresado es: %d\nEl sexo del alumno: %c \nLa edad: %d \nLa primer nota: %d \nLa primer nota: %d \nEl apellido es: %s" ,legajo[tamanio],sexo[tamanio],edad[tamanio],nota1[tamanio],nota2[tamanio],apellido[tamanio][30]);
}
