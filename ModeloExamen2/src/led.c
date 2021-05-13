#include "led.h"



int ePantalla_ObtenerID()
{
	int pantalla_idIncremental = 0;
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return pantalla_idIncremental += 1;
}
void ePantalla_Inicializar(ePantalla arrayPantalla[], int TAM)
{
	int i;

	//SI EXISTE EL arrayPantallaPantalla Y EL LIMITE ES VALIDO
	if (arrayPantalla != NULL && TAM > 0) {
		//RECORRO TODO EL arrayPantallaPantalla
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			arrayPantalla[i].isEmpty = LIBRE;
		}
	}
}
int ePantalla_ObtenerNombre (eTipo arrayTipo[],int cant,int codigo,char detalle[MAX_CHARS_CADENAS])
{
	int ret;
	ret = -1;
	int i;
	if(arrayTipo != NULL && cant > 0 && (isdigit(codigo)) == 0  && detalle != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arrayTipo[i].codigo == codigo)
			{
				if(arrayTipo[i].codigo== 1)
				{
				strcpy(detalle,"LED");
				ret = 0;
				break;
				}
				if(arrayTipo[i].codigo== 2)
				{
					strcpy(detalle,"LCD");
				ret = 0;
				break;
				}

			}
		}
	}

	return ret;
}

int ePantalla_ObtenerIndexLibre(ePantalla arrayPantalla[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL arrayPantallaPantalla Y EL LIMITE ES VALIDO
	if (arrayPantalla != NULL && TAM > 0) {
		//RECORRO TODO EL arrayPantallaPantalla
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (arrayPantalla[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
int ePantalla_BuscarPorID(ePantalla arrayPantalla[], int TAM, int ID)
{
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayPantalla != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (arrayPantalla[i].idPantalla == ID && arrayPantalla[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
ePantalla ePantalla_CargarDatos(void)
{
	ePantalla auxiliar;


	if((utn_getString(auxiliar.nombre,MAX_CHARS_CADENAS,"INGRESE NOMBRE: ","ERROR. REINGRESE: ",3,3)) != 0)
	{
		printf("\n Error al ingresar el nombre");
	}
	if(utn_getNumero(&auxiliar.id_tipo,"INGRESE TIPO: LCD[1] - LED[2]: ", "ERROR. REINGRESE: ",LCD,LED,3) != 0)
	{
		printf("\n Error al ingresar el tipo");
	}
	if(utn_getFloat(&auxiliar.precio,"INGRESE EL PRECIO: ", "ERROR. REINGRESE: ",1000,999999,3) != 0)
	{
		printf("\n Error al ingresar el precio");
	}


	return auxiliar;
}
int ePantalla_Alta(ePantalla arrayPantalla[], int TAM)
{
	int rtn = 0;
	ePantalla auxPantalla;

	//BUSCO ESPACIO EN arrayPantalla
	int index = ePantalla_ObtenerIndexLibre(arrayPantalla, TAM);

	//SI INDEX == -1 arrayPantalla LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE arrayPantalla LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO arrayPantalla AUXILIAR
		auxPantalla = ePantalla_CargarDatos();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxPantalla.isEmpty = OCUPADO;

		//MOSTRAR EL DATO

		if (utn_getRespuesta("\nDESEA CONTINUAR SI[S] - NO[N]: ","ERROR. REINGRESE.",3)==0)
		{
			//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
			auxPantalla.idPantalla = ePantalla_ObtenerID();
			//SETEO EL arrayPantalla CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			arrayPantalla[index] = auxPantalla;
			//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
			rtn = 1;
		}
	}

	return rtn;
}
void ePantalla_MostrarUno (ePantalla arrayPantalla[],int tamanio,eTipo arrayTipo[],int cant)
{
	char detalle[20];
	ePantalla_ObtenerNombre(arrayTipo,MAX_CHARS_CADENAS,arrayPantalla[MAX].idTipo,detalle);
	utn_getMayusMin (arrayPantalla[tamanio].nombre, MAX_CHARS_CADENAS);
	//PRINTF DE UN SOLO arrayPantalla
	printf("%5d %15s %5d %5.2f\n", arrayPantalla.idPantalla, arrayPantalla.nombre, arrayPantalla.id_tipo,
			arrayPantalla.precio);
}

int ePantalla_MostrarTodos(ePantalla arrayPantalla[], int TAM)
{
	int i;
	int rtn = 0;

	//CABECERA
	printf("%5s %5s %15s %15s\n\n", "ID", "NOMBRE", "ID TIPO", ""); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayPantalla != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (arrayPantalla[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO arrayPantalla
				ePantalla_MostrarUno(arrayPantalla[i]);
				//CONTADOR DE arrayPantalla
				rtn++;
			}
		}
	}

	return rtn;
}
ePantalla ePantalla_ModificarUno(ePantalla arrayPantalla)
{
	ePantalla auxiliar = arrayPantalla;

	if((utn_getString(auxiliar.nombre,MAX_CHARS_CADENAS,"INGRESE NOMBRE: ","ERROR. REINGRESE: ",3,3)) != 0)
	{
		printf("\n Error al ingresar el nombre");
	}
	if(utn_getNumero(&auxiliar.id_tipo,"INGRESE TIPO: LCD[1] - LED[2]: ", "ERROR. REINGRESE: ",LCD,LED,3) != 0)
	{
		printf("\n Error al ingresar el tipo");
	}
	if(utn_getFloat(&auxiliar.precio,"INGRESE EL PRECIO: ", "ERROR. REINGRESE: ",1000,999999,3) != 0)
	{
		printf("\n Error al ingresar el precio");
	}
	return auxiliar;
}
int ePantalla_Modificacion(ePantalla arrayPantalla[], int TAM)
{
	int rtn = 0;
	int idPantalla;
	int index;
	int flag = 0;
	ePantalla auxiliar;

	//LISTO TODOS LOS Orquesta
	if (ePantalla_MostrarTodos(arrayPantalla, TAM)) {
		//BANDERA EN 1 SI HAY Orquesta DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Orquesta PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idPantalla = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (ePantalla_BuscarPorID(arrayPantalla, TAM, idPantalla) == -1) {
			puts("NO EXISTE ID.");
			idPantalla = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Orquesta A MODIFICAR
		index = ePantalla_BuscarPorID(arrayPantalla, TAM, idPantalla);

		//LLAMO A FUNCION QUE MODIFICA Orquesta
		auxiliar = ePantalla_ModificarUno(arrayPantalla[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		arrayPantalla[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}
int ePantalla_Baja (ePantalla arrayPantalla[], int TAM)
{
	int rtn = -1;
	int idPantalla;
	int index;
	int flag = 0;

	if (ePantalla_MostrarTodos(arrayPantalla, TAM))
	{
		flag = 1;
	}

	if (flag) {
		printf("\nINGRESE ID A DAR DE BAJA: ");
		scanf("%d",&idPantalla);

		while (ePantalla_BuscarPorID(arrayPantalla, TAM, idPantalla) == -1)
		{
			printf("NO EXISTE ID. Reingrese el id a dar de baja:");
			scanf("%d",&idPantalla);
		}
		index = ePantalla_BuscarPorID(arrayPantalla, TAM, idPantalla);
		if(utn_getRespuesta ("\nDESEA DAR BAJA SI[S] - NO[N]: ","\nERROR. DESEA CONTINUAR SI[S] - NO[N]: ", 3)==0)
		{
			arrayPantalla[index].isEmpty = 1;
			rtn = 0;
		}
		else
		{
			rtn = -1;
		}

	}

	return rtn;
}

