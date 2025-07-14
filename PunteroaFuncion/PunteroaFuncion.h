#ifndef PUNTEROAFUNCION_H_INCLUDED
#define PUNTEROAFUNCION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define condicion -1
#define MSJ "Elija una opcion:\n\n"\
            "[1] Mostrar Mensaje 1 \n"\
            "[2] Mostrar Mensaje 2 \n"\
            "[3] Mostrar Mensaje 3 \n"\
            "[4] Mostrar Mensaje 4 \n"\
            "----->1 2 3 4"


typedef struct
{
   int cod;
   int cant;

}Temp;
int Menu(const char* mensaje,const int* opciones,int cant,int Busqueda(void*,void*,int));
int IngresoVFloat(float* vec,int cant);
void MostrarVector(const int *vec,int ce);
void intercambiar(int* menor,int* i);
int* buscarmenor(int* inicio,int* fin);
void OrdenamientoSeleccion(int* aux,int ce);
void OrdenamientoInsercion(int* aux,int ce);
void* Map(void* emp,unsigned ce,unsigned tdato,void* buscado,void* Busqueda(void*,void*));
int matoi(const void* cad,void* val);
#endif // PUNTEROAFUNCION_H_INCLUDED
