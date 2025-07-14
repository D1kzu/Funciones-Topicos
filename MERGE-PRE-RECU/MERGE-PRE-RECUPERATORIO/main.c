#include "cabeceras.h"
#define LOTEA "loteA.txt"
#define LOTEB "loteB.txt"

int cmpID(const void* elem1,const void* elem2)
{
    ProductoA* prod=(ProductoA*)elem1;
    ProductoB* compra=(ProductoB*)elem2;
    return prod->id_producto-compra->id_producto;
}
int main()
{
    crearLoteA();
    crearLoteB();

    Merge(LOTEA,LOTEB,cmpID);
    return 0;
}
