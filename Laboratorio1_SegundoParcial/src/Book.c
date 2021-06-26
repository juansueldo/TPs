#include "Book.h"

eBook* eBook_new()
{
    eBook* pAuxBook;

    pAuxBook = (eBook*)malloc(sizeof(eBook));

    return pAuxBook;
}
void eBook_delete(eBook *this)
{

    if(this != NULL)
    {
        free(this);
    }
}
eBook* eBook_newParametros(char* id,char* titulo,char* autor, char* precio, char* editorial)
{
    eBook* this = eBook_new();
    void *retorno = NULL;
    if(this != NULL && id != NULL && titulo != NULL && autor != NULL && precio != NULL && editorial != NULL)
    {
    	if(!eBook_setId(this, atoi(id)) &&
    	!eBook_setTitulo(this, titulo) &&
    	!eBook_setAutor(this, autor) &&
		!eBook_setPrecio(this,atof(precio)) &&
    	!eBook_setEditorial(this, atoi(editorial)))
    	{
    		retorno = this;
    	}
    	else
    	{
    		eBook_delete(this);
    		retorno = this;
    	}

    }
    return retorno;
}
int eBook_setId(eBook* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int eBook_getId(eBook* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;

	}
	return retorno;
}
int eBook_setTitulo(eBook* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo, titulo);
        retorno = 0;
    }

    return retorno;
}
int eBook_getTitulo(eBook* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo !=NULL)
    {
        strcpy(titulo, this->titulo);
        retorno = 0;
    }

    return retorno;
}
int eBook_setAutor(eBook* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor != NULL)
    {
        strcpy(this->autor, autor);
        retorno = 0;
    }

    return retorno;
}
int eBook_getAutor(eBook* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor !=NULL)
    {
        strcpy(autor, this->autor);
        retorno = 0;
    }

    return retorno;
}
int eBook_setPrecio(eBook* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}
int eBook_getPrecio(eBook* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}
int eBook_setEditorial(eBook* this,int editorial)
{
    int retorno = -1;

    if(this != NULL && editorial > 0 && editorial < 7)
    {
        this->editorial = editorial;
        retorno = 0;
    }
    return retorno;
}
int eBook_getEditorial(eBook* this,int* editorial)
{
	int retorno = -1;
	if(this != NULL && editorial != NULL)
	{
		*editorial = this->editorial;
		retorno = 0;

	}
	return retorno;
}
int eBook_compareByAutor(void* pThis1, void* pThis2)
{
    int comparar;
    eBook* pAuxBook1 = (eBook*)pThis1;
    eBook* pAuxBook2 = (eBook*)pThis2;

    if(pAuxBook1 != NULL && pAuxBook2 != NULL)
    {
        comparar = strcmp(pAuxBook1->autor, pAuxBook2->autor);
    }

    return comparar;
}
int eBook_getEditorialId (eEditorial* arrayEditorial,int editorialId,char* detalleEditorial)
{
	int retorno = -1;
	if(arrayEditorial != NULL && detalleEditorial != NULL)
	{
		if(arrayEditorial->editorial == editorialId)
		{
			switch(editorialId)
			{
			case 1:
				strcpy(detalleEditorial,"Planeta");
				break;
			case 2:
				strcpy(detalleEditorial,"SIGLO XXI EDITORES");
				break;
			case 3:
				strcpy(detalleEditorial,"Pearson");
				break;
			case 4:
				strcpy(detalleEditorial,"Minotauro");
				break;
			case 5:
				strcpy(detalleEditorial,"Salamandra");
				break;
			case 6:
				strcpy(detalleEditorial,"Penguin books");
				break;
			}
			retorno = 0;
		}
	}

	return retorno;
}
void calcularMonto(void* this)
{
	int editorial;
	float precio;
	float precioDescuento;
	if(this != NULL)
	{
		//Planeta: 20% (si el monto es mayor o igual a $300)
		//* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
		eBook_getEditorial(this, &editorial);
		eBook_getPrecio(this, &precio);

		if(editorial == 1 && precio >= 300)
		{
			precioDescuento = precio - (precio * 0.20);
			eBook_setPrecio(this, precioDescuento);
		}
		if(editorial == 2 && precio <= 200)
		{
			precioDescuento = precio - (precio * 0.10);
			eBook_setPrecio(this, precioDescuento);

		}
	}
}/*
int eBook_setHora(eBook* this,char* horario)
{
    int retorno = -1;

    if(this != NULL && horario != NULL)
    {
        strcpy(this->horario, horario);
        retorno = 0;
    }

    return retorno;
}
int eBook_getHora(eBook* this,char* horario)
{
    int retorno = -1;

    if(this != NULL && horario !=NULL)
    {
        strcpy(horario, this->horario);
        retorno = 0;
    }

    return retorno;
}
int eBook_setCantidad(eBook* this,int cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad >= 0)
	{
		retorno = 0;
		this->cantidad_entradas = cantidad;
	}
	return retorno;
}
int eBook_getCantidad(eBook* this,int* cantidad)
{
	int retorno = -1;
	if(this != NULL && cantidad != NULL)
	{
		retorno = 0;
		*cantidad = this->cantidad_entradas;
	}
	return retorno;
}
int eBook_getDays (eDias* arrayDias,int dia,char* detalleDia)
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

int eBook_setMonto(eBook* this,float monto)
{
	int retorno = -1;
	if(this != NULL && monto >= 0)
	{
		retorno = 0;
		this->monto = monto;
	}
	return retorno;
}
int eBook_getMonto(eBook* this,float* monto)
{
	int retorno = -1;
	if(this != NULL && monto != NULL)
	{
		retorno = 0;
		*monto = this->monto;
	}
	return retorno;
}
int eBook_getMontoGenrado (eBook* this, int dia,int cantidad, float* monto)
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
		eBook_getDia(this, &dia);
		eBook_getCantidad(this, &cantidad);

		if(dia == 1 || dia == 2 || dia ==3)
		{
			monto = 240 * cantidad;
			eBook_setMonto(this, monto);
		}
		else
		{
			monto = 350 * cantidad;
			eBook_setMonto(this, monto);
		}
		if(cantidad > 3)
		{
			descuento = monto *0.1;
			monto = monto - descuento;
			eBook_setMonto(this, monto);

		}
	}
}
eBook* eBook_newParametrosInt(int id,char* nombre,int dia, char* horario, int sala, int cantidad, float monto)
{
    void *retorno = NULL;
    eBook* this = eBook_new();
    if( this!=NULL && id > 0 && nombre != NULL && dia >= 0 && horario != NULL && sala > 0 && cantidad > 0 && monto > 0)
    {
    	 if(!eBook_setId(this, id) &&
    	    !eBook_setNombre(this, nombre) &&
    	    !eBook_setDia(this, dia) &&
    		!eBook_setHora(this,horario) &&
    	    !eBook_setSala(this, sala) &&
    		!eBook_setCantidad(this,cantidad)&&
			!eBook_setMonto(this,monto))
    	   {
    	    	retorno = this;
    	   }
    	   else
    	    {
    	    	eBook_delete(this);
    	    	retorno = this;
    	    }

    	    }
    	    return retorno;
}
int eBook_compareBynombre(void* pThis1, void* pThis2)
{
    int comparar;
    eBook* pAuxeBook1 = (eBook*)pThis1;
    eBook* pAuxeBook2 = (eBook*)pThis2;

    if(pAuxeBook1 != NULL && pAuxeBook2 != NULL)
    {
    	utn_getMayusMin(pAuxeBook1->nombre_pelicula, MAX_NOMBRE);
    	utn_getMayusMin(pAuxeBook2->nombre_pelicula, MAX_NOMBRE);
        comparar = strcmp(pAuxeBook1->nombre_pelicula, pAuxeBook2->nombre_pelicula);
    }

    return comparar;
}
void eBook_delete(eBook *this)
{

    if(this != NULL)
    {
        free(this);
    }
}

int eBook_setId(eBook* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int eBook_getId(eBook* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;

	}
	return retorno;
}
int eBook_setNombre(eBook* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}
int eBook_getNombre(eBook* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;
}

int eBook_setHorasTrabajadas(eBook* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
int eBook_getHorasTrabajadas(eBook* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

int eBook_setSueldo(eBook* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}
int eBook_getSueldo(eBook* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}
int eBook_print(eBook* this)
{
    int retorno = -1;
    int id;
    char nombre[eBook_NOMBRE_MAX];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL && eBook_getId(this, &id)==0
    				&& eBook_getNombre(this, nombre)==0
					&& eBook_getHorasTrabajadas(this, &horasTrabajadas)==0
					&& eBook_getSueldo(this, &sueldo)==0)
    {
    	printf("|*******|**********************|*******|************|\n");
    	printf("|   ID  |        NOMBRE        | HORAS |   SUELDO   |\n");
    	printf("|*******|**********************|*******|************|\n");
    	utn_getMayusMin(this->nombre,eBook_NOMBRE_MAX);
    	printf("| %5d | %20s | %5d | %10d |\n",
    		            	id, nombre, horasTrabajadas, sueldo);
        printf("|*******|**********************|*******|************|\n");

        retorno = 0;
    }

    return retorno;
}
eBook eBook_change (eBook* this, int opcion)
{
	eBook* pAuxeBook = this;
	char nombre[eBook_NOMBRE_MAX];
	int horasTrabajadas;
	int sueldo;
	switch(opcion)
	{
	case 1:
		if(!utn_getString(nombre, eBook_NOMBRE_MAX, "INGRESE EL NUEVO NOMBRE: ", "\nERROR", 1,3)
				&& eBook_setNombre(pAuxeBook,nombre))
		{
			printf("\nEL NOMBRE NO FUE CAMBIADO\n");
		}
		else
		{
			eBook_getNombre(pAuxeBook, nombre);
			printf("\nNOMBRE CAMBIADO\n");
		}
    break;
	case 2:
		if(!utn_getNumero(&horasTrabajadas, "INGRESE LAS HORAS TRABAJADAS: ", "\nERROR", 1, eBook_HORA_MAX,3)
				&& eBook_setHorasTrabajadas(pAuxeBook, horasTrabajadas))
		{
			printf("\nLAS HORAS TRABAJADAS NO FUERON CAMBIADAS\n");
		}
		else
		{
			eBook_getHorasTrabajadas(pAuxeBook, &horasTrabajadas);
			printf("\nHORAS TRABAJADAS CAMBIADAS\n");
		}
    break;
	case 3:
		if(!utn_getNumero(&sueldo, "INGRESE EL NUEVO SUELDO: ", "\nERROR", 1, eBook_SUELDO_MAX,3)
				&& eBook_setSueldo(pAuxeBook, sueldo))
		{
			printf("\nEL SUELDO NO FUE CAMBIADO\n");
		}
		else
		{
			eBook_getSueldo(pAuxeBook, &sueldo);
			printf("\nSUELDO CAMBIADO\n");
		}
    break;
	}

	return *pAuxeBook;

}
int eBook_compareByID(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eBook* pAuxeBook1 = (eBook*)pThis1;
    eBook* pAuxeBook2 = (eBook*)pThis2;

    if(pAuxeBook1 != NULL && pAuxeBook2 != NULL)
    {
        resultado = pAuxeBook1->id - pAuxeBook2->id;

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

int eBook_compareBynombre(void* pThis1, void* pThis2)
{
    int comparar;
    eBook* pAuxeBook1 = (eBook*)pThis1;
    eBook* pAuxeBook2 = (eBook*)pThis2;

    if(pAuxeBook1 != NULL && pAuxeBook2 != NULL)
    {
    	utn_getMayusMin(pAuxeBook1->nombre, eBook_NOMBRE_MAX);
    	utn_getMayusMin(pAuxeBook2->nombre, eBook_NOMBRE_MAX);
        comparar = strcmp(pAuxeBook1->nombre, pAuxeBook2->nombre);
    }

    return comparar;
}

int eBook_compareByhorasTrabajadas(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eBook* pAuxeBook1 = (eBook*)pThis1;
    eBook* pAuxeBook2 = (eBook*)pThis2;

    if(pAuxeBook1 != NULL && pAuxeBook2 != NULL)
    {
        resultado = pAuxeBook1->horasTrabajadas - pAuxeBook2->horasTrabajadas;

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

int eBook_compareBysueldo(void* pThis1, void* pThis2)
{
    int comparar;
    int resultado;
    eBook* pAuxeBook1 = (eBook*)pThis1;
    eBook* pAuxeBook2 = (eBook*)pThis2;

    if(pAuxeBook1 != NULL && pAuxeBook2 != NULL)
    {
        resultado = pAuxeBook1->sueldo - pAuxeBook2->sueldo;

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



