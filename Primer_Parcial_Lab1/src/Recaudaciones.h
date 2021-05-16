
#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

#include "Contribuyente.h"
#define ARBA 1
#define IIBB 2
#define GANANCIAS 3

#define CANT 50
#define CANT_TIPO 3


typedef struct {
	int idContribuyente;
	int mes;
	int idTipo;
	int idRecaudacion;
	int idEstado;
	float importe;
	int isEmpty;
} eRecaudacion;

typedef struct {
	int idTipo;
	char descripcion[MAX_CHARS_CADENAS];
} eTipo;

typedef struct {
	int idEstado;
	char detalleEstado[MAX_CHARS_CADENAS];
} eEstado;

/*
 * @brief recibe una estructura y la inicializa
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int eRecaudacion_inicializar (eRecaudacion arrayRecaudacion[],int tam);
/*
 * @brief recibe una estructura y la inicializa
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int eTipo_inicializar (eTipo arrayTipo[],int cant);
/*
 * @brief Obtiene el tipo de recaudacion ingresada por el usuario
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 * @param tipo id del tipo ingresado por el usuario
 * @return retorna cero en caso de exito
 */
int eRecaudacion_obtenerNombre (eTipo arrayTipo[],int cant,int tipo,char detalle[20]);
/*
 * @brief recorre la estrucutra en busca de un campo libre
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @return retorna cero en caso de que el campo esta vacio
 */
int eRecaudacion_buscarLibre (eRecaudacion arrayRecaudacion[],int tam);
/*
 * @brief recorre la estrucutra, busca que el id ingresado coincida con el que se busca
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @para id que se ingresa para comprar
 * @return retorna cero en caso de coincidencia
 */
int eRecaudacion_buscarId (eRecaudacion arrayRecaudacion[],int tam,int id);
/*
 * @brief pide al usuario el ingreso del id del contribuyente, si coincide con un id existente,
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @return auxiliar donde se cargaron los datos ingresados por el usuario
 */
eRecaudacion eRecaudacion_cargar (eContribuyente arrayContribuyente[], int cant);
/*
 * @brief carga en la estructura arrayRecaudacion los datos ingresados por el usuario
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param pIdContador puntero donde se dejara el id de la recaudacion
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @return retorna cero en caso de que se cargaran todos los datos
 */
int eRecaudacion_alta (eRecaudacion arrayRecaudacion[], int tam, int *pIdContador, eContribuyente arrayContribuyente[], int cant);
/*
 * @brief modifica la estructura arrayRecaudacion, con los nuevos datos ingresados por el usuario
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que se modificaran los datos
 */
int eRecaudacion_modificar (eRecaudacion arrayRecaudacion[], int tamanio);
/*
 * @brief muestra un contribuyente y el tipo de recaudacion
 * @param arrayRecaudacion estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 */
void eRecaudacion_mostrarUno (eRecaudacion arrayRecaudacion[],int tamanio, eTipo arrayTipo[], int cant);
/*
 * @brief muestra todos los contribuyentes ingresados por el usuario y el tipo de recaudacion
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 * @return retorna cero en caso de que hayan empleados a mostrar
 */
int eRecaudacion_mostrarTodos (eRecaudacion arrayRecaudacion[],int tamanio, eTipo arrayTipo[], int cant);

//int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
int eRecaudacion_cambiarEstadoSaldar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
/*Se pedirán los siguientes datos: ID
de contribuyente, mes, tipo (1-ARBA, 2-IIBB, 3-GANANCIAS) e importe. Se generará
automáticamente un identificador numérico (comenzando en 100) para la recaudación y se
imprimirá en pantalla.
*/
#endif /* RECAUDACIONES_H_ */
