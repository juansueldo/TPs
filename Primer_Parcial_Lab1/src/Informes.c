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
int eInforme_baja (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant)
{
	int rtn = -1;
	int idContribuyente;
	int index;
	int indexRecaudacion;
	int flag = 0;

	if (eContribuyente_mostrarTodos(arrayContribuyentes, tamanio) == 0)
	{
		flag = 1;
	}

	if (flag) {
		printf("\n*****************************************************************\n");
		printf("\nINGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA: ");
		scanf("%d",&idContribuyente);

		while (eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente) == -1)
		{
			printf("NO EXISTE ID. INGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA:");
			scanf("%d",&idContribuyente);
		}
		index = eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente);
		indexRecaudacion = eRecaudacion_buscarIdContribuyente (arrayRecaudacion,cant,idContribuyente);
		if(utn_getRespuesta ("\nDESEA DAR DE BAJA EL CONTRIBUYENYE  [S] SI [N] NO:  ","\nERROR. DESEA DAR DE BAJA EL CONTRIBUYENYE  [S] SI [N] NO: ", 3)==0)
		{
			arrayContribuyentes[index].isEmpty = 1;
			if(index == indexRecaudacion)
			{
				arrayRecaudacion[indexRecaudacion].isEmpty = 1;
			}
			rtn = 0;
		}
		else
		{
			rtn = -1;
		}

	}

	return rtn;
}
int informe_motrarTodos (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
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

				printf("\n*************************************************************\n");
				printf("\n ID    NOMBRE           APELLIDO               CUIL       ");
				printf("\n**************************************************************\n");
				printf("\n%5d %15s     %15s         %15s    \n"
						,arrayContribuyente[i].idContribuyente
						,arrayContribuyente[i].nombre
						,arrayContribuyente[i].apellido
						,arrayContribuyente[i].cuil);

				for(j = 0; j < tam; j++)
				{
					if(arrayContribuyente[i].idContribuyente == arrayRecaudacion[j].idContribuyente && arrayRecaudacion[j].isEmpty ==0)
					{
						char detalle[30];
						char detalleEstado[20];
						eRecaudacion_obtenerNombre (arrayTipo,cant,arrayRecaudacion[j].idTipo,detalle);
						eRecaudacion_obtenerNombreEstado (arrayEstado,cantEstado,arrayRecaudacion[j].idEstado,detalleEstado);
						printf("\n**********************************************************************************\n");
						printf("\n ID RECAUDACION        MES      IMPORTE      TIPO     ESTADO  ");
						printf("\n**********************************************************************************\n");
						printf("%d    %15d   %10.2f     %15s   %15s\n"
							,arrayRecaudacion[j].idRecaudacion
							,arrayRecaudacion[j].mes
							,arrayRecaudacion[j].importe
							,detalle
							,detalleEstado);
				}
				}
				rtn = 0;
			}
		}


	}
	return rtn;
}
int mostrarSaldados (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int i;
	int rtn = -1;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{

		for(i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].idEstado == 2)
			{
				informe_motrarTodos(arrayRecaudacion,tam, arrayContribuyente,cant, arrayTipo, cantTipo, arrayEstado, cantEstado);
				rtn = 0;
				}
			}

	}
	return rtn;
}
