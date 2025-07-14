#ifndef FUNGENERICAS_H_INCLUDED
#define FUNGENERICAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombre[10];
    double sueldo;
}Templeado;
int m_search(const void* c1,const void* buscado,size_t ce,size_t tam,int cmp(const void*,const void*));
void* Buscarmenor(const void* c1,size_t ce,size_t tam,int cmp(const void*,const void*));
void ord_gen( void* c1,size_t ce,size_t tam,int cmp(const void*,const void*));
void intercambio(void* minimo,void* c1,size_t tam);
#endif // FUNGENERICAS_H_INCLUDED
