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
    char buffer[5][200];
    eSala* pAuxSala = NULL;

    if(pFile != NULL && pArrayListMovie != NULL)
    {
    	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);
    	do
        {
        	cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

        	if(cantidad < 5)
            {
        		printf("\nFIN");
        		break;
            }
        	else
        	{
        		pAuxSala = eSala_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

                if(pAuxSala != NULL && ll_add(pArrayListMovie, (eSala*)pAuxSala) == 0)
                {
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

