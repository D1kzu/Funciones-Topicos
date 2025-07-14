#ifndef PREPARCIAL_H_INCLUDED
#define PREPARCIAL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int cod;
    char nombre[31];
    float sueldo;
}Temp;

typedef struct{

    Temp emp;
    char estado;
}Tnov;
void crearEmpDat();
void crearNovDat();

void Merge(size_t tam1,size_t tam2,int cmp(const void*,const void*));
int LeerArchivo(const char* nom,size_t tam, void Mostrar(const void*,size_t));
#endif // PREPARCIAL_H_INCLUDED
