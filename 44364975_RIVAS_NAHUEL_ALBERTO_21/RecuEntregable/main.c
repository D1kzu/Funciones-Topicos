#include "FnsComplemento.h"

int main()
{
    tOpCmp compararElegido;
    compararElegido = compararEnteros;
    int vec[] = {1, 44, 3, 55, 7, 45, 15}, **mat1, **mat2, **matResultante, cf1 = 2, cc1 = 3, cf2 = 3, cc2 = 4, i, j;
    qSortPropio(vec, sizeof(vec) / sizeof(*vec), sizeof(*vec), compararElegido);
    mat1 = crearDinMat(cf1, cc1);
    mat2 = crearDinMat(cf2, cc2);
    llenarMat(mat1, cf1, cc1);
    llenarMat(mat2, cf2, cc2);
    matResultante = productoMatrices(mat1, mat2, cf1, cc1, cf2, cc2);
    for(i = 0; i < cf1; i++){
        for(j = 0; j < cc2; j++){
            printf("%d ", matResultante[i][j]);
        }
        printf("\n");
    }
    liberarDinMat(mat1, cf1);
    liberarDinMat(mat2, cf2);
    liberarDinMat(matResultante, cf1);
    printf("\n\n");
    cf1 = 4;
    cc1 = 3;
    cf2 = 3;
    cc2 = 5;
    mat1 = crearDinMat(cf1, cc1);
    mat2 = crearDinMat(cf2, cc2);
    llenarMat(mat1, cf1, cc1);
    llenarMat(mat2, cf2, cc2);
    matResultante = productoMatrices(mat1, mat2, cf1, cc1, cf2, cc2);
    for(i = 0; i < cf1; i++){
        for(j = 0; j < cc2; j++){
            printf("%d ", matResultante[i][j]);
        }
        printf("\n");
    }
    liberarDinMat(mat1, cf1);
    liberarDinMat(mat2, cf2);
    liberarDinMat(matResultante, cf1);
    printf("\n\n");
    cf1 = 2;
    cc1 = 2;
    cf2 = 2;
    cc2 = 2;
    mat1 = crearDinMat(cf1, cc1);
    mat2 = crearDinMat(cf2, cc2);
    llenarMat(mat1, cf1, cc1);
    llenarMat(mat2, cf2, cc2);
    matResultante = productoMatrices(mat1, mat2, cf1, cc1, cf2, cc2);
    for(i = 0; i < cf1; i++){
        for(j = 0; j < cc2; j++){
            printf("%d ", matResultante[i][j]);
        }
        printf("\n");
    }
    liberarDinMat(mat1, cf1);
    liberarDinMat(mat2, cf2);
    liberarDinMat(matResultante, cf1);
    printf("\n\n");
    cf1 = 2;
    cc1 = 3;
    cf2 = 2;
    cc2 = 3;
    mat1 = crearDinMat(cf1, cc1);
    mat2 = crearDinMat(cf2, cc2);
    llenarMat(mat1, cf1, cc1);
    llenarMat(mat2, cf2, cc2);
    matResultante = productoMatrices(mat1, mat2, cf1, cc1, cf2, cc2);
    if(matResultante){
        for(i = 0; i < cf1; i++){
            for(j = 0; j < cc2; j++){
                printf("%d ", matResultante[i][j]);
            }
            printf("\n");
        }
        liberarDinMat(matResultante, cf1);
    }
    else{ printf("Fin lote de pruebas\n\n"); }
    liberarDinMat(mat1, cf1);
    liberarDinMat(mat2, cf2);

    return 0;
}
