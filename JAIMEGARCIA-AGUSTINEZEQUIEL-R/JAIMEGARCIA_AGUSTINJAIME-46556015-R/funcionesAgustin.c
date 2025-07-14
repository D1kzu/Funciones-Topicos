#include "funciones.h"

int CrearTDA(TDAPalabra* tda)
{
    tda->palabra=malloc(TAM_PALABRA*sizeof(char));
    if(!(tda->palabra))
        return 0;
    tda->ce=0;
    tda->tam=TAM_PALABRA;
    tda->cant_max=16000;
    return 1;
}
void DestruirTDA(TDAPalabra* tda)
{
    tda->ce=0;
    tda->tam=0;
    tda->palabra=0;
    free(tda->palabra);
}
int voynich(const char* nombre,Tpalabra* palabra,TDAPalabra* tda)
{
    FILE* pf=fopen(nombre,"rt");
    if(!pf)
        return TODO_MAL;
    char linea[TAM_LINEA];

    while(fgets(linea,TAM_LINEA-1,pf))
    {
        ParsearLinea(linea,palabra,tda);
    }
    fclose(pf);
    return TODO_BIEN;
}

void ParsearLinea(char* linea,Tpalabra* palabra,TDAPalabra* tda)
{
    char* aux;
    aux=strrchr(linea,'\n');
    if(aux)
        *aux='\0';
    aux=strrchr(linea,'.');
    if(!aux)
        return;
    while(aux)
    {

        if(Signo(aux+1))
            GuardarPalabra(aux+1,palabra,tda);
        *aux='\0';
        aux=strrchr(linea,'.');

    }

    if(Signo(linea))
        GuardarPalabra(linea,palabra,tda);
}

int Signo(const char* aux)
{
    char* aux2=(char*)aux;
    while(*aux2)
    {
        if(*aux2=='?')
            return TODO_MAL;
        aux2++;
    }
    return TODO_BIEN;
}
int cmpString(const void* aux,const void* palabra)
{
    int result;
    char* aux2=(char*)aux;
    char* palabra2=(char*)palabra;
    while(*aux2 && *palabra2)
    {
        result=*aux2-*palabra2;
        if(result!=0)
            return 1;
        aux2++;
        palabra2++;
    }
    if(!*aux2 && !*palabra2)
        return 0;
    return 1;
}
int Busqueda(Tpalabra* palabra,TDAPalabra* tda,int cmp(const void*,const void*))
{
    Tpalabra* aux=palabra;
    for(int i=0; i<tda->ce; i++)
    {
        if(cmp((aux+i)->palabra,tda->palabra)==0)
            return i;
    }
    return -1;
}
void InsertarFinal(Tpalabra* palabra,TDAPalabra* tda)
{
    /*if(tda->ce==tda->cant_max)
    {
        aux=realloc(palabra,(TAM_MAX*sizeof(Tpalabra))*TAM_MAX);
        if(!aux)
            {
                printf("AAAAAAAA");
                return;
            }
        palabra=aux;
        tda->cant_max+=TAM_MAX;

    }*/
    strcpy((palabra+tda->ce)->palabra,tda->palabra);
    (palabra+tda->ce)->apariciones=1;
}
void GuardarPalabra(char* aux,Tpalabra* palabra,TDAPalabra* tda)
{
    int pos;
    strcpy(tda->palabra,aux);
    pos=Busqueda(palabra,tda,cmpString);
    if(pos==-1)
    {
        ///strcpy(palabra->palabra,tda->palabra);
        InsertarFinal(palabra,tda);
        (tda->ce)++;
    }
    else
        ((palabra+pos)->apariciones)++;


}

void OrdenarMayor(Tpalabra* palabra,int ce,int tam,int cmp(const void*,const void*))
{
    qsort(palabra->palabra,ce,tam,cmp);
}
int CantTDA(TDAPalabra* tda)
{
    return tda->ce;
}
