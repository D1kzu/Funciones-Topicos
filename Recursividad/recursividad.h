#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM_BASE 5
typedef struct
{
    char nom[20];
    int cod;
    double sueldo;
}Tejemplo;
int Rfactorial(int num);
int Rstrlen(const char* cadena);
char* Rstrchr(const char* cadena,int buscado);
char* Rstrrchr(const char* cadena,int buscado);
void* Rbinaria(const void* vec,const void* buscado,size_t ce,size_t tam,int cmp(const void*,const void*));
int Rpalindromo(char* inicio,char* fin);
void Rmap(void* vec,size_t ce,size_t tam,int accion(void*));
void RmapInverso(void* vec,size_t ce,size_t tam,void accion(void*) );
int Rsumadigitos(char* vec);
int RsumayMostrarInverso(int* vec,size_t ce,void accion(void*));
char* Rstrstr(const char* cad1,const char* cad2);
int empiezaCon(const char* cad1, const char* cad2);
#endif // RECURSIVIDAD_H_INCLUDED
