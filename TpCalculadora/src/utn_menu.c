#include <stdio.h>
#include <stdlib.h>

int utn_menu1 (int* opcion, char* mensaje,int operador1,char*mensaje2, int operador2,char*mensaje3,char* mensajeError, int min, int max, int salir)
{

	int retorno = -1;
	int bufferMenu;
	if(mensaje != NULL && mensaje2 != NULL && mensaje3 != NULL &&mensajeError != NULL && min <= max && salir != 0)
	{
		printf("%s",mensaje);
		scanf("%d",&bufferMenu);
		scanf("%d",&operador1);
		printf("%s",mensaje2);
		scanf("%d",&operador1);
		printf("%s",mensaje3);

		if(bufferMenu >= min && bufferMenu <= max)
		{
		  *opcion = bufferMenu;
		  retorno = 0;
		}
		else
		{
		  printf("%s",mensajeError);
	    }

	}
	return retorno;
}

int utn_menu (int* opcion, char* mensaje,char* mensajeError, int min, int max, int salir)
{

	int retorno = -1;
	int bufferMenu;
	if(mensaje != NULL && mensajeError != NULL && min <= max && salir != 0)
	{
		printf("%s",mensaje);
		scanf("%d",&bufferMenu);

		if(bufferMenu >= min && bufferMenu <= max)
		{
		  *opcion = bufferMenu;
		  retorno = 0;
		}
		else
		{
		  printf("%s",mensajeError);
	    }

	}
	return retorno;
}

