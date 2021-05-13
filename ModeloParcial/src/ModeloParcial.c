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
		utn_menu(&opcion, "\nMenu\n1. Dar alta orquesta \n2. Dar de baja orquesta \n3. Listar orquesta \n4. Dar alta musico  \n5. Modificar musico \n6. Eliminar musico \n7. Listar musicos \n8. Agregar instrumentos \n9. Listar instrumentos \n10. Salir \n Ingrese:", "\nNO ES VALIDO\n", 1, 10,10);

		switch (opcion)
		{

		case 1:
			//ALTA ORQUESTA
			if (eOrquesta_Alta(Orquesta, TAM_ESTRUCTURA)) {
				printf(" * Orquesta DADO DE ALTA EXITOSAMENTE");
			} else {
				printf(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Orquesta");
			}
			system("pause");
			break;
		case 2:
			//BAJA ORQUESTA
			if (eOrquesta_Baja(Orquesta, TAM_ESTRUCTURA)) {
				printf("\n * BAJA DE Orquesta EXITOSA");
				eOrquesta_MostrarTodos(Orquesta, TAM_ESTRUCTURA);
			} else {
				printf("\n * BAJA DE Orquesta CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//LISTADO ORQUESTA
			if (eOrquesta_MostrarTodos(Orquesta, TAM_ESTRUCTURA)) {

			} else {
				printf("No hay nada para mostrar");
			}
			break;

		case 4:
			//ALTA MUSICO
			if(eMusicoOrquesta_Alta(Musicos, TAM_MUSICOS, Orquesta, TAM_ESTRUCTURA, Instrumentos, TAM_INSTRUMENTOS)){
				puts("ALTA DE MUSICO EXITOSA");
			}else{
				puts("ERROR EN ALTA DE MUSICO");
			}
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


