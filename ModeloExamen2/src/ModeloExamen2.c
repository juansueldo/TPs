/*
 ============================================================================
 Name        : ModeloExamen2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "led.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int flagAlta = 0;
	//int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	ePantalla arrayPantalla[MAX];


	//INICIALIAZO ARRAY DE ESTRUCTURA
	ePantalla_Inicializar(arrayPantalla, MAX);


	//BUCLE DE MENU
	do {
		utn_menu(&opcion, "\nMenu\n1. ALTA \n2. MODIFICAR \n3. BAJA \n4. \n10. Salir \n Ingrese:", "\nNO ES VALIDO\n", 1, 10,10);

		switch (opcion)
		{

		case 1:
			//ALTA arrayPantalla
			if (ePantalla_Alta(arrayPantalla, MAX))
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
			if(ePantalla_Modificacion  (arrayPantalla, MAX) == 0)
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
			if(ePantalla_Baja(arrayPantalla, MAX) == 0)
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
			//ALTA MUSICO

			break;
		case 5:
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
