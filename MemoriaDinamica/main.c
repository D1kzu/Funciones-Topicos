#include "MemoriaDinamica.h"
#define TAM 1024
int main()
{
    /*Tmio *mio;
    if(CrearVectorEstructura(&mio)==0)
        printf("Vector no creado");
    else
        {printf("\n Vector Creado Exitosamente");
        MostrarEstructura(mio,2);
        free(mio);
        }*/
    ///STRCPY
    /*int cadena[TAM]={12,41,412,123,531};
    MostrarInt(cadena,5);
    void* Dest=CopioCosas(cadena,sizeof(int)*5);
    MostrarInt(Dest,5);
    free(Dest);
    */
    float** mat=CrearMatrizDinamica(COL,FIL);
    InicializarMatriz(mat,COL,FIL);
    for(int i=0;i<10;i++)
    {
        printf("\n");
        for(int j=0;j<10;j++)
            printf("\t%f",mat[i][j]);
    }

    DestruirMatrizDinamica(mat,10);
    return 0;
}
