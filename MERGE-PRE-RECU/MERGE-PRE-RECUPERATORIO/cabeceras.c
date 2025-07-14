#include "cabeceras.h"


void crearLoteA() {
    FILE* archivo = fopen("loteA.txt", "wt");
    if (!archivo) {
        perror("Error al crear loteA.txt");
        exit(EXIT_FAILURE);
    }

    ProductoA productos[] = {
        {1, "Tornillos", 10.50, 100},
        {2, "Tuercas", 5.75, 200},
        {3, "Clavos", 3.25, 300},
        {4, "Arandelas", 1.10, 150},
        {5, "Bulones", 8.90, 80}
    };

    int n = sizeof(productos) / sizeof(ProductoA);
    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d|%s|%.2f|%d\n",
                productos[i].id_producto,
                productos[i].descripcion,
                productos[i].precio_unitario,
                productos[i].stock);
    }

    fclose(archivo);
    printf("Archivo loteA.txt creado con éxito.\n");
}

// Función para crear el archivo loteB.txt
void crearLoteB() {
    FILE* archivo = fopen("loteB.txt", "wt");
    if (!archivo) {
        perror("Error al crear loteB.txt");
        exit(EXIT_FAILURE);
    }

    ProductoB compras[] = {
        {1, "Hierros SA", 150, "2024-06-15"},
        {2, "Aceros SRL", 100, "2024-06-10"},
        {4, "FerroMetal", 50, "2024-06-20"},
        {5, "Inducom", 400, "2024-06-05"},
        {6, "Aceros SRL", 200, "2024-06-01"}
    };

    int n = sizeof(compras) / sizeof(ProductoB);
    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d|%s|%d|%s\n",
                compras[i].id_producto,
                compras[i].proveedor,
                compras[i].cantidad_comprada,
                compras[i].fecha);
    }

    fclose(archivo);
    printf("Archivo loteB.txt creado con éxito.\n");
}



void Merge(const char* lote1,const char* lote2,int cmp(const void*,const void*))
{
    FILE* p1=fopen(lote1,"rt");
    if(!p1)
        return;
    FILE* p2=fopen(lote2,"rt");
    if(!p2)
    {
        fclose(p1);
        return;
    }
    FILE* pt=fopen("Producto_temp.txt","wt");
    if(!pt)
    {
        fclose(p1);
        fclose(p2);
        return;
    }
    FILE* pe=fopen("Errores.txt","wt");
    if(!pe)
    {
        fclose(p1);
        fclose(p2);
        fclose(pt);
        return;
    }
    char linea1[TAM_LINEA];
    char linea2[TAM_LINEA];
    ProductoA* prod=malloc(sizeof(ProductoA));
    if(!prod)
    {
        fclose(p1);
        fclose(p2);
        return;
    }
    ProductoB* compra=malloc(sizeof(ProductoB));
    if(!compra)
    {
        fclose(p1);
        fclose(p2);
        free(prod);
        return;
    }
    int comparador=0;
    char* pp1=fgets(linea1,TAM_LINEA-1,p1);
    char* pp2=fgets(linea2,TAM_LINEA-1,p2);
    while(pp1 && pp2)
    {
        if(comparador==0)
        {
            ParsearProd(linea1,prod);
            ParsearCompra(linea2,compra);
        }
        comparador=cmp(prod,compra);
        if(comparador==0)
            {
                if(EvaluarStock(prod,compra)!=0)
                    Error(prod,compra,&pe);
                fprintf(pt,"%d|%s|%f|%d\n",prod->id_producto,prod->descripcion,prod->precio_unitario,prod->stock);
                pp1=fgets(linea1,TAM_LINEA-1,p1);
                pp2=fgets(linea2,TAM_LINEA-1,p2);
                comparador=cmp(prod,compra);
            }
        else
            {
                if(comparador<0)
                   {
                       fprintf(pt,"%d|%s|%f|%d\n",prod->id_producto,prod->descripcion,prod->precio_unitario,prod->stock);
                       pp1=fgets(linea1,TAM_LINEA-1,p1);
                       ParsearProd(linea1,prod);
                   }

                else
                    {
                        pp2=fgets(linea2,TAM_LINEA-1,p2);
                        ParsearCompra(linea2,compra);
                    }
            }


    }
    fclose(p1);
    fclose(p2);
    fclose(pt);
    fclose(pe);
    free(prod);
    free(compra);
    remove(lote1);
    rename("Producto_temp.txt",lote1);

}

void ParsearProd(char* linea,ProductoA* prod)
{
    char* aux;

    aux=strrchr(linea,'\n');
    *aux='\0';
    aux=strrchr(linea,'|');
    *aux='\0';
    sscanf(aux+1,"%d",&(prod->stock));
    aux=strrchr(linea,'|');
    *aux='\0';
    sscanf(aux+1,"%f",&(prod->precio_unitario));
    aux=strrchr(linea,'|');
    *aux='\0';
    strcpy(prod->descripcion,aux+1);
    sscanf(linea,"%d",&(prod->id_producto));
}
void ParsearCompra(char* linea,ProductoB* compra)
{
    char* aux;
    aux=strrchr(linea,'\n');
    *aux='\0';
    aux=strrchr(linea,'|');
    strcpy(compra->fecha,aux+1);
    *aux='\0';
    aux=strrchr(linea,'|');
    sscanf(aux+1,"%d",&compra->cantidad_comprada);
    *aux='\0';
    aux=strrchr(linea,'|');
    strcpy(compra->proveedor,aux+1);
    *aux='\0';
    sscanf(linea,"%d",&(compra->id_producto));

}

int EvaluarStock(ProductoA* prod,ProductoB* compra)
{
    if(prod->stock  >   compra->cantidad_comprada)
        prod->stock-=compra->cantidad_comprada;
    else
        return -1;
    return 0;
}
void Error(ProductoA* prod,ProductoB* compra,FILE** pe)
{
    prod->stock-=compra->cantidad_comprada;
    fprintf(*pe,"%d|%s|%f|%d\n",prod->id_producto,prod->descripcion,prod->precio_unitario,prod->stock);
}
