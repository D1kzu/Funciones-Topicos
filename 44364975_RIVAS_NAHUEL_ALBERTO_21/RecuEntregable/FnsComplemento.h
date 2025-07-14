#ifndef FNSCOMPLEMENTO_H_INCLUDED
#define FNSCOMPLEMENTO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#define MAXFIL 50
#define MAXCOL 50

typedef int (*tOpCmp)(const void*, const void*);

void qSortPropio(void *, size_t, size_t, int (*comparar)(const void *, const void *));
int compararEnteros(const void *, const void *);
void intercambiar(void *, void *, size_t);
int **productoMatrices(int **,int **, size_t, size_t, size_t, size_t);
int **crearDinMat(size_t, size_t);
int *crearIntArray(size_t);
void llenarMat(int **, size_t, size_t);
void liberarDinMat(int **, size_t);
//void inicializarMat(int **, size_t, size_t);

#endif // FNSCOMPLEMENTO_H_INCLUDED
