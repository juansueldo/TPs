/*
 ============================================================================
 Name        : Clase4Menu.c
 Author      : 
A- Hacer el menú de un programa con las siguientes opciones:
1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó
C- Al menú anterior chequear que no pueda ver sus compras,
si no ingresó primero a comprar al menos una vez
D- Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que contenga:
1. Vender 2. Hacer factura 3. Volver atrás
E- A lo anterior sumarle que haya compras para poder vender.
(Si compré una vez y vendí una vez no puedo ingresar a vender).
F- Pasar las acciones de menú a funciones y llevarlas a una biblioteca
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_menu.h"

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
	menu = utn_menu (&eleccion, "\nMenu: \n1.Login\n2.Comprar\n3.Ver mis Compras\n4.Vender\n5.Salir\n", "\nError. Vuelva a ingresar", 1, 5, 5);
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
			vender = utn_getVender (flagLogueo,flagCompras, "\nMenu venta","\nDebe loguearse primero para continuar", "\nDebe comprar para vender");
			if(vender == 0)
			{
			do
			{
				menuVenta  = utn_menu (&eleccionVenta, "\n1.Vender\n2.Facturar\n3.Volver atras\n", "\nError. Vuelva a ingresar", 1, 3, 3);

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
				}
				}
				}while(eleccionVenta != 3);
			}
			break;
		case 5:
			printf("\nLogout");
			break;
		}
	}
	}while(eleccion != 5);

	return EXIT_SUCCESS;
}
