#include "cadenas.h"

#define ES_NUMERO(x) (x>='0' && x<='9')?1:0
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

char* mstrstr(const char* s1,const char* s2)
{
    char* aux=NULL;
    int band=0;
    if(!*s2)
        return (char*)s1;
    while(*s1)
    {
        while((*s1)==(*s2) && (*s2))
        {
          if(band==0)
            {aux=(char*)s1;band=1;}
            s2++;
            s1++;
        }
          band=0;
        s1++;
    }
    return aux;
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
    void* ini=destino;

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

int matoi(const char* cad)
{
    int entero,signo=1;
    while(*cad!='\n' && *cad!='\0')
        {
            if(*cad=='-')
                signo=-1;
            else
                signo=1;
            if(ES_NUMERO(*cad)==1)
            {
              entero=((*cad)-'0')+entero*10;
            }
            cad++;
        }
    return signo*entero;

}

double matof(const char* cad)
{
    double entero=0;
    double signo=1,decimal=0,fraccion=0,divisor=1;
    if(*cad=='-')
        signo=-1;

     while (*cad != '\n' && *cad != '\0') {
        if (*cad == '.') {
            decimal = 1;
            cad++;
        }

        if (ES_NUMERO(*cad)) {
            if (!decimal) {
                entero = entero * 10 + (*cad - '0');
            } else {
                fraccion = fraccion * 10 + (*cad - '0');
                divisor *= 10;
            }
        }

        cad++;
    }
    return signo * (entero + fraccion / divisor);;
}
