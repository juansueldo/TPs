#include "Menu.h"

int menu_principal (int* opcion)
{
	int retorno = -1;
	printf("\n ");
    printf("\n |***********************************************************************************|\n");
    printf(" |                                  MENU PRINCIPAL                                   |\n");
    printf(" |***********************************************************************************|\n");
	printf(" |  [1] Cargar archivo.                                                              |\n");
	printf(" |  [2] Imprimir ventas.                                                             |\n");
	printf(" |  [3] Generar archivo de montos.                                                   |\n");
	printf(" |  [4] Informes.                                                                    |\n");
	printf(" |  [5] Salir del programa.                                                          |\n");
	printf(" |***********************************************************************************|\n\n");
	if(utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 5, 3)==0)
	{
		retorno = 0;
	}
	return retorno;
}
void menu_editarEmpleado (int *opcion)
{
	printf("\n ");
	printf("\n |***********************************************************************************|\n");
	printf(" |                                  MENU EDCION                                      |\n");
	printf(" |***********************************************************************************|\n");
	printf(" |  [1] Editar nombre.                                                               |\n");
	printf(" |  [2] Editar horas trabajadas.                                                     |\n");
	printf(" |  [3] Editar sueldo.                                                               |\n");
	printf(" |  [4] Volver atras.                                                                |\n");
	printf(" |***********************************************************************************|\n\n");
utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 4, 3);

}
void menu_ordenamiento (int *opcion)
{
	printf("\n ");
	printf("\n |***********************************************************************************|\n");
	printf(" |                                  ORDENAR                                          |\n");
	printf(" |***********************************************************************************|\n");
	printf(" |  [1] Ordenar por ID.                                                              |\n");
	printf(" |  [2] Ordenar por nombre.                                                          |\n");
	printf(" |  [3] Ordenar por horas trabajadas.                                                |\n");
	printf(" |  [4] Ordenar por sueldo.                                                          |\n");
	printf(" |  [5] Volver atras.                                                                |\n");
	printf(" |***********************************************************************************|\n\n");
	utn_menu(opcion,"\nINGRESE:", "\nERROR", 1, 5, 3);
}
