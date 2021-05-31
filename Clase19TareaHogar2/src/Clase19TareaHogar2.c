/*
 ============================================================================
 Name        : Clase19TareaHogar2.c
 Author      : Juan Sueldo
 Realizar una función que reciba como parámetro
 un array de enteros, su tamaño, un valor entero y un índice.
 La función se engargará de insertar el valor entero en el índice especificado.
 El array debera reestrucurarse dinámicamente
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void fBuscar (int array[], int len, int entero, int index);

int main(void) {
	setbuf(stdout, NULL);
	int i;
	int* vector;
	int* vecAux;
	vector=(int*)malloc(sizeof(int)*TAM);

	if (vector!=NULL)
	 {
	     for (i=0;i<TAM;i++)
	     {
	    	 printf("\nINGRESE EL NUMERO DE LA POSICION %d: ",i);
	    	 scanf("%d",&(*(vector+i)));
	     }
	}
	for (i=0;i<TAM;i++)
	{
	    printf("\nNUMERO INGRESADO: %d POSICION: %d", *(vector+i), i);
	}
	vecAux = (int*)realloc(vector,sizeof(int)*TAM+1);
	if (vecAux!=NULL)
	{
		vector = vecAux;
	}

	fBuscar (vector, TAM+1, 10, 2);

	printf("\n\n");

	for (i=0;i<TAM+1;i++)
	{
	    if(i != 2)
	    {
		printf("\nNUMERO INGRESADO: %d POSICION: %d", *(vector+i), i);
	    }
	    else
		{
		    printf("\nNUMERO INSERTADO: %d POSICION: %d", *(vector+i), i);
		}
	}

free(vector);
free(vecAux);

	return EXIT_SUCCESS;
}
void fBuscar (int array[], int len, int entero, int index)
{
	int i;
	int j;
	int aux;
	if(array!=NULL && len>0)
	{
		for(i=0; i<len-1; i++)
		{
		for(j= i+1; j < len; j++)
		{
			if(i == index)
			{
				aux = *(array+i);
				*(array+i) = *(array+j);
				*(array+j) = aux;

			}
		}
		}
		*(array+index) = entero;
	}
}
