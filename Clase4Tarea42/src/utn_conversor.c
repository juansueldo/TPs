
#include <stdio.h>
#include <stdlib.h>

float pasaje (float centigrado)
{
    float resulFarenheit;
    resulFarenheit = (centigrado * 1.8) + 32;

    return resulFarenheit;
}
float pasaje2 (float farenheit)
{
    float resulCentrigrados;
    resulCentrigrados = (farenheit-32) /1.8;

    return resulCentrigrados;
}
