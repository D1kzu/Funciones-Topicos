#include <stdio.h>
#include <stdlib.h>
#include "examen.h"
#define MAXLINE 1024

//Descomente la macro RENDIREXAMEN para deshabilitar el metodo desofuscarLineaV2 en favor del metodo
//mi_desofuscarLineaV2 que debe implementar usted.


#define RENDIREXAMEN

#ifdef RENDIREXAMEN
    #define desofuscarLineaV2 mi_desofuscarLineaV2
#endif // EXAMEN

int main()
{
    /*
    Ejercicio Cadenas
    ----------------------
    Mediante el metodo quieroUnaLineaDeTextoOfuscadaV2 adquiera una cita en texto
    afuscada y realice el proceso de "desofuscado" para obtener la frase original.

    Cada palabra (Conjunto de caracteres que responden a isalpha) ha sido ofuscada
    de la siguiente manera:
    1.Se a dado vuelta la palabra
    2.Cada letra ha cambiada mediante la siguiente regla
    Letra origen -> Letra destino

    a->f
    b->e
    c->d
    d->c
    e->b
    f->a



    Algunos consejos:
    .Antes de codificar piense una estrategia de solucion
    .Separe el problema en partes y prueba individualmente cada una si es necesario.

    .
    Nota:
    .Las frases estan en espanol (excepto probablemente una) y son varias, en cada ejecucion puede obtener cualquiera
    aleatoriamente, su desarrollo debera desofuscar cualquiera.

    Disclaimer: Las citas no representan las opiniones de quien formulo el ejercicio :)
    */

    char linea[MAXLINE];

    quieroUnaLineaDeTextoOfuscadaV2(linea);
    printf("Linea original:%s\n", linea);

    desofuscarLineaV2(linea);
    printf("Linea desofuscada:%s\n", linea);

    return 0;
}

