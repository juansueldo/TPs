/*
 ============================================================================
 Name        : Clase16Tarea1.c
 Author      : 
 Version     :Recibe el array como vector y accede a los datos utilizando notación vectorial ([])
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
void funcionUno (int array[], int tam);
void funcionDos (int array[], int tam);
void funcionTres (int* array, int tam);
void funcionCuatro (int* array, int tam);
int main()
{

    int i = 0;
	int numero[i];
	for(i = 0; i < 5; i++)
	{
		numero[i] = i;
 	}
	funcionUno (numero, i);
    printf("\n");
    funcionDos (numero, i);
    printf("\n");
    funcionTres (numero, i);
     printf("\n");
    funcionCuatro (numero, i);
    return 0;
}
void funcionUno (int array[], int tam)
{
    int i;
    for(i= 0; i < tam; i++)
    {
        printf("\nFUNCION 1: %d", array[i]);
    }
}
void funcionDos (int array[], int tam)
{
    int i;
    for(i= 0; i < tam; i++)
    {
        printf("\nFUNCION 2: %d", *(array+i));
    }
}
void funcionTres (int* array, int tam)
{
    int i;
    for(i= 0; i < tam; i++)
    {
        printf("\nFUNCION 3: %d", array[i]);
    }
}
void funcionCuatro (int* array, int tam)
{
    int i;
    for(i= 0; i < tam; i++)
    {
        printf("\nFUNCION 4: %d", *(array+i));
    }
}
