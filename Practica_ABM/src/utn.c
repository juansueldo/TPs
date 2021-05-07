#include "utn.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
eCarrera carrera[3]={
		{1, "Disenio", OCUPADO},
		{2, "Programador", OCUPADO},
		{3, "Ingeniero", OCUPADO},
	};

int idIncremento = 999;

void inicializarStruct (datosAlumnos alumno[], int tamanio)
{
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (alumno != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//SET ESTADO DE "LIBRE"
		    alumno[i].edad = LIBRE;
		    alumno[i].promedio = LIBRE;
		    alumno[i].nota1 = LIBRE;
		    alumno[i].nota2 = LIBRE;
		    alumno[i].sexo = ' ';
		    strcpy(alumno[i].apellido," ");
			alumno[i].isEmpty = LIBRE;
		}
	}
}

int utn_getId()
{
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return idIncremento += 1;
}

int utn_getIdLibre(datosAlumnos alumno[], int tamanio)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (alumno != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (alumno[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int utn_buscarPorID(datosAlumnos alumno[], int tamanio, int ID)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (alumno != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (alumno[i].legajo == ID && alumno[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

void utn_MostrarUno(datosAlumnos alumno)
{
	//PRINTF DE UN SOLO Gen
	printf("%-5d  %-10d   %-5c  %-5d   %-5d   %-5d    %-5.2f      %-15s\n", alumno.idCarrera,alumno.legajo, alumno.sexo, alumno.edad, alumno.nota1, alumno.nota2,alumno.promedio,alumno.apellido);

}

int utn_MostrarTodos(datosAlumnos alumno[], int tamanio)
{
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\nId Carrera  Legajo  Sexo   Edad    Nota 1  Nota 2   Promedio   Apellido");
	//printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (alumno != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (alumno[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				utn_MostrarUno(alumno[i]);
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

int utn_MostrarDadosDeBaja(datosAlumnos alumno[], int tamanio)
{
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Gen\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (alumno != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (alumno[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Gen
				utn_MostrarUno(alumno[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		retorno = 1;
	}

	return retorno;
}

datosAlumnos utn_CargarDatos(void)
{
	datosAlumnos auxiliar;
	printf("Ingrese el id de la carrera:\n");
	fflush(stdin);
	scanf("%d",&auxiliar.idCarrera);
	printf("Ingrese el sexo:\n");
	fflush(stdin);
	scanf("%c",&auxiliar.sexo);
	printf("Ingrese la edad:\n");
	fflush(stdin);
	scanf("%d",&auxiliar.edad);
	printf("Ingrese la nota 1:\n");
	fflush(stdin);
	scanf("%d",&auxiliar.nota1);
	printf("Ingrese la nota 2:\n");
	fflush(stdin);
	scanf("%d",&auxiliar.nota2);
	auxiliar.promedio = ((float)auxiliar.nota1 +auxiliar.nota2)/2;
	printf("Ingrese el apellido:\n");
	fflush(stdin);
	scanf("%s", auxiliar.apellido);

	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

datosAlumnos utn_ModificarUno(datosAlumnos alumno)
{
	datosAlumnos auxiliar;
	if(alumno.isEmpty == 1)
	{
		printf("Ingrese el sexo:\n");
		fflush(stdin);
		scanf("%c",&auxiliar.sexo);
		printf("Ingrese la edad:\n");
		fflush(stdin);
		scanf("%d",&auxiliar.edad);

	}
	auxiliar = alumno;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return alumno;
}

int utn_Alta(datosAlumnos alumno[], int tamanio)
{
	int retorno = 0;
	datosAlumnos auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = utn_getIdLibre(alumno, tamanio);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = utn_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.legajo = utn_getId();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxGen.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		alumno[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}

	return retorno;
}

int utn_Baja(datosAlumnos alumno[], int tamanio)
{
	int retorno = 0;
	int id;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (utn_MostrarTodos(alumno, tamanio)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag == 1) {
		//PIDO ID A DAR DE BAJA
		printf("\nIngrese el legajo a dar de baja:\n");
		fflush(stdin);
		scanf("%d",&id);
		 /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (utn_buscarPorID(alumno, tamanio, id) == -1) {
			printf("NO EXISTE ID.");
			id = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = utn_buscarPorID(alumno, tamanio, id);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		alumno[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		retorno = 1;
	}

	return retorno;
}

int utn_Modificacion(datosAlumnos alumno[], int tamanio)
{
	int retorno = 0;
	int id;
	int index;
	int flag = 0;
	datosAlumnos auxiliar;

	//LISTO TODOS LOS Gen
	if (utn_MostrarTodos(alumno, tamanio)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag == 1) {
		//PIDO ID A MODIFICAR
		printf("\nIngrese el legajo a dar a modificar:\n");
		fflush(stdin);
		scanf("%d",&id);
		 /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (utn_buscarPorID(alumno, tamanio, id) == -1) {
			puts("NO EXISTE ID.");
			id = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = utn_buscarPorID(alumno, tamanio, id);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = utn_ModificarUno(alumno[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		alumno[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		retorno = 1;
	}

	return retorno;
}

void utn_ordenarLeg (datosAlumnos alumno[], int tamanio)
{
	int i;
	int j;
	datosAlumnos aux;
	for(i = 0; i < tamanio -1;i++)
	{
		for(j = i+1; j < tamanio; j++)
		{
			if(alumno[i].legajo > alumno[j].legajo)
			{
				aux = alumno[i];
				alumno[i] = alumno[j];
				alumno[j] = aux;

			}
		}
	}
}
void utn_ordenarApellido (datosAlumnos alumno[], int tamanio)
{
	int i;
	int j;
	datosAlumnos aux;
	for(i = 0; i < tamanio -1;i++)
		{
			for(j = i+1; j < tamanio; j++)
			{
				if(strcmp(alumno[i].apellido,alumno[j].apellido)>0)
				{
					aux = alumno[i];
					alumno[i] = alumno[j];
					alumno[j] = aux;
				}
				}
			}
}
void utn_ordenarProm (datosAlumnos alumno[], int tamanio)
{
	int i;
	int j;
	datosAlumnos aux;
	for(i = 0; i < tamanio -1;i++)
	{
		for(j = i+1; j < tamanio; j++)
		{
			if(alumno[i].promedio > alumno[j].promedio)
			{
				aux = alumno[i];
				alumno[i]= alumno[j];
				alumno[j] = aux;


			}
			else if(alumno[i].promedio == alumno[j].promedio)
			{
				if(alumno[i].legajo > alumno[j].legajo)
					{
					aux = alumno[i];
					alumno[i]= alumno[j];
					alumno[j] = aux;
					}
			}
		}
	}
}
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max,int salir)
{

	int retorno = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max && salir != 0) {
		printf("%s", mensaje);
		scanf("%d", &bufferMenu);

		if (bufferMenu >= min && bufferMenu <= max) {
			*opcion = bufferMenu;
			retorno = 0;
		} else {
			printf("%s", mensajeError);
		}
	}
	return retorno;
}
void utn_carrera (datosAlumnos alumno[], int tamanio, eCarrera carrera[], int cantidad)
{
	int codigo;
	if(alumno != NULL && carrera != NULL)
	{
	eCarrera auxiliar[cantidad];
	printf("\nIngrese la descripcion de la carrera 'Disenio', 'Programador' o 'Ingeniero':\n");
	fflush(stdin);
	gets(auxiliar[cantidad].descripcionCarrera);

	strcpy(carrera[tamanio].descripcionCarrera, auxiliar[cantidad].descripcionCarrera);
	if(utn_getDescripcionCarrera (carrera, tamanio,carrera[tamanio].descripcionCarrera,&codigo)==0)
	{
		printf("\nEl id es: %d",codigo);
		utn_MostrarIdCarrera(alumno, tamanio,&codigo);

	}
	}


}
int utn_getDescripcionCarrera (eCarrera carrera[], int tamanio,char descripcion[30], int*id)
{
	int retorno = -1;
	eCarrera auxiliar[tamanio];
	if(strcmp(descripcion,"Disenio")==0)
	{
		auxiliar[tamanio].idCarrera = 1;
		*id = auxiliar[tamanio].idCarrera;
		retorno = 0;
	}
	if(strcmp(descripcion,"Programador")==0)
	{
		auxiliar[tamanio].idCarrera = 2;
		*id = auxiliar[tamanio].idCarrera;
		retorno = 0;
	}
	if(strcmp(descripcion,"Ingeniero")==0)
	{
		auxiliar[tamanio].idCarrera = 1;
		*id = auxiliar[tamanio].idCarrera;
		retorno = 0;
	}
	return retorno;
}
int utn_buscarPorIdCarrera(datosAlumnos alumno[], int tamanio, int ID)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (alumno != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tamanio; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (alumno[i].idCarrera == ID && alumno[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int utn_MostrarIdCarrera(datosAlumnos alumno[], int tamanio,int*ID)
{
	int i;
	int retorno = 0;
	int cantidad = 0;
	int aux=0;
	//CABECERA
	if(alumno != NULL && ID != NULL && tamanio >0)
	{
	printf("\nId Carrera  Legajo  Sexo   Edad    Nota 1  Nota 2   Promedio   Apellido");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (alumno != NULL && tamanio > 0) {
		//RECORRO TODO EL ARRAY
		if(utn_buscarPorIdCarrera(alumno,tamanio,aux)==0)
		{
		for (i = 0; i < tamanio; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (alumno[i].isEmpty == OCUPADO)
			{
				*ID=aux;
				utn_MostrarUno(alumno[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		retorno = 1;
	}}

	return retorno;
}
