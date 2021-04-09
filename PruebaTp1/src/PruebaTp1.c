/*
 ============================================================================
 Name        : PruebaTp1.c
 Author      : Juan Sueldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int main(void)
{
	setbuf(stdout, NULL);
	int menu;
	int opcion;
	int num1 = 0;
	int num2 = 0;
	    do
		{
	    	menu = utn_mostrarMenu (&opcion, num1, num2,"La opcion no es valida\n",1,5,5);
			if(menu == 0)
			{
			    switch (opcion)
			    {
			    case 1:
			    printf("\nIngrese el primer operando:\n");
			    scanf("%d",&num1);
			    printf("\nPrimer operandor ingresador: %d\n",num1);
			    break;
			    case 2:
			    printf("\nIngrese el segundo operandor:\n");
			    scanf("%d",&num2);
			    printf("\nSegundo operandor ingresado: %d\n",num2);
			    break;
			    }
			}


	}while (opcion != 5);
	return 0;
}


