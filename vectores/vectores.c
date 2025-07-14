#include <stdio.h>
#include <stdlib.h>

#include "vectores.h"
void InsertarElemento(int *vec,int *ce,int val,int TAM)
{
    int *ini=vec;

    vec=(*ce)==TAM?vec+(*ce)-1:vec+(*ce);

    while((vec>ini) && *(vec-1)>val)
    {
        *vec=*(vec-1);
        vec--;
    }
    if(*ce==TAM)
      {
        if(*vec>val)
            *vec=val;
      }
      else
        {*ce=*ce+1;
        *vec=val;
        }

}

void InsertarPosicion(int *vec,int *ce,int val,int TAM)
{
    int *ini=vec;
    int posi=0;
    vec=(*ce)==TAM?vec+(*ce)-1:vec+(*ce);
    posi=(*ce);
    while(vec>ini && (posi)>pos)
    {
        posi--;
        vec--;
    }
    *vec=val;

}

void MostrarVector(int *vec,int ce)
{
        int i;
    for(i=0;i<ce;i++)
    {
        printf("%d\n",*vec);
        vec++;
    }

}

