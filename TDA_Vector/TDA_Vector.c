#include "TDA_Vector.h"


int CrearVector(Vector* v,size_t tam)
{
    v->vec=calloc(TAM_BASE,tam);
    if(!v->vec)
        return 0;
    v->ce=0;
    v->tam=tam;
    v->tmax=TAM_BASE;
    return 1;
}

void DestruirVector(Vector* v)
{
    v->ce=0;
    v->tam=0;
    v->tmax=0;
    free(v->vec);

}


void* InsertarFinal(Vector* v,void* dato)
{
    void* pos=v->vec+(v->ce*v->tam);
    if(v->tmax==v->ce)
    {
        if(!redimensionar(v,v->tam))
            return NULL;
    }
    memcpy(pos,dato,v->tam);
    (v->ce)++;
    return v;
}

void* InsertarPos(Vector* v,void* dato,unsigned pos)
{
    void* fin=v->vec+(v->ce*v->tam);
    void* ini=v->vec;
    unsigned posi;
    if(v->tmax==v->ce)
    {
        if(!redimensionar(v,(v->tmax+1)))
            return NULL;

    }
    posi=(v->ce)++;
    while(ini<fin && posi>pos)
    {
        pisar((ini),(ini-1),v->tam);
        posi--;
        ini--;
    }
    memcpy(ini,dato,v->tam);
    (v->ce)++;
    return v;

}
int redimensionar(Vector* v,size_t nuevaCap)
{
    void* nVec= realloc(v->vec,(v->ce + nuevaCap )* v->tam);
    if(!nVec)
        return -1;
    free(v->vec);
    v->vec = nVec;
    v->ce += nuevaCap;
    free(nVec);
    return 0;

}

void pisar(void* dest,void* ini,size_t tam)
{
    int i=0;
    while(i<tam)
    {
        *(char*)ini=*(char*)(dest);
        i++;
    }
}

void InsertarOrden(Vector* vec,void* val, int cmp(void*, void*))
{
    void* ini=vec->vec;
    void* fin;
    if(vec->ce==vec->tam)
    fin=vec->ce==vec->tam?vec->vec+(vec->ce-1)*vec->tam:vec->vec+vec->ce*vec->tam;
    while(ini<fin && cmp(ini,val)<0)
    {
        ini+=vec->tam;
    }
    if(vec->ce==0)
        {
            memcpy(ini,val,vec->tam);
            (vec->ce)++;
            return;
        }
    if(cmp(ini,val)!=0)
        {
            memmove(ini+vec->tam,ini,fin-ini+vec->tam);
            memcpy(ini,val,vec->tam);
            (vec->ce)++;
        }
}
void Map(Vector* v,int accion(void*))
{
    void* aux=v->vec;
    for(int i=0;i<v->ce;i++)
    {
        accion(aux);
        aux+=v->tam;
    }

}
int EliminarElemento(Vector* v,void* val,int cmp(void*,void*))
{
    void*fin;
    void* ini=v->vec;
    if(v->ce==v->tmax)// Me posiciono al final del vector (si ce<tam me posiciono en el primer lugar vacio)
        fin=ini+(v->ce-1)*v->tam;
    else
        fin=ini+v->ce*v->tam;
    int result=cmp(ini,val);
    while(ini<fin && result!=0) // aumento vec mientras sea menor que fin y distinto que el valor a eliminar
    {
        ini+=v->tam;
        result=cmp(ini,val);
    }
    if(result==0) // Si sale por ser igual a val
    {
        while(ini<fin)// El valor del proximo elemento va pisando el valor a eliminar hasta que el vector llega a fin
        {
            memcpy(ini,(ini+v->tam),v->tam);
            ini+=v->tam;
        }
        (v->ce)--;
        return 1;
    }
    else
        return 0;
}

void EliminarPos(Vector* v,int pos)
{
    void* ini=v->vec;
    void* fin;
    if(v->ce<pos)
    {
        printf("No existe la posicion a eliminar");
        return;
    }
    if(v->ce==v->tmax)// Me posiciono al final del vector (si ce<tam me posiciono en el primer lugar vacio)
        fin=ini+(v->ce-1)*v->tam;
    else
        fin=ini+v->ce*v->tam;

    ini+=(pos-1)*v->tam;
    while(ini<fin)
    {
        memcpy(ini,(ini+v->tam),v->tam);
        ini+=v->tam;
    }
    (v->ce)--;

}
