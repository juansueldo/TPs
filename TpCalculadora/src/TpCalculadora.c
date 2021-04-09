/*
 ============================================================================
 Name        : TpCalculadora.c
 Author      : Juan Sueldo
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_menu.h"
#include "utn_calculos.h"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int opcion;
	int operador1 =0;
	int operador2 =0;
	int suma;
	int resta;
	int multiplicacion;
	int division;
	int factorial1;
	int factorial2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	long unsigned int resultadoFactorial1;
	long unsigned int resultadoFactorial2;



	do
	{
		menu = utn_mostrarMenu (&opcion, operador1, operador2,"La opcion no es valida\n",1,5,5);
		if(menu == 0)
		{
		switch(opcion)
		{
		case 1:
		    printf("\nIngrese el primer operando:\n");
		    scanf("%d",&operador1);
		    printf("\nPrimer operando ingresado: %d\n",operador1);
			break;

		case 2:
			printf("\nIngrese el segundo operando:\n");
			scanf("%d",&operador2);
			printf("\nSegundo operando ingresado: %d\n",operador2);
			break;

		case 3:
			if(operador1 == 0 && operador2 == 0)
			{
				printf("\nDebe ingresar al menos un valor para continuar\n");
			}
			else
			{
					suma = utn_getSuma(operador1, operador2, &resultadoSuma,"\nLos operadores tienen que ser distintos a cero");
					if(suma == 0)
					{
						printf("A.Se realizo la suma\n");
					}

					resta = utn_getResta(operador1, operador2, &resultadoResta,"\nLos operadores tienen que ser distintos a cero");
					if(resta == 0)
					{
						printf("B.Se realizo la resta\n");
					}

					division = utn_getDividir(operador1, operador2,"C.No es posible dividir por cero\n", &resultadoDivision);
					if(division == 0)
					{
						printf("C.Se realizo la division\n");
					}

					multiplicacion = utn_getMultiplicar(operador1, operador2,&resultadoMultiplicacion);
					if(multiplicacion == 0)
					{
						printf("D.Se realizo la multiplicacion\n");
					}

					factorial1 = utn_getFactorial(operador1, &resultadoFactorial1,"\nE.El operador A tiene que ser mayor a cero\n");
					if(factorial1 == 0)
					{
						printf("E.Se realizo el factoreo de A\n");
					}
					factorial2 = utn_getFactorial(operador2, &resultadoFactorial2,"\nF.El operador B tiene que ser mayor a cero\n");
					if(factorial2 == 0)
					{
						printf("F.Se realizo el factoreo de B\n");
					}
				}
			break;
		case 4:
			if(operador1 == 0 && operador2 == 0)
			{
			printf("Debe ingresar al menos un valor para continuar\n");
			}

					if(suma == 0)
					{
						printf("A.El resultado de A+B es: %d\n",resultadoSuma);
					}

					if(resta == 0)
					{
						printf("B.El resultado de A-B es: %d\n",resultadoResta);
					}

					if(division == 0)
					{
						printf("C.El resultado de A/B es: %.2f\n", resultadoDivision);
					}
						else
					{
						printf("C.No es posible dividir por cero\n");
					}

					if(multiplicacion == 0)
					{
						printf("D.El resultado de A*B es: %d\n",resultadoMultiplicacion);
					}

					if(factorial1 == 0)
					{
						printf("E.El resultado del factorial de A es: %d\n",resultadoFactorial1);
					}
					if(factorial2 == 0)
					{
						printf("F.El resultado del factorial de B es: %d\n",resultadoFactorial2);
					}

			break;
		case 5:
			printf("Adios");
			break;

	}
	}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
