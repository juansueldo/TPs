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

int main() {
	system("cls");
	setbuf (stdout, NULL);

	int menu;
	int flagLogin = 0;
	int acumCompras = 0;
	int contCompras = 0;
	int menu2;
	int venta = 0;

	do{
		printf("\nIngrese: \n1.Loguearse\n2.Comprar\n3.Ver mis Compras\n4.Vender\n5.Salir\n");
		scanf("%d",&menu);

		switch (menu)
		{
			case 1:
				printf("\nSe ha logueado");
				flagLogin = 1;
				if(flagLogin == 1)
				{
					printf("\nYa se ha logueado");
				}
				break;
			case 2:
				if(flagLogin == 0)
				{
					printf("\nPrimero debe loguearse");
				}
				else
				{
					printf("\nUsted acaba de comprar");
					acumCompras ++;
					contCompras += acumCompras;
				}
				break;
			case 3:
				if(flagLogin == 0)
				{
					printf("\nPrimero debe loguearse");
				}
				else
				{
					if(acumCompras == 0)
					{
						printf("Debe comprar para ver sus compras");
					}
					else
					{
						printf("Usted realizo %d compras",acumCompras);
					}
				}
				break;
			case 4:
				if(flagLogin == 0)
				{
					printf("\nPrimero debe loguearse");
				}
				else
				{
					if(acumCompras == 0)
					{
						printf("Debe comprar para poder vender");
					}
					else
					{
						do{
							printf("\n1.Vender \n2.Hacer factura \n3.Volver atrás\n");
							scanf("%d",&menu2);

							switch (menu2)
							{
							case 1:
								venta ++;
								contCompras -= venta;
								break;
							case 2:
								if(venta == 0)
								{
									printf("\nDebe vender para facturar");
								}
								else
								{
									printf("\nSe facturo");
								}
								break;
							default:
								printf("\nError. Vuelva a ingresar");
							}
						}while (menu2 !=3);
					}
					}
				   break;
		default:
		printf("\nError. Vuelva a ingresar");
		}

		}while(menu != 5);

	return EXIT_SUCCESS;
}
