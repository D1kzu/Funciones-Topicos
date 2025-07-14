#include "PunteroaFuncion.h"
#include <stdio.h>
#include <stdlib.h>

#define MSJ1 "USTED A ELEGIDO EL 1ER MENSAJE"
#define MSJ2 "USTED A ELEGIDO EL 2ER MENSAJE"
#define MSJ3 "USTED A ELEGIDO EL 3ER MENSAJE"
#define MSJ4 "USTED A ELEGIDO EL 4ER MENSAJE"
void* BusquedaTemp(void* cad,void* buscado)
{
    Temp* aux=(Temp*)cad;
    Temp* pos=NULL;
        if((aux->cod)==*(int*)buscado)
            pos=aux;
    return pos;
}
int main()
{
    /// EJ°1
    /*int opciones[]={1,2,3,4,5};
    int res;
    int cant=sizeof(opciones)/sizeof(int);
    do{
    res=Menu(MSJ,opciones,cant,BusquedaInt);
    switch(res)
    {
        case 1: printf("%s\n",MSJ1); break;
        case 2: printf("%s\n",MSJ2); break;
        case 3: printf("%s\n",MSJ3); break;
        case 4: printf("%s\n",MSJ4); break;
    }
    }while(res!=5);
    return 0;*/
    /// EJ°2
    /*float* vec=malloc(TAM*sizeof(float));
    int i=IngresoVFloat(vec,TAM);
        printf("\n\n Ingreso Correcto: %d elementos cargados",i);
        free(vec);*/
    ///EJ BUSQUEDASELECCION
    /*int emp[TAM]={1,2,50,51,40};
    int dato=4;
    int* result=Map(emp,TAM,sizeof(Temp),&dato,BusquedaTemp);
    if(result==NULL)
        printf("\n Codigo no encontrado");
    else
        printf("\n Direccion:%p valor:%d",result,*result);*/
    ///EJ ORDENAMIENTOINSERCION
    /*int aux[TAM]={103,914,12,312,2};
    OrdenamientoInsercion(aux,TAM);
    MostrarVector(aux,TAM);*/
    return 0;
}


