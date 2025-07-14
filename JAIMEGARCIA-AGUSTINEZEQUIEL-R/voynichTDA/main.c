#include <stdio.h>
#include <stdlib.h>
#include "cabeceras.h"

int main()
{
    TDA vec;
    if(voynich(&vec,NOM_ARCH)!=0)
        return -1;

    return 0;
}
