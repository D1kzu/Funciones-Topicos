#include <stdio.h>
#include <stdlib.h>
#include "PreParcial.h"

int cmpDNI(const void* buffer1,const void* buffer2)
{
    Temp* pemp=(Temp*)buffer1;
    Tnov* pnov=(Tnov*)buffer2;
    return pemp->cod - pnov->emp.cod;
}
void MostrarEmp(const void* buffer1,size_t tam)
{
    Temp* emp=(Temp*)buffer1;
    printf("%d      %s      %f\n",emp->cod,emp->nombre,emp->sueldo);
}
int main()
{

    crearEmpDat();
    Merge(sizeof(Temp),sizeof(Tnov),cmpDNI);
    LeerArchivo("Emp.dat",sizeof(Temp),MostrarEmp);
    printf("\n\n");
    LeerArchivo("Errores.dat",sizeof(Temp),MostrarEmp);
    ///FINIQUITADO
    return 0;
}
