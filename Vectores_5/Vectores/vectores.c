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

void insertarElemOrdenado(int* vec, size_t* ce, size_t tam, int num)
{
    int* fin = vec + *ce;

    if (*ce == tam)
    {
        (*ce)--;
    }

    while (*vec < num)
    {
        vec++;
    }
    while (fin > vec)
    {
        *fin = *(fin-1);
        fin--;
    }

    *fin = num;
    (*ce)++;
}
void InsertarPosicion(int *vec,int *ce,int val,int pos,int TAM)
{
    int *ini=vec;
    int posi=(*ce);
    vec=(*ce)==TAM?vec+(*ce)-1:vec+(*ce);
    while(vec>ini && (posi)>pos)
    {
        *(vec)=*(vec-1);
        posi--;
        vec--;
    }
    *vec=val;
    if((*ce)<TAM)
        (*ce)++;
}

int EliminarPosicion(int *vec,int *ce,int pos,int TAM)
{
    int *fin=(*ce)==TAM?vec+(*ce)-1:vec+(*ce);
    vec+=(pos-1);
    if(pos>(*ce))
        return 0;

    while(vec<fin)
        {
            *vec=*(vec+1);
            vec++;
        }
        (*ce)--;
        return 1;

}

int EliminarPrimero(int *vec,int *ce,int val,int TAM)
{
    int *fin=(*ce)==TAM?vec+(*ce)-1:vec+(*ce);

    while(vec<fin && *(vec)!=val)
    {
        vec++;
    }
    if(*vec==val)
    {
        while(vec<fin)
    {
        *vec=*(vec+1);
            vec++;
    }
    (*ce)--;
    return 1;
    }
    else
        return 0;

}

int EliminarVarios(int *vec,int *ce,int val,int TAM)
{
    int *pl=vec;//Declaro puntero de lectura al inicio del vector
    int *pe=vec;//Declaro puntero de escritura al inicio del vector
    int ce1=*ce;
    int i;

    for(i=0;i<(ce1);i++)//For para iterar en los elementos del vector
    {
        if(*(pl)!=val)//Pregunto si el elemento del vector es distinto al valor a eliminar
        {
            *(pe)=*pl;//Si es distinto le asigna al puntero de escritura la misma direccion que el puntero de lectura
            pe++; //Aumenta la direccion del puntero de lectura para estar en la misma direccion que el puntero de lectura

        }
        else
            (*ce)--;//Si es igual al valor a eliminar decrementa la cantidad de elementos ya que encontro un elemento a eliminar
        pl++;//Sea o no igual al valor al ser un puntero de unicamente lectura avanza su posicion por cada iteracion
    }
    if(ce1!=(*ce))//Pregunto si hubo modificaciones en los elementos del vector, y si los hubo regreso un 1 como signo de que se realizo con exito la eliminacion
        return 1;
    else
        return 0;// Si devuelvo 0 significa que el elemento a eliminar no se encontraba en el vector
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

