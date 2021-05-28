/*
 ============================================================================
 Name        : Clase19Tarea2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int multiplicar (int num1, int num2);
int calculador( int operador1, int(*pFuncion)(int,int),int operador2,int* pResultado);

int main(void) {
	setbuf(stdout,NULL);
	int numero1 = 9;
	int numero2 = 3;
	int resultado;
	int(*pFuncion)(int,int);
	pFuncion = multiplicar;
	int aux = calculador(numero1, pFuncion, numero2, &resultado);
	printf("\nEl resultado de la multiplicacion es: %d",aux);

	return EXIT_SUCCESS;
}
int multiplicar (int num1, int num2)
{
	int resultado;

	resultado = num1 * num2;
	return resultado;
}
int calculador( int operador1, int(*pFuncion)(int num1,int num2),int operador2,int* pResultado)
{

    if(pResultado != NULL)
    {
    	printf("\nEl primer numero es: %d", operador1);
    	printf("\nEl segunddo numero es: %d", operador2);
    	*pResultado = pFuncion(operador1 , operador2);
    }

    pFuncion(operador1 , operador2);

    return *pResultado;
}
