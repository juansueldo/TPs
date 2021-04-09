/*
 ============================================================================
 Name        : Clase5TareaExtra.c
 Author      : 
 Ejercicio array paralelo: de 10 empleados,
 cargar edad y sueldo. Se pide ingresar los datos consecutivamente y calcular el sueldo promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 2

int main(void) {
	setbuf(stdout, NULL);
	int edad[CANTIDAD];
	float sueldo[CANTIDAD];
	int legajo;
	int acumSueldo = 0;
	int contSueldo = 0;
	float promedio;

	for(legajo = 0;legajo < CANTIDAD; legajo++)
	{
		printf("Ingrese la edad del empleado: \n");
		scanf("%d",&edad[legajo]);

		printf("Ingrese el sueldo: \n");
		scanf("%f",&sueldo[legajo]);
		acumSueldo += (float)sueldo[legajo];
		contSueldo ++;
	}
	promedio = (float)acumSueldo /contSueldo;

	printf("El sueldo promedio es %.2f\n",promedio);

	for(legajo = 0;legajo < CANTIDAD; legajo++)
	{
		printf("El empleado del legajo %d, tiene %d años y su sueldo es de %.2f\n",legajo,edad[legajo],sueldo[legajo]);
	}
	return EXIT_SUCCESS;
}
