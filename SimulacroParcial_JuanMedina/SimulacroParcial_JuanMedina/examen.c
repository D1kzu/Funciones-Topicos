#include "examen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COL 6
#define FIL 2
#define ES_LETRA(X) ((((X) >= 'A' && (X) <= 'Z')) || ((X) >= 'a' && (X) <= 'z')? 1: 0)

//No me deja ponerla en el Punto C

char* mi_desofuscarLineaV2(char* linea)
{
    char* ini = linea;
    char* fin = linea;
    char aux;
    while(*fin != '\0')
    {
        while((*fin != '\0') && (ES_LETRA(*fin) == 1))//fin de la palabra
            fin++;

        linea = fin;
        fin--;

        ///Dar vuelta la Palabra
        while(fin>=ini)
        {

            if(fin!=ini)
            {
                *fin = BuscarLetras(*fin);
                *ini = BuscarLetras(*ini);
                aux = *fin;
                *fin = *ini;
                *ini = aux;

            }
            else
                *fin = BuscarLetras(*fin);
            fin--;
            ini++;
        }

        fin=linea;

        while((*fin != '\0') && (ES_LETRA(*fin) != 1))//fin de la palabra
            fin++;

        ini=fin;
    }
    return linea;
}

char BuscarLetras(char buscar)
{
    char* letras = "abcdef";
    char* r = strchr(letras, buscar);
    if (!r)
        return buscar;
    else
        return *(letras += (strlen(letras)- 1 - (r - letras)));  // 5 = strlen(letras) - 1
}
