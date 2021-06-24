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
    eMovie* pAuxMovie = NULL;
    eDias* arrayDias = NULL;

    if(pArrayListMovies != NULL)
    {
    	if(ll_len(pArrayListMovies)>0)
    	{
        printf("|*******|**********************************|*******|*************|*******|**************|\n");
        printf("|   ID  |               NOMBRE             |  DIA  |   HORARIO   |  SALA |   CANTIDAD   |\n");
        printf("|*******|**********************************|*******|*************|*******|**************|\n");
        do
        {
        for(i = 0 ; i < ll_len(pArrayListMovies); i++)
        {
        	pAuxMovie = (eMovie*)ll_get(pArrayListMovies, i);
        	eMovie_getId(pAuxMovie, &id);
        	eMovie_getNombre(pAuxMovie, nombre);
        	eMovie_getDia(pAuxMovie, &dia);
        	eMovie_getDays(arrayDias, &dia, pAuxMovie, detalleDia);
        	eMovie_getHora(pAuxMovie, horario);
        	eMovie_getSala(pAuxMovie, &sala);
        	eMovie_getCantidad(pAuxMovie, &cantidad);

            utn_getMayusMin(nombre,MAX_NOMBRE);
            printf("| %5d | %50s | %10s | %10s | %10d | %10d|\n", id,nombre,detalleDia, horario,sala,cantidad);
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
	eMovie* pAuxMovie = NULL;
	int dia;
	int cantidad;
	float auxMonto;
	float descuento;
	int i;
	if(pArrayListMovies != NULL)
	{
		if(pAuxMovie != NULL)
		{
		for(i = 0; i < ll_len(pArrayListMovies);i++)
		{
			pAuxMovie = (eMovie*)ll_get(pArrayListMovies, i);
			eMovie_getDia(pAuxMovie, &dia);
			eMovie_getCantidad(pAuxMovie, &cantidad);

			if(dia == 1 || dia == 2 || dia ==3)
			{
				auxMonto = 240;
				printf("%.2f",auxMonto);
				//eMovie_setMonto(pAuxMovie, auxMonto);
			}
			else
			{
				auxMonto = 350;
				printf("%.2f",auxMonto);
				//eMovie_setMonto(pAuxMovie, auxMonto);
			}
			if(cantidad > 3)
			{
				descuento = auxMonto * 0.1;
				auxMonto = auxMonto - descuento;
			}

			printf("%.2f",auxMonto);
			retorno = 0;
		}
		}
	}
	return retorno;
}

