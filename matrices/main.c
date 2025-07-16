#include "matrices.h"
int main()
{
    /*int m[TAM][TAM]= {{1,0,0,0,2},
                      {0,1,0,0,3},
                      {0,0,1,0,4},
                      {0,0,0,0,5},
                      {0,0,0,0,1}
    };*/
    //printf("El resultado de la suma de los elementos debajo de la diagonal es de: %d",TrianguloSuperior(m,TAM));
    //printf("El resultado de la suma de los elementos por encima de la diagonal es de: %d",TrianguloInferior(m,TAM));
        //DiagonalInferior(m,TAM);
    //Transpuesta(m,TAM,TAM);
    /*if(Identidad(m,TAM,TAM)==-1)
    {
        printf("Matriz no identidad");
    }
    else
        printf("Matriz Identidad");
    */
    ///ESPIRAL (FALTA ARREGLAR PARA CIERTOS CASOS)
    //Espiral(m,TAM,TAM);
    ///IMPLEMENTACION MATRIZ DINAMICA
    int** mat=MatrizDinamicaEnteros(5,5);
    DestruirMatrizDinamica(mat,5);
    return 0;
}
