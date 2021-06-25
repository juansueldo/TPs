/*
 * Controller.h
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListMovies);
int controller_ListMovies(LinkedList* pArrayListMovies);
int controller_getMontos (LinkedList* pArrayListMovies);
int controller_saveAsText(char* path , LinkedList* pArrayListMovies);
int controller_ListBySala(LinkedList* pArrayListMovies);
#endif /* CONTROLLER_H_ */
