/*
 ============================================================================
 Name        : ModeloExamen2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include "Pantallas.h"
#include "Publicidad.h"

int main()
{
    setbuf(stdout, NULL);

	int opcion;
	int flagAlta = 0;
	int contador = 0;
	int contPublicidad = 0;
	int flagAltaPublicidad = 0;
	//int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	ePantalla arrayPantalla[MAX];
    eTipo arrayTipo[CANT];
    ePublicidad arrayPublicidad[MAX];


	//INICIALIAZO ARRAY DE ESTRUCTURA
    ePantalla_inicializar(arrayPantalla, MAX);

    strcpy(arrayTipo[0].descripcion,"LCD");
	arrayTipo[0].codigo = 1;

	strcpy(arrayTipo[1].descripcion,"LED");
	arrayTipo[1].codigo = 2;

	//BUCLE DE MENU
	do {
		utn_menu(&opcion, "\nMenu\n1. ALTA \n2. MODIFICAR \n3. BAJA \n4. CONTRATAR PULICIDAD \n10. Salir \n Ingrese:", "\nNO ES VALIDO\n", 1, 10,10);

		switch (opcion)
		{

		case 1:
			//ALTA arrayPantalla
			if (ePantalla_alta(arrayPantalla, MAX, &contador))
			{
				printf("\nALTA EXITOSA\n");
				flagAlta = 1;
			}
			else
			{
				printf("\nERROR. SIN ESPACIO PARA ALMACENAR");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if(flagAlta == 1)
			{
			if(ePantalla_modificarPantallas (arrayPantalla, MAX,arrayTipo,CANT) == 0)
			{
				printf("\nSE MODIFICO\n");
			}
			else
			{
				printf("\nNO SE MODICO\n");
			}
			}
			system("pause");
			break;
		case 3:
			//BAJA
			if(flagAlta == 1)
			{
			if(ePantalla_baja (arrayPantalla, MAX, arrayTipo, CANT) == 0)
			{
				printf("\nSE DIO LA BAJA\n");
			}
			else
			{
				printf("\nNO SE DIO LA BAJA\n");
			}
			}
			system("pause");
			break;
		case 4:
			//CONTRATAR PUBLICIDAD
			if(flagAlta == 1)
			{
			if(ePublicidad_alta (arrayPantalla,MAX,arrayPublicidad,arrayTipo,CANT, &contPublicidad)==0)
			{
				printf("\nALTA EXITOSA\n");
				flagAltaPublicidad = 1;
			}
			else
			{
				printf("\nNO SE DIO DE ALTA\n");
			}
			}
			system("pause");
			break;
		case 5:
			ePublicidad_modificarPantallas (arrayPublicidad, MAX, arrayPantalla, MAX);
			//MODIFICAR MUSICO
			 break;
		case 6:
			//ELIMINAR MUSICO
			break;
		case 7:
			//LISTAR MUSICOS
			break;
		case 8:
			//ALTA INSTRUMENTO
			break;
		case 9:
			//LISTAR INSTRUMENTOS
			break;
		}
	} while (opcion != 10);

	puts("\n... FIN PROGRAMA");

	return 0;
}

