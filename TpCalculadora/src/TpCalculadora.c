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
	int a;
	int b;
	int suma;
	int resta;
	int producto;
	int division;
	int resultado;

	printf("Ingresar 1er operando:\n");
	scanf("%d",&a);

	printf("Ingresar 2do operando:\n");
	scanf("%d",&b);

	suma = utn_getSuma (a, b);
	resta = utn_getResta (a, b);
	producto = utn_getMultiplicar (a, b);
	division = utn_getDividir (a, b, &resultado);

	printf("El resultado de la suma es: %d\n",suma);
	printf("El resultado de la resta es: %d\n",resta);
	printf("El resultado de la multiplicacion es: %d\n",producto);
	if(division != 0)
	{
		printf("El resultado de la division es: %.2f\n", resultado);
	}
	else
	{
		printf("No se puede dividir por cero\n");
	}


	return EXIT_SUCCESS;
}
