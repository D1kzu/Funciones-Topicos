#include "vectores.h"
#include <stdlib.h>
#define TAM 5
int main()
{
    int val[TAM]={2,19,9,5,5};
    int vec[TAM]={};
    int i=0;
    while(i<TAM)
    {
      InsertarElemento(vec,&i,val[i],TAM);
    }
    MostrarVector(vec,i);
    return 0;
}
