#include "Informes.h"

int eInforme_baja (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant)
{
	int rtn = -1;
	int idContribuyente;
	int index;
	int flag = 0;
	int i;
	if(eContribuyente_isEmpty(arrayContribuyentes, tamanio)==0)
	{
	if (eContribuyente_mostrarTodos(arrayContribuyentes, tamanio) == 0)
	{
		flag = 1;
	}

	if (flag) {
		printf("\n*****************************************************************\n");
		utn_getNumero(&idContribuyente,"\nINGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA: ","ERORR. NO ES UN ID VALIDO",1000,1999,3);
		while (eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente) == -1)
		{
			utn_getNumero(&idContribuyente,"\nNO EXISTE ID. INGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA:","ERORR. NO ES UN ID VALIDO",1000,1999,3);
		}
		index = eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente);
		if(utn_getRespuesta ("\nDESEA DAR DE BAJA EL CONTRIBUYENYE  [S] SI [N] NO:  ","\nERROR. DESEA DAR DE BAJA EL CONTRIBUYENYE  [S] SI [N] NO: ", 3)==0)
		{
			arrayContribuyentes[index].isEmpty = 1;
			for(i = 0; i < cant; i++)
			{
				if(idContribuyente == arrayRecaudacion[i].idContribuyente)
				{
					arrayRecaudacion[i].isEmpty = 1;
				}

			}
			rtn = 0;
		}
		}
		else
		{
			rtn = -1;
		}

	}

	return rtn;
}
void eRecaudacion_mostrarTipoEstado(eRecaudacion arrayRecaudacion[],int tam, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	char detalle[30];
	char detalleEstado[20];
	eRecaudacion_obtenerNombre (arrayTipo,cantTipo,arrayRecaudacion[tam].idTipo,detalle);
	eRecaudacion_obtenerNombreEstado (arrayEstado,cantEstado,arrayRecaudacion[tam].idEstado,detalleEstado);
	printf("\n**********************************************************************************\n");
	printf(" ID RECAUDACION        MES      IMPORTE      TIPO     ESTADO  ");
	printf("\n**********************************************************************************\n");
	printf("%d    %15d   %10.2f     %15s   %15s\n"
			,arrayRecaudacion[tam].idRecaudacion
			,arrayRecaudacion[tam].mes
			,arrayRecaudacion[tam].importe
			,detalle
			,detalleEstado);


}
int mostrarTodos(eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	int i;
	int j;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for(i = 0; i < cant; i++)
		{
			if(arrayContribuyente[i].isEmpty == 0)
			{
				printf("\n\n*************************************************************\n");
				printf(" ID    NOMBRE           APELLIDO               CUIL       ");
				printf("\n**************************************************************\n");
				eContribuyente_mostrarUno(arrayContribuyente,i);
			}
			for(j = 0; j < tam; j++)
			{
				if(arrayContribuyente[i].idContribuyente == arrayRecaudacion[j].idContribuyente && arrayRecaudacion[j].isEmpty ==0)
				{
					eRecaudacion_mostrarTipoEstado(arrayRecaudacion,j,arrayTipo,cantTipo,arrayEstado,cantEstado);
					rtn =0;
				}

				}
			}
		}
		return rtn;
}
int eRecaudacion_mostrarSaldados (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	int i;
	int j;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].isEmpty == 0 && arrayRecaudacion[i].idEstado == 2)
			{
				eRecaudacion_mostrarTipoEstado(arrayRecaudacion,i,arrayTipo,cantTipo,arrayEstado,cantEstado);

			for(j = 0; j < tam; j++)
			{
				if(arrayRecaudacion[i].idContribuyente == arrayContribuyente[j].idContribuyente && arrayContribuyente[j].isEmpty ==0)
				{
					printf("\n*************************************************************\n");
					printf("  ID    NOMBRE           APELLIDO               CUIL       ");
					printf("\n**************************************************************\n");
					eContribuyente_mostrarUno(arrayContribuyente,j);
					printf("\n\n");
					rtn = 0;
				}
				}
			}
		}

	}
	return rtn;
}

int baja_ContribuyenteRecaudaciones (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant)
{
	int rtn = -1;
	int id;
	int index;
	int i;
	for(i = 0; i < tamanio; i++)
	{
		if(arrayContribuyentes[i].isEmpty == 0)
		{
			if(eContribuyente_bajaContribuyente (arrayContribuyentes, i, &id, &index)==0)
			{
				for(int j = 0; j < cant; j++)
				{
					if(arrayRecaudacion[j].isEmpty == 0)
					{
					eRecaudacion_baja (arrayRecaudacion, j, &id, &index);

					}
				}

			}
			rtn = 0;
		}
	}

	return rtn;
}
void menu (eContribuyente arrayContribuyentes[], int tam,eRecaudacion arrayRecaudadores[], int cant, eTipo arrayTipo [],int cantTipo,eEstado arrayEstado[], int cantEstado )
{
	int opcion;
	int flagAlta = 0;
	int flagRecaudacion = 0;
	int flagEstado = 0;
	int contIdContribuyente = 1000;
	int contIdRecaudaciones = 100;




	do
	{
		utn_menu(&opcion, "\nMenu\n1. ALTA COTRIBUYENTE \n2. MODIFICAR CONTRIBUYENTE \n3. BAJA CONTRIBUYENTE \n4. ALTA RECAUDADACIONES \n5. REFINANCIAR RECAUDACION \n6. SALDAR RECAUDACION \n7. IMPRIMIR CONTRIBUYEBTES \n8. IMPRIMIR RECAUDACION \n9. SALIR \nINGRESE: ", "\nNO ES VALIDO\n", 1, 9);

		switch (opcion)
		{

		case 1:
			if (eContribuyente_alta(arrayContribuyentes, tam, &contIdContribuyente)==0)
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
				if(eContribuyente_modificar(arrayContribuyentes, tam) ==0)
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

				if(eInforme_baja(arrayContribuyentes, tam, arrayRecaudadores, cant) ==0)
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
				if (eRecaudacion_alta(arrayRecaudadores, cant, &contIdRecaudaciones,arrayContribuyentes,tam)==0)
				{
					printf("\nALTA EXITOSA.\n\n");
					eRecaudacion_mostrarTodos (arrayRecaudadores,cant, arrayTipo, cantTipo);
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
				if(eRecaudacion_estadoRefinanciar (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo)==0)
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
				if(eRecaudacion_estadoSaldado (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo)==0)
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
				if(mostrarTodos (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado) > 0)
				{
					printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
				}
				else
				{
					printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
				}
			}
			else
			{
				printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
			}
			break;
		case 8:
			if(flagAlta == 1 && flagRecaudacion == 1 && flagEstado == 1)
			{
				if(eRecaudacion_mostrarSaldados (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado) > 0)
				{
					printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
				}
				else
				{
					printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
				}
			}
			else
			{
				printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
			}
			break;
		case 9:
				printf("\nFIN.");
			break;
		}
	} while (opcion != 9);
}


