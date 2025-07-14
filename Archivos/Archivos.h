#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define TAM 1024
#define TAM_LINEA 255
#define DNI 4
#define NOMBRE 10
#define APELLIDO 15
#define SUELDO 10
typedef struct
{
    int dni;
    char apellido[TAM];
    char nombre[TAM];
    double sueldo;
}Temp;
typedef struct
{
    int dni;
    char apellido[TAM];
    char nombre[TAM];
    float promedio;
}Test;

bool AbrirArch(FILE** pf,const char* nom);
int CrearLote_Est(const char* nom);
int CrearLote_Emp(const char* nom);
int LeerArchivo(const char* nom,size_t tam, void Mostrar(const void*,size_t));
void Merge(size_t tam1,size_t tam2,int cmp(const void*,const void*,size_t,size_t));
void aumentarSueldo(void* buffer2,size_t tam2,FILE** p2);
float VerificarPromedio(void* buffer2);
void MostrarEmp(const void* aux,size_t tam);
void CrearArchtxt(FILE** pf);
void LeerArchivotxt(FILE** pf);
void LeerArchivotxtFijo(FILE** pf);
int Parsear(char* linea, Temp* emp);
void PasartxtaBin(FILE** pt,FILE** pb);
void ParsearFijo(char* linea,Temp* emp);
void Ejercicio5_3(char* linea,size_t tam);
#endif // ARCHIVOS_H_INCLUDED
