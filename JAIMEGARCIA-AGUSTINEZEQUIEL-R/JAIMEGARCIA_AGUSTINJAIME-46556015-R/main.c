#include "cabeceras.h"

int main()
{
    TDASimVec *sv;
    sv = crearTDA(sizeof(sPalabras));

    if(!voynich(sv))
        printf("\nError al ejecutar la funcion.\n");
    else
    {
        ordenar(sv, cmpCont);
        mostrar(sv);
    }

    destruirTDA(sv);
    return 0;
}
