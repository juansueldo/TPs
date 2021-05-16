#include "Informes.h"

int informe_ContribuyentesIdRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, int* auxId)
{
	int rtn = -1;
	int i;
	int indexIdContribuyente;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && tam > 0 && cant > 0 && auxId != NULL)
	{
		for(i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].idRecaudacion == *auxId)
			{
				indexIdContribuyente = eContribuyente_buscarId (arrayContribuyente,cant,arrayRecaudacion[i].idContribuyente);
				printf("\n*************************************************************\n");
				printf("\n ID    NOMBRE           APELLIDO               CUIL       ");
				printf("\n**************************************************************\n");
				eContribuyente_mostrarUno (arrayContribuyente,indexIdContribuyente);
				rtn = 0;
			}
		}

	}
	return rtn;
}
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo, int* indexId)
{
	int rtn = -1;
	int flag = 0;
	int idRecaudacion;

	if (eRecaudacion_mostrarTodos (arrayRecaudacion,tam, arrayTipo, cantTipo) == 0)
	{
		flag = 1;
	}

	if (flag)
	{
		printf("\n*****************************************************************\n");
		printf("INGRESE EL ID DE LA RECAUDACION: ");
		scanf("%d",&idRecaudacion);

		while (eRecaudacion_buscarId(arrayRecaudacion, tam, idRecaudacion) == -1)
		{
			printf("NO EXISTE ID. REINGRESE EL ID DE LA RECAUDACION:");
			scanf("%d",&idRecaudacion);
		}
	}
	if(eRecaudacion_buscarId(arrayRecaudacion, tam, idRecaudacion) != -1)
	{
		*indexId = eRecaudacion_buscarId(arrayRecaudacion, tam, idRecaudacion);
		informe_ContribuyentesIdRecaudaciones (arrayRecaudacion,tam, arrayContibuyente, cant, &idRecaudacion);
		rtn = 0;
	}
	return rtn;
}
int eRecaudacion_estadoRefinanciar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int index;
	if(eRecaudacion_cambiarEstado (arrayRecaudacion,tam,arrayContibuyente,cant,arrayTipo, cantTipo,&index)==0)
	{
		if(utn_getRespuesta ("\nDESEA CAMBIAR EL ESTADO A REFINANCIAR [S] SI [N]: ","DESEA CAMBIAR EL ESTADO A REFINANCIAR [S] SI [N]: ", 3)==0)
		{
			arrayRecaudacion[index].idEstado = 1;
			rtn = 0;
		}
	}
	return rtn;
}
int eRecaudacion_estadoSaldado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int index;
	if(eRecaudacion_cambiarEstado (arrayRecaudacion,tam,arrayContibuyente,cant,arrayTipo, cantTipo,&index)==0)
	{
		if(utn_getRespuesta ("\nDESEA CAMBIAR EL ESTADO A SALDAR [S] SI [N]: ","DESEA CAMBIAR EL ESTADO A SALDAR [S] SI [N]: ", 3)==0)
		{
			arrayRecaudacion[index].idEstado = 2;
			rtn = 0;
		}
	}
	return rtn;
}
int eRecaudacion_obtenerNombreEstado (eEstado arrayEstado[],int cant,int estado,char detalle[20])
{
	int rtn = -1;
	int i;
	if(arrayEstado != NULL && cant > 0 && (isdigit(estado)) == 0  && detalle != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arrayEstado[i].idEstado == estado)
			{
				if(arrayEstado[i].idEstado== 1)
				{
				strcpy(detalle,"REFINANCIADO");
				rtn = 0;
				break;
				}
				if(arrayEstado[i].idEstado== 2)
				{
					strcpy(detalle,"SALDADO");
					rtn = 0;
				break;
				}

			}
		}
	}

	return rtn;
}
int informe_ContribuyentesRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	int i;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if(arrayContribuyente[i].idContribuyente == arrayRecaudacion[i].idContribuyente)
			{
				char detalle[30];
				char detalleEstado[20];
				eRecaudacion_obtenerNombre (arrayTipo,cant,arrayRecaudacion[i].idTipo,detalle);
				eRecaudacion_obtenerNombreEstado (arrayEstado,cantEstado,arrayRecaudacion[i].idEstado,detalleEstado);
				printf("\n*************************************************************\n");
				printf("\n ID    NOMBRE           APELLIDO               CUIL       ");
				printf("\n**************************************************************\n");
				printf("\n%5d %15s     %15s         %15s    \n"
						,arrayContribuyente[i].idContribuyente
						,arrayContribuyente[i].nombre
						,arrayContribuyente[i].apellido
						,arrayContribuyente[i].cuil);
				printf("\n**********************************************************************************\n");
				printf("\n ID RECAUDACION        MES      IMPORTE      TIPO     ESTADO  ");
				printf("\n**********************************************************************************\n");
				printf("%d    %15d   %10.2f     %15s   %15s\n"
							,arrayRecaudacion[i].idRecaudacion
							,arrayRecaudacion[i].mes
							,arrayRecaudacion[i].importe
							,detalle
							,detalleEstado);
			}
			rtn = 0;
		}


	}
	return rtn;
}
int mostrarTodos (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int i;
	int rtn = -1;
	if(arrayContribuyente != NULL && tam > 0)
	{

		for (i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].isEmpty == 0 && arrayContribuyente[i].isEmpty==0)
			{
				informe_ContribuyentesRecaudaciones (arrayRecaudacion,i,arrayContribuyente,i, arrayTipo,i, arrayEstado, i);
			}
		}
		rtn = 0;
	}
	return rtn;
}
