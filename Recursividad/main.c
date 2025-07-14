#include <stdio.h>
#include <stdlib.h>
#include "recursividad.h"

int cmpINT(const void* c1,const void* c2)
{
    int* e1=(int*)c1;
    int* e2=(int*)c2;

    return  *e1-*e2; /// HACE (VEC+MEDIO)-BUSCADO

}
int main()
{
    /*int vec[10]={10,20,30,40,50,60,70,80,90,100};
    int buscado=70;
    void* resultado=Rbinaria(vec,&buscado,10,sizeof(int),cmpINT);
    if(resultado!=NULL)
        printf("se encontro el elemento %d",*(int*)resultado);
    else
        printf("No se encontro el elemento a buscar");*/

    char cadena[]="aza";
    char* fin=cadena+strlen(cadena);
    if(Rpalindromo(cadena,fin)!=0)
        printf("LA CADENA ES PALINDROMO");
    else
        printf("LA CADENA NO ES PALINDROMO");
    return 0;
}
