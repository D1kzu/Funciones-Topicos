#include <stdio.h>
#include <stdlib.h>
#include "TDA_Vector.h"
int cmpInt(void* a,void* b)
{
    Tejemplo* aux1=(Tejemplo*)a;
    Tejemplo* aux2=(Tejemplo*)b;

    return aux1->cod - aux2->cod;

}
int MostrarEjemplo(void* v)
{
    Tejemplo* aux=(Tejemplo*)v;

    printf("\n%s  %d  %lf",aux->nom,aux->cod,aux->sueldo);
    return 0;
}
int main()
{
    Vector aux;
    Tejemplo dato[TAM_BASE]={{"Agustin",3,239.99},{"Jose Maita",10,340.95},{"Jorge",1,5000},{"Natalia",11,329.31},{"Cecilia",2,999}};
    if(!CrearVector(&aux,sizeof(Tejemplo)))
       printf("\n No se pudo reservar memoria");
    else
       {
           for(int i=0;i<TAM_BASE;i++)
            {InsertarOrden(&aux,&dato[i],cmpInt);
            }
       }

        Map(&(aux),MostrarEjemplo);

    EliminarPos(&aux,3);
    Map(&aux,MostrarEjemplo);
        DestruirVector(&aux);
    return 0;
}
