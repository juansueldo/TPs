/*
 ============================================================================
 Name        : Clase19Tarea3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

typedef struct{
	int idProducto;
	char marca[20];
	int precio;
}eProducto;

typedef int(*pFunc)(eProducto*,eProducto*);
int compararPorMarca(eProducto* arrayProducto1,eProducto*arrayProducto2);
int compararPorPrecio(eProducto* arrayProducto1,eProducto*arrayProducto2);
int ordenador(eProducto arrayProducto[], int tam, pFunc pFuncion);

int main(void) {
	setbuf(stdout, NULL);
	eProducto arrayProductos[TAM] = {{1,"Noganet",1200},{2,"Logitech",890},{3,"Genius",1450}};
	int(*pFunc)(eProducto*,eProducto*);
	pFunc = compararPorMarca;

	ordenador(arrayProductos, TAM, pFunc);

	for(int i = 0;i < TAM; i++)
	{
		printf("\nId %d MARCA %s PRECIO %d", (*(arrayProductos+i)).idProducto, (*(arrayProductos+i)).marca, (*(arrayProductos+i)).precio);
	}
	pFunc = compararPorPrecio;
	ordenador(arrayProductos, TAM, pFunc);

		for(int i = 0;i < TAM; i++)
		{
			printf("\nId %d MARCA %s PRECIO %d", (*(arrayProductos+i)).idProducto, (*(arrayProductos+i)).marca, (*(arrayProductos+i)).precio);
		}
	return EXIT_SUCCESS;
}
int compararPorMarca(eProducto* arrayProducto1,eProducto*arrayProducto2)
{
	int retorno = -1;
	eProducto aux;
	if(arrayProducto1 != NULL && arrayProducto2 != NULL)
	{
		if(strcmp((*(arrayProducto1)).marca,(*(arrayProducto2)).marca)>0)
		{
			aux = *arrayProducto1;
			*arrayProducto1 = *arrayProducto2;
			*arrayProducto2 = aux;
					retorno = 0;
				}

	}
	return retorno;
}
int compararPorPrecio(eProducto* arrayProducto1,eProducto*arrayProducto2)
{
		int retorno = -1;
		eProducto aux;
		if(arrayProducto1 != NULL && arrayProducto2 != NULL)
		{

			if((*(arrayProducto1)).precio >(*(arrayProducto2)).precio)
			{
					aux = *arrayProducto1;
					*arrayProducto1 = *arrayProducto2;
					*arrayProducto2 = aux;
					retorno = 0;
			}

		}
		return retorno;
}
int ordenador(eProducto arrayProducto[], int tam, pFunc pFuncion)
{
	int retorno = -1;
	int i;
	int j;

	if(arrayProducto != NULL && tam > 0)
	{
	for (i = 0;i<tam-1; i++)
	{
		for(j= i+1; j < tam; j++)
		{
			if(pFuncion((arrayProducto+i), (arrayProducto+j)))
			{
				retorno =0; //printf("\nId %d MARCA %s PRECIO %d", (*(arrayProducto)).idProducto, (*(arrayProducto)).marca, (*(arrayProducto)).precio);
			}

			if(pFuncion ((arrayProducto+i), (arrayProducto+j)))
			{
				retorno =0; //printf("\nId %d MARCA %s PRECIO %d", (*(arrayProducto)).idProducto, (*(arrayProducto)).marca, (*(arrayProducto)).precio);
			}

		}

	}
	}
	return retorno;
}
