/*
 ============================================================================
 Name        : Prueba.c
 Author      : Juan Sueldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn_prueba.h"

int main ()
{
	system("cls");
	setbuf (stdout, NULL);
	int menu;
	int eleccion;
	int login;
	int flagLogueo = 0;
	int comprar;
	int flagCompras = 0;
	int ver;
	int vender;
	int menuVenta;
	int eleccionVenta;
	int venta;
	int acumVenta = 0;
	int facturar;

	do{
	menu = utn_menu (&eleccion, "\nIngrese: \n1.Loguearse\n2.Comprar\n3.Ver mis Compras\n4.Vender\n5.Salir\n", "\nError. Vuelva a ingresar", 1, 5, 5);
	if(menu == 0)
	{
	switch(eleccion)
		{
		case 1:
			login = utn_getLogueo ("\nSe ha logueado");
			if(login == 0)
			{
				flagLogueo ++;
			}
			break;
		case 2:
			comprar = utn_getComprar (flagLogueo, "\nUsted acaba de comprar", "\nDebe Loguearse primero para comprar");
			if(comprar == 0)
			{
				flagCompras ++;
			}
			break;
		case 3:
			ver = utn_getVerComprar (flagLogueo,flagCompras, "\nUsted realizo: ", "\nDebe loguearse primero para ver sus compras", "\nDebe comprar para ver las compras");
			if(ver == 0)
			{
				printf("%d compras",flagCompras);
			}
			break;
		case 4:
			vender = utn_getVender (flagLogueo,flagCompras, "\nEsta por vender","\nDebe loguearse primero para continuar", "\nDebe comprar para vender");
			if(vender == 0)
			{
			do
			{
				menuVenta  = utn_menu (&eleccionVenta, "\nIngrese: \n1.Vender\n2.Facturar\n3.Volver atras\n", "\nError. Vuelva a ingresar", 1, 3, 3);

				if(menuVenta == 0)
				{

					switch (eleccionVenta)
					{
					case 1:
						venta = utn_getVender (flagLogueo,flagCompras, "\nRealizo ","\nDebe loguearse primero para continuar", "\nDebe comprar para vender");
						if(venta == 0)
						{
							acumVenta ++;
							printf("%d ventas",acumVenta);
							flagCompras --;
						}
						break;
					case 2:
						facturar = utn_getFacturar (acumVenta,"\nAcaba de facturar el item: ", "\nDebe vender para facturar");
						if(facturar == 0)
						{
							printf("%d",acumVenta);
							acumVenta --;
						}
						break;
					case 3:
						printf("\nRegreso atras");
						break;
				}
				}
				}while(menuVenta < 3);
			}
			break;
		case 5:
			printf("\nAdios");
			break;
		}
	}
	}while(menu < 5);

	return EXIT_SUCCESS;
}

