/*
 ============================================================================
 Name        : Orquesta.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Entidades.h"

#define TAM_ESTRUCTURA 5
#define TAM_MUSICOS 5
#define TAM_INSTRUMENTOS 5

int main(void) {

	setbuf(stdout, NULL);

	int opc;
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
		Menu();
		opc = Get_IntRange("INGRESE OPCION: ", "ERROR. REINGRESE: ", 1, 4);

		//MENU SWITCH
		switch (opc) {
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
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
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}

