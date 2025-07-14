#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAYUS(x) ((x)>='a' && (x)<='z')?(x)-32:(x)
#define MINUS(x) ((x)>='A' && (x)<='Z')?(x)+32:(x)
#define ESLETRA(x) (((x)>='a' && (x)<='z')|| ((x)>='A' && (x)<='Z'))?1:0
int EsPalindromox(const char* s1);
int mstrcmp(const char* s1,const char* s2);
int mstrstr(const char* s1,const char* s2);
int ProximaPalabra(char* ini,char** cad);
void MostrarCadena(char* cad, int tam);
void EliminarEspacio(char** ini);
void* my_Memmcpy(void* ini,const void* p,size_t cdesp);
void* my_Memmove(void* destino,const void* orige, size_t cdesp);
#endif // CADENAS_H_INCLUDED
