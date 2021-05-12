#include "Entidades.h"

int eMusicoOrquesta_Alta(
		eMusico arrayMusico[], int TAM_MUSICO,
		eOrquesta arrayOrquesta[], int TAM_ORQUESTA,
		eInstrumento arrayInstrumento[], int TAM_INSTRUMENTO) {

	int rtn = 0;
	eMusico auxMusico;
	int idOrquesta;

	int index = eMusico_ObtenerIndexLibre(arrayMusico, TAM_MUSICO);

	if (index != -1) {
		auxMusico = eMusico_CargarDatos();

		//ID DE ORQUESTA
		eOrquesta_MostrarTodos(arrayOrquesta, TAM_ORQUESTA);
		printf("\nINGRESE ID A DAR DE BAJA: ");
		scanf("%d",&idOrquesta);

		while (eOrquesta_BuscarPorID(arrayOrquesta, TAM_ORQUESTA, idOrquesta) == -1)
		{
			printf("NO EXISTE ID. Reingrese el id a dar de baja:");
			scanf("%d",&idOrquesta);
		}

		while (eOrquesta_BuscarPorID(arrayOrquesta, TAM_ORQUESTA, idOrquesta) == -1) {
			puts("ID NO EXISTE.");
			printf("\nINGRESE ID A DAR DE BAJA: ");
			scanf("%d",&idOrquesta);
		}
		auxMusico.idOrquesta = idOrquesta;

		//ID DE INSTRUMENTO
		auxMusico.idInstrumento = 999;

		//TENGO TODO CARGADO
		if(utn_getRespuesta ("\nDesea dar la baja el empleado? (si 's' o NO 'no'): ","\nError. Ingrese (SI 's' o NO 'n')", 3)==0)
		{
			auxMusico.idMusico = eMusico_ObtenerID();
			auxMusico.isEmpty = OCUPADO;
			arrayMusico[index] = auxMusico;
			rtn = 1;
		}

	}
	return rtn;
}
void eMusicoOrquestaInstrumento_MostrarUno(eMusico Musico, eOrquesta o, eInstrumento i){

}
void Nada(void){
	/*eMusico m;

	int indiceOrquesta = eOrquesta_BuscarPorID(arrayOrquesta, TAM_Orq, m.idOrquesta);
	int indiceInstrumento = eInstrumento_BuscarPorID(arrayInstrumento, TAM_Ins, m.idInstrumento);
	*/
}

