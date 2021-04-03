/*
 ============================================================================
 Name        : Clase1Tarea23.c
 Author      : Juan Sueldo
Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe. En caso de que no
exista también informarlo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("cls");
	setbuf (stdout, NULL);

	int numero;
	int primero;
	int segundo;
	int tercero;
	int mayor;
	int menor;
	int i;

	for(i = 0; i < 3; i++)
		{
			printf("Ingrese un numero:\n");
			scanf("%d",&numero);

			switch (i)
			{
			case 0:
				primero = numero;
				mayor = numero;
				menor = numero;
				break;
			case 1:
				segundo = numero;
				break;
			case 2:
				tercero = numero;
				break;
			}
			if(numero > mayor)
					{
						mayor = numero;
					}
					if(numero < menor)
					{
						menor = numero;
					}

				}
				if (primero != mayor && primero != menor)
				{
					printf("\nEl numero del medio es %d",primero);
				}
				else if(segundo != mayor && segundo != menor)
				{
					printf("\nEl numero del medio es %d", segundo);
				}
				else if(tercero != mayor && tercero != menor)
				{
					printf("\nEl numero del medio es %d", tercero);
				}
				else
				{
					printf("\nNo existe");
				}

	return EXIT_SUCCESS;
	}
