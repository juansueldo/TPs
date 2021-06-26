#include "Menu.h"

int menu_principal (int* opcion)
{
	int retorno = -1;
	printf("\n ");
    printf("\n |***********************************************************************************|\n");
    printf(" |                                  MENU PRINCIPAL                                   |\n");
    printf(" |***********************************************************************************|\n");
	printf(" |  [1] Cargar archivo.                                                              |\n");
	printf(" |  [2] Ordenar por autor.                                                           |\n");
	printf(" |  [3] Listar libros.                                                               |\n");
	printf(" |  [4] Informes.                                                                    |\n");
	printf(" |  [5] Salir del programa.                                                          |\n");
	printf(" |***********************************************************************************|\n\n");
	if(utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 5, 3)==0)
	{
		retorno = 0;
	}
	return retorno;
}
