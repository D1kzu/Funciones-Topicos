#include <stdio.h>
#include <stdlib.h>
#include "Archivos.h"
int cmpDNI(const void* buffer1,const void* buffer2 ,size_t tam1,size_t tam2)
{
    Temp* pemp=(Temp*)buffer1;
    Test* pest=(Test*)buffer2;
    return pemp->dni-pest->dni;
}
/*void MostrarEmp(const void* aux,size_t tam)
{
    Temp* pemp=(Temp*)aux;
    printf("\n %d | %s | %s | %lf",pemp->dni,pemp->apellido,pemp->nombre,pemp->sueldo);
}*/
/*void MostrarEst(const void* aux,size_t tam)
{
    Test* pest=(Test*)aux;
    printf("\n %d | %s | %s | %f",pest->dni,pest->apellido,pest->nombre,pest->promedio);
}
*/
int main()
{
    /*CrearLote_Emp("Empleados.dat");
    CrearLote_Est("Estudiantes.dat");
    LeerArchivo("Empleados.dat",sizeof(Temp),MostrarEmp);
    printf("\n\n");
    LeerArchivo("Estudiantes.dat",sizeof(Test),MostrarEst);
    system("pause");
    Merge(sizeof(Temp),sizeof(Test),cmpDNI);
    FILE* p1=fopen("Empleados.txt","rt");
    LeerArchivotxt(&p1);
    FILE* p2=fopen("EmpleadosFijo.txt","rt");
    LeerArchivotxtFijo(&p2);
    fclose(p2);*/
    char arraytexto[TAM_LINEA]="Hola, esto es una prueba para    verificar el ejercicio de archivos";
    Ejercicio5_3(arraytexto,TAM_LINEA);
    return 0;
}
