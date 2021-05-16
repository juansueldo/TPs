/*
 ============================================================================
 Name        : Primer_Parcial_Lab1.c
 Author      : Juan Sueldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Contribuyente.h"
#include "Recaudaciones.h"
#include "Informes.h"

int main()
{
    setbuf(stdout, NULL);

	int opcion;
	int flagAlta = 0;
	int flagRecaudacion = 0;
	int contIdContribuyente = 1000;
	int contIdRecaudaciones = 100;


	eContribuyente arrayContribuyentes[MAX];
	eRecaudacion arrayRecaudadores [CANT];
	eTipo arrayTipo[CANT_TIPO];

    eContribuyente_inicializar(arrayContribuyentes, MAX);
    eRecaudacion_inicializar(arrayRecaudadores, CANT);

    strcpy(arrayTipo[0].descripcion,"ARBA");
   	arrayTipo[0].idTipo = ARBA;

   	strcpy(arrayTipo[1].descripcion,"IIBB");
   	arrayTipo[1].idTipo = IIBB;

   	strcpy(arrayTipo[2].descripcion,"GANANCIAS");
   	arrayTipo[2].idTipo = GANANCIAS;


	do
	{
		utn_menu(&opcion, "\nMenu\n1. ALTA COTRIBUYENTE \n2. MODIFICAR CONTRIBUYENTE \n3. BAJA CONTRIBUYENTE \n4. ALTA RECAUDADACIONES \n5. REFINANCIAR RECAUDACION \n6. SALDAR RECAUDACION \n7. IMPRIMIR CONTRIBUYEBTES \n8. IMPRIMIR RECAUDACION \n10. SALIR \nINGRESE:", "\nNO ES VALIDO\n", 1, 10);

		switch (opcion)
		{

		case 1:
			if (eContribuyente_alta(arrayContribuyentes, MAX, &contIdContribuyente)==0)
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
			if(flagAlta == 1)
			{
				if(eContribuyente_modificar(arrayContribuyentes, MAX) ==0)
				{
					printf("\nSE MODIFICO EL CONTRIBUYENTE");
				}
				else
				{
					printf("\nNO SE MODIFICO EL CONTRIBUYENTE");
				}
			}
			system("pause");
			break;
		case 3:
			if(flagAlta == 1)
			{
			if(eContribuyente_baja(arrayContribuyentes, MAX) ==0)
			{
				printf("\nSE DIO LA BAJA DEL CONTRIBUYENTE");
			}
			else
			{
				printf("\nNO SE DIO LA BAJA");
			}
		}

			system("pause");
			break;
		case 4:
			if(flagAlta == 1)
			{
			if (eRecaudacion_alta(arrayRecaudadores, CANT, &contIdRecaudaciones,arrayContribuyentes,MAX)==0)
			{
				printf("\nALTA EXITOSA\n");
				eRecaudacion_mostrarTodos (arrayRecaudadores,CANT, arrayTipo, CANT_TIPO);
				flagRecaudacion = 1;
			}
			else
			{
				printf("\nERROR. SIN ESPACIO PARA ALMACENAR");
			}
			}
			system("pause");
			break;
		case 5:
			if(flagAlta == 1 && flagRecaudacion == 1)
			{
			if(eRecaudacion_cambiarEstado (arrayRecaudadores,CANT, arrayContribuyentes, MAX, arrayTipo, CANT_TIPO)==0)
			{
				printf("\nSE REFINANCIO.");
			}
			else
			{
				printf("\nNO SE REFINANCIO.");
			}
			}
			system("pause");
			 break;
		case 6:
			eRecaudacion_cambiarEstadoSaldar (arrayRecaudadores,CANT, arrayContribuyentes, MAX, arrayTipo, CANT_TIPO);
			break;
		case 7:
			informe_ContribuyentesRecaudaciones (arrayRecaudadores,CANT, arrayContribuyentes, MAX, arrayTipo, CANT_TIPO);
			break;
		case 8:

			break;
		case 9:

			break;
		}
	} while (opcion != 10);

	puts("\nFIN.");

	return 0;
}


