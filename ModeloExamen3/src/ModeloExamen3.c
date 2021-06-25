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
	LinkedList* salasJuegos = ll_newLinkedList();

	do{
	    	menu_principal (&option);
	        switch(option)
	        {
	            case 1:
	            	printf("CARGANDO DATOS...\n");
	            	printf("ESTO PUEDE DEMORAR UNOS MINUTOS...\n");
	                if(controller_loadFromText("salajuegos.csv",salasJuegos) == 0)
	                {
	                	printf("\nSE LEYERON LOS DATOS\n");
	                }
	                else
	                {
	                	printf("\nNO SE LEYERON LOS DATOS\n");
	                }
	                break;
	          case 2:
	        	   if(controller_ListMovies(salasJuegos)!=0)
	        	   {
	        		   printf("\nNO HAY EMPLEADOS PARA MOSTRAR");
	        	   }
	        	   break;/*
	           case 3:
	        	   if(ll_map(listapeliculas, calcularMonto)==0)
	        	   {
	        		   printf("\nSE OBTUVIERON LOS MONTOS");
	        		   if(controller_saveAsText("archivos2.csv",listapeliculas)==0)
	        		   {
	        			   printf("\nSE GUARDARON LOS DATOS");
	        		   }
	        		   else
	        		   {
	        			   printf("\nNO SE GUARDARON LOS DATOS");
	        		   }
	        	   }
	        	   else
	        	   {
	        		   printf("\nNO SE OBTUVIERON LOS MONTOS");
	        	   }
	        	   break;
	           case 4:
	        	   	   controller_ListBySala(listapeliculas);
	        	   break;*/
	           case 5:
	        	   printf("\nFIN DEL PROGRAMA.");
	        	   break;
	        }
	}while(option != 5);
	return EXIT_SUCCESS;
}
