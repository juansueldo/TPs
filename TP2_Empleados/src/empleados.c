#include "utn.h"
#include "empleados.h"

int initEmployees (eEmployee arrayEmpleados[],int tamanio)
{
	int i;
	int ret;
	ret = -1;
	if(arrayEmpleados != NULL && tamanio >0)
	{

		for (i = 0; i < tamanio; ++i)
		{
			arrayEmpleados[i].id = 0;
			strcpy(arrayEmpleados[i].name," ");
			strcpy(arrayEmpleados[i].lastName," ");
			arrayEmpleados[i].salary = 0;
			arrayEmpleados[i].sector = 0;
			arrayEmpleados[i].isEmpty=1;
		}
		ret = 0;
	}
	return ret;
}
int initSector (eSector arraySector[],int tamanio)
{
	int i;
	int ret;
	ret = -1;
	if(arraySector != NULL && tamanio >0)
	{

		for (i = 0; i < tamanio; ++i)
		{
			arraySector[i].sector = 0;
			strcpy(arraySector[i].detalleSector," ");
			arraySector[i].isEmpty=1;
		}
		ret = 0;
	}
	return ret;
}
int buscarLibre (eEmployee arrayEmpleados[],int tamanio)
{
	int ret;
	int i;
	ret = -1;
	if(arrayEmpleados != NULL && tamanio > 0)
	{
		for (i = 0; i < tamanio; ++i)
		{
			if(arrayEmpleados[i].isEmpty==1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
int buscarId (eEmployee arrayEmpleados[],int tamanio)
{
	int ret;
	int i;
	int idEmpleado;
	ret = -1;
	int validarId;
	scanf("\n %d",&idEmpleado);
	validarId = isdigit(idEmpleado);

	if(arrayEmpleados != NULL && tamanio > 0 && validarId != 0)
	{
			for (i = 0; i < tamanio; i++)
			{

				if(idEmpleado == arrayEmpleados[i].id && arrayEmpleados[i].isEmpty==0)
				{
					ret = i;
					break;
				}

			}
	}

	return ret;
}
eEmployee utn_CargarDatos(void)
{
	eEmployee auxiliar;
	int contadorErrores = 0;

		if(utn_getNumero(&auxiliar.id,"\nIngrese el ID del empleado:\n","\nError. Ingrese el ID del empleado:\n",1,1000,3) != 0)
				{
					contadorErrores++;
					printf("\n Error al ingresar el ID");
				}

				if((utn_getString(auxiliar.name,30,"\nIngrese el nombre del empleado:\n","\nError. Ingrese el nombre del empleado:\n",3,3)) != 0)
				{
					contadorErrores++;
					printf("\n Error al ingresar el nombre");
				}
				if((utn_getString(auxiliar.lastName,30,"\nIngrese el apellido del empleado:\n","\nError. Ingrese el apellido del empleado:\n",3,3)) != 0)
				{
					contadorErrores++;
					printf("\n Error al ingresar el apellido");
				}
				if(utn_getFloat(&auxiliar.salary,"\nIngrese el sueldo del empleado:\n","\nError. Ingrese el sueldo del empleado:\n",1000,999999,3) != 0)
				{
					contadorErrores++;
					printf("\n Error al ingresar el sueldo");
				}
				if(utn_getNumero(&auxiliar.sector,"\nIngrese el sector (1. RRHH, 2. Programador, 3. Diseniador, 4. Otros):\n","\nError. Ingrese el sector (1. RRHH, 2. Programador, 3. Diseniador, 4. Otros):\n",1,4,3) != 0)
				{
					contadorErrores++;
					printf("\n Error al ingresar el sector");
				}

				return auxiliar;


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
int utn_Alta(eEmployee empleados[], int tamanio)
{
	int retorno = 0;
	eEmployee auxiliar;

	//BUSCO ESPACIO EN ARRAY
	int index = utn_getIdLibre(empleados, tamanio);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxiliar = utn_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxiliar.id = buscarId(empleados,tamanio);
		//CAMBIO SU ESTADO A "OCUPADO"
		auxiliar.isEmpty = 0;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		empleados[index] = auxiliar;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}

	return retorno;
}
int cargarEmpleados (eEmployee arrayEmpleados[],int tamanio)
{
	int ret = -1;
	int contadorErrores = 0;

	int auxId;
	char auxName[30];
	char auxLastName[30];
	float auxSalary;
	int auxSector;

	if(arrayEmpleados != NULL && tamanio > 0)
	{

			if(utn_getNumero(&auxId,"\nIngrese el ID del empleado:\n","\nError. Ingrese el ID del empleado:\n",1,1000,3) != 0)
			{
				contadorErrores++;
				printf("\n Error al ingresar el ID");
			}

			if((utn_getString(auxName,30,"\nIngrese el nombre del empleado:\n","\nError. Ingrese el nombre del empleado:\n",3,3)) != 0)
			{
				contadorErrores++;
				printf("\n Error al ingresar el nombre");
			}
			fflush(stdin);
			if((utn_getString(auxLastName,30,"\nIngrese el apellido del empleado:\n","\nError. Ingrese el apellido del empleado:\n",3,3)) != 0)
			{
				contadorErrores++;
				printf("\n Error al ingresar el apellido");
			}
			fflush(stdin);
			if(utn_getFloat(&auxSalary,"\nIngrese el sueldo del empleado:\n","\nError. Ingrese el sueldo del empleado:\n",1000,999999,3) != 0)
			{
				contadorErrores++;
				printf("\n Error al ingresar el sueldo");
			}
			if(utn_getNumero(&auxSector,"\nIngrese el sector (1. RRHH, 2. Programador, 3. Diseniador, 4. Otros):\n","\nError. Ingrese el sector (1. RRHH, 2. Programador, 3. Diseniador, 4. Otros):\n",1,4,3) != 0)
			{
				contadorErrores++;
				printf("\n Error al ingresar el sector");
			}

			if(contadorErrores == 0 && arrayEmpleados[tamanio].isEmpty == 1)
			{
				arrayEmpleados[tamanio].isEmpty = 0;
				arrayEmpleados[tamanio].id = auxId;
				strcpy(arrayEmpleados[tamanio].name,auxName);
				strcpy(arrayEmpleados[tamanio].lastName,auxLastName);
				arrayEmpleados[tamanio].salary = auxSalary;
				arrayEmpleados[tamanio].sector = auxSector;

				ret = arrayEmpleados[tamanio].isEmpty;
			}

	}
	return ret;
}
int modificarEmpleados(eEmployee arrayEmpleados[],int tamanio,int campoModificar)
{
	int ret = -1;
	char auxName[30];
	char auxLastName[30];
	float auxSalary;
	int auxSector;
	int flagName = 0;
	int flagLastName = 0;
	int flagSalary = 0;
	int flagSector = 0;


	int contadorErrores = 0;

	if(arrayEmpleados != NULL && tamanio > -1)
	{
			switch (campoModificar)
			{
				case 1:
					if((utn_getString(auxName,30,"\nIngrese el nombre del empleado:\n","\nError. Ingrese el nombre del empleado:\n",3,3)) != 0)
					{
						contadorErrores++;

					}
					else
					{
						flagName = 1;
					}
					break;
				case 2:
					if((utn_getString(auxLastName,30,"\nIngrese el apellido del empleado:\n","\nError. Ingrese el apellido del empleado:\n",3,3)) != 0)
					{
						contadorErrores++;
					}
					else
					{
						flagLastName = 1;
					}
					break;
				case 3:
					if(utn_getFloat(&auxSalary,"\nIngrese el sueldo del empleado:\n","\nError. Ingrese el sueldo del empleado:\n",1000,999999,3) != 0)
					{
						contadorErrores++;
					}
					else
					{
						flagSalary = 1;
					}
					break;
				case 4:
					if(utn_getNumero(&auxSector,"\nIngrese el sector (1. RRHH, 2. Programador, 3. Diseniador, 4. Otros):\n","\nError. Ingrese el sector (1. RRHH, 2. Programador, 3. Diseniador, 4. Otros):\n",1,4,3) != 0)
					{
						contadorErrores++;
					}
					else
					{
						flagSector = 1;
					}
					break;
				default:
					break;
			}
			if(contadorErrores == 0 && flagName != 0)
			{
				strcpy(arrayEmpleados[tamanio].name,auxName);
				ret = 0;
			}
			if(contadorErrores == 0 && flagLastName != 0)
			{
				strcpy(arrayEmpleados[tamanio].lastName,auxLastName);
				ret = 0;
			}
			if(contadorErrores == 0 && flagSalary != 0)
			{
				arrayEmpleados[tamanio].salary = auxSalary;
				ret = 0;
			}
			if(contadorErrores == 0 && flagSector != 0)
			{
				arrayEmpleados[tamanio].sector = auxSector;
				ret = 0;
			}

	}


	return ret;
}
int getNombreSector (eSector arraySector[],int cant,int sector,char detalleSector[])
{
	int ret;
	ret = -1;
	int i;
	if(arraySector != NULL && cant > 0 && (isdigit(sector)) == 0  && detalleSector != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arraySector[i].sector == sector)
			{
				strcpy(detalleSector,arraySector[i].detalleSector);
				ret = 0;
				break;
			}
		}
	}

	return ret;
}
void mostrarEmpleado (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[])
{
	char detalleSector[20];
	getNombreSector(arraySector,CANT,arrayEmpleados[tamanio].sector,detalleSector);
	//strcpy(detalleSector,);

	printf("\n %d \t %s \t %s \t %.2f \t %d \t %s \t"
			,arrayEmpleados[tamanio].id
			,arrayEmpleados[tamanio].name
			,arrayEmpleados[tamanio].lastName
			,arrayEmpleados[tamanio].salary
			,arrayEmpleados[tamanio].sector
			,detalleSector);
}
int mostrarEmpleados (eEmployee arrayEmpleados[],int tamanio,eSector arraySector[])
{
	int i;
	int ret;
	ret = -1;
	if(arrayEmpleados != NULL && tamanio > 0)
	{
		for (i = 0; i < tamanio; ++i)
		{

			if(arrayEmpleados[i].isEmpty == 0)
			{
				mostrarEmpleado(arrayEmpleados,i,arraySector);
			}
		}
		ret = 0;
	}
	return ret;
}



