#include "Publicidad.h"

ePublicidad ePublicidad_cargarPublicidad (void)
{
	ePublicidad auxPublicidad;

		if((utn_getString(auxPublicidad.video,30,"\nIngrese el nombre del archivo: ","\nError. Ingrese el nombre del archivo: ",1,3)) != 0)
		{
			printf("\n Error al ingresar el nombre");
		}
		if(utn_getNumero(&auxPublicidad.dias,"\nIngrese la cantidad de dias: ","\nError. Ingrese la cantidad de dias: ",30,365,3) != 0)
		{
			printf("\n Error al ingresar la cantidad de dias");
		}
		if(utn_getCuit(auxPublicidad.cuit,"\nIngrese el cuit: ","\nError. Ingrese el cuit:",3) != 0)
		{
			printf("\n Error al ingresar el codigo");
		}

	return auxPublicidad;
}
int ePublicidad_alta (ePantalla arrayPantalla [],int tam, ePublicidad arrayPublicidad[], eTipo arrayTipo[],int cant, int *pCont)
{
	int rtn = -1;
	int idPantalla;
	int index;
	int flag = 0;
	ePublicidad  auxPublicidad;

	if (ePantalla_mostrarTodos(arrayPantalla, tam, arrayTipo, cant) == 0)
	{
	flag = 1;


	if (flag)
	{
	printf("\nINGRESE EL ID DE LA PANTALLA DONDE SE VA A PUBLICAR:");
	scanf("%d",&idPantalla);
	}
	while (ePantalla_buscarId(arrayPantalla, tam, idPantalla) == -1)
	{
		printf("NO EXISTE ID. REINGRESE EL ID DE LA PANTALLA DONDE SE VA A PUBLICAR:");
		scanf("%d",&idPantalla);
	}
	index = ePantalla_buscarId(arrayPantalla, tam, idPantalla);
	if(index != -1)
	{
		auxPublicidad.idPantalla = *pCont;
		auxPublicidad = ePublicidad_cargarPublicidad();
		rtn = 0;
	}
	if(rtn == 0)
	{
		(*pCont)++;
		auxPublicidad.idPantalla = *pCont;
		arrayPublicidad[index] = auxPublicidad;

	}
	}

	return rtn;
}
int ePublicidad_buscarCuit (ePublicidad arrayPublicidad[],int tam,char pCuit[14])
{
	int rtn = -1;
	int i;

	if (arrayPublicidad != NULL && tam > 0 && pCuit != NULL) {
		for (i = 0; i < tam; i++) {
			if(strcmp(arrayPublicidad[i].cuit,pCuit) == 0 && arrayPublicidad[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
int ePublicidad_obtenerPublicidad (ePantalla arrayPantalla[],int cant,int codigo,ePantalla auxPantalla[])
{
	int ret;
	ret = -1;
	int i;
	if(arrayPantalla != NULL && cant > 0 && (isdigit(codigo)) == 0  && auxPantalla != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			auxPantalla = arrayPantalla;
			ret = 0;
			break;
		}
	}
	return ret;
}
void ePublicidad_mostrarUno (ePublicidad arrayPublicidad[] ,int tam)
{

	printf("\n %s     %5d         %5s "
			, arrayPublicidad[tam].cuit
			, arrayPublicidad[tam].dias
			, arrayPublicidad[tam].video);
}
int ePublicidad_mostrarTodos (ePantalla arrayPublicidad[],int tam, ePantalla arrayPantalla[], int cant, eTipo arrayTipo[])
{
	int i;
	int ret;
	ret = -1;
	if(arrayPublicidad != NULL && tam > 0 && arrayPantalla != NULL)
	{
		printf("\n*****************************************************************************\n");
		printf("\n ID    NOMBRE       CODIGO         PRECIO               CODIGO DETALLE ");
		printf("\n*****************************************************************************\n");
		for (i = 0; i < tam; i++)
		{
			if(arrayPublicidad[i].isEmpty == 0 && arrayPublicidad[i].idPantalla == arrayPantalla[i].idPantalla)
			{
				ePublicidad_mostrarUno (arrayPublicidad ,i);
				ePantalla_mostrarTodos(arrayPantalla, tam, arrayTipo, cant);
			}
		}
		ret = 0;
	}
	return ret;
}
ePublicidad ePublicidad_modificarUno (ePublicidad arrayPublicidad, int campoModificar)
{
	ePublicidad auxiliar = arrayPublicidad;
		switch (campoModificar)
		{
			case 1:
				if((utn_getString(auxiliar.video,30,"\nIngrese el nombre del archivo: ","\nError. Ingrese el nombre del archivo: ",1,3)) != 0)
				{
					printf("\n Error al ingresar el nombre");
				}
				fflush(stdin);
				break;
				case 2:
					if(utn_getNumero(&auxiliar.dias,"\nIngrese la cantidad de dias: ","\nError. Ingrese la cantidad de dias: ",30,365,3) != 0)
					{
					printf("\n Error al ingresar la cantidad de dias");
					}
					break;
				case 3:
					if(utn_getCuit(auxiliar.cuit,"\nIngrese el cuit: ","\nError. Ingrese el cuit:",3) != 0)
					{
					printf("\n Error al ingresar el codigo");
					}
					break;
				default:
					break;
				}

	return auxiliar;
}
int ePublicidad_modificarPantallas (ePublicidad arrayPublicidad[], int tam, ePantalla arrayPantalla[], int cant,eTipo arrayTipo[])
{
		int rtn = -1;
		char auxCuit[14];
		int index;
		int flag = 0;
		int auxMod;
		ePublicidad auxiliar;

		if (ePublicidad_mostrarTodos(arrayPublicidad, tam, arrayPantalla, cant, arrayTipo) == 0)
		{
			flag = 1;
		}

		if (flag) {
			printf("\n*****************************************************************\n");
			printf("Ingrese el CUIT a modificar:");
			scanf("%s",auxCuit);

			while (ePublicidad_buscarCuit(arrayPublicidad, tam, auxCuit) == -1)
			{
				printf("NO EXISTE ID. Reingrese el id a modificar:");
				scanf("%s",auxCuit);
			}


			index = ePublicidad_buscarCuit(arrayPublicidad, tam, auxCuit);
			printf("\n*****************************************************************\n");
			printf("INGRESE EL CAMPO A MODIFICAR \n1. NOMBRE \n2. CODIGO \n3. PRECIO");
			printf("\n*****************************************************************\n");
			printf("Ingrese:");
			scanf("%d",&auxMod);
			if(utn_getRespuesta ("\nDESEA MODIFICAR (SI 's' o NO 'n'): ","\nERROR. INGRESE (SI 's' o NO 'n')", 3)==0)
			{
			auxiliar = ePublicidad_modificarUno (arrayPublicidad[index],auxMod);
			arrayPublicidad[index] = auxiliar;
			rtn = 0;
			}

		}

		return rtn;
}


