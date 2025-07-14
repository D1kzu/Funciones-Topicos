#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_LINEA 1024
#define TAM_PALABRA 15
#define TODO_MAL 0
#define TODO_BIEN 1
#define CANT_PALABRAS 255
#define TAM_MAX 3
typedef struct
{
    char palabra[TAM_PALABRA];
    int apariciones;

}Tpalabra;

typedef struct
{
    char* palabra;
    int ce;
    int tam;
    int cant_max;

}TDAPalabra;
int CrearTDA(TDAPalabra* tda);
void DestruirTDA(TDAPalabra* tda);
int voynich(const char* nombre,Tpalabra* palabra,TDAPalabra* tda);
void ParsearLinea(char* linea,Tpalabra* palabra,TDAPalabra* tda);
int Signo(const char* aux);
int Busqueda(Tpalabra* palabra,TDAPalabra* tda,int cmp(const void*,const void*));
int cmpString(const void* aux,const void* palabra);
void GuardarPalabra(char* aux,Tpalabra* palabra,TDAPalabra* tda);
void OrdenarMayor(Tpalabra* palabra,int ce,int tam,int cmp(const void*,const void*));
int CantTDA(TDAPalabra* tda);
#endif // FUNCIONES_H_INCLUDED
