#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define NOM_ARCH "voynich.txt"


int cmpCont(const void* elem1, const void* elem2)
{
    Tpalabra* pri = (Tpalabra*)elem1;
    Tpalabra* seg = (Tpalabra*)elem2;
    return seg->apariciones - pri->apariciones;
}
int main()
{
    Tpalabra* palabra=malloc(16000*sizeof(Tpalabra));
    TDAPalabra tda;
    int ce=0;
    if(!CrearTDA(&tda))
        return 0;
    if(!palabra)
        return 0;
    if(!voynich(NOM_ARCH,palabra,&tda))
        printf("OCURRIO UN ERROR");
    else
        printf("SE PUDO ABRIR EL ARCHIVO");
    ce=CantTDA(&tda);
    OrdenarMayor(palabra,ce,sizeof(Tpalabra),cmpCont);
    for(int i=0;i<10;i++)
    {
        printf("\n%s aparecio %d",(palabra+i)->palabra,(palabra+i)->apariciones);
    }
    DestruirTDA(&tda);
    free(palabra);
    return 0;
}
