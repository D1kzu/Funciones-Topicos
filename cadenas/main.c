#include "cadenas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1024
#define MAX(x,y) (x>y)?x:y
int main()
{
   /* char c1[]="   hola a      todos";
    char* ini=c1;
    while(ProximaPalabra(c1,&ini))
    {
        MostrarCadena(ini,strlen(ini));
    }
    */
    /*char origen[TAM]="hola como estas";
    char* destino=(origen);

    my_Memmove(destino+2,origen,strlen((MAX(origen,destino)))+1);//+1 ya que strlen no contempla el '\0'
    printf("%s",destino);
    */
    ///EJEMPLO MATOI Y MATOF
    /*char aux[]="-12+3-4A.99";
    printf("RESULTADO: %lf",matof(aux));
    */

    ///EJEMPLO STRSTR
    char cad1[]="hola a todos";
    char cad2[]="a";
    printf("%s",mstrstr(cad1,cad2));
    return 0;
}
