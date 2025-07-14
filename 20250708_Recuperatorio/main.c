#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Examen.h"

#define EXAMEN

#ifdef EXAMEN
    #define multiplicarMatrices multiplicarMatricesAlumno
    #define rstrrchr            rstrrchrAlumno
#endif // EXAMEN

int test_mat01();
int test_strrchr01();


int main()
{


    if(!test_mat01()){
        puts("Fallo multiplicacion de matrices");
    }

    if(!test_strrchr01()){
        puts("Fallo al strrchr recursivo");
    }


    return 0;
}


int test_mat01(){
    //Prueba simple de matrices
    const int f1 = 2;
    const int c1 = 3;
    int mat1[MAX_FIL][MAX_COL] = {  {1,2,3},
                                    {4,5,6},

                                 };


    const int f2 = 3;
    const int c2 = 2;
    int mat2[MAX_FIL][MAX_COL] = {{1,2},
                                  {3,4},
                                  {5,6}
                                 };

    int matRes[MAX_FIL][MAX_COL]; //Matriz donde se deposita el resultado.
    int matResEsperada[MAX_FIL][MAX_COL] = {
        {22,28},
        {49,64}
    } ;

    multiplicarMatrices(mat1, f1, c1, mat2, f2, c2, matRes);
    //Es es necesario que lo pruebe asi, pruebe como quiera pero entregue una implementacion que funcione.
    return memcmp(matRes, matResEsperada, f1*c2)==0;



}


int test_strrchr01(){
    //Prueba minima elemental...
    char cad[] = "Hola mundo que tal";

    return strrchr(cad, 'o')==rstrrchr(cad, 'o');
}

