#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBooks);
int controller_ListBooks(LinkedList* pArrayListBooks);
int controller_sort (LinkedList* pArrayListBooks);
int controller_saveAsText(char* path , LinkedList* pArrayListMovies);
#endif /* CONTROLLER_H_ */
