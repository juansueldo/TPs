/*
 ============================================================================
 Name        : Juan Sueldo
 Author      :
 Ejercicio 5-2:Pedir el ingreso de 10 números enteros entre -1000 y 1000.
 Determinar:Cantidad de positivos y negativos.Sumatoria de los pares.El mayor de los impares.
 Listado de los números ingresados.Listado de los números pares.
 Listado de los números de las posiciones impares.  Se deberán utilizar funciones y vectores
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int utn_getNumero (int num[], int cantidad, char*mensaje, char*mensajeError, int min, int max);
void utn_getSuma (int num[], int size, int* acumPares);
void utn_getPositivos (int num[],int size,int*pContador );
void utn_getNegativos (int num[],int size,int*pContador);
void utn_getMayor (int num[], int size, int*mayor);
void utn_getOrdenar(int num[], int size);


int main(void) {
	system("cls");
    setbuf(stdout, NULL);
	int numero[MAX];
	int i;
	int validar;
	int acumPares = 0;
	int contPositivos = 0;
	int contNegativos = 0;
	int imparMayor;

	for(i = 0; i < MAX; i++)
	{
		validar = utn_getNumero (numero, i, "Ingrese un numero:\n", "Error. Ingrese un numero:\n", -1000, 1000);
		utn_getSuma (numero,MAX,&acumPares);
		utn_getPositivos (numero,MAX,&contPositivos);
		utn_getNegativos (numero,MAX,&contNegativos);
		utn_getMayor (numero, MAX,&imparMayor);
	}

	if(validar == 0)
	{
    printf("\nLa cantidad de positivos es: %d", contPositivos);
    printf("\nLa cantidad de negativos es: %d", contNegativos);
    printf("\nLa suma de los pares es: %d",acumPares);
    printf("\nLa el mayor de los impares: %d",imparMayor);

    printf("\nEl orden de los numero ingresados es: ");
    for(i = 0; i < MAX; i++)
    {
        printf("%d,",numero[i]);
    }

    printf("\nEl orden de los pares ingresados es: ");
    for(i = 0; i < MAX; i++)
    {
    	utn_getOrdenar(numero,MAX);
        if(numero[i] % 2 == 0)
        {
            printf("%d,",numero[i]);
        }
    }
    printf("\nEl orden de los numeros ingresados en la posicion impar es: ");
    for(i = 0; i < MAX; i++)
        {
    		utn_getOrdenar(numero,MAX);
            if(!(i % 2 == 0))
            {
                printf("%d,",numero[i]);
            }
        }
	}

	return EXIT_SUCCESS;
}
int utn_getNumero (int num[], int cantidad, char*mensaje, char*mensajeError, int min, int max)
{
	int retorno = -1;
	int i = cantidad;
	if(mensaje != NULL && mensajeError != NULL && min <= max)
	{
		printf("%s",mensaje);
		scanf("%d",&num[i]);
		while(num[i] < min || num[i] > max)
		{
			printf("%s",mensajeError);
			scanf("%d",&num[i]);
		}
		retorno = 0;
	}
	return retorno;
}
void utn_getPositivos (int num[],int size,int*pContador )
{
	int contNum = 0;
	int i;
	if(pContador != NULL)
	{
		for(i = 0; i < MAX; i++)
		{
		if(num[i] > 0)
		{
		contNum ++;
		*pContador = contNum;
		}
		}
	}
}
void utn_getNegativos (int num[],int size,int*pContador)
{
	int contNum = 0;
	int i;
	if(pContador != NULL)
	{
		for(i = 0; i < MAX; i++)
		{
		if(num[i] < 0)
		{
		contNum ++;
		*pContador = contNum;
		}
		}
	}
}
void utn_getSuma (int num[], int size, int* acumPares)
{
	int i;
	if(acumPares != NULL)
	{
	*acumPares = 0;
	for(i = 0; i < MAX; i++)
	{
	if(num[i] % 2 == 0)
	{
		*acumPares += num [i];
	}
	}
	}

}
void utn_getMayor (int num[], int size, int*mayor)
{
	int i;
	int max;
	int flag = 1;
	if(mayor != NULL)
	{
	for(i = 0; i < MAX; i++)
	{
	if(num[i] % 2 != 0)
	{
		if(flag == 1 || num[i] > max)
		{
		    max = num[i];
		    *mayor = max;
		    flag = 0;
		}
	}
	}
	}

}
void utn_getOrdenar(int num[], int size)
{
	int i;
	int j;
	int aux;

	 for(i = 0; i < MAX-1; i++)
	 {
		for(j = i+1; j < MAX ;j++)
		{
			if(num[i] > num[j])
		    {
			aux = num[i];
			num[i] = num[j];
			num[j] = aux;
		     }
		 }
	}

}


