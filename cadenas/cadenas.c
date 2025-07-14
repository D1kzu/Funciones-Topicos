#include "cadenas.h"
int EsPalindromox(const char* s1)
{
    const char* si=s1;
    const char* sf=s1;
    while(sf)
    {
        sf++;
    }
    sf--;
    while(si<=(sf) && ((MAYUS(*si))==(MAYUS(*sf))))
    {
        si++;
        sf--;
        (*si)==' '?si++:si;
        (*sf)==' '?sf--:sf;
    }
    if((si)>=sf)
    {
        return 1;
    }
    else
        return 0;

}

int mstrcmp(const char* s1,const char* s2)
{
    while((*s1)&&(*s2) && ((*s1)==(*s2)))
    {
        s1++;
        s2++;
    }
    return ((*s1)-(*s2));
}

int mstrstr(const char* s1,const char* s2)
{
    while(*s1)
    {
        while((*s1)==(*s2) && (*s2))
        {
            s2++;
        }
        s1++;
    }
    return s1-s2;
}

int ProximaPalabra(char* cad,char** ini)
{
    int CantLetras=0;
    EliminarEspacio(ini);
    cad=*ini;
    while( (**ini) && ESLETRA((**ini)))
    {
        CantLetras++;
        (*ini)++;
    }
    EliminarEspacio(ini);
    return CantLetras;
}

void MostrarCadena(char* cad,int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%c",*cad);
        cad++;
    }
    printf("\n");
}

void EliminarEspacio(char** ini)
{
    while( (**ini) && !ESLETRA((**ini)))
    {
        (*ini)++;
    }
}

void* my_Memmcpy(void* destino,const void* origen,size_t cdesp)
{
    int i;
    //char* ini=(char*)destino;
    for(i=0; i<cdesp; i++)
    {
        *(char*)destino=*(char*)origen;
        (char*)destino++;
        (char*)origen++;
    }
    //destino=ini;
    return destino;
}

void* my_Memmove(void* destino,const void* origen, size_t cdesp)
{
    //char* ini=destino;
    int i;
    void* aux=malloc(cdesp);
    char* ini=(char*)destino;

    strcpy((char*)aux,(char*)origen);
    for(i=0; i<cdesp; i++)
    {
        *(char*)destino=*(char*)aux;
        destino++;
        aux++;
    }
    aux-=cdesp;
    free(aux);
    return ini;

}

