#include "utn.h"
#define MAX 2
#define CANT 3

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int opcion2;


	//CREO ARRAY DE ESTRUCTURA
	datosAlumnos alumno[MAX];
	eCarrera carrera[3];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	inicializarStruct(alumno, MAX);

	//BUCLE DE MENU
	do {
	    if( utn_menu (&opcion,"\n1. Alta.\n2. Listar. \n3. Baja. \n4. Modificar. \n5. Ordenar. \n6.Informar Estudiantes. \n7.Estudiante mas joven. \n8.Estudiante mas grande. \n9. Estudiantes para Cada Carrera. \n10.Salir","\nNo es una opción válida.", 1, 10,10) == 0)
		{
		//MENU SWITCH
		switch (opcion)
		{
		case 1:
			//ALTA
			if (utn_Alta(alumno, MAX))
			{
				printf("Se dio de alta al alumno\n");
			} else {
				printf("ERROR. SIN ESPACIO PARA ALMACENAR MAS ALUMNOS");
			}
			break;
		case 2:
			//LISTADO Gen
			utn_MostrarTodos(alumno, MAX);
			break;
		case 3:
			//BAJA
			fflush(stdin);
			if (utn_Baja(alumno, MAX)) {
				printf("\nBAJA DE ALUMNO EXITOSA");
				utn_MostrarTodos(alumno, MAX);
			} else {
				printf("\nBAJA DE ALUMNO CANCELADA");
			}
			break;
		case 4:
			//MODIFICACION
			if (utn_Modificacion(alumno, MAX)) {
				printf("\n * MODIFICACION DE ALUMNO EXITOSA\n");
				utn_MostrarTodos(alumno, MAX);
			} else {
				printf("\n * MODIFICACION DE ALUMNO CANCELADA");
			}
			break;
		case 5:
			do
			{
			if(utn_menu(&opcion2, "\n1.Odernar por apellido \n2.Ordenar por promedio. \n3.Ordenar por legajo \n4.Volver atras.", "\nNo es un numero valido.", 1, 4, 4)==0)
			{
				switch(opcion2)
				{
				case 1:
					utn_ordenarApellido (alumno, MAX);
					printf("\nSe ordeno por apellido.");
					break;
				case 2:
					utn_ordenarProm (alumno, MAX);
					printf("\nSe ordeno por promedio.");
					break;
				case 3:
					utn_ordenarLeg (alumno, MAX);
					printf("\nSe ordeno por legajo.");
					break;
				}
			}
			}while(opcion2 !=4);
			break;
		case 6:
			utn_carrera (alumno,MAX,carrera,CANT);
			break;
		}

		}
	} while (opcion != 10);



	return 0;
}
