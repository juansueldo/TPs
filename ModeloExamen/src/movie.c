/*
 * movie.c
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */
#include "movie.h"

eMovie* eMovie_new()
{
    eMovie* pAuxeMovie;

    pAuxeMovie = (eMovie*)malloc(sizeof(eMovie));

    return pAuxeMovie;
}
void eMovie_delete(eMovie *this)
{

    if(this != NULL)
    {
        free(this);
    }
}
eMovie* eMovie_newParametros(char* idStr,char* nombreStr,char* diaStr, char* horarioStr, char* salaStr, char* cantidadStr)
{
    eMovie* this = eMovie_new();
    void *retorno = NULL;
    if(this != NULL && idStr != NULL && nombreStr != NULL && horarioStr != NULL && salaStr != NULL &&cantidadStr != NULL)
    {
    	if(!eMovie_setId(this, atoi(idStr)) &&
    	!eMovie_setNombre(this, nombreStr) &&
    	!eMovie_setDia(this, atoi(diaStr)) &&
		!eMovie_setHora(this,horarioStr) &&
    	!eMovie_setSala(this, atoi(salaStr)) &&
		!eMovie_setCantidad(this,atoi(cantidadStr)))
    	{
    		retorno = this;
    	}
    	else
    	{
    		eMovie_delete(this);
    		retorno = this;
    	}

    }
    return retorno;
}
int eMovie_setId(eMovie* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id_venta = id;
	}
	return retorno;
}
int eMovie_getId(eMovie* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id_venta;
		retorno = 0;

	}
	return retorno;
}
int eMovie_setNombre(eMovie* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre_pelicula, nombre);
        retorno = 0;
    }

    return retorno;
}
int eMovie_getNombre(eMovie* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre_pelicula);
        retorno = 0;
    }

    return retorno;
}

int eMovie_setDia(eMovie* this,int dia)
{
	int retorno = -1;
	if(this != NULL && dia >= 0)
	{
		retorno = 0;
		this->dia = dia;
	}
	return retorno;
}
int eMovie_getDia(eMovie* this,int* dia)
{
	int retorno = -1;
	if(this != NULL && dia != NULL)
	{
		retorno = 0;
		*dia = this->dia;
	}
	return retorno;
}

int eMovie_setSala(eMovie* this,int sala)
{
	int retorno = -1;
	if(this != NULL && sala >= 0)
	{
		retorno = 0;
		this->sala = sala;
	}
	return retorno;
}
int eMovie_getSala(eMovie* this,int* sala)
{
	int retorno = -1;
	if(this != NULL && sala != NULL)
	{
		retorno = 0;
		*sala = this->sala;
	}
	return retorno;
}
int eMovie_setHora(eMovie* this,char* horario)
{
    int retorno = -1;

    if(this != NULL && horario != NULL)
    {
        strcpy(this->horario, horario);
        retorno = 0;
    }

    return retorno;
}
int eMovie_getHora(eMovie* this,char* horario)
{
    int retorno = -1;

    if(this != NULL && horario !=NULL)
    {
        strcpy(horario, this->horario);
        retorno = 0;
    }

    return retorno;
}
int eMovie_setCantidad(eMovie* this,int cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad >= 0)
	{
		retorno = 0;
		this->cantidad_entradas = cantidad;
	}
	return retorno;
}
int eMovie_getCantidad(eMovie* this,int* cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad != NULL)
	{
		retorno = 0;
		*cantidad = this->cantidad_entradas;
	}
	return retorno;
}
int eMovie_getDays (eDias* arrayDias,int dia,char* detalleDia)
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

int eMovie_setMonto(eMovie* this,float monto)
{
	int retorno = -1;
	if(this != NULL && monto >= 0)
	{
		retorno = 0;
		this->monto = monto;
	}
	return retorno;
}
int eMovie_getMonto(eMovie* this,float* monto)
{
	int retorno = -1;
	if(this != NULL && monto != NULL)
	{
		retorno = 0;
		*monto = this->monto;
	}
	return retorno;
}
int eMovie_getMontoGenrado (eMovie* this, int dia,int cantidad, float* monto)
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

eMovie* eMovie_newParametrosInt(int id,char* nombre,int dia, char* horario, int sala, int cantidad, float monto)
{
    void *retorno = NULL;
    eMovie* this = eMovie_new();
    if( this!=NULL && id > 0 && nombre != NULL && dia >= 0 && horario != NULL && sala > 0 && cantidad > 0 && monto > 0)
    {
    	 if(!eMovie_setId(this, id) &&
    	    !eMovie_setNombre(this, nombre) &&
    	    !eMovie_setDia(this, dia) &&
    		!eMovie_setHora(this,horario) &&
    	    !eMovie_setSala(this, sala) &&
    		!eMovie_setCantidad(this,cantidad)&&
			!eMovie_setMonto(this,monto))
    	   {
    	    	retorno = this;
    	   }
    	   else
    	    {
    	    	eMovie_delete(this);
    	    	retorno = this;
    	    }

    	    }
    	    return retorno;
    	}
/*
void eMovie_delete(eMovie *this)
{

    if(this != NULL)
    {
        free(this);
    }
}

int eMovie_setId(eMovie* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int eMovie_getId(eMovie* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;

	}
	return retorno;
}
int eMovie_setNombre(eMovie* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}
int eMovie_getNombre(eMovie* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;
}

int eMovie_setHorasTrabajadas(eMovie* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
int eMovie_getHorasTrabajadas(eMovie* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

int eMovie_setSueldo(eMovie* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}
int eMovie_getSueldo(eMovie* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}
int eMovie_print(eMovie* this)
{
    int retorno = -1;
    int id;
    char nombre[eMovie_NOMBRE_MAX];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL && eMovie_getId(this, &id)==0
    				&& eMovie_getNombre(this, nombre)==0
					&& eMovie_getHorasTrabajadas(this, &horasTrabajadas)==0
					&& eMovie_getSueldo(this, &sueldo)==0)
    {
    	printf("|*******|**********************|*******|************|\n");
    	printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
    	printf("|*******|**********************|*******|************|\n");
    	utn_getMayusMin(this->nombre,eMovie_NOMBRE_MAX);
    	printf("| %5d | %20s | %5d | %10d |\n",
    		            	id, nombre, horasTrabajadas, sueldo);
        printf("|*******|**********************|*******|************|\n");

        retorno = 0;
    }

    return retorno;
}
eMovie eMovie_change (eMovie* this, int opcion)
{
	eMovie* pAuxeMovie = this;
	char nombre[eMovie_NOMBRE_MAX];
	int horasTrabajadas;
	int sueldo;
	switch(opcion)
	{
	case 1:
		if(!utn_getString(nombre, eMovie_NOMBRE_MAX, "INGRESE EL NUEVO NOMBRE: ", "\nERROR", 1,3)
				&& eMovie_setNombre(pAuxeMovie,nombre))
		{
			printf("\nEL NOMBRE NO FUE CAMBIADO\n");
		}
		else
		{
			eMovie_getNombre(pAuxeMovie, nombre);
			printf("\nNOMBRE CAMBIADO\n");
		}
    break;
	case 2:
		if(!utn_getNumero(&horasTrabajadas, "INGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 1, eMovie_HORA_MAX,3)
				&& eMovie_setHorasTrabajadas(pAuxeMovie, horasTrabajadas))
		{
			printf("\nLAS HORAS TRABAJADAS NO FUERON CAMBIADAS\n");
		}
		else
		{
			eMovie_getHorasTrabajadas(pAuxeMovie, &horasTrabajadas);
			printf("\nHORAS TRABAJADAS CAMBIADAS\n");
		}
    break;
	case 3:
		if(!utn_getNumero(&sueldo, "INGRESE EL NUEVO SUELDO: ", "\nERROR", 1, eMovie_SUELDO_MAX,3)
				&& eMovie_setSueldo(pAuxeMovie, sueldo))
		{
			printf("\nEL SUELDO NO FUE CAMBIADO\n");
		}
		else
		{
			eMovie_getSueldo(pAuxeMovie, &sueldo);
			printf("\nSUELDO CAMBIADO\n");
		}
    break;
	}

	return *pAuxeMovie;

}
int eMovie_compareByID(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eMovie* pAuxeMovie1 = (eMovie*)pThis1;
    eMovie* pAuxeMovie2 = (eMovie*)pThis2;

    if(pAuxeMovie1 != NULL && pAuxeMovie2 != NULL)
    {
        resultado = pAuxeMovie1->id - pAuxeMovie2->id;

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

int eMovie_compareBynombre(void* pThis1, void* pThis2)
{
    int comparar;
    eMovie* pAuxeMovie1 = (eMovie*)pThis1;
    eMovie* pAuxeMovie2 = (eMovie*)pThis2;

    if(pAuxeMovie1 != NULL && pAuxeMovie2 != NULL)
    {
    	utn_getMayusMin(pAuxeMovie1->nombre, eMovie_NOMBRE_MAX);
    	utn_getMayusMin(pAuxeMovie2->nombre, eMovie_NOMBRE_MAX);
        comparar = strcmp(pAuxeMovie1->nombre, pAuxeMovie2->nombre);
    }

    return comparar;
}

int eMovie_compareByhorasTrabajadas(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eMovie* pAuxeMovie1 = (eMovie*)pThis1;
    eMovie* pAuxeMovie2 = (eMovie*)pThis2;

    if(pAuxeMovie1 != NULL && pAuxeMovie2 != NULL)
    {
        resultado = pAuxeMovie1->horasTrabajadas - pAuxeMovie2->horasTrabajadas;

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

int eMovie_compareBysueldo(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eMovie* pAuxeMovie1 = (eMovie*)pThis1;
    eMovie* pAuxeMovie2 = (eMovie*)pThis2;

    if(pAuxeMovie1 != NULL && pAuxeMovie2 != NULL)
    {
        resultado = pAuxeMovie1->sueldo - pAuxeMovie2->sueldo;

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
