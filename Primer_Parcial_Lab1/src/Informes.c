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

			}
		}

	}
	return rtn;
}
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int flag = 0;
	int idRecaudacion;
	eEstado arrayEstado;

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
		informe_ContribuyentesIdRecaudaciones (arrayRecaudacion,tam, arrayContibuyente, cant, &idRecaudacion);
	}

	if(utn_getRespuesta ("\nDESE CAMBIAR EL ESTADO A REFINANCIAR [S] SI [N]: ","DESE CAMBIAR EL ESTADO A REFINANCIAR [S] SI [N]: ", 3)==0)
	{
		strcpy(arrayEstado.detalleEstado,"REFINANCIAR");
		rtn = 0;
	}
	return rtn;
}
int eRecaudacion_cambiarEstadoSaldar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int flag = 0;

	int idRecaudacion;
	eEstado arrayEstado;

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
			informe_ContribuyentesIdRecaudaciones (arrayRecaudacion,tam, arrayContibuyente, cant, &idRecaudacion);
		}
	if(utn_getRespuesta ("\nDESE CAMBIAR EL ESTADO A SALDAR [S] SI [N]: ","DESE CAMBIAR EL ESTADO A SALDAR [S] SI [N]: ", 3)==0)
	{
		strcpy(arrayEstado.detalleEstado,"SALDADO");
		rtn = 0;
	}
	return rtn;
}
int informe_ContribuyentesRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int i;
	int indexIdContribuyente;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if(arrayContribuyente[i].idContribuyente == arrayRecaudacion[i].idContribuyente)
			{
				indexIdContribuyente = arrayRecaudacion[i].idContribuyente;
				eContribuyente_mostrarTodos(arrayContribuyente, indexIdContribuyente);
				eRecaudacion_mostrarTodos (arrayRecaudacion,tam, arrayTipo, cantTipo);
			}
			rtn = 0;
			break;
		}


	}
	return rtn;
}


