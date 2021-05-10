

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Validate_OnlyNumberInt(char *pData);
int Validate_OnlyNumberFloat(char *pData);
int Validate_OnlyAlphabet(char *pData);
int Validate_OnlyAlphabetWithSpaces(char *pData);
int getInt(char mensaje[]);
void utn_getNumber(int* pNumero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);



#endif /* BIBLIOTECA_H_ */
