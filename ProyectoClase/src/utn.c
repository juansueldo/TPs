#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void inicializarNumEntero (int array[], int tamanio)
{
	int i;
	for(i = 0; i < tamanio; i++)
	{
		array[i] = 0;
	}
}
void inicializarNumFloat (float array[], int tamanio)
{
	int i;
	for(i = 0; i < tamanio; i++)
	{
		array[i] = 0;
	}
}
void inicializarChar (char array[], int tamanio)
{
		int i;
		for(i = 0; i < tamanio; i++)
		{
			array[i] = ' ';
		}
}
void inicializarString(char array[][30], int tamanio)
{
	int i;
		for(i = 0; i < tamanio; i++)
		{
			strcpy(array[i]," ");
		}
}
//void validar(int legajo)


