#include "PreParcial.h"

void crearEmpDat() {
    FILE *f = fopen("Emp.dat", "wb");
    if (!f) {
        perror("No se pudo crear Emp.dat");
        return;
    }

    Temp empleados[] = {
        {10, "Maria Pia", 200.0},
        {20, "Juan Perez", 300.0},
        {30, "Diego Beltran", 200.0},
        {40, "Diego Martinez", 200.0},
        {50, "Nicolas Sattel", 200.0},
        {60, "Macarla De Negri", 150.0},
        {80, "Damian Cale", 800.0}
    };

    fwrite(empleados, sizeof(Temp), sizeof(empleados) / sizeof(Temp), f);
    fclose(f);
}

void crearNovDat() {
    FILE *f = fopen("Nov.dat", "wb");
    if (!f) {
        perror("No se pudo crear Nov.dat");
        return;
    }

    Tnov novedades[] = {
        {{17, "Ana Benitez", 300.0}, 'a'},
        {{20, "Juan Perez Beltran", 250.0}, 'm'},
        {{33, "Jorge Asraliam", 300.0}, 'a'},
        {{55, "Badom Daniel", 250.0}, 'b'},
        {{80, "Damian Cale", 800.0}, 'b'},
        {{85, "Santiago Franco", 800.0}, 'm'},
        {{87, "Anabel Docaso", 150.0}, 'b'},
        {{88, "Martina Capusso", 200.0}, 'a'}
    };

    fwrite(novedades, sizeof(Tnov), sizeof(novedades)/sizeof(Tnov), f);
    fclose(f);
}
char EvaluadorDeEstado(const void* buffer)
{
    Tnov* nov=(Tnov*)buffer;
    return nov->estado;
}
void GuardarTemp(const void* buffer2,size_t tam2,FILE** pt)
{
    Tnov* nov=(Tnov*)buffer2;
    fwrite(&(nov->emp),tam2,1,*pt);
}

void GuardarErrores(const void* buffer2,size_t tam2,FILE** pr)
{
    Tnov* nov=(Tnov*)buffer2;
    fwrite(&(nov->emp),tam2,1,*pr);
}

void CambiarTemp()
{
    remove("Emp.dat");
    rename("Temp.dat","Emp.dat");
}
void Merge(size_t tam1,size_t tam2,int cmp(const void*,const void*))
{
    FILE* pe=fopen("Emp.dat","rb");
    FILE* pn=fopen("Nov.dat","rb");
    FILE* pt=fopen("Temp.dat","wb");
    FILE* pr=fopen("Errores.dat","wb");
    if(!pe || !pn || !pt)
        return;
    int comparador=0;
    void* buffer1=malloc(tam1);
    void* buffer2=malloc(tam2);
    if(!buffer1 || !buffer2)
        return;
    fread(buffer1,tam1,1,pe);
    fread(buffer2,tam2,1,pn);

   while(!feof(pe) && !feof(pn))
    {
        comparador=cmp(buffer1,buffer2);
        if(comparador==0)
        {
            if(EvaluadorDeEstado(buffer2)!='b')
                GuardarTemp(buffer2,tam1,&pt);
            fread(buffer1,tam1,1,pe);
            fread(buffer2,tam2,1,pn);
        }
        else
        {
            if(comparador<0)
            {
                GuardarTemp(buffer1,tam1,&pt);
                fread(buffer1,tam1,1,pe);
            }
            else
            {
                if(EvaluadorDeEstado(buffer2)!='b')
                    GuardarTemp(buffer2,tam1,&pt);
                else
                    GuardarErrores(buffer2,tam1,&pr);

                fread(buffer2,tam2,1,pn);
            }
        }
    }
    while(!feof(pe))
    {
        GuardarTemp(buffer1,tam2,&pt);
        fread(buffer1,tam1,1,pe);
    }
    while(!feof(pn))
    {
        if(EvaluadorDeEstado(buffer2)=='a')
            GuardarTemp(buffer2,tam2,&pt);
        else
            GuardarErrores(buffer2,tam1,&pr);
        fread(buffer2,tam2,1,pn);
    }
    fclose(pe);
    fclose(pn);
    fclose(pt);
    fclose(pr);
    CambiarTemp(&pe);
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
