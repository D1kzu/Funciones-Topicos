#include <stdio.h>
#include <stdlib.h>
#include "FunGenericas.h"
int cmpInt(const void* elem1,const void* elem2)
{
    Templeado* e1=(Templeado*)elem1;
    int* e2=(int*)elem2;
    return (e1->dni)- *e2;
}
int main()
{
    Templeado empleado[5]={{1,"Jorge",1000},{10,"Pepe",23.49},{2,"Agustin",89.00},{15,"K1ng",120},{100,"Natalia",39}};
    int buscado=2;
    //ord_gen(empleado,5,sizeof(Templeado),cmpInt);
    int pos=m_search(empleado,&buscado,5,sizeof(Templeado),cmpInt);
    if(!pos)
        printf("no se encontro el elemento");
    else
        printf("Se encontro a %s",empleado[pos].nombre);
    for(int i=0;i<5;i++)
        printf("\n%d  %s  %lf",empleado[i].dni,empleado[i].nombre,empleado[i].sueldo);
    return 0;
}
