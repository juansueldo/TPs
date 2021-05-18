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
	int flagEstado = 0;
	int contIdContribuyente = 1000;
	int contIdRecaudaciones = 100;


	eContribuyente arrayContribuyentes[MAX];
	eRecaudacion arrayRecaudadores [CANT];
	eTipo arrayTipo[CANT_TIPO];
	eEstado arrayEstado[2];

    eContribuyente_inicializar(arrayContribuyentes, MAX);
    eRecaudacion_inicializar(arrayRecaudadores, CANT);
    eTipo_inicializar (arrayTipo, CANT_TIPO);
    eEstado_inicializar(arrayEstado, 2);

    strcpy(arrayTipo[0].descripcion,"ARBA");
   	arrayTipo[0].idTipo = ARBA;

   	strcpy(arrayTipo[1].descripcion,"IIBB");
   	arrayTipo[1].idTipo = IIBB;

   	strcpy(arrayTipo[2].descripcion,"GANANCIAS");
   	arrayTipo[2].idTipo = GANANCIAS;

   	strcpy(arrayEstado[0].detalleEstado,"REFINANCIADO");
   	arrayEstado[0].idEstado = 1;

   	strcpy(arrayEstado[1].detalleEstado,"SALDADO");
   	arrayEstado[1].idEstado = 2;


	do
	{
		utn_menu(&opcion, "\nMenu\n1. ALTA COTRIBUYENTE \n2. MODIFICAR CONTRIBUYENTE \n3. BAJA CONTRIBUYENTE \n4. ALTA RECAUDADACIONES \n5. REFINANCIAR RECAUDACION \n6. SALDAR RECAUDACION \n7. IMPRIMIR CONTRIBUYEBTES \n8. IMPRIMIR RECAUDACION \n9. SALIR \nINGRESE: ", "\nNO ES VALIDO\n", 1, 9);

		switch (opcion)
		{

		case 1:
			if (eContribuyente_alta(arrayContribuyentes, MAX, &contIdContribuyente)==0)
			{
				printf("\nALTA EXITOSA.\n\n");
				flagAlta = 1;
			}
			else
			{
				printf("\nERROR. SIN ESPACIO PARA ALMACENAR.\n\n");
			}
			system("pause");
			break;
		case 2:
			if(flagAlta == 1)
			{
				if(eContribuyente_modificar(arrayContribuyentes, MAX) ==0)
				{
					printf("\nSE MODIFICO EL CONTRIBUYENTE.\n\n");
				}
				else
				{
					printf("\nNO SE MODIFICO EL CONTRIBUYENTE.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE PARA MODIFICARLO.\n\n");
			}
			system("pause");
			break;
		case 3:
			if(flagAlta == 1)
			{

				if(eInforme_baja(arrayContribuyentes, MAX, arrayRecaudadores, CANT) ==0)
				{
					printf("\nSE DIO LA BAJA DEL CONTRIBUYENTE.\n\n");
				}
				else
				{
					printf("\nNO SE DIO LA BAJA.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE PARA DARLO DE BAJA.\n\n");
			}
			system("pause");
			break;
		case 4:
			if(flagAlta == 1)
			{
				if (eRecaudacion_alta(arrayRecaudadores, CANT, &contIdRecaudaciones,arrayContribuyentes,MAX)==0)
				{
					printf("\nALTA EXITOSA.\n\n");
					eRecaudacion_mostrarTodos (arrayRecaudadores,CANT, arrayTipo, CANT_TIPO);
					flagRecaudacion = 1;
				}
				else
				{
					printf("\nERROR. SIN ESPACIO PARA ALMACENAR.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE PARA AGREGAR RECAUDACIONES.\n\n");
			}
			system("pause");
			break;
		case 5:
			if(flagAlta == 1 && flagRecaudacion == 1)
			{
				if(eRecaudacion_estadoRefinanciar (arrayRecaudadores,CANT, arrayContribuyentes, MAX, arrayTipo, CANT_TIPO)==0)
				{
					printf("\nSE REFINANCIO.\n\n");
					flagEstado = 1;
				}
				else
				{
					printf("\nNO SE REFINANCIO.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE Y RECAUDACION PARA CONTINUAR.\n\n");
			}
			system("pause");
			 break;
		case 6:
			if(flagAlta == 1 && flagRecaudacion == 1)
			{
				if(eRecaudacion_estadoSaldado (arrayRecaudadores,CANT, arrayContribuyentes, MAX, arrayTipo, CANT_TIPO)==0)
				{
					printf("\nSE SALDO.\n\n");
					flagEstado = 1;
				}
				else
				{
					printf("\nNO SE SALDO.\n\n");
				}
				}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE Y RECAUDACION PARA CONTINUAR.\n\n");
			}
			system("pause");
			break;
		case 7:
			if(flagAlta == 1 && flagRecaudacion == 1 && flagEstado == 1)
			{
				mostrarTodos (arrayRecaudadores,CANT, arrayContribuyentes, MAX, arrayTipo, CANT_TIPO,arrayEstado, 2);
			}
			else
			{
				printf("\nDEBEN INGRESAR TODOS LOS DATOS.\n\n");
			}
			break;
		case 8:
			if(flagAlta == 1 && flagRecaudacion == 1 && flagEstado == 1)
			{
				mostrarSaldados (arrayRecaudadores,CANT, arrayContribuyentes, MAX, arrayTipo, CANT_TIPO,arrayEstado, 2);
			}
			else
			{
				printf("\nDEBEN INGRESAR TODOS LOS DATOS.\n\n");
			}
			break;
		case 9:
				printf("\nFIN.");
			break;
		}
	} while (opcion != 9);


	return EXIT_SUCCESS;
}


