
#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

#include "Contribuyente.h"
#define ARBA 1
#define IIBB 2
#define GANANCIAS 3

#define CANT 50
#define CANT_TIPO 3

typedef struct {
	int idEstado;
	int idRecaudacion;
	char detalleEstado[MAX_CHARS_CADENAS];
} eEstado;

typedef struct {
	int idContribuyente;
	int mes;
	int idTipo;
	int idRecaudacion;
	eEstado arrayEstado;
	float importe;
	int isEmpty;
} eRecaudacion;

typedef struct {
	int idTipo;
	char descripcion[MAX_CHARS_CADENAS];
} eTipo;

/*typedef struct {
	int idEstado;
	char detalle[MAX_CHARS_CADENAS];
} eEstado;*/

int eRecaudacion_inicializar (eRecaudacion arrayRecaudacion[],int tam);
int eTipo_inicializar (eTipo arrayTipo[],int cant);
int eRecaudacion_obtenerNombre (eTipo arrayTipo[],int cant,int tipo,char detalle[20]);
int eRecaudacion_buscarLibre (eRecaudacion arrayRecaudacion[],int tam);
int eRecaudacion_buscarId (eRecaudacion arrayRecaudacion[],int tam,int id);
eRecaudacion eRecaudacion_cargarPantalla (eContribuyente arrayContribuyente[], int cant);
int eRecaudacion_alta (eRecaudacion arrayRecaudacion[], int tam, int *pIdContador, eContribuyente arrayContribuyente[], int cant)         ;
int eRecaudacion_modificar (eRecaudacion arrayRecaudacion[], int tamanio);
int eRecaudacion_modificar (eRecaudacion arrayRecaudacion[], int tamanio);
void eRecaudacion_mostrarUno (eRecaudacion arrayRecaudacion[],int tamanio, eTipo arrayTipo[], int cant);
int eRecaudacion_mostrarTodos (eRecaudacion arrayRecaudacion[],int tamanio, eTipo arrayTipo[], int cant);
int eRecaudacion_buscarId (eRecaudacion arrayRecaudacion[],int tam,int id);
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
/*Se pedirán los siguientes datos: ID
de contribuyente, mes, tipo (1-ARBA, 2-IIBB, 3-GANANCIAS) e importe. Se generará
automáticamente un identificador numérico (comenzando en 100) para la recaudación y se
imprimirá en pantalla.
*/
#endif /* RECAUDACIONES_H_ */
