/*
 ============================================================================
 Name        : Clase19MemoriaDinamica.c
 Author      : 
 Realizar una funci�n que reciba como par�metro:
 un array de enteros, su tama�o y un entero.
 La funci�n se encargar� de buscar el valor
 y borrar� la primera ocurrencia del mismo.
 El array deber� reestructurarse din�micamente
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void fBuscar (int array[], int len, int entero);

int main(void) {
	setbuf(stdout, NULL);
	int i;
	int* vec;
	int* vaux;
	vec=(int*)malloc(sizeof(int)*5);

	if (vec!=NULL)
	 {
	     for (i=0;i<5;i++)
	     {
	    	 printf("\nINGRESE UN NUMERO: ");
	    	 scanf("%d",&(*(vec+i)));
	         //*(vec+i)=i;
	     }
	}

	for (i=0;i<5;i++)
	{
	    printf("\n Notacion Aritmetica Contenido %d posicion %d", *(vec+i), i);
	}

	fBuscar (vec, i, 0);

	printf("\n\n");
	for (i=0;i<5;i++)
	{
		   printf("\n Notacion Aritmetica Contenido %d posicion %d", *(vec+i), i);
	}

	vaux = (int*)realloc(vec,sizeof(int)*10); //AGRANDAR SU TAMA�O DINAMICAMENTE
	 if (vaux!=NULL)
	 {
	     vec = vaux;
	 }

	 for(i=5;i<10;i++)
	 {
		 printf("\nINGRESE UN NUMERO: ");
		 scanf("%d",&(*(vec+i)));
	 }

	 printf("\n\n");
	 for (i=0;i<10;i++)
	 {
	 	 printf("\n Numero ingresado %d", *(vec+i));
	 }

	 fBuscar (vec, i, 0);

	 printf("\n\n");
	 for (i=0;i<10;i++)
	 {
	 	printf("\n Notacion Aritmetica Contenido %d posicion %d", *(vec+i), i);
	 }

	return EXIT_SUCCESS;
}
void fBuscar (int array[], int len, int entero)
{
	int i;
	if(array!=NULL && len>0)
		{
			for(i=0; i<len; i++)
			{
				if(*(array+i)==2)
				{
					*(array+i)=0;

				}
			}
		}
}
