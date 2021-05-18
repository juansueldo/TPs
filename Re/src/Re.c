#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int esCuit(char* cadena);

int main()
{
	setbuf(stdout, NULL);
    char i[11];

    printf("\nIngrese el cuil");
    fflush(stdin);
    scanf("%s",i);
   if(esCuit(i) ==0)
   {
	   printf("\nEs valido");
   }
   else
   {
	   printf("\nNo es valido");
   }

    return 0;
}
int esCuit(char* cadena)
{
	int ret;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(cadena!=NULL)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
			{
				if(cadena[i]=='-')
				{
					contadorGuion++;
				}
				else
				{
					ret=-1;
					break;
				}
			}
		}
		if(contadorDigito==11 && contadorGuion==2)
		{
			ret=0;
		}
	}
	return ret;
}
