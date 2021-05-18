
#ifndef INFORMES_H_
#define INFORMES_H_

#include "Recaudaciones.h"
#include "Contribuyente.h"

/*
 *@brief Muestra los datos del contribuyente que en caso que el id de contribuyente coincida con la reaudacion
 *@param arrayRecaudacion estructura que incluye las recaudaciones
 *@param tam cantidad de elementos
 *@param arrayContribuyente estructura que incluye los contribuyentes
 *@param cant cantidad de elementos
 *@param *auxId puntero que recibe el id a comparar
 *@return retorna cero si conicide el id y se muestra en pantalla los datos del contribuyente
 */
int informe_ContribuyentesIdRecaudaciones (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, int* auxId);

int informe_motrarTodos (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
/*
 * @brief Pide al usuario el ingreso del idRecaudacion la cual se va a cambiar el estado, y obtiene el id a modificar
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param arrayTipo estructura que incluye los tipos de recaudaciones
 * @param cantTipo cantidad de elementos
 * @param *indexId puntero que recibe el id
 * @return retorna cero en caso de que el id ingresado por el usuario sea valido
 */
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo, int* indexId);
/*
 * @brief Pregunta al usuario si quiere cambiar el estado de la recaudacion, si ingresa 's' modifica el estado
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param arrayTipo estructura que incluye los tipos de recaudaciones
 * @param cantTipo cantidad de elementos
 * @return retorna cero en caso de que el estado se cambio a refinanciar
 */
int eRecaudacion_estadoRefinanciar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
/*
 * @brief Pregunta al usuario si quiere cambiar el estado de la recaudacion, si ingresa 's' modifica el estado
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param arrayTipo estructura que incluye los tipos de recaudaciones
 * @param cantTipo cantidad de elementos
 * @return retorna cero en caso de que el estado se cambio a saldado
 */
int eRecaudacion_estadoSaldado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
/*
 * @brief Obtiene el estado de recaudacion ingresada por el usuario
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 * @param estado id del estado ingresado por el usuario
 * @param detalle cadena que guarda el estado
 * @return retorna cero en caso de exito
 */
int eRecaudacion_obtenerNombreEstado (eEstado arrayEstado[],int cant,int estado,char detalle[20]);

/*
 * @brief Muestra al usuario los contribuyentes y pide el ingreso del ID del contribuyente a dar de baja, da la baja del contribuyente y sus recaudaciones
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param cant cantidad de elementos
 * return retorna cero si se dio la baja
 */
int eInforme_baja (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant);
int mostrarTodos(eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
int eInforme_baja (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant);
int mostrarSaldados (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
#endif /* INFORMES_H_ */
