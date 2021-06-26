/*
 ============================================================================
 Name        : Laboratorio1_SegundoParcial.c
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
	char auxDoc[MAX_NOMBRE];
	LinkedList* listaLibros = ll_newLinkedList();

	do{
	    	menu_principal (&option);
	        switch(option)
	        {
	            case 1:
	            	printf("\nINGRESE EL NOMBRE DEL ARCHIVO A LEER (Datos.csv): ");
	            	scanf("%s",auxDoc);
	            	fflush(stdin);

	            	printf("CARGANDO DATOS...\n");
	            	printf("ESTO PUEDE DEMORAR UNOS MINUTOS...\n");
	                if(controller_loadFromText(auxDoc,listaLibros) == 0)
	                {
	                	printf("\nSE LEYERON LOS DATOS\n");
	                }
	                else
	                {
	                	printf("\nNO SE LEYERON LOS DATOS\n");
	                }
	                break;
	           case 2:

	        	   if(controller_sort(listaLibros)!=0)
	        	   {
	        		   printf("\nNO HAY AUTORES PARA ORDENAR");
	        	   }
	        	   else
	        	   {
	        		   printf("\nSE ORDENO POR AUTOR");
	        	   }
	        	   break;
	           case 3:
	        	   if(controller_ListBooks(listaLibros)!=0)
	        	   {
	        		   printf("\nNO HAY LIBROS PARA MOSTRAR");
	        	   }
	        	   break;
	          case 4:
	        	  if(ll_map(listaLibros, calcularMonto)==0)
	        	  {
	        		  printf("\nSE APLICARON LOS DESCUENTOS CORRESPONDIENTES");
	        		  if(controller_saveAsText("mapeado.csv",listaLibros)==0)
	        		  {
	        			  printf("\nSE GUARDARON LOS DATOS EN [mapeado.csv] ");
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
	           case 5:
	        	   printf("\nFIN DEL PROGRAMA.");
	        	   break;
	        }
	}while(option != 5);
	return EXIT_SUCCESS;
}
