#include <stdlib.h>
#include "vectores.h"

#define TAM 5

int main()
{
    int i;
    int vec[TAM];
    int ce = 0;
    int pos=1;
    int vecIns[] = {11,3,1,15,5,16,20,10,11,8};
    for(i=0;i<sizeof(vecIns)/sizeof(int);i++){
        InsertarPosicion(vec,&ce,vecIns[i],pos,TAM);
        pos++;
    }
    MostrarVector(vec, ce);
    return 0;
}
