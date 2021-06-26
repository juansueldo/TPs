#include "Parser.h"
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook)
{
    int cantidad;
    int retorno = -1;
    char buffer[5][200];
    eBook* pAuxBook = NULL;

    if(pFile != NULL && pArrayListBook != NULL)
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
        		pAuxBook = eBook_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

                if(pAuxBook != NULL && ll_add(pArrayListBook, (eBook*)pAuxBook) == 0)
                {
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

