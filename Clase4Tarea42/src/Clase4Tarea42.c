/*
 ============================================================================
 Name        : Clase4Tarea42.c
 Author      : Juan Sueldo
 Ejercicio 4-2:
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
validando que las temperaturas ingresadas estén entre el punto
de congelación y ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit
se hacen en otra biblioteca.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "utn_conversor.h"

int main()
{
	system("cls");
    setbuf (stdout, NULL);
    int menu;
    int mostrar;
    float convertir;
    float centigrados;
    float fahrenheit;

    printf("Bienvenidxs, que dato desea ingresar? \n1.Centigrados.\n2.Fahrenheit.\n");
    scanf("%d",&menu);

    switch(menu)
    {
        case 1:
        mostrar = utn_getValidar (&centigrados, "Ingrese los centigrados(El valor debe ser mayor a 0 y menor a 100)\n", "Error. El valor debe ser mayor a 0 y menor a 100\n",0, 100, 2);
        if(mostrar == 0)
        {
            printf("La temperatura es %.2f°C",centigrados);
            convertir = pasaje (&centigrados, "Desea convertir a fahrenheit? s/n\n","Error. No valido\n");
            printf("\nLa temperatura en fahrenheit es %.2f°F",convertir);
        }
        else
        {
            printf("\nError");
        }
        break;

        case 2:
        mostrar = utn_getValidar (&fahrenheit, "Ingrese los fahrenheit(El valor debe ser mayor a 32 y menor a 212)\n", "Error. El valor debe ser mayor a 32 y menor a 212\n",32, 212, 2);
        if(mostrar == 0)
        {
            printf("La temperatura es %.2f °F",fahrenheit);
            convertir = pasaje2 (fahrenheit);
            printf("\nLa temperatura en centigrados es %.2f °C",convertir);
        }
        else
        {
            printf("\nError");
        }
        break;
        default:
        	printf("\nError. Opcion no valida.");
    }

    return EXIT_SUCCESS;
}

