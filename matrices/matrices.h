#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 4

int TrianguloSuperior(int m[][5],int fc);
int TrianguloInferior(int m[][TAM],int fc);
void DiagonalInferior(int m[][TAM],int fc);
void Transpuesta(int m[][TAM],int cf, int cc);
int Diagonal(int m[][TAM],int cf,int cc);
int Identidad(int m[][TAM],int cf,int cc);
#endif // MATRICES_H_INCLUDED
