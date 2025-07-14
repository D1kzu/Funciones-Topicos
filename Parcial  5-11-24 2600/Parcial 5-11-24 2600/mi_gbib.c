#include "mi_gbib.h"

void TrozarVariable(char* linea,TCliente* cliente)
{
    char* aux;
    aux=strrchr(linea,'|');
    if(!aux)
        return;
    sscanf((aux+1),"%f",&(cliente->saldo));
    *aux='\0';
    aux=strrchr(linea,'|');
    if(!aux)
        return;
    strcpy((cliente->codSeg),(aux+1));
    *aux='\0';
    aux=strrchr(linea,'|');
    if(!aux)
        return;
    strcpy((cliente->nomYAp),(aux+1));
    *aux='\0';
    sscanf(linea,"%d",&(cliente->legajo));

}
void MostrarCliente(const TCliente* cliente,int cant)
{
    const TCliente* clientes=cliente;
    for(int i=0;i<cant;i++)
    {
        printf("%d  %s  %s  %2.2f\n",clientes->legajo,clientes->nomYAp,clientes->codSeg,clientes->saldo);
        clientes++;
    }
}
int restaurarArchClientesALU(const char* archOri, const char* archDes)
{
    int cant_reg=0,cambios=0,i=0;
    char linea[MAX_LINE]; //entero(6)+'|'(1)+nombre(65)+'|'(1)+codigo(513)+'|'(1)+sueldo(7)+'\n'
    FILE* ppermutado=fopen(archOri,"rt");
    TCliente* cliente;
    cliente=malloc(MAX_RANGE*sizeof(TCliente));
    if(!ppermutado || !cliente)
        return 0;
    FILE* prestaurado=fopen(archDes,"wt");
    if(!prestaurado)
    {
        free(cliente);
        fclose(ppermutado);
        return 0;
    }
    FILE* ptabla=fopen(TABLA_PERM,"rt");
    if(!ptabla)
    {
        free(cliente);
        fclose(ppermutado);
        fclose(prestaurado);
        fclose(ptabla);
        return 0;
    }
    tabla* pelem=malloc(15*sizeof(tabla));
    if(!pelem)
        return 0;
    while(fgets(linea,MAX_LINE-1,ppermutado))
    {
        TrozarVariable(linea,cliente+cant_reg);
        cant_reg++;
    }
    MostrarCliente(cliente,cant_reg);
    while(fgets(linea,MAX_LINE-1,ptabla))
    {
        TrozarFijo(linea,pelem);
        cambios++;
        pelem++;
    }
    pelem--;
    while(i<cambios)
    {
        intercambioo(&(cliente+pelem->elem1)->saldo,&(cliente+pelem->elem2)->saldo,sizeof(float));
        pelem--;
        i++;
    }
    pelem++;
    MostrarCliente(cliente,cant_reg);
    GuardarTabla(cliente,cant_reg,&prestaurado);
    free(pelem);
    printf("cliente = %p\n", (void*)cliente);
    free(cliente);
    fclose(ppermutado);
    fclose(prestaurado);
    fclose(ptabla);
    return 1;
}

void GuardarTabla(TCliente* cliente,int cant_reg,FILE** pr)
{
        TCliente* aux=cliente;

        for(int i=0;i<cant_reg;i++)
        {
            fprintf(*pr,"%d|%s|%s|%f\n",aux->legajo,aux->nomYAp,aux->codSeg,aux->saldo);
            aux++;
        }
}


void TrozarFijo(char* linea,tabla* pelem)
{
    char* aux=linea;
    strncpy(aux,linea,TAM_ELEM_TABLA-1);
    sscanf(aux,"%d",&pelem->elem1);
    aux+=TAM_ELEM_TABLA;
    sscanf(aux,"%d",&pelem->elem2);


}

void intercambioo(void* elem1,void* elem2,size_t tam)
{
    char aux;
    int i=0;
    while(i<tam)
    {
        aux=*(char*)elem1;
        *(char*)elem1=*(char*)elem2;
        *(char*)elem2=aux;
        i++;
        elem1++;
        elem2++;
    }

}
