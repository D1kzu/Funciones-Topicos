#ifndef CABECERAS_H_INCLUDED
#define CABECERAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINEA 100
#define MIN_ELEM 3


typedef struct
{
    char nom[MAX_LINEA];
    int cont;
}sPalabras;

typedef struct
{
    void *vec;
    unsigned ce, tamElem, maxElem;
}TDASimVec;


TDASimVec* crearTDA(unsigned tam);
int voynich(TDASimVec* sv);
int contarPalabras(const char *linea);
void trozarLinea(char *linea, int col, void* pal, TDASimVec *sv);
void insertarAlFinal(TDASimVec* sv, void *elem);
int signoExclamacion(char *s);
int buscar(char *linea, TDASimVec *sv, int (*cmp)(const void *, const void *));
void ordenar(TDASimVec* sv, int (*cmp)(const void *, const void *));
void mostrar(TDASimVec* sv);
int cmpNom(const void* elem1, const void* elem2);
int cmpCont(const void* elem1, const void* elem2);
void destruirTDA(TDASimVec *sv);



#endif // CABECERAS_H_INCLUDED
