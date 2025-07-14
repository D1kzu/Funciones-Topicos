#ifndef TDA_VECTOR_H_INCLUDED
#define TDA_VECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_BASE 5
typedef struct{
void* vec;
unsigned ce;
unsigned tmax;
size_t tam;
}Vector;

typedef struct
{
    char nom[20];
    int cod;
    double sueldo;
}Tejemplo;
int CrearVector(Vector* v,size_t tam);
void DestruirVector(Vector* v);
void* InsertarFinal(Vector* v,void* dato);
void* InsertarPos(Vector* v,void* dato,unsigned pos);
int redimensionar(Vector* v,size_t NuevaCap);
void pisar(void* dest,void* ini,size_t tam);
void VectorVacio(Vector* v);
void InsertarOrden(Vector* v,void* val,int cmp(void*,void*));
int EliminarElemento(Vector* v,void* val,int cmp(void*,void*));
void Map(Vector* v,int accion(void*));
void EliminarPos(Vector* v,int pos);
#endif // TDA_VECTOR_H_INCLUDED
