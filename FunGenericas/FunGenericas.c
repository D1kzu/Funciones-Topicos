#include "FunGenericas.h"


int m_search(const void* c1,const void* buscado,size_t ce,size_t tam,int cmp(const void*,const void*))
{
    size_t i=0;
    while(i<ce)
    {
        if(cmp(c1,buscado)==0)
            return i;
        i++;
        c1+=tam;
    }
    return 0;
}
void intercambio(void* min,void* c1,size_t tam)
{
   char aux;
   char* aux_min=(char*)min;
   char* aux_c1=(char*)c1;
    int i=0;
    while(i<tam)
    {
        aux=*aux_min;
        *aux_min=*aux_c1;
        *aux_c1=aux;
        aux_min++;
        aux_c1++;
        i++;
    }


}
void* Buscarmenor(const void* c1,size_t ce,size_t tam,int cmp(const void*,const void*))
{
    void* min=(void*)c1;
    for(int i=1;i<ce;i++)
    {
        if(cmp(c1+i*tam,min)<0)
            min=((void*)c1+i*tam);
    }
    return min;
}


void ord_gen(void* c1,size_t ce,size_t tam,int cmp(const void*,const void*))
{
    size_t i=0;
    void* min;
    for(i=0;i<ce;i++)
    {
        min=Buscarmenor(c1+i*tam,ce-i,tam,cmp);
        intercambio(min,(c1+i*tam),tam);
    }


}
