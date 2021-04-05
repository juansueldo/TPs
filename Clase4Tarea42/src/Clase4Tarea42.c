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
    char respuesta = 's';
    char respuesta2 = 's';
    int validarCent;
    int validarFar;

    do
    {
    printf("Que dato desea ingresar? \n1.Centigrados.\n2.Fahrenheit.\n");
    scanf("%d",&menu);

    switch(menu)
    	{
    	 case 1:
    	 mostrar = utn_getValidar (&centigrados, "Ingrese la temperatura en centigrados(El valor debe ser mayor a 0 y menor a 100)\n", "Error. El valor debe ser mayor a 0 y menor a 100\n",0, 100, 2);
    	 if(mostrar == 0)
    	 {
    	 printf("La temperatura es %.2f°C\n",centigrados);
    	 validarCent = utn_getValidar2("Desea convertir a fahrenheit? s/n\n", "ERROR. Desea convertir a fahrenheit? s/n\n", respuesta2 , 's', 'n', "\nFin.");
    	 if(validarCent == 0)
    	 {
    	 convertir = pasaje (centigrados);
    	 printf("\nLa temperatura en centigrados es %.2f °C\n",convertir);
    	 }
    	 }
    	 break;

    	 case 2:
    	 mostrar = utn_getValidar (&fahrenheit, "Ingrese la temperatura en fahrenheit(El valor debe ser mayor a 32 y menor a 212)\n", "Error. El valor debe ser mayor a 32 y menor a 212\n",32, 212, 2);
    	 if(mostrar == 0)
    	 {
    	 printf("La temperatura es %.2f °F\n",fahrenheit);
    	 validarFar = utn_getValidar2("Desea convertir a centrigrados? s/n\n", "ERROR. Desea convertir a centigrados? s/n\n", respuesta , 's', 'n', "\nFin.");
    	 if(validarFar == 0)
    	 {
    	 convertir = pasaje2 (fahrenheit);
    	 printf("\nLa temperatura en centigrados es %.2f °C\n",convertir);
    	 }
    	 }
    	 break;

    	 default:
    	 printf("\nError. Opcion no valida.");
    	 }
    }while((menu != 1) && (menu !=2));

    return EXIT_SUCCESS;
}

