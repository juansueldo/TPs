#include "Informes.h"

int informe_ContribuyentesRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int i;
	if(arrayRecaudacion != NULL && arrayContibuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if(arrayContibuyente[i].idContribuyente == arrayRecaudacion[i].idContribuyente)
			{
			eContribuyente_mostrarTodos(arrayContibuyente, cant);
			eRecaudacion_mostrarTodos (arrayRecaudacion,tam, arrayTipo, cantTipo);
			}
			rtn = 0;
			break;
		}


	}
	return rtn;
}


