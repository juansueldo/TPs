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
int utn_getValidar2(char*mensaje, char*mensajeError,char respuesta, char s, char n, char*mensaje2)
{
	int retorno = -1;
	if(mensaje != NULL && mensajeError != NULL  && mensaje2 != NULL)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&respuesta);
			if(respuesta == s)
			{
				retorno = 0;
			}
			else if(respuesta == n)
			{
				printf("%s",mensaje2);
			}
			else
			{
				printf("%s",mensajeError);
			}

		}while((respuesta != s) && (respuesta != n));

	}
	return retorno;
}
