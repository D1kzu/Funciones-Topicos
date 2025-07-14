#include "PunteroaFuncion.h"

int Menu(const char* mensaje,const int* opciones,int cant,int Busqueda(void*,void*,int))
{
    int op;
    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("\n %d",&op);
    }
    while(Busqueda((int*)opciones,&op,cant)==-1);
    return op;
}

int IngresoVFloat(float* vec,int cant)
{
    float dato;
    int i=0;
    float* ini=vec;
    if(!vec)
        return 0;
    printf("\n Ingrese el valor a insertar (-1 para cortar)");
    scanf("%f",&dato);
    while(dato!=-1 && i<cant)
    {
        *vec=dato;

        i++;
        if(i<cant)
        {
            printf("\n Ingrese el valor a insertar (-1 para cortar)");
            scanf("%f",&dato);
            vec++;
        }


    }
    vec=ini;
    //MostrarVector(vec,i);
    return i;
}
void OrdenamientoSeleccion(int* aux,int ce)
{
    int* i;
    int* ult=aux+ce-1;
    int* menor;
    for(i=aux; i<ult; i++)
    {
        menor=buscarmenor(i,ult);
        intercambiar(menor,i);


    }


}

void OrdenamientoInsercion(int* aux,int ce)
{
    int j,i;
    int val;
    for(i=1;i<ce;i++)
    {
        val=*(aux+i);
        j=i-1;
        while(j>=0 && val<*(aux+j))
        {
            *(aux+j+1)=*(aux+j);
            j--;
        }
        *(aux+j+1)=val;
    }
}

void intercambiar(int* menor,int* i)
{
    int atemp=*menor;
    *menor=*i;
    *i=atemp;
}
int* buscarmenor(int* inicio,int* fin)
{
    int* m=inicio;
    for(int* j=inicio+1; j<=fin; j++)
    {
        if(*j<*m)
            m=j;
    }
    return m;
}
void MostrarVector(const int *vec,int ce)
{
    int i;
    for(i=0; i<ce; i++)
    {
        printf("%d\n",*vec);
        vec++;
    }


}
void* Map(void* emp,unsigned ce, unsigned tdato,void* buscado,void* Busqueda(void*,void*))
{
    void* ini=emp;
    int i=0;
    void* result=Busqueda(emp,buscado);
    while(result==NULL && i<ce)
        {result=Busqueda(emp,buscado);
            i++;
         emp+=tdato;
        }

    emp=ini;
    return result;
}

