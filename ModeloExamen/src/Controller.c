/*
 * Controller.c
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListMovies)
{
    int verificar;
    int retorno = -1;
    FILE* file = NULL;

    if(pArrayListMovies != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
        	verificar = parser_MovieFromText(file, pArrayListMovies);
        	if(verificar == 0)
        	{
        		retorno = 0;
        	}

        }
    }

    fclose(file);
    return retorno;
}
int controller_ListMovies(LinkedList* pArrayListMovies)
{
    int retorno = -1;
    int i;
    int j;
    int id;
    int pantalla = 999;
    int respuesta;
    int respuesta2;
	char nombre[MAX_NOMBRE];
	int dia;
	char horario[MAX_NOMBRE];
	char detalleDia[MAX_NOMBRE];
	int sala;
	int cantidad;
    eMovie* pAuxMovie = eMovie_new();
    eDias* arrayDias = NULL;

    if(pArrayListMovies != NULL)
    {
    	if(ll_len(pArrayListMovies)>0)
    	{
        printf("|*******|**************************************************************|************|************|*******|***********|\n");
        printf("|   ID  |                        NOMBRE                                |    DIA     |   HORARIO  |  SALA |  CANTIDAD |\n");
        printf("|*******|**************************************************************|************|************|*******|***********|\n");
        do
        {
        for(i = 0 ; i < ll_len(pArrayListMovies); i++)
        {
        	pAuxMovie = (eMovie*)ll_get(pArrayListMovies, i);
        	eMovie_getId(pAuxMovie, &id);
        	eMovie_getNombre(pAuxMovie, nombre);
        	eMovie_getDia(pAuxMovie, &dia);
        	eMovie_getHora(pAuxMovie, horario);
        	eMovie_getSala(pAuxMovie, &sala);
        	eMovie_getCantidad(pAuxMovie, &cantidad);
        	for(j=0; j < 7; j++)
        	{
        		arrayDias = (eDias*)ll_get(pArrayListMovies, j);
        		eMovie_getDays(arrayDias, dia, detalleDia);
        	}

            utn_getMayusMin(nombre,MAX_NOMBRE);
            printf("| %5d | %60s | %10s | %10s | %5d | %10d| %10.2f\n", id,nombre,detalleDia, horario,sala,cantidad,pAuxMovie->monto);

            if(i == pantalla)
             {
        		do
        		{
        			respuesta = utn_getRespuesta ("\nPRESIONE [S] PARA MOSTRAR MAS EMPLEADOS: ","\nERROR", 3);
        			pantalla+=999;
        		}while(respuesta != 0);
              }
        	}
        	respuesta2 = utn_getRespuesta ("\nPRESIONE [S] PARA CONTINUAR: ","\nERROR", 3);

        }while(respuesta2 != 0);
        retorno = 0;

    	}
    }
    return retorno;
}
int controller_getMontos (LinkedList* pArrayListMovies)
{
	int retorno = -1;
	eMovie* pAuxMovie = eMovie_new();
	int id;
	int dia;
	int cantidad;
	char horario[MAX_NOMBRE];
	char nombre[MAX_NOMBRE];
	int sala;
	float auxMonto;
	int i;

	if(pArrayListMovies != NULL)
	{
		for(i = 0; i < ll_len(pArrayListMovies);i++)
		{
			pAuxMovie = (eMovie*)ll_get(pArrayListMovies, i);

			eMovie_getDia(pAuxMovie, &dia);
			eMovie_getCantidad(pAuxMovie, &cantidad);
			eMovie_getId(pAuxMovie, &id);
			eMovie_getNombre(pAuxMovie, nombre);
			eMovie_getHora(pAuxMovie, horario);
        	eMovie_getSala(pAuxMovie, &sala);
			eMovie_getMontoGenrado (pAuxMovie, dia,cantidad, &auxMonto);
			eMovie_setMonto(pAuxMovie, auxMonto);
			pAuxMovie = eMovie_newParametrosInt(id,nombre,dia,horario,sala,cantidad,auxMonto);

		}
			if(pAuxMovie != NULL && ll_add(pArrayListMovies, (eMovie*)pAuxMovie) == 0)
			{
				retorno = 0;
			}
	}

	return retorno;
}
int controller_saveAsText(char* path , LinkedList* pArrayListMovies)
{
    FILE* file = NULL;
    int retorno = -1;
    int eMovieQTY;
    int i;
    eMovie* pAuxMovie;

    if(pArrayListMovies != NULL)
    {
        eMovieQTY = ll_len(pArrayListMovies);

        file = fopen(path, "w");

        if(file != NULL
           && eMovieQTY > 0 && eMovieQTY <= 700
           && fprintf(file, "id_venta,nombre_pelicula,dia,horario,sala,cantidad_entradas,monto\n") != -1)
        {
            for(i = 0; i < eMovieQTY; i++)
            {
            	pAuxMovie = (eMovie*)ll_get(pArrayListMovies, i);
                if(fprintf(file, "%d,%s,%d,%s,%d,%d,%.2f\n",
                		pAuxMovie->id_venta,
						pAuxMovie->nombre_pelicula,
						pAuxMovie->dia,
						pAuxMovie->horario,
						pAuxMovie->sala,
						pAuxMovie->cantidad_entradas,
						pAuxMovie->monto) == -1)
                {
                    break;
                }

            }
        }

        if(i > 0 && i == eMovieQTY)
        {
        	//printf("\nMONTOS %.2f",pAuxeMovie->monto);
        	retorno = 0;
        }
    }

    fclose(file);
    free(pAuxMovie);
    return retorno;
}

int controller_ListBySala(LinkedList* pArrayListMovies)
{
	int retorno = -1;
	eMovie* pAuxMovie = eMovie_new();
	int sala;
	int auxSala;
	int i;
	int cantidad;
	float monto;
	char nombre[MAX_NOMBRE];
	char auxNombre[MAX_NOMBRE];
	int flag = 1;
	if(pArrayListMovies != NULL && ll_isEmpty(pArrayListMovies)==0)
	{
		utn_getNumero(&auxSala, "\nINGRESE LA SALA A IMPRIMIR: ", "\nERROR", 1, 5, 3);
		printf("|*********|********|**************|**************************************************************|\n");
		printf("|   SALA  |CANTIDAD|    MONTO     |                      NOMBRE                                  |\n");
		printf("|*********|********|**************|**************************************************************|\n");
		ll_sort(pArrayListMovies,eMovie_compareBynombre,1);
		for(i = 0; i < ll_len(pArrayListMovies); i++)
		{
			pAuxMovie = ll_get(pArrayListMovies, i);
			eMovie_getSala(pAuxMovie, &sala);
			if(auxSala == sala)
			{
				eMovie_getCantidad(pAuxMovie, &cantidad);
				eMovie_getMonto(pAuxMovie, &monto);
				eMovie_getNombre(pAuxMovie, nombre);
				if(flag ==1 || strcmp(auxNombre,nombre) !=0)
				{
					strcpy(auxNombre,nombre);
					retorno = 0;

				}
				printf("|  %5d  |  %5d |   %5.2f  |   %60s|\n",sala,cantidad,monto,nombre);
			}
		}
		retorno = 0;
	}
	return retorno;
}
