/*
 ============================================================================
 Name        : ModeloParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "entidades.h"

#define TAM_ESTRUCTURA 5
#define TAM_MUSICOS 5
#define TAM_INSTRUMENTOS 5

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	//int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eOrquesta Orquesta[TAM_ESTRUCTURA];
	eMusico Musicos[TAM_MUSICOS];
	eInstrumento Instrumentos[TAM_INSTRUMENTOS];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eOrquesta_Inicializar(Orquesta, TAM_ESTRUCTURA);
	eMusico_Inicializar(Musicos, TAM_MUSICOS);
	eInstrumento_Inicializar(Instrumentos, TAM_INSTRUMENTOS);

	//BUCLE DE MENU
	do {
		utn_menu(&opcion, "\nMenu\n1. Dar alta orquesta \n2. Dar de baja orquesta \n3. Listar \n4. Dar alta musico  \n6. Salir\n Ingrese:", "\nNO ES VALIDO\n", 1, 5,5);

		//MENU SWITCH
		switch (opcion)
		{

		case 1:
			//ALTA
			if (eOrquesta_Alta(Orquesta, TAM_ESTRUCTURA)) {
				puts(" * Orquesta DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Orquesta");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eOrquesta_Baja(Orquesta, TAM_ESTRUCTURA)) {
				puts("\n * BAJA DE Orquesta EXITOSA");
				eOrquesta_MostrarTodos(Orquesta, TAM_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE Orquesta CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//LISTADO Orquesta
			if (eOrquesta_MostrarTodos(Orquesta, TAM_ESTRUCTURA)) {
				system("pause");
			} else {
				puts("No hay nada para mostrar pa");
			}
			break;

		case 4:
			if(eMusicoOrquesta_Alta(Musicos, TAM_MUSICOS, Orquesta, TAM_ESTRUCTURA, Instrumentos, TAM_INSTRUMENTOS)){
				puts("ALTA DE MUSICO EXITOSA");
			}else{
				puts("ERROR EN ALTA DE MUSICO");
			}
			break;

			/*case 5:
			 //ORDENAR Orquesta
			 criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
			 eOrquesta_Sort(Orquesta, TAM_ESTRUCTURA, criterioDeOrdenamiento);
			 system("pause");
			 break;*/
		}
	} while (opcion != 6);

	puts("\n... FIN PROGRAMA");

	return 0;
}


