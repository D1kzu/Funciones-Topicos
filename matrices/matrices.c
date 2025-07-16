#include "matrices.h"

int TrianguloSuperior(int m[][5],int fc)
{
    int i,j,suma=0;

    for(i=0; i<fc; i++)
    {
        for(j=0; j<i; j++)
        {
            suma+=m[i][j];
        }
    }
    return suma;
}

int TrianguloInferior(int m[][TAM],int fc)
{
    int i,j,suma=0;

    for(i=0; i<fc; i++)
    {
        for(j=i+1; j>i && j<fc; j++)
        {
            suma+=m[i][j];
        }

    }
    return suma;
}

void DiagonalInferior(int m[][TAM],int fc)
{
    int i,j;
    for(i=fc/2+1; i<fc; i++)
    {
        for(j=i/2; j<i; j++)
            printf("\n%d\t",m[i][j]);
    }
}

void Transpuesta(int m[][TAM],int cf,int cc)
{
    int i,j,aux;

    for(i=0; i<cf; i++)
    {
        for(j=0; j<i; j++)
        {
            aux=m[j][i];
            m[j][i]=m[i][j];
            m[i][j]=aux;
        }

    }

    for(i=0; i<cf; i++)
    {
        printf("\n");
        for(j=0; j<cc; j++)
            printf("%3d",m[i][j]);
    }

}

int Diagonal(int m[][TAM],int cf,int cc)
{
    int i,j;

    for(i=0; i<cf; i++)
    {
        for(j=0; j<i; j++)
        {
            if(m[i][j]!=0 || m[j][i]!=0)
            {
                return -1;

            }
            else
            {
                if(m[i][i]==0)
                {
                    return -1;
                }
            }

        }
    }
    return 1;
}

int Identidad(int m[][TAM],int cf,int cc)
{
    int i,j;
    for(i=0; i<cf; i++)
    {
        for(j=0; j<i; j++)
        {
            if(m[i][j]!=0 || m[j][i]!=0)
            {
                return -1;

            }
            else
            {
                if(m[i][i]!=1)
                {
                    return -1;
                }
            }

        }
    }
    return 1;
}

void Espiral(int m[][TAM],int cf,int cc)
{
  int inicioFila = 0,inicioCol = 0,i;

    while (inicioFila < cf && inicioCol <cc) {
        // Recorre la fila superior
        for (i = inicioCol; i <cc; i++)
            printf("%d ", m[inicioFila][i]);
        inicioFila++;
        printf("\n\n");
        // Recorre la columna derecha
        for (i = inicioFila; i <cf; i++)
            printf("%d ", m[i][cc-1]);
        cc--;
        printf("\n\n");
        // Recorre la fila inferior (si queda)
        if (inicioFila < cf) {
            for (i = cc-1; i >= inicioCol; i--)
                printf("%d ", m[cf-1][i]);
            cf--;
        }
        printf("\n\n");

        // Recorre la columna izquierda (si queda)
        if (inicioCol <cc) {
            for (i = cf-1; i >= inicioFila; i--)
                printf("%d ", m[i][inicioCol]);
            inicioCol++;
        }
        printf("\n\n");
    }
}


int** MatrizDinamicaEnteros(int cf,int cc)
{
    int i=0;
    int** aux=malloc(cf*sizeof(int*));
    int** ini=aux;
    if(!aux)
        return NULL;
    while(i<cc)
    {
        *aux=malloc(cc*sizeof(int));
        if(!*aux)
        {
            DestruirMatrizDinamica(ini,i);
            printf("\n No se pudo crear matriz");
            return NULL;
        }
        (aux)++;
        i++;
    }
    return ini;
}

void DestruirMatrizDinamica(int** aux,int cc)
{
    while(cc>0)
    {
        free(*(aux+cc-1));
        cc--;
    }
    free(aux);
}
