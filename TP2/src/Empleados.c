#include "Empleados.h"


int idIncremento = 0;

void inicializarStruct (eEmployee empleados[], int tamanio)
{
	int i;
	for(i = 0; i < tamanio; i++)
	{
		empleados[i].id = 0;
		strcpy(empleados[i].name," ");
		strcpy(empleados[i].lastName," ");
		empleados[i].sector = 0;
		empleados[i].isEmpty = 1;

	}
}
int utn_getIdLibre (eEmployee empleados[], int tamanio)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (empleados!= NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (empleados[i].isEmpty == 1) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int utn_getId()
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return idIncremento += 1;
}

int utn_buscarPorID (eEmployee empleados[], int tamanio, int ID)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (empleados != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (empleados[i].id == ID && empleados[i].isEmpty == 0) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void utn_MostrarUno(eEmployee empleados)
{
	//PRINTF DE UN SOLO Gen
	printf("     %3d         %5s	      %10s        %.2f    %3d\n", empleados.id,empleados.name,empleados.lastName,empleados.salary,empleados.sector);

}

int utn_MostrarTodos(eEmployee empleados[], int tamanio)
{
	int i;
	int retorno = 0;
	int cantidad = 0;

	printf("***********************************************************************\n");
	printf("\n       ID        NOMBRE        APELLIDO        SUELDO      SECTOR\n");
	printf("***********************************************************************\n\n");
	//printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (empleados != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (empleados[i].isEmpty == 0) {
				//MUESTRO UN SOLO Gen
				utn_MostrarUno(empleados[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}
eEmployee utn_CargarDatos(void)
{
	eEmployee auxiliar;
	float auxFloat;
	int auxInt;
	printf("\n**********************\n");
	utn_getString(auxiliar.name,"Ingrese el nombre:\n","No es un nombre valido\n",3);
	printf("\n**********************\n");
	utn_getString(auxiliar.lastName,"Ingrese el apellido:\n","No es un apellido valido\n",3);
	printf("\n***********************\n");
	utn_getFloat(&auxFloat,"Ingrese el sueldo:\n","No es un sueldo valido.\n",1000,999999,3);
	auxiliar.salary=auxFloat;
	printf("\n**********************\n");
	utn_getNumber(&auxInt,"Ingrese el sector(del 1 al 8):\n","No es un sector valido",1,8,3);
	auxiliar.sector=auxInt;

	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eEmployee utn_ModificarUno(eEmployee empleados)
{
	eEmployee auxiliar;
	float auxFloat;
	int auxInt;
	if(empleados != NULL && empleados.isEmpty == 0)
	{
		printf("\n**********************\n");
		utn_getString(auxiliar.name,"Ingrese el nombre:\n","No es un nombre valido\n",3);
		printf("\n**********************\n");
		utn_getString(auxiliar.lastName,"Ingrese el apellido:\n","No es un apellido valido\n",3);
		printf("\n***********************\n");
		utn_getFloat(&auxFloat,"Ingrese el sueldo:\n","No es un sueldo valido.\n",1000,999999,3);
		auxiliar.salary=auxFloat;
		printf("\n**********************\n");
		utn_getNumber(&auxInt,"Ingrese el sector(del 1 al 8):\n","No es un sector valido",1,8,3);
		auxiliar.sector=auxInt;

	}
	auxiliar = empleados;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return empleados;
}

int utn_Alta(eEmployee empleados[], int tamanio)
{
	int retorno = 0;
	eEmployee auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = utn_getIdLibre(empleados, tamanio);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = utn_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.id = utn_getId();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxGen.isEmpty = 0;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		empleados[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}

	return retorno;
}
int utn_Modificacion(eEmployee empleados[], int tamanio)
{
	int retorno = 0;
	int id;
	int index;
	int flag = 0;
	eEmployee auxiliar;
	if(empleados != NULL && tamanio > 0 && empleados[tamanio].isEmpty == 0)
	{
	if (utn_MostrarTodos(empleados, tamanio)) {
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag == 1) {
		//PIDO ID A MODIFICAR
		printf("\nIngrese el ID del empleado a modificar:\n");
		fflush(stdin);
		scanf("%d",&id);

		 /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (utn_buscarPorID(empleados, tamanio, id) == -1) {
			printf("NO EXISTE ID.");
			id = 0; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = utn_buscarPorID(empleados, tamanio, id);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = utn_ModificarUno(empleados[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		empleados[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		retorno = 1;
	}
	}

	return retorno;
}
int utn_Baja(eEmployee empleados[], int tamanio)
{
	int retorno = 0;
	int id;
	int index;
	int flag = 0;
	//LISTO TODOS LOS Gen
	if (utn_MostrarTodos(empleados, tamanio)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag == 1) {
		//PIDO ID A DAR DE BAJA
		printf("\nIngrese el ID a dar de baja:\n");
		fflush(stdin);
		scanf("%d",&id);
		 /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (utn_buscarPorID(empleados, tamanio, id) == -1) {
			printf("NO EXISTE ID.");
			id = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = utn_buscarPorID(empleados, tamanio, id);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		empleados[index].isEmpty = 1;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		retorno = 1;
	}

	return retorno;
}
void utn_ordenarApellido (eEmployee empleados[], int tamanio)
{
	int i;
	int j;
	eEmployee aux;
	if(empleados != NULL && tamanio > 0)
	{
	for(i = 0; i < tamanio -1;i++)
		{
			for(j = i+1; j < tamanio; j++)
			{
				if(strcmp(empleados[i].lastName,empleados[j].lastName)>0)
				{
					aux = empleados[i];
					empleados[i] = empleados[j];
					empleados[j] = aux;
				}
				else if(empleados[i].lastName == empleados[j].lastName)
							{
								if(empleados[i].sector > empleados[j].sector)
									{
									aux = empleados[i];
									empleados[i]= empleados[j];
									empleados[j] = aux;
									}
							}
				}
			}
	}
}
void get_promedio (eEmployee empleados[], int tamanio)
{
	int count = 0;
	float promedio;
	if(empleados != NULL && tamanio >0 && empleados[tamanio].isEmpty == 0)
	{
		count++;
		promedio = empleados[tamanio].salary / (float)count;
		printf("El promedio de los sueldos es %.2f",promedio);
	}
}


