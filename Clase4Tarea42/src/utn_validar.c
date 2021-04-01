#include <stdio.h>
#include <stdlib.h>

int utn_getValidar (float*num, char*mensaje, char*mensajeError,int min, int max, int reintentos)
{
    int retorno = -1;
    float buffer;
    if(num != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%f",&buffer);
            if(buffer >= min && buffer <= max)
            {
                *num = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos --;
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
