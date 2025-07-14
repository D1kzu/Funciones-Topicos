#include "cabeceras.h"


int voynich(TDA* vec,const char* nombre)
{
    FILE* pf=fopen(nombre,"rt");
    if(!pf)
        return -1;
    Tpalabra palabra;
    vec=CrearTDA(&palabra,MIN_TAM,sizeof(Tpalabra));
    if(!vec)
       return -1;
    char linea[MAX_LINEA];
    while(fgets(linea,MAX_LINEA-1,pf))
    {
        ParsearLinea(linea,vec,&palabra);
    }
    return 0;
}

void ParsearLinea(char* linea,TDA* vec,Tpalabra* palabra)
{
    char* aux;
    aux=strrchr(linea,'\n');

    while(*aux)
    {
        *aux='\0';
        aux=strrchr(linea,'.');
        if(Signo(aux+1,'?')==0)
            {
                strcpy(vec->vec,aux+1);
                GuardarPalabra(vec,palabra);
            }
    }
    if(Signo(linea,'?')==0)
    {
        strcpy(vec->vec,linea);
        GuardarPalabra(vec,palabra);
    }

}
int cmpString(const void* elem1,const void* elem2)
{
    char* aux1=(char*)elem1;
    char* aux2=(char*)elem2;

    return strcmp(aux1,aux2);
}
void GuardarPalabra(TDA* vec,Tpalabra* elem)
{
    int pos=Buscar(vec->vec,elem->palabra,vec->ce,cmpString);
    if(pos==-1)
    {
        InsertarFinal(vec->vec,elem,vec->ce);

    }
    else
        ((elem+pos)->apariciones)++;
}

int Buscar(void* vec,void* elem,int ce,int cmp(const void*,const void*))
{
    int i=0;

    while(i<ce)
    {
        if(cmp(vec,elem)==0)
            return i;
        i++;

    }
    return -1;
}
void InsertarFinal(void* vec,Tpalabra* elem,int ce)
{
    char* pvec=(char*)vec;
    strcpy((elem+ce)->palabra,pvec);
    elem->apariciones=1;



}
int Signo(const char* aux,char buscado)
{
    char* aux2=(char*)aux;
    while(*aux2)
    {
        if(*aux2==buscado)
            return -1;
        aux2++;
    }
    return 0;
}

TDA* CrearTDA(Tpalabra* palabra,int min_tam,int tam)
{
    TDA* vec=malloc(sizeof(TDA));
    if(!vec)
        return NULL;
    palabra=malloc(sizeof(Tpalabra)*min_tam);
    if(!palabra)
    {
        free(vec);
        return NULL;
    }
    vec->vec=palabra;
    vec->ce=0;
    vec->tam=tam;
    vec->max_tam=min_tam;
    return vec;
}
