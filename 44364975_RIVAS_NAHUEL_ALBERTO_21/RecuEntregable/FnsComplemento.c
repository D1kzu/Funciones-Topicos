#include "FnsComplemento.h"

void qSortPropio(void *vec, size_t ce, size_t tamDato, int (*comparar)(const void *, const void *)){
    int i, cambio = 1, j = 1;
    void *siguiente, *anterior;
    while(cambio){
        siguiente = vec + ((ce - 1) * tamDato);
        anterior = vec + ((ce - 2) * tamDato);
        cambio = 0;
        for(i = 0; i < ce - j; i++){
            if(comparar(siguiente, anterior) < 0){
                intercambiar(siguiente, anterior, tamDato);
                cambio++;
            }
            siguiente -= tamDato;
            anterior -= tamDato;
        }
        j++;
    }
}

int compararEnteros(const void *n1, const void *n2){
    return *((int*)n1) - *((int*)n2);
}

void intercambiar(void *a, void *b, size_t tamDato){
    int i;
    char aux;
    for(i = 0; i < tamDato; i++){
        aux = *((char *)a);
        *((char *)a) = *((char *)b);
        *((char *)b) = aux;
        (char*)a++;
        (char*)b++;
    }
}

int **productoMatrices(int **Mat1,int **Mat2, size_t cf1, size_t cc1, size_t cf2, size_t cc2){
    int i, k, l, acum, **MatResultante;
    if(cc1 == cf2){
        MatResultante = crearDinMat(cf1, cc2);
        for(i = 0; i < cf1; i++){
            for(l = 0; l < cc2; l++){
                acum = 0;
                for(k = 0; k < cf2; k++){
                    acum += Mat1[i][k] * Mat2[k][l];
                }
                MatResultante[i][l] = acum;
            }
        }
        return MatResultante;
    }
    return NULL;
}

int **crearDinMat(size_t cf, size_t cc){
    int **mat = malloc(sizeof(int*) * cf), i;
    if(!mat){ return NULL; }
    for(i = 0; i < cf; i++){
        mat[i] = crearIntArray(cc);
        if(!mat[i]){
            liberarDinMat(mat, i);
            return NULL;
        }
    }
    return mat;
}

int *crearIntArray(size_t cc){
    int *vec = malloc(sizeof(int) * cc);
    if(!vec){ return NULL; }
    else{ return vec; }
}

void liberarDinMat(int **mat, size_t cf){
    int i;
    for(i = 0; i < cf; i++){
        free(mat[i]);
    }
    free(mat);
}

void llenarMat(int **mat, size_t cf, size_t cc){
    int i, j;
    for(i = 0; i < cf; i++){
        for(j = 0; j < cc; j++){
            mat[i][j] = 1 + i + j;
        }
    }
}

/*void inicializarMat(int **mat, size_t cf, size_t cc){
    int i, j;
    for(i = 0; i < cf; i++){
        for(j = 0; j < cc; j++){
            mat[i][j] = 0;
        }
    }
}*/
