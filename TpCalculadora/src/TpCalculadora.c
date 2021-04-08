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
	//int menu1;
	int operador1 =0;
	int operador2 =0;
	int menuOperaciones;
	int opcion;
	float operacion;
	int result;
	int operacion2;
	float resultado;
	int resultado2;


	do
	{
		//menu1 = utn_menu1 (&menu, "Menu:\n1.Ingresar 1er operando (A=%d)\n",operador1,"2.Ingresar 2do operando (B=%d)\n",operador2,"3.Calcular las operaciones\n4.Mostrar los resultados\n5.Salir\n","Ingrese una opcion válida\n", 1, 5, 5);

		printf("Menu:\n");
		printf("1.Ingresar 1er operando (A=%d)\n", operador1);
		printf("2.Ingresar 2do operando (B=%d)\n", operador2);
		printf("3.Calcular las operaciones\n");
		printf("4.Mostrar los resultados\n");
		printf("5.Salir\n");
		scanf("%d",&menu);
		//if(menu1 == 0){

		switch(menu)
		{
		case 1:
		    printf("Ingrese el primer operando:\n");
		    scanf("%d",&operador1);
		    printf("Primer operando ingresado: %d\n",operador1);
			break;

		case 2:
			printf("Ingrese el segundo operando:\n");
			scanf("%d",&operador2);
			printf("Segundo operando ingresado: %d\n",operador2);
			break;

		case 3:
			if(operador1 == 0 && operador2 == 0)
			{
				printf("Debe ingresar al menos un valor para continuar\n");
			}
			else
			{
			menuOperaciones = utn_menu (&opcion, "\n1.Calcular la suma (A+B)\n2.Calcular la resta (A-B)\n3.Calcular la division (A/B)\n4.Calcular la multiplicacion (A*B)\n5.Calcular el factorial (A!)\n","Opcion no valida", 1, 6, 6);
			if(menuOperaciones == 0)
			{
				switch(opcion)
				{
				case 1:
					operacion = utn_getSuma(operador1, operador2, &result,"\nLos operadores tienen que ser distintos a cero");
					if(operacion == 0)
					{
						printf("Se realizo la suma\n");
					}
					break;
				case 2:
					operacion = utn_getResta(operador1, operador2, &result,"\nLos operadores tienen que ser distintos a cero");
					if(operacion == 0)
					{
						printf("Se realizo la resta\n");
					}
					break;
				case 3:
					operacion = utn_getDividir(operador1, operador2,"No es posible dividir por cero\n", &resultado);
					if(operacion == 0)
					{
						printf("Se realizo la division\n");
					}
					break;
				case 4:
					operacion = utn_getMultiplicar(operador1, operador2,&result,"\nNo se puede sacar el factorial de un numero menor o igual a cero");
					if(operacion == 0)
					{
						printf("Se realizo la multiplicacion\n");
					}
					break;
				case 5:
					operacion = utn_getFactorial(operador1, &result,"\nEl operador A tiene que ser mayor a cero\n");
					if(operacion == 0)
					{
						printf("Se realizo el factoreo de A\n");
					}
					operacion2 = utn_getFactorial(operador2, &resultado2,"\nEl operador B tiene que ser mayor a cero\n");
					if(operacion2 == 0)
					{
						printf("Se realizo el factoreo de B\n");
					}
					break;
				}
			}
			}
			break;
		case 4:
			if(operador1 == 0 && operador2 == 0)
			{
			printf("Debe ingresar al menos un valor para continuar\n");
			}
			else if(operacion != 0)
			{
				printf("Debe realizar una operacion para mostrar los resultados\n");
			}
			else
			{
				switch(opcion)
				{
				case 1:
					if(operacion == 0)
					{
						printf("El resultado de A+B es: %d\n",result);
					}
					break;
				case 2:
					if(operacion == 0)
					{
						printf("El resultado de A-B es: %d\n",result);
					}
					break;
				case 3:
					if(operacion == 0)
					{
						printf("El resultado de A/B es: %.2f\n", resultado);
					}
						else
					{
						printf("No es posible dividir por cero\n");
					}
					break;
				case 4:
					if(operacion == 0)
					{
						printf("El resultado de A*B es: %d\n",result);
					}
					break;
				case 5:
					if(operacion == 0)
					{
						printf("El resultado del factorial de A es: %d\n",result);
					}
					if(operacion2 == 0)
					{
						printf("El resultado del factorial de B es: %d\n",resultado2);
					}
					break;
				}
			}
			break;
		case 5:
			printf("Adios");
			break;

	}
	}while(menu != 5);

	return EXIT_SUCCESS;
}
