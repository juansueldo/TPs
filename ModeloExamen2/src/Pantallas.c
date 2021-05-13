#include "utn.h"
#include "Pantallas.h"

int ePantalla_inicializar (ePantalla arrayPantalla[],int tam)
{
	int i;
	int ret;
	ret = -1;
	if(arrayPantalla != NULL && tam >0)
	{

		for (i = 0; i < tam; ++i)
		{
			arrayPantalla[i].idPantalla = 0;
			strcpy(arrayPantalla[i].nombre," ");
			arrayPantalla[i].codigo = 0;
			arrayPantalla[i].precio = 0;
			arrayPantalla[i].isEmpty=1;
		}
		ret = 0;
	}
	return ret;
}
int eTipo_inicializar (eTipo arrayTipo[],int cant)
{
	int i;
	int ret;
	ret = -1;
	if(arrayTipo != NULL && cant >0)
	{

		for (i = 0; i < cant; ++i)
		{
			arrayTipo[i].codigo = 0;
			strcpy(arrayTipo[i].descripcion," ");
		}
		ret = 0;
	}
	return ret;
}
int ePantalla_obtenerNombre (eTipo arrayTipo[],int cant,int codigo,char detalle[20])
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
				strcpy(detalle,"LCD");
				ret = 0;
				break;
				}
				if(arrayTipo[i].codigo== 2)
				{
					strcpy(detalle,"LED");
				ret = 0;
				break;
				}
			}
		}
	}

	return ret;
}

int ePantalla_buscarLibre (ePantalla arrayPantalla[],int tam)
{
	int ret;
	int i;
	ret = -1;
	if(arrayPantalla != NULL && tam > 0)
	{
		for (i = 0; i < tam; ++i)
		{
			if(arrayPantalla[i].isEmpty==1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
int ePantalla_buscarId (ePantalla arrayPantalla[],int tam,int id)
{
	int rtn = -1;
	int i;

	if (arrayPantalla != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (arrayPantalla[i].idPantalla == id && arrayPantalla[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
ePantalla ePantalla_cargarPantalla (void)
{
	ePantalla auxiliar;

		if((utn_getString(auxiliar.nombre,30,"\nIngrese el nombre de la pantalla: ","\nError. Ingrese el nombre la pantalla: ",1,3)) != 0)
		{
			printf("\n Error al ingresar el nombre");
		}
		if(utn_getFloat(&auxiliar.precio,"\nIngrese el precio: ","\nError. Ingrese el sueldo el precio: ",1000,999999,3) != 0)
		{
			printf("\n Error al ingresar el precio");
		}
		if(utn_getNumero(&auxiliar.codigo,"\nIngrese el tipo [1] LCD [2] LED: ","\nError. Ingrese el tipo [1] LCD [2] LED:",1,4,3) != 0)
		{
			printf("\n Error al ingresar el codigo");
		}

	return auxiliar;
}
int ePantalla_alta (ePantalla arrayPantalla[], int tam, int *pIdContador)
{
	int rtn = 0;
	ePantalla auxiliarPantalla;

	int index = ePantalla_buscarLibre (arrayPantalla, tam);

	if (index != -1)
	{
		//auxiliarPantalla.idPantalla = *pIdContador;
		auxiliarPantalla = ePantalla_cargarPantalla();

		auxiliarPantalla.isEmpty = 0;
		rtn = 1;
	}
	if(rtn == 1)
	{
		(*pIdContador)++;
		auxiliarPantalla.idPantalla = *pIdContador;
		arrayPantalla[index] = auxiliarPantalla;
	}


	return rtn;
}
void ePantalla_mostrarUno (ePantalla arrayPantalla[],int tam,eTipo arrayTipo[],int cant)
{
	char detalle[20];
	ePantalla_obtenerNombre(arrayTipo,cant,arrayPantalla[tam].codigo,detalle);
	//arrayPantalla[tam].idPantalla = ePantalla_ObtenerID();
	utn_getMayusMin (arrayPantalla[tam].nombre, 30);

	printf("\n %d     %5s         %5d          %6.2f        %15s     "
			, arrayPantalla[tam].idPantalla
			, arrayPantalla[tam].nombre
			, arrayPantalla[tam].codigo
			, arrayPantalla[tam].precio
			, detalle);
}
int ePantalla_mostrarTodos (ePantalla arrayPantalla[],int tam, eTipo arrayTipo[], int cant)
{
	int i;
	int ret;
	ret = -1;
	if(arrayPantalla != NULL && tam > 0 && arrayTipo != NULL && cant >0)
	{
		printf("\n*****************************************************************************\n");
		printf("\n ID    NOMBRE       CODIGO         PRECIO               CODIGO DETALLE ");
		printf("\n*****************************************************************************\n");
		for (i = 0; i < tam; i++)
		{

			if(arrayPantalla[i].isEmpty == 0)
			{
				ePantalla_mostrarUno (arrayPantalla,i, arrayTipo,cant);
			}
		}
		ret = 0;
	}
	return ret;
}
ePantalla ePantalla_modificarUno (ePantalla arrayPantalla, int campoModificar)
{
	ePantalla auxiliar = arrayPantalla;
			switch (campoModificar)
			{
				case 1:
					if((utn_getString(auxiliar.nombre,30,"\nIngrese el nombre la pantalla: ","\nError. Ingrese el nombre de la pantalla: ",3,3)) != 0)
					{
						printf("\n Error al ingresar el nombre");
					}
					fflush(stdin);
					break;
				case 2:
					if(utn_getFloat(&auxiliar.precio,"\nIngrese el sueldo el precio: ","\nError. Ingrese el sueldo el precio: ",1000,999999,3) != 0)
					{
						printf("\n Error al ingresar el precio");
					}
					break;
				case 3:
					if(utn_getNumero(&auxiliar.codigo,"\nIngrese el tipo [1] LCD [2] LED: ","\nError. Ingrese el tipo [1] LCD [2] LED:",1,4,3) != 0)
					{
						printf("\n Error al ingresar el codigo");
					}
					break;
				default:
					break;
				}

	return auxiliar;
}
int ePantalla_modificarPantallas (ePantalla arrayPantalla[], int tam, eTipo arrayTipo[], int cant)
{
		int rtn = -1;
		int idPantalla;
		int index;
		int flag = 0;
		int auxMod;
		ePantalla auxiliar;

		if (ePantalla_mostrarTodos(arrayPantalla, tam, arrayTipo, cant) == 0)
		{
			flag = 1;
		}

		if (flag) {
			printf("\n*****************************************************************\n");
			printf("Ingrese el id de la pantalla a modificar:");
			scanf("%d",&idPantalla);

			while (ePantalla_buscarId(arrayPantalla, tam, idPantalla) == -1)
			{
				printf("NO EXISTE ID. Reingrese el id a modificar:");
				scanf("%d",& idPantalla);
			}


			index = ePantalla_buscarId(arrayPantalla, tam, idPantalla);
			printf("\n*****************************************************************\n");
			printf("INGRESE EL CAMPO A MODIFICAR \n1. NOMBRE \n2. CODIGO \n3. PRECIO");
			printf("\n*****************************************************************\n");
			printf("Ingrese:");
			scanf("%d",&auxMod);
			if(utn_getRespuesta ("\nDESEA MODIFICAR (SI 's' o NO 'n'): ","\nERROR. INGRESE (SI 's' o NO 'n')", 3)==0)
			{
			auxiliar = ePantalla_modificarUno(arrayPantalla[index],auxMod);
			arrayPantalla[index] = auxiliar;
			rtn = 0;
			}

		}

		return rtn;
}
int ePantalla_baja (ePantalla arrayPantalla[], int tam, eTipo arrayTipo[], int cant)
{
	int rtn = -1;
	int idPantalla;
	int index;
	int flag = 0;

	if (ePantalla_mostrarTodos(arrayPantalla, tam, arrayTipo, cant) == 0)
	{
		flag = 1;
	}

	if (flag)
		{
		printf("\nINGRESE EL ID DE LA PANTALLA A DAR DE BAJA:");
		scanf("%d",&idPantalla);

		while (ePantalla_buscarId(arrayPantalla, tam, idPantalla) == -1)
		{
			printf("NO EXISTE ID. REINGRESE EL ID DE LA PANTALLA A DAR DE BAJA:");
			scanf("%d",&idPantalla);
		}
		index = ePantalla_buscarId(arrayPantalla, tam, idPantalla);
		if(utn_getRespuesta ("\nDESEA DAR DE BAJA (si 's' o NO 'no'): ","\nERROR. DESEA DAR DE BAJA (SI 's' o NO 'n')", 3)==0)
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
