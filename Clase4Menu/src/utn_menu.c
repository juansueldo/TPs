#include <stdio.h>
#include <stdlib.h>

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
int utn_getLogueo (char* mensaje)
{
	int retorno = -1;
	if( mensaje != NULL)
	{
		printf("%s",mensaje);
		retorno = 0;
	}
	return retorno;
}
int utn_getComprar (int menu, char* mensaje, char* mensajeError)
{
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL)
	{
		if(menu == 1)
			{
				printf("%s",mensaje);
				retorno = 0;

			}
			else
			{
				printf("%s",mensajeError);
			}

	}
	return retorno;
}
int utn_getVerComprar (int menu,int comprar, char* mensaje, char* mensajeError, char* mensajeError2)
{
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL)
	{
		if(menu == 1 && comprar != 0)
			{
				printf("%s",mensaje);
				retorno = 0;
		}
		if(menu != 1)
		{
			printf("%s",mensajeError);
		}
		if(menu == 1 && comprar == 0)
		{
			printf("%s",mensajeError2);
		}

	}
	return retorno;
}
int utn_getVender (int menu,int comprar, char* mensaje, char* mensajeError, char* mensajeError2)
{
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL)
	{
		if(menu == 1 && comprar != 0)
			{
				printf("%s",mensaje);
				retorno = 0;
		}
		if(menu != 1)
		{
			printf("%s",mensajeError);
		}
		if(menu == 1 && comprar == 0)
		{
			printf("%s",mensajeError2);
		}

	}
	return retorno;
}
int utn_getFacturar (int menu, char* mensaje, char* mensajeError)
{
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL)
	{
		if(menu >= 1)
			{
				printf("%s",mensaje);
				retorno = 0;

			}
			else
			{
				printf("%s",mensajeError);
			}

	}
	return retorno;
}
