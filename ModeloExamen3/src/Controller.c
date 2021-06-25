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
	char fecha[MAX_NOMBRE];
	char detalleTipo[MAX_NOMBRE];
	int tipo;
	int duracion;
	int j;
	int cantidad;
    eSala* pAuxSala = eSala_new();
    eTipo* pArrayTipo = NULL;

    if(pArrayListMovies != NULL)
    {
    	if(ll_len(pArrayListMovies)>0)
    	{
        printf("|*******|************|************|************|************|\n");
        printf("|   ID  |    FECHA   |    TIPO    |   CANTIDAD |  DURACION  |\n");
        printf("|*******|************|************|************|************|\n");
        do
        {
        for(i = 0 ; i < ll_len(pArrayListMovies); i++)
        {
        	pAuxSala = (eSala*)ll_get(pArrayListMovies, i);

        	eSala_getId(pAuxSala, &id);
        	eSala_getFecha(pAuxSala, fecha);
        	eSala_getTipo(pAuxSala, &tipo);
        	eSala_getCantidad(pAuxSala, &cantidad);
        	eSala_getDuracion(pAuxSala, &duracion);
        	for(j=0; j < 4; j++)
        	{
        		pArrayTipo = (eTipo*)ll_get(pArrayListMovies, j);
        		eSala_getDetalleTipo(pArrayTipo, tipo, detalleTipo);
        	}
        	//utn_getMayusMin(detalleTipo,MAX_NOMBRE);
            printf("| %5d | %10s | %10s | %10d | %10d |\n", id,fecha,detalleTipo, cantidad,duracion);

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
}/*
int controller_getMontos (LinkedList* pArrayListMovies)
{
	int retorno = -1;
	eMovie* pAuxSala = eMovie_new();
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
			pAuxSala = (eMovie*)ll_get(pArrayListMovies, i);

			eMovie_getDia(pAuxSala, &dia);
			eMovie_getCantidad(pAuxSala, &cantidad);
			eMovie_getId(pAuxSala, &id);
			eMovie_getNombre(pAuxSala, nombre);
			eMovie_getHora(pAuxSala, horario);
        	eMovie_getSala(pAuxSala, &sala);
			eMovie_getMontoGenrado (pAuxSala, dia,cantidad, &auxMonto);
			eMovie_setMonto(pAuxSala, auxMonto);
			pAuxSala = eMovie_newParametrosInt(id,nombre,dia,horario,sala,cantidad,auxMonto);

		}
			if(pAuxSala != NULL && ll_add(pArrayListMovies, (eMovie*)pAuxSala) == 0)
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
    eMovie* pAuxSala;

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
            	pAuxSala = (eMovie*)ll_get(pArrayListMovies, i);
                if(fprintf(file, "%d,%s,%d,%s,%d,%d,%.2f\n",
                		pAuxSala->id_venta,
						pAuxSala->nombre_pelicula,
						pAuxSala->dia,
						pAuxSala->horario,
						pAuxSala->sala,
						pAuxSala->cantidad_entradas,
						pAuxSala->monto) == -1)
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
    free(pAuxSala);
    return retorno;
}

int controller_ListBySala(LinkedList* pArrayListMovies)
{
	int retorno = -1;
	eMovie* pAuxSala = eMovie_new();
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
			pAuxSala = ll_get(pArrayListMovies, i);
			eMovie_getSala(pAuxSala, &sala);
			if(auxSala == sala)
			{
				eMovie_getCantidad(pAuxSala, &cantidad);
				eMovie_getMonto(pAuxSala, &monto);
				eMovie_getNombre(pAuxSala, nombre);
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
*/
