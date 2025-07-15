#include <stdio.h>
#include <stdlib.h>
#include "recursividad.h"

int cmpINT(const void* c1,const void* c2)
{
    int* e1=(int*)c1;
    int* e2=(int*)c2;

    return  *e1-*e2; /// HACE (VEC+MEDIO)-BUSCADO

}
int MostrarEjemplo(void* v)
{
    char aux=*(char*)v;

    printf("%c",aux);
    return 0;
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

    ///EJEMPLO RPALINDROMO
    /*char cadena[]="aza";
    char* fin=cadena+strlen(cadena);
    if(Rpalindromo(cadena,fin)!=0)
        printf("LA CADENA ES PALINDROMO");
    else
        printf("LA CADENA NO ES PALINDROMO");*/

    ///EJEMPLO RMAP
    /*Tejemplo dato[TAM_BASE]={{"Agustin",3,239.99},{"Jose Maita",10,340.95},{"Jorge",1,5000},{"Natalia",11,329.31},{"Cecilia",2,999}};
    char aux[]="cadena auxiliar";
    Rmap(aux,1,Rstrlen(aux),MostrarEjemplo);
    */
    ///EJEMPLO RSTRRCHR
    /*char cadena[]="azazrm";
    printf("%s",Rstrrchr(cadena,'a'));
    */
    ///EJEMPLO RMAPINVERSO
    char aux[]="es palindromo";
    //Tejemplo dato[TAM_BASE]={{"Agustin",3,239.99},{"Jose Maita",10,340.95},{"Jorge",1,5000},{"Natalia",11,329.31},{"Cecilia",2,999}};
    RmapInverso(aux,Rstrlen(aux)+1,sizeof(char),MostrarEjemplo);

    return 0;
}
