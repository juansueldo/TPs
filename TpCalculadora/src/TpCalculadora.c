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
#include "utn_calculos.h"

int main(void) {
	setbuf(stdout, NULL);
	//int eleccion;
	int menu;
	float operador1 =0;
	float operador2 =0;
	int menuOperaciones;
	int opcion;
	float operacion;
	float resultado;
	/*int menuResultado;
	int opcionResultado;*/


	do
	{
		printf("Menu:\n");
		printf("1.Ingresar 1er operando (A=%.2f)\n", operador1);
		printf("2.Ingresar 2do operando (B=%.2f)\n", operador2);
		printf("3.Calcular las operaciones\n");
		printf("4.Mostrar los resultados\n");
		printf("5.Salir\n");
		scanf("%d",&menu);

		switch(menu)
		{
		case 1:
		    printf("Ingrese el primer operando:\n");
		    scanf("%f",&operador1);
		    printf("Primer operando ingresado: %.2f\n",operador1);
			break;

		case 2:
			printf("Ingrese el segundo operando:\n");
			scanf("%f",&operador2);
			printf("Segundo operando ingresado: %.2f\n",operador2);
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
					operacion = utn_getSuma(operador1, operador2);
					break;
				case 2:
					operacion = utn_getResta(operador1, operador2);
					break;
				case 3:
					operacion = utn_getDividir(operador1, operador2, &resultado);
					break;
				case 4:
					operacion = utn_getMultiplicar(operador1, operador2);
					break;
				case 5:

					break;
				}
			}
			}
			break;
		case 4:
			/*menuResultado = utn_menu (&opcionResultado, "\nEl resultado:\n1.Suma\n2.Resta\n3.Division\n4.Producto\n","Opcion no valida", 1, 6, 6);
			if(menuResultado == 0)
			{*/
				switch(opcion)
				{
				case 1:
					printf("El resultado de A+B es: %.2f\n",operacion);
					break;
				case 2:
					printf("El resultado de A-B es: %.2f\n",operacion);
					break;
				case 3:
					if(operacion != 0)
					{
						printf("El resultado de A/B es: %.2f\n", resultado);
					}
						else
					{
						printf("No es posible dividir por cero\n");
					}
					break;
				case 4:
					printf("El resultado de A*B es: %.2f\n",operacion);
					break;
				case 5:
					break;
				}
			//}
			break;
		case 5:
			break;
	}
	}while(menu != 5);

	return EXIT_SUCCESS;
}
