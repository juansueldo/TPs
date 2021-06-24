/*
 ============================================================================
 Name        : ModeloExamen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Menu.h"

int main(void) {
	system("cls");
	setbuf(stdout,NULL);
	int option;
	LinkedList* listapeliculas = ll_newLinkedList();

	do{
	    	menu_principal (&option);
	        switch(option)
	        {
	            case 1:
	            	printf("CARGANDO DATOS...\n");
	            	printf("ESTO PUEDE DEMORAR UNOS MINUTOS...\n");
	                if(controller_loadFromText("archivo.csv",listapeliculas) == 0)
	                {
	                	printf("\nSE LEYERON LOS DATOS\n");
	                }
	                else
	                {
	                	printf("\nNO SE LEYERON LOS DATOS\n");
	                }
	                break;
	           case 2:
	        	   if(controller_ListMovies(listapeliculas)!=0)
	        	   {
	        		   printf("\nNO HAY EMPLEADOS PARA MOSTRAR");
	        	   }
	        	   break;
	           case 3:
	        	   controller_getMontos (listapeliculas);
	        }
	}while(option != 5);
	return EXIT_SUCCESS;
}
