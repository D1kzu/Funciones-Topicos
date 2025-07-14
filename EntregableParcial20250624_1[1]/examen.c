#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TODO_OKEY 1
#define TODO_MAL 0
#define TAM_NOMAPELLIDO 50
#define NO_ENCONTRADO -1
//
typedef struct
{
    int dni;
    char nombre[TAM_NOMAPELLIDO];
    char apellido[TAM_NOMAPELLIDO];
    float promedio;
} tEstudiante;


void VERARCHIVO(const char* num)
{
    FILE* pf=fopen(num,"rb");
    rewind(pf);
    if(!pf)
        return;
    tEstudiante estudiante;
    fread(&estudiante,sizeof(tEstudiante),1,pf);
    while(!feof(pf))
    {
        printf("%d  %s  %s  %f\n",estudiante.dni,estudiante.nombre,estudiante.apellido,estudiante.promedio);
        fread(&estudiante,sizeof(tEstudiante),1,pf);
    }
}
int fbbinariaALU(void* clave, const char* nomarch, size_t tam, int cmp(const void *, const void *)) {
    FILE* pf = fopen(nomarch, "rb");
    if (!pf) {
        printf("\nError al abrir el archivo: %s", nomarch);
        return TODO_MAL;
    }
    fseek(pf, 0, SEEK_END);
    long tam_archivo = ftell(pf);
    int cant_reg = tam_archivo / tam;
    int desde = 0;
    int hasta = cant_reg - 1;
    int medio;
    void* buffer = malloc(tam);
    if (!buffer) {
        fclose(pf);
        printf("\nError al reservar memoria...");
        return TODO_MAL;
    }
    while (desde <= hasta) {
        medio = (desde + hasta) / 2;
        fseek(pf, medio * tam, SEEK_SET);
        fread(buffer, tam, 1, pf);

        int resultado = cmp(buffer, clave);

        if (resultado == 0) {
            memcpy(clave, buffer, tam);
            free(buffer);
            fclose(pf);
            return TODO_OKEY;
        } else if (resultado < 0) {
            desde = medio + 1;
        } else {
            hasta = medio - 1;
        }
    }
    free(buffer);
    fclose(pf);
    return NO_ENCONTRADO;
}

int InsertarOrdenado(void* c1,void* val,int* ce,size_t tam,size_t tipo,int cmp(const void*,const void*))
{
    void* fin=malloc(tam);
    if(!fin)
        //return MAL;

    fin=(*ce)==tam?c1+((*ce)-1)*tipo:c1+(*ce)*tipo;

    while(fin>c1 && cmp(val,fin-tipo))
    {
        memcpy(fin,fin-tipo,tipo);
        fin-=tipo;
    }
    if(*ce==tam)
       {
        if(cmp(val,fin)>0)
            return TODO_MAL;
        else
            memcpy(fin,val,tipo);
       }
    else
    {
        (*ce)++;
        memcpy(fin,val,tipo);
    }
    return TODO_OKEY;

}


int fbbinariaALUAGUSTIN(void* clave, const char* nomarch, size_t tam, int cmp(const void *, const void *))
{
    FILE* pf=fopen(nomarch,"rb");
    if(!pf)
        return -1;
    void* buffer=malloc(tam);
    if(!buffer)
        return -1;
    fseek(pf,tam,0);
    long int cant_registros=ftell(pf);
    size_t fin=cant_registros;
    size_t ini=0;
    size_t medio;
    int comparador;
    while(ini<=fin)
    {
        medio=(ini+fin)/2;
        fseek(pf,medio*tam,0);
        fread(buffer,tam,1,pf);
        comparador=cmp(buffer,clave);
        if(comparador==0)
            {
                memcpy(clave,buffer,tam);
                free(buffer);
                fclose(pf);
                return 1;
            }
        if(comparador>0)
            fin=medio-1;
        else
            ini=medio+1;
    }
    free(buffer);
    fclose(pf);
    return -1;
}
