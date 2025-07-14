#ifndef CABECERAS_H_INCLUDED
#define CABECERAS_H_INCLUDED
#define NOM_ARCH "voynich.txt"
#define MAX_PALABRA 15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_TAM 10
#define MAX_LINEA 1024
typedef struct
{
    void* vec;
    int ce;
    int tam;
    int max_tam;
}TDA;

typedef struct
{
    char palabra[MAX_PALABRA];
    int apariciones;
}Tpalabra;
int voynich(TDA* vec,const char* nombre);
TDA* CrearTDA(Tpalabra* palabra,int min_tam,int tam);
int Signo(const char* aux,char buscado);
void ParsearLinea(char* linea,TDA* vec,Tpalabra* palabra);
int Buscar(void* vec,void* elem,int ce,int cmp(const void*,const void*));
void InsertarFinal(void* vec,Tpalabra* elem,int ce);
void GuardarPalabra(TDA* vec,Tpalabra* elem);
#endif // CABECERAS_H_INCLUDED
