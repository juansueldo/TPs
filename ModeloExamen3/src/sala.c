/*
 * movie.c
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */
#include "sala.h"

eSala* eSala_new()
{
	eSala* pAuxeSala;

    pAuxeSala = (eSala*)malloc(sizeof(eSala));

    return pAuxeSala;
}
void eSala_delete(eSala* this)
{

    if(this != NULL)
    {
        free(this);
    }
}

eSala* eSala_newParametros (char* idStr,char* fechaStr,char* tipoStr, char* cantidadStr, char* duracionStr)
{
    eSala* this = eSala_new();
    void *retorno = NULL;
    if(this != NULL && idStr != NULL && fechaStr != NULL && tipoStr != NULL && duracionStr != NULL &&cantidadStr != NULL)
    {
    	if(!eSala_setId(this, atoi(idStr)) &&
    	!eSala_setFecha(this, fechaStr) &&
    	!eSala_setTipo(this, atoi(tipoStr)) &&
		!eSala_setCantidad(this,atoi(cantidadStr)) &&
    	!eSala_setDuracion(this, atoi(duracionStr)))
    	{
    		retorno = this;
    	}
    	else
    	{
    		eSala_delete(this);
    		retorno = this;
    	}

    }
    return retorno;
}
int eSala_setId(eSala* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id_partida = id;
	}
	return retorno;
}
int eSala_getId(eSala* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id_partida;
		retorno = 0;

	}
	return retorno;
}
int eSala_setTipo(eSala* this,int tipo)
{
	int retorno = -1;
	if(this != NULL && tipo >= 0)
	{
		retorno = 0;
		this->tipo = tipo;
	}
	return retorno;
}
int eSala_getTipo(eSala* this,int* tipo)
{
	int retorno = -1;
	if(this != NULL && tipo != NULL)
	{
		retorno = 0;
		*tipo = this->tipo;
	}
	return retorno;
}

int eSala_setCantidad(eSala* this,int cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad >= 0)
	{
		retorno = 0;
		this->cantidad = cantidad;
	}
	return retorno;
}
int eSala_getCantidad(eSala* this,int* cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad != NULL)
	{
		retorno = 0;
		*cantidad = this->cantidad;
	}
	return retorno;
}
int eSala_setFecha(eSala* this,char* fecha)
{
    int retorno = -1;

    if(this != NULL && fecha != NULL)
    {
        strcpy(this->fecha, fecha);
        retorno = 0;
    }

    return retorno;
}
int eSala_getFecha(eSala* this,char* fecha)
{
    int retorno = -1;

    if(this != NULL && fecha !=NULL)
    {
        strcpy(fecha, this->fecha);
        retorno = 0;
    }

    return retorno;
}
int eSala_setDuracion(eSala* this,int duracion)
{
	int retorno = -1;
	if(this != NULL && duracion >= 0)
	{
		retorno = 0;
		this->duracion = duracion;
	}
	return retorno;
}
int eSala_getDuracion(eSala* this,int* duracion)
{
	int retorno = -1;
	if(this != NULL && duracion != NULL)
	{
		retorno = 0;
		*duracion = this->duracion;
	}
	return retorno;
}/*
int eSala_getDays (eDias* arrayDias,int dia,char* detalleDia)
{
	int retorno = -1;
	if(arrayDias != NULL && detalleDia != NULL)
	{
		if(arrayDias->dia == dia)
		{
			switch(dia)
			{
			case 0:
				strcpy(detalleDia,"Domingo");
				//retorno = 0;
				break;
			case 1:
				strcpy(detalleDia,"Lunes");
				//retorno = 0;
				break;
			case 2:
				strcpy(detalleDia,"Martes");
				//retorno = 0;
				break;
			case 3:
				strcpy(detalleDia,"Miercoles");
				//retorno = 0;
				break;
			case 4:
				strcpy(detalleDia,"Jueves");
				//retorno = 0;
				break;
			case 5:
				strcpy(detalleDia,"Viernes");
				//retorno = 0;
				break;
			case 6:
				strcpy(detalleDia,"Sabado");
				//retorno = 0;
				break;
			}
			retorno = 0;
		}
	}

	return retorno;
}

int eSala_setMonto(eSala* this,float monto)
{
	int retorno = -1;
	if(this != NULL && monto >= 0)
	{
		retorno = 0;
		this->monto = monto;
	}
	return retorno;
}
int eSala_getMonto(eSala* this,float* monto)
{
	int retorno = -1;
	if(this != NULL && monto != NULL)
	{
		retorno = 0;
		*monto = this->monto;
	}
	return retorno;
}
int eSala_getMontoGenrado (eSala* this, int dia,int cantidad, float* monto)
{
	int retorno = -1;
	float descuento;
	if(this != NULL)
	{
		if(dia == 1 || dia == 2 || dia ==3)
		{
			*monto = 240 * cantidad;
		}
		else
		{
			*monto = 350 * cantidad;
		}
		if(cantidad > 3)
		{
			descuento = *monto *0.1;
			*monto = *monto - descuento;
		}
		retorno = 0;
	}
	return retorno;
}
void calcularMonto(void* this)
{
	int dia;
	int cantidad;
	float monto;
	int descuento;
	if(this != NULL)
	{
		eSala_getDia(this, &dia);
		eSala_getCantidad(this, &cantidad);

		if(dia == 1 || dia == 2 || dia ==3)
		{
			monto = 240 * cantidad;
			eSala_setMonto(this, monto);
		}
		else
		{
			monto = 350 * cantidad;
			eSala_setMonto(this, monto);
		}
		if(cantidad > 3)
		{
			descuento = monto *0.1;
			monto = monto - descuento;
			eSala_setMonto(this, monto);

		}
	}
}
eSala* eSala_newParametrosInt(int id,char* nombre,int dia, char* horario, int sala, int cantidad, float monto)
{
    void *retorno = NULL;
    eSala* this = eSala_new();
    if( this!=NULL && id > 0 && nombre != NULL && dia >= 0 && horario != NULL && sala > 0 && cantidad > 0 && monto > 0)
    {
    	 if(!eSala_setId(this, id) &&
    	    !eSala_setNombre(this, nombre) &&
    	    !eSala_setDia(this, dia) &&
    		!eSala_setHora(this,horario) &&
    	    !eSala_setSala(this, sala) &&
    		!eSala_setCantidad(this,cantidad)&&
			!eSala_setMonto(this,monto))
    	   {
    	    	retorno = this;
    	   }
    	   else
    	    {
    	    	eSala_delete(this);
    	    	retorno = this;
    	    }

    	    }
    	    return retorno;
}
int eSala_compareBynombre(void* pThis1, void* pThis2)
{
    int comparar;
    eSala* pAuxeSala1 = (eSala*)pThis1;
    eSala* pAuxeSala2 = (eSala*)pThis2;

    if(pAuxeSala1 != NULL && pAuxeSala2 != NULL)
    {
    	utn_getMayusMin(pAuxeSala1->nombre_pelicula, MAX_NOMBRE);
    	utn_getMayusMin(pAuxeSala2->nombre_pelicula, MAX_NOMBRE);
        comparar = strcmp(pAuxeSala1->nombre_pelicula, pAuxeSala2->nombre_pelicula);
    }

    return comparar;
}
void eSala_delete(eSala *this)
{

    if(this != NULL)
    {
        free(this);
    }
}

int eSala_setId(eSala* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int eSala_getId(eSala* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;

	}
	return retorno;
}
int eSala_setNombre(eSala* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}
int eSala_getNombre(eSala* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;
}

int eSala_setHorasTrabajadas(eSala* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
int eSala_getHorasTrabajadas(eSala* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

int eSala_setSueldo(eSala* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}
int eSala_getSueldo(eSala* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}
int eSala_print(eSala* this)
{
    int retorno = -1;
    int id;
    char nombre[eSala_NOMBRE_MAX];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL && eSala_getId(this, &id)==0
    				&& eSala_getNombre(this, nombre)==0
					&& eSala_getHorasTrabajadas(this, &horasTrabajadas)==0
					&& eSala_getSueldo(this, &sueldo)==0)
    {
    	printf("|*******|**********************|*******|************|\n");
    	printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
    	printf("|*******|**********************|*******|************|\n");
    	utn_getMayusMin(this->nombre,eSala_NOMBRE_MAX);
    	printf("| %5d | %20s | %5d | %10d |\n",
    		            	id, nombre, horasTrabajadas, sueldo);
        printf("|*******|**********************|*******|************|\n");

        retorno = 0;
    }

    return retorno;
}
eSala eSala_change (eSala* this, int opcion)
{
	eSala* pAuxeSala = this;
	char nombre[eSala_NOMBRE_MAX];
	int horasTrabajadas;
	int sueldo;
	switch(opcion)
	{
	case 1:
		if(!utn_getString(nombre, eSala_NOMBRE_MAX, "INGRESE EL NUEVO NOMBRE: ", "\nERROR", 1,3)
				&& eSala_setNombre(pAuxeSala,nombre))
		{
			printf("\nEL NOMBRE NO FUE CAMBIADO\n");
		}
		else
		{
			eSala_getNombre(pAuxeSala, nombre);
			printf("\nNOMBRE CAMBIADO\n");
		}
    break;
	case 2:
		if(!utn_getNumero(&horasTrabajadas, "INGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 1, eSala_HORA_MAX,3)
				&& eSala_setHorasTrabajadas(pAuxeSala, horasTrabajadas))
		{
			printf("\nLAS HORAS TRABAJADAS NO FUERON CAMBIADAS\n");
		}
		else
		{
			eSala_getHorasTrabajadas(pAuxeSala, &horasTrabajadas);
			printf("\nHORAS TRABAJADAS CAMBIADAS\n");
		}
    break;
	case 3:
		if(!utn_getNumero(&sueldo, "INGRESE EL NUEVO SUELDO: ", "\nERROR", 1, eSala_SUELDO_MAX,3)
				&& eSala_setSueldo(pAuxeSala, sueldo))
		{
			printf("\nEL SUELDO NO FUE CAMBIADO\n");
		}
		else
		{
			eSala_getSueldo(pAuxeSala, &sueldo);
			printf("\nSUELDO CAMBIADO\n");
		}
    break;
	}

	return *pAuxeSala;

}
int eSala_compareByID(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eSala* pAuxeSala1 = (eSala*)pThis1;
    eSala* pAuxeSala2 = (eSala*)pThis2;

    if(pAuxeSala1 != NULL && pAuxeSala2 != NULL)
    {
        resultado = pAuxeSala1->id - pAuxeSala2->id;

        if(resultado > 0)
        {
            comparar = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparar = -1;
            }
            else
            {
                comparar = 0;
            }
        }
    }

    return comparar;
}

int eSala_compareBynombre(void* pThis1, void* pThis2)
{
    int comparar;
    eSala* pAuxeSala1 = (eSala*)pThis1;
    eSala* pAuxeSala2 = (eSala*)pThis2;

    if(pAuxeSala1 != NULL && pAuxeSala2 != NULL)
    {
    	utn_getMayusMin(pAuxeSala1->nombre, eSala_NOMBRE_MAX);
    	utn_getMayusMin(pAuxeSala2->nombre, eSala_NOMBRE_MAX);
        comparar = strcmp(pAuxeSala1->nombre, pAuxeSala2->nombre);
    }

    return comparar;
}

int eSala_compareByhorasTrabajadas(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eSala* pAuxeSala1 = (eSala*)pThis1;
    eSala* pAuxeSala2 = (eSala*)pThis2;

    if(pAuxeSala1 != NULL && pAuxeSala2 != NULL)
    {
        resultado = pAuxeSala1->horasTrabajadas - pAuxeSala2->horasTrabajadas;

        if(resultado > 0)
        {
            comparar = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparar = -1;
            }
            else
            {
                comparar = 0;
            }
        }
    }

    return comparar;
}

int eSala_compareBysueldo(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eSala* pAuxeSala1 = (eSala*)pThis1;
    eSala* pAuxeSala2 = (eSala*)pThis2;

    if(pAuxeSala1 != NULL && pAuxeSala2 != NULL)
    {
        resultado = pAuxeSala1->sueldo - pAuxeSala2->sueldo;

        if(resultado > 0)
        {
            comparar = 1;
        }
        else
        {
            if(resultado < 0)
            {
                comparar = -1;
            }
            else
            {
                comparar = 0;
            }
        }
    }

    return comparar;
}

*/
