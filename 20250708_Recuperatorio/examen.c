#include <stdio.h>
#include "examen.h"

int multiplicarMatricesAlumno(int mat1[][MAX_COL],int fmat1,int cmat1,int mat2[][MAX_COL],int fmat2,int cmat2,int matR[][MAX_COL])
{

    int i,j,k;
    int result;
      for(k=0;k<fmat1;k++)
      {
        for(i=0;i<fmat1;i++)
       {
           for(j=0;j<cmat1;j++)
           {
               result+=mat2[j][i]*mat1[k][j];
           }
           matR[k][i]=result;
           printf("\n%d",result);
           result=0;
       }
      }
    return 0;
}


char *rstrrchrAlumno(const char *cad, int c)
{
    char* resultado;
    if(*cad=='\0')
        return NULL;
    resultado=rstrrchrAlumno(cad+1,c);
    if(resultado)
        return resultado;
    if(*cad==c)
        return (char*)cad;
    else
        return NULL;

}
