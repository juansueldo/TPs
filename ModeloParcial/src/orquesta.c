#include "Orquesta.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
int Orquesta_idIncremental = 0;

int eOrquesta_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Orquesta_idIncremental += 1;
}

void eOrquesta_Inicializar(eOrquesta array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eOrquesta_ObtenerIndexLibre(eOrquesta array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eOrquesta_BuscarPorID(eOrquesta array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idOrquesta == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eOrquesta_MostrarUno(eOrquesta Orquesta) {
	//PRINTF DE UN SOLO Orquesta
	printf("%5d %5d %15s %15s\n", Orquesta.idOrquesta, Orquesta.tipo,
			Orquesta.nombre, Orquesta.lugar);
}

int eOrquesta_MostrarTodos(eOrquesta array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\n\t> LISTADO Orquesta");
	printf("%5s %5s %15s %15s\n\n", "ID", "TIPO", "NOMBRE", "LUGAR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Orquesta
				eOrquesta_MostrarUno(array[i]);
				//CONTADOR DE Orquesta
				rtn++;
			}
		}
	}

	return rtn;
}

int eOrquesta_MostrarDadosDeBaja(eOrquesta array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\t> Orquesta\n");
	printf("%5s %5s %15s %15s\n\n", "ID", "TIPO", "NOMBRE", "LUGAR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Orquesta
				eOrquesta_MostrarUno(array[i]);
				//CONTADOR DE Orquesta
				rtn++;
			}
		}
	}

	return rtn;
}

eOrquesta eOrquesta_CargarDatos(void) {
	eOrquesta auxiliar;
	int opcion;

	if((utn_getString(auxiliar.nombre,MAX_CHARS_CADENAS,"INGRESE NOMBRE: ","ERROR. REINGRESE: ",3,3)) != 0)
	{
		printf("\n Error al ingresar el nombre");
	}

	if((utn_getString(auxiliar.lugar,MAX_CHARS_CADENAS,"INGRESE LUGAR: ","ERROR. REINGRESE: ",3,3)) != 0)
	{
		printf("\n Error al ingresar el nombre");
	}
	if(utn_getNumero(&auxiliar.fecha.dia,"INGRESE DIA: ", "ERROR. REINGRESE: ",1,31,3) != 0)
	{
		printf("\n Error al ingresar el ID");
	}
	if(utn_getNumero(&auxiliar.fecha.mes,"INGRESE MES: ", "ERROR. REINGRESE: ",1,12,3) != 0)
	{
		printf("\n Error al ingresar el ID");
	}
	if(utn_getNumero(&auxiliar.fecha.anio,"INGRESE MES: ", "ERROR. REINGRESE: ",1900,2022,3) != 0)
	{
		printf("\n Error al ingresar el ID");
	}

	printf("\nSELECCIONE TIPO\n\t1- SINFONICA\n\t2- FILARMONICA\n\t3-CAMARA\n");

	switch (utn_getNumero(&opcion,"OPCION: ", "ERROR. REINGRESE: ", 1, 3,3)) {

	case SINFONICA:
		auxiliar.tipo = SINFONICA;
		break;

	case FILARMONICA:
		auxiliar.tipo = FILARMONICA;
		break;

	case CAMARA:
		auxiliar.tipo = CAMARA;
		break;
	}

	return auxiliar;
}

eOrquesta eOrquesta_ModificarUno(eOrquesta Orquesta) {
	eOrquesta auxiliar = Orquesta;
	if((utn_getString(auxiliar.nombre,MAX_CHARS_CADENAS,"INGRESE NOMBRE: ","ERROR. REINGRESE: ",3,3)) != 0)
	{
		printf("\n Error al ingresar el nombre");
	}

	if((utn_getString(auxiliar.lugar,MAX_CHARS_CADENAS,"INGRESE LUGAR: ","ERROR. REINGRESE: ",3,3)) != 0)
	{
		printf("\n Error al ingresar el nombre");
	}
	if(utn_getNumero(&auxiliar.fecha.dia,"INGRESE DIA: ", "ERROR. REINGRESE: ",1,31,3) != 0)
	{
		printf("\n Error al ingresar el ID");
	}
	if(utn_getNumero(&auxiliar.fecha.mes,"INGRESE MES: ", "ERROR. REINGRESE: ",1,12,3) != 0)
	{
		printf("\n Error al ingresar el ID");
	}
	if(utn_getNumero(&auxiliar.fecha.anio,"INGRESE MES: ", "ERROR. REINGRESE: ",1900,2022,3) != 0)
	{
		printf("\n Error al ingresar el ID");
	}
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eOrquesta_Alta(eOrquesta array[], int TAM) {
	int rtn = 0;
	eOrquesta auxOrquesta;

	//BUSCO ESPACIO EN ARRAY
	int index = eOrquesta_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Orquesta AUXILIAR
		auxOrquesta = eOrquesta_CargarDatos();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxOrquesta.isEmpty = OCUPADO;

		//MOSTRAR EL DATO

		if (utn_getRespuesta("\nDESEA CONTINUAR SI[S] - NO[N]: ","ERROR. REINGRESE.",3)==0)
		{
			//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
			auxOrquesta.idOrquesta = eOrquesta_ObtenerID();
			//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			array[index] = auxOrquesta;
			//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
			rtn = 1;
		}
	}

	return rtn;
}
int eOrquesta_Baja (eOrquesta array[], int TAM)
{
	int rtn = -1;
	int idOrquesta;
	int index;
	int flag = 0;

	if (eOrquesta_MostrarTodos(array, TAM))
	{
		flag = 1;
	}

	if (flag) {
		printf("\n*****************************************************************\n");
		printf("\nINGRESE ID A DAR DE BAJA: ");
		scanf("%d",&idOrquesta);

		while (eOrquesta_BuscarPorID(array, TAM, idOrquesta) == -1)
		{
			printf("NO EXISTE ID. Reingrese el id a dar de baja:");
			scanf("%d",&idOrquesta);
		}
		index = eOrquesta_BuscarPorID(array, TAM, idOrquesta);
		if(utn_getRespuesta ("\nDesea dar la baja el empleado? (si 's' o NO 'no'): ","\nError. Ingrese (SI 's' o NO 'n')", 3)==0)
		{
			array[index].isEmpty = 1;
			rtn = 0;
		}
		else
		{
			rtn = -1;
		}

	}

	return rtn;
}
int eOrquesta_Modificacion(eOrquesta array[], int TAM) {
	int rtn = 0;
	int idOrquesta;
	int index;
	int flag = 0;
	eOrquesta auxiliar;

	//LISTO TODOS LOS Orquesta
	if (eOrquesta_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Orquesta DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Orquesta PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idOrquesta = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eOrquesta_BuscarPorID(array, TAM, idOrquesta) == -1) {
			puts("NO EXISTE ID.");
			idOrquesta = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Orquesta A MODIFICAR
		index = eOrquesta_BuscarPorID(array, TAM, idOrquesta);

		//LLAMO A FUNCION QUE MODIFICA Orquesta
		auxiliar = eOrquesta_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eOrquesta_Sort(eOrquesta array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eOrquesta aux;

	/** EJEMPLO DE SORT CON ID DE Orquesta */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idOrquesta > array[j].idOrquesta) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idOrquesta < array[j].idOrquesta) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}

