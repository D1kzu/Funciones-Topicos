#ifndef GBIB_H_INCLUDED
#define GBIB_H_INCLUDED

#define ARCHPERM "perm.txt"
#define MAX_LINE 597
#define MAX_RANGE 6
#define MAX_LINE_PERM 12
#define MAX_REG 50000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*Cmp)(const void* elem1, const void* elem2);

typedef struct
{
    int legajo;
    char nomYAp[65];
    char codSeg[513];
    float saldo;
} sCliente;

typedef struct
{
    int elem1;
    int elem2;
} sPerm;

int crearLotePruebaClientes(const char* nomArchivo);
int permutarArchClientes(const char* archOri, const char* archDes);
int restaurarArchClientes(const char* archOri, const char* archDes);

int permutarArchClientesALU(const char* archOri, const char* archDes);
int restaurarArchClientesALU(const char* archOri, const char* archDes);

void intercambioGenerico(void* elem1, void* elem2, size_t tamElem);
void trozarMedicionVariable(char* linea, sCliente* cliente);
void trozarMedicionFija(char* linea, sPerm* perm);

#endif // GBIB_H_INCLUDED
