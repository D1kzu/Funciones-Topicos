#include "MemoriaDinamica.h"

int CrearVector(int var)
{
    int i;
    int* ini;
    int* vec=malloc(sizeof(int)*var);
    ini=vec;
    if(!vec)
    { printf("\nNo se pudo reservar memoria");
        return 0;}
    else
        {for(i=0;i<var;i++)
           {
               *vec=3+i;
               vec++;
           }
           vec=ini;
           MostrarVector(vec,var);
           free(vec);
        }

    return 1;
}

void MostrarVector(const int* vec,int var)
{
    int i;
    for(i=0;i<var;i++)
    {
        printf("%d\n",*vec);
        vec++;
    }

}

int CrearVectorEstructura(Tmio** mio)
{
    int i;
    *mio=malloc(sizeof(Tmio)*3);
    Tmio* ini=*mio;
    if(!mio)
        return 0;

    for(i=0;i<2;i++)
    {
        printf("\n Ingrese cadena:");
        gets((*mio)->cad);
        printf("\n Ingrese entero,flotante y caracter:");
        scanf("%d/%f/%c",&(*mio)->entero,&(*mio)->flotante,&(*mio)->caracter);
        fflush(stdin);
        (*mio)++;
    }
    *mio=ini;
    return 1;
}

void MostrarEstructura(const Tmio* mio,int var)
{
    for(int i=0;i<var;i++)
    {
        printf("\n %s | %d | %f | %c ",mio->cad,mio->entero,mio->flotante,mio->caracter);
        mio++;
    }
}

char* copiaCadena(const char* cad)
{
    char* cad2=malloc(strlen(cad)+1);
    char* ini;
    if(!cad2)
    {
        return NULL;
    }
    ini=cad2;
    while(*cad)
    {
        *cad2=*cad;
        cad++;
        cad2++;
    }
    *cad2=*cad; /// EL FREE SE REALIZA EN EL MAIN, ES POR ESO QUE STRCPY NO UTILIZA MEMORIA DINAMICA
    return ini;
}

void* CopioCosas(void* elemento,unsigned tam)
{
    unsigned i=0;
    void* aux=malloc(tam);
    if(!aux)
        return NULL;
    void* ini=aux;
    while(i<tam)
    {
        *(char*)aux=*(char*)elemento;
        aux++;
        elemento++;
        i++;
    }

    return ini;

}

void CopiarCosasPF(void* elemento,unsigned tam)
{

}


void MostrarInt(void* elem,unsigned ce)
{
    int* e=(int*)elem;
    for(unsigned i=0;i<ce;i++)
    {
        printf("\n%d",*e);
        e++;
    }
    printf("\n");
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
void DestruirMatrizDinamica(float** mat,int ce)
{
    int i=0;
    if(mat)
    {
      while(i<ce)
      {
          free(*(mat+i));
          i++;
      }
      free(mat);
    }
}
float** CrearMatrizDinamica(int cc,int cf)
{
    float** mat=malloc(cf*sizeof(float*));
    float** ini=mat;
    int i=0;
    if(!mat)
        return NULL;

    while(i<cf)
    {
        *mat=malloc(cc*sizeof(float));
        if(!*mat)
        {
            DestruirMatrizDinamica(ini,i);
            return NULL;
        }
        i++;
        (mat)++;
    }
    return ini;

}
void InicializarMatriz(float** mat,int cc,int cf)
{
    int i,j;
    float** ini=mat;
    for(i=0;i<cc;i++)
    {
        for(j=0;j<cf;j++)
            mat[i][j]=0;
    }
    mat=ini;
}


