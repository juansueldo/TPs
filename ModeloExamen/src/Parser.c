/*
 * Parser.c
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */
#include "Parser.h"
int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListMovie)
{
    int cantidad;
    int retorno = -1;
    char buffer[6][200];
    eMovie* pAuxMovie = NULL;

    if(pFile != NULL && pArrayListMovie != NULL)
    {
    	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
    	do
        {
        	cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);

        	if(cantidad < 6)
            {
        		printf("\nFIN");
        		break;
            }
        	else
        	{
        		pAuxMovie = eMovie_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);

                if(pAuxMovie != NULL && ll_add(pArrayListMovie, (eMovie*)pAuxMovie) == 0)
                {
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

