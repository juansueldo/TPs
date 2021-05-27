/*
 ============================================================================
 Name        : TareaClase18.c
 Author      : 
 EJERCICIO
Realizar un programa que :
a)tenga 2 funciones una para calcular el minimo y otra para
calcular el maximo :
que retorne -1 si hubo errores y 0 si funcionó bien
que reciba dos número para comparar y un entero por referencia para devolver
el mínimo o máximo encontrado
b)Luego desarrollar una función que reciba por parámetro dos número enteros y
un puntero a función que ejecute la función recibida por parámetro y retorne el
resultado por retorno.  Puede recibir cualquiera de las dos funciones desarrolladas en
el punto a)
Crear un main donde se utilice la función del punto b) utilizando las 2 funciones
desarrolladas en el punto a)

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int fMaximo (int num1, int num2, int *pMaximo);
int fMninimo (int num1, int num2, int *pMinimo);
int calcular( int numero1, int numero2, int(*pFuncion)(int,int,int*) );

int main(void) {
	setbuf(stdout,NULL);
	int num1;
	int num2;
	int opcion;
	int auxiliar;
	int (*pHacer)(int,int,int*);

	utn_getNumero(&num1,"\nIngrese el primer numero[0 a 9999]: ","\nERROR.",0,9999,3);
	utn_getNumero(&num2,"\nIngrese segundo numero[0 a 9999]: ","\nERROR.",0,9999,3);
	printf("\n\n");
	do
	{
		utn_menu(&opcion,"\nIngrese una opcion  1 [Maximo] 2 [Minimo] 3 [Salir]: ","\nERROR.",1,3);

		switch(opcion)
		{
		case 1:
			pHacer = fMaximo;
			if(pHacer)
			{
				auxiliar = calcular(num1,num2,pHacer);
				printf("\nEl maximo es %d\n\n",auxiliar);
			}
			else
			{
				printf("\nNo existe el maximo\n\n");
			}
			system ("pause");
		break;
		case 2:
			pHacer = fMninimo;
			if(pHacer)
			{
				auxiliar = calcular(num1,num2,pHacer);
				printf("\nEl minimo es %d\n\n",auxiliar);
			}
			else
			{
				printf("\nNo existe el minimo\n\n");
			}
			system ("pause");
		break;
		case 3:
			printf("\nFin");
		break;
	}
	}while(opcion != 3);
	return EXIT_SUCCESS;
}
int fMaximo (int num1, int num2, int *pMaximo)
{
	int rtn = -1;
	int max;
    if(pMaximo != NULL)
    {
	    if(num1 > num2)
	    {
		    max = num1;
		    *pMaximo = max;
		    rtn = 0;
	    }
	    else
	    {
		    max = num2;
		    *pMaximo = max;
		    rtn = 0;
	    }
    }
	return rtn;
}
int fMninimo (int num1, int num2, int *pMinimo)
{
	int rtn = -1;
    if(pMinimo != NULL)
    {
	    if(num1 < num2)
	    {
		    *pMinimo = num1;
		    rtn = 0;
	    }
    	else

	    {
		    *pMinimo = num2;
		    rtn = 0;
	    }
}
	return rtn;
}
int calcular( int numero1, int numero2, int(*pFuncion)(int,int,int*) )
{
    int auxResultado;
    printf("\nEl primer numero ingresado es: %d ", numero1);
    printf("\nEl segundo numero ingresado es: %d ", numero2);
    printf("\n\n");
    pFuncion(numero1 , numero2 , &auxResultado);

    return auxResultado;
}


