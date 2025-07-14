#include "recursividad.h"
#define ES_LETRA(x) (x>96 && x<123)?1:0

int Rfactorial(int num)
{

    if(num==0)
       return 1;
    return num * Rfactorial(num-1);
}

int Rstrlen(const char* cadena)
{

    if(*(cadena)=='\0' || !(cadena))
        return 0;
    return 1 + Rstrlen(cadena+1);
}

char* Rstrchr(const char* cadena,int buscado)
{
    if(*cadena=='\0')
        return NULL;
    if(*cadena==buscado)
        return (char*)cadena;
    return Rstrchr(cadena+1,buscado);
}

char* Rstrrchr(const char* cadena, int buscado)
{
    char* resultado;

    if(*cadena=='\0')
        return NULL;
    resultado=Rstrrchr(cadena+1,buscado);
    if(resultado)
        return resultado;
    if(*cadena==buscado)
        return (char*)cadena;
    else
        return NULL;
}


void* Rbinaria(const void* vec,const void* buscado,size_t ce,size_t tam,int cmp(const void*,const void*))
{
    void* fin=(void*)vec+(ce-1)*tam;
    void* medio=(void*)vec+(ce/2)*tam;
    int comparador;
    if(ce==0 || vec>fin)
        return NULL;
    comparador=cmp(medio,buscado);
    if(comparador==0)
        return medio;
    if(comparador<0)
        return Rbinaria(medio+tam,buscado,(ce/2),tam,cmp);///+TAM PARA NO CONSIDERAR EL ELEMENTO "MEDIO"
    else
        return Rbinaria(vec,buscado,(ce/2),tam,cmp);

}

int Rpalindromo(char* inicio,char* fin)
{
    if(!ES_LETRA(*inicio))
        return Rpalindromo(inicio+1,fin);
    if(!ES_LETRA(*fin))
        return Rpalindromo(inicio,fin-1);

    if(*inicio==*fin)
    {
        if(inicio<fin)
            return Rpalindromo(inicio+1,fin-1);
        else
            return 1;
    }
    return 0;
}
