
#ifndef BOOK_H_
#define BOOK_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

#define MAX_NOMBRE 70

typedef struct{
	int id;
	char titulo[MAX_NOMBRE];
	char autor[MAX_NOMBRE];
	float precio;
	int editorial;
}eBook;

typedef struct{
	int editorial;
	char editorialDetalle[MAX_NOMBRE];
}eEditorial;

/** brief Constructor que obtiene el espacio en memoria para los libros
 * @return retorna NULL sino se pudo reservar espacio
 */
eBook* eBook_new();
/** \brief Nueva estructura de Libros ingresando los valores por parametros.
 *
 * @param id parametro que recibe el ID a cargar.
 * @param titulo parametro que recibe el titulo del libro.
 * @param autor  parametro que recibe el nombre del autor.
 * @param precio  parametro que recibe el precio.
 * @param editorial  parametro que recibe la editorial.
 * @return this retorna el Liro con los datos que se recibieron por parametro, en caso contrario retorna NULL.
 *
 */
eBook* eBook_newParametros(char* id,char* titulo,char* autor, char* precio, char* editorial);
/** \brief Libera la memoria que se asingno a un libro
 *
 * @param this direccion de memoria de un Libro.
 *
 */
void eBook_delete(eBook *this);

int eBook_setId(eBook* this,int id);
int eBook_getId(eBook* this,int* id);

int eBook_setTitulo(eBook* this,char* titulo);
int eBook_getTitulo(eBook* this,char* titulo);


int eBook_setAutor(eBook* this,char* autor);
int eBook_getAutor(eBook* this,char* autor);


int eBook_setPrecio(eBook* this,float precio);
int eBook_getPrecio(eBook* this,float* precio);

int eBook_setEditorial(eBook* this,int editorial);
int eBook_getEditorial(eBook* this,int* editorial);

int eBook_compareByAutor(void* pThis1, void* pThis2);

int eBook_getEditorialId (eEditorial* arrayEditorial,int editorialId,char* editorial);

void calcularMonto(void* this);


#endif /* BOOK_H_ */
