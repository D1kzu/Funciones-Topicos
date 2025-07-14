#ifndef MI_GBIB_H_INCLUDED
#define MI_GBIB_H_INCLUDED

#define ARCHPERM "perm.txt"
#define MAX_LINE 599
#define MAX_RANGE 10
#define MAX_LINE_PERM 12
#define MAX_REG 50000
#define TABLA_PERM "perm.txt"
#define TAM_ELEM_TABLA 5
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
} TCliente; // 6+1+65+1+513+1+4+7+1

typedef struct
{
    int elem1;
    int elem2;
} tabla;
int permutarArchClientes(const char* archOri, const char* archDes);
int restaurarArchClientes(const char* archOri, const char* archDes);
int permutarArchClientesALU(const char* archOri, const char* archDes);
int restaurarArchClientesALU(const char* archOri, const char* archDes);
void TrozarFijo(char* linea,tabla* pelem);
void TrozarVariable(char* linea,TCliente* cliente);
void intercambioo(void* elem1,void* elem2,size_t tam);
void GuardarTabla(TCliente* cliente,int cant_reg,FILE** pr);
#endif // MI_GBIB_H_INCLUDED
