#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 *
 */
int utn_mostrarMenu (int* opcion, int operador1, int operador2,char*mensajeError, int min, int max, int salir)
{
	int retorno = -1;
	int bufferMenu;

	if(opcion != NULL)
	{
		printf("Menu:\n1.Ingresar 1er operando (A= %d)\n2.Ingresar 2do operando (B= %d)\n3.Calcular las operaciones\n4.Mostrar los resultados\n5.Salir\n" ,operador1,operador2);
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
int utn_menu (int* opcion,int operador1,int operador2,char* mensajeError, int min, int max, int salir)
{

	int retorno = -1;
	int bufferMenu;


	if(opcion != NULL && mensajeError != NULL && min <= max && salir != 0)
	{

		printf("Menu:\n1.Ingresar 1er operando (A= %d)\n2.Ingresar 2do operando (B= %d)\n3.Calcular las operaciones\n4.Mostrar los resultados\n5.Salir\n" ,operador1,operador2);
		scanf("%d",&bufferMenu);


		if(bufferMenu >= min && bufferMenu <= max)
		{
			scanf("%d",&operador1);
			scanf("%d",&operador2);
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


