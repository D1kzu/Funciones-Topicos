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
                return 0;

            }
            else
            {
                if(m[i][i]==0)
                {
                    return 0;
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
