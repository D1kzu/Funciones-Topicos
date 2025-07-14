#ifndef CABECERAS_H_INCLUDED
#define CABECERAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_LINEA 255

typedef struct {
    int id_producto;         // Campo en común
    char descripcion[50];
    float precio_unitario;
    int stock;
} ProductoA;

typedef struct {
    int id_producto;         // Campo en común
    char proveedor[40];
    int cantidad_comprada;
    char fecha[11];          // formato: "YYYY-MM-DD"
} ProductoB;


void crearLoteA();
void crearLoteB();
void Merge(const char* lote1,const char* lote2,int cmp(const void*,const void*));
void ParsearProd(char* linea,ProductoA* prod);
void ParsearCompra(char* linea,ProductoB* compra);
int EvaluarStock(ProductoA* prod,ProductoB* compra);
void ActualizarStock(ProductoA* prod,ProductoB* compra,FILE** pt);
void Error(ProductoA* prod,ProductoB* compra,FILE** pe);
#endif // CABECERAS_H_INCLUDED
