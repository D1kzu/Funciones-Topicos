#ifndef MEMORIADINAMICA_H_INCLUDED
#define MEMORIADINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAXLINE 1024
typedef struct{
char cad[MAXLINE];
int entero;
float flotante;
char caracter;
}Tmio;
int CrearVector(int var);
int CrearVectorEstructura(Tmio** mio);
void MostrarVector(const int* vec,int var);
void MostrarEstructura(const Tmio* mio,int var);
char* copiaCadena(const char* cad);
void* CopioCosas(void* elemento,unsigned tam);
void MostrarInt(void* elem,unsigned ce);
void* my_Memmcpy(void* ini,const void* p,size_t cdesp);
void* my_Memmove(void* destino,const void* orige, size_t cdesp);
float** CrearMatrizDinamica(int cc,int cf);
void DestruirMatrizDinamica(float** mat,int ce);
void InicializarMatriz(float** mat,int cf,int cc);
#endif // MEMORIADINAMICA_H_INCLUDED
