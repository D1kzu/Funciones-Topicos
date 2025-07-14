#include "Archivos.h"
bool AbrirArch(FILE** pf,const char* nom)
{
    *pf=fopen(nom,"rt");
    if(*pf)
        return true;
    else
        return false;

}

int CrearLote_Emp(const char* nom)
{
    Temp emp[5]={{10,"Messi","Lionel",150.0},
                 {12,"Suarez","Luis",300.0},
                 {14,"Fernandez","Equi",500.0},
                 {15,"Fernandez","Enzo",350.0},
                 {16,"Antonio","Antonio",100.0}};
    FILE* pf=fopen(nom,"wb");
    if(!pf)
        return 0;
    fwrite(emp,sizeof(emp),1,pf);
    fclose(pf);
    return 1;

}
int CrearLote_Est(const char* nom)
{
    Test est[5]={{10,"Messi","Lionel",10},
    {11,"Jaime","Agustin",8},
    {12,"Suarez","Luis",6},
    {15,"Fernandez","Enzo",9},
    {16,"Antonio","Antonio",4},};
    FILE* pf=fopen(nom,"wb");
    if(!pf)
        return 0;
    fwrite(est,sizeof(est),1,pf);
    fclose(pf);
    return 1;
}
int LeerArchivo(const char* nom,size_t tam, void Mostrar(const void*,size_t))
{
    FILE* pf=fopen(nom,"rb");
    if(!pf)
        return 0;
    void* buffer=malloc(tam);
    if(!buffer)
        return 0;
    fread(buffer,tam,1,pf);
    while(!feof(pf))
    {Mostrar(buffer,tam);
     fread(buffer,tam,1,pf);
    }
    free(buffer);
    fclose(pf);
    return 1;
}

void Merge(size_t tam1,size_t tam2,int cmp(const void*,const void*,size_t,size_t))
{
    FILE* p1=fopen("Empleados.dat","r+b");
    FILE* p2=fopen("Estudiantes.dat","rb");
    if( !p1 && !p2)
        return;
    void* buffer1=malloc(tam1);
    void* buffer2=malloc(tam2);
    if( !buffer1 && !buffer2)
    {
        fclose(p1);
        fclose(p2);
        return;
    }

    fread(buffer1,tam1,1,p1);
    fread(buffer2,tam2,1,p2);
    while(!feof(p1) && !feof(p2))
    {
        if(cmp(buffer1,buffer2,tam1,tam2)==0)
        {
            if(VerificarPromedio(buffer2)>=7)
                {aumentarSueldo(buffer1,tam1,&p1);
                 fflush(p1);
                 }
            fread(buffer1,tam1,1,p1);
            fread(buffer2,tam2,1,p2);


        }
        else
         {
            if(cmp(buffer1,buffer2,tam1,tam2)>0)
                fread(buffer2,tam2,1,p2);
            else
                fread(buffer1,tam1,1,p1);
         }
    }
    free(buffer1);
    free(buffer2);
    fclose(p1);
    fclose(p2);
}

void aumentarSueldo(void* buffer1,size_t tam1,FILE** p1)
{
    Temp* pemp=(Temp*)buffer1;

    pemp->sueldo=pemp->sueldo+pemp->sueldo*0.50;
    fseek(*p1,-1*tam1,SEEK_CUR);
    fwrite(pemp,tam1,1,*p1);

}
float VerificarPromedio(void* buffer2)
{
    Test* pest=(Test*)buffer2;
    return pest->promedio;
}

void MostrarEmp(const void* aux,size_t tam)
{
    Temp* pemp=(Temp*)aux;
    printf("\n %d | %s | %s | %lf",pemp->dni,pemp->apellido,pemp->nombre,pemp->sueldo);
}

void CrearArchtxt(FILE** pf)
{
    Temp emp[5]={{10,"Messi","Lionel",150.0},
                 {12,"Suarez","Luis",300.0},
                 {14,"Fernandez","Equi",500.0},
                 {15,"Fernandez","Enzo",350.0},
                 {16,"Antonio","Antonio",100.0}};
    Temp* pemp=emp;
    for(int i=0;i<sizeof(emp)/sizeof(Temp);i++)
    {
        fprintf(*pf,"%d|%s|%s|%lf\n",pemp->dni,pemp->nombre,pemp->apellido,pemp->sueldo);
        pemp++;
    }
}

void LeerArchivotxt(FILE** pf)
{
    char linea[TAM_LINEA];
    Temp emp;
    while(fgets(linea,TAM_LINEA-1,(*pf)))
    {
        Parsear(linea,&emp);
        if(emp.dni>12)
            printf("%d|%s|%s|%lf\n",emp.dni,emp.nombre,emp.apellido,emp.sueldo);
    }
}
void LeerArchivotxtFijo(FILE** pf)
{
    char linea[TAM_LINEA];
    Temp emp;
    while(fgets(linea,TAM_LINEA-1,(*pf)))
    {
        ParsearFijo(linea,&emp);
        if(emp.dni>12)
            printf("%d%s%s%lf\n",emp.dni,emp.nombre,emp.apellido,emp.sueldo);
    }
}
int Parsear(char* linea, Temp* emp)
{
    char* p;
    p=strrchr(linea,'|');
    if(!p)
        return 0;
    sscanf(p+1,"%lf",&(emp->sueldo));
    *p='\0';
    p=strrchr(linea,'|');
    if(!p)
        return 0;

    strcpy(emp->apellido,p+1);
    *p='\0';
    p=strrchr(linea,'|');
    strcpy(emp->nombre,p+1);
    *p='\0';
    sscanf(linea,"%d",&(emp->dni));
    return 1;

}
void PasartxtaBin(FILE** pt,FILE** pb)
{
    Temp emp;
    fread(&emp,sizeof(Temp),1,*pb);
    while(!feof(*pb))
    {
        fprintf(*pt,"%2d|%s|%s|%lf\n",emp.dni,emp.nombre,emp.apellido,emp.sueldo);
        fread(&emp,sizeof(Temp),1,*pb);
    }
}

void ParsearFijo(char* linea,Temp* emp)
{
    char* p=linea+38;//me posiciono al final de la linea
    *p='\0';
    p-=SUELDO;
    sscanf(p,"%lf",&(emp->sueldo));
    *p='\0';
    p-=APELLIDO;
    strcpy(emp->apellido,p);
    *p='\0';
    p-=NOMBRE;
    strcpy(emp->nombre,p);
    *p='\0';
    p-=DNI;
    sscanf(p,"%d",&(emp->dni));
}
int ProximaPalabra(char* cad,char** ini)
{

}

void Ejercicio5_3(char* linea,size_t tam)
{

}
