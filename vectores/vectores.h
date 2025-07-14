#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
void InsertarElemento(int *vec,int *ce,int val,int TAM);
void InsertarPosicion(int *vec,int *ce,int val,int pos,int TAM);
int EliminarPosicion(int *vec,int *ce,int pos,int TAM);
int EliminarPrimero(int *vec,int *ce,int val,int TAM);
int EliminarVarios(int *vec,int *ce,int val,int TAM);
void MostrarVector(int *vec,int ce);
void insertarElemOrdenado(int* vec, size_t* ce, size_t tam, int num);
#endif // VECTORES_H_INCLUDED
