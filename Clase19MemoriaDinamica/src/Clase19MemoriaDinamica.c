/*
 ============================================================================
 Name        : Clase19MemoriaDinamica.c
 Author      : 
 Realizar una función que reciba como parámetro:
 un array de enteros, su tamaño y un entero.
 La función se encargará de buscar el valor
 y borrará la primera ocurrencia del mismo.
 El array deberá reestructurarse dinámicamente
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void fBuscar (int array[], int len, int entero);

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

	fBuscar (vector, TAM, 2);

	printf("\n\n");

	vecAux = (int*)realloc(vector,sizeof(int)*TAM-1);
	if (vecAux!=NULL)
	{
		vector = vecAux;
	}
	for (i=0;i<TAM-1;i++)
	{
		printf("\nNUMERO INGRESADO: %d POSICION: %d", *(vector+i), i);
	}

free(vector);
free(vecAux);

	return EXIT_SUCCESS;
}
void fBuscar (int array[], int len, int entero)
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
				if(*(array+i) == entero)
				{
					aux = *(array+i);
					*(array+i) = *(array+j);
					*(array+j) = aux;
					break;

				}

				}
			}
		}
}
