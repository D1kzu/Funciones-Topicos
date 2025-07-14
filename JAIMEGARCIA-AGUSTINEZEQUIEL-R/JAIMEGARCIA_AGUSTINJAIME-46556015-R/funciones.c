#include "cabeceras.h"

TDASimVec* crearTDA(unsigned tam)
{
    TDASimVec *sv;
    sv = malloc(sizeof(TDASimVec));
    if(!sv)
        return NULL;

    sPalabras *vec;
    vec = malloc(tam * MIN_ELEM);
    if(!vec)
    {
        free(sv);
        return NULL;
    }

    sv->vec = vec;
    sv->ce = 0;
    sv->maxElem = MIN_ELEM;
    sv->tamElem = tam;
    return sv;
}

int voynich(TDASimVec* sv)
{
    FILE *fp = fopen("voynich.txt", "rt");
    if(!fp)
        return 0;

    void* pal = malloc(sizeof(sPalabras));
    if(!pal)
    {
        fclose(fp);
        return 0;
    }

    int col;
    char linea[MAX_LINEA];

    while(fgets(linea, MAX_LINEA-1, fp))
    {
        col = contarPalabras(linea);
        trozarLinea(linea, col, pal, sv);
    }

    fclose(fp);
    free(pal);
    return 1;
}

int contarPalabras(const char* linea)
{
    int i=1;
    while(*linea)
    {
        if(*linea == '.')
            i++;
        linea++;
    }
    return i;
}

void trozarLinea(char *linea, int col, void *pal, TDASimVec *sv)
{
    int i=0, pos;
    char palabra[MAX_LINEA];
    sPalabras* vec = (sPalabras*)pal;
    char *p;

    p = strchr(linea,'\n');
    if(p)
        *p = '\0';

    while(i<col)
    {
        if((p = strrchr(linea, '.')) != NULL)
        {
            sscanf(p+1, "%s", palabra);
            *p = '\0';
        }
        else
        {
            sscanf(linea, "%s", palabra);
        }

        if(!signoExclamacion(palabra))
        {
            strcpy(vec->nom, palabra);
            pos = buscar(vec->nom, sv, cmpNom);
            if(pos == -1)
            {
                vec->cont = 1;
                insertarAlFinal(sv, vec);
            }
        }

        i++;
    }
}

int signoExclamacion(char *s)
{
    while(*s)
    {
        if(*s == '?')
            return 1;
        s++;
    }
    return 0;
}

int cmpNom(const void* elem1, const void* elem2)
{
    sPalabras* pri = (sPalabras*)elem1;
    sPalabras* seg = (sPalabras*)elem2;
    return strcmp(pri->nom, seg->nom);
}

int cmpCont(const void* elem1, const void* elem2)
{
    sPalabras* pri = (sPalabras*)elem1;
    sPalabras* seg = (sPalabras*)elem2;
    return seg->cont - pri->cont;
}

void insertarAlFinal(TDASimVec *sv, void *elem)
{
    void *nVec;
    if(sv->ce == sv->maxElem)
    {
        nVec = realloc(sv->vec, (sv->maxElem + MIN_ELEM) * sv->tamElem);
        if(!nVec)
            return 0;

        sv->vec = nVec;
        sv->maxElem += MIN_ELEM;
    }

    memcpy((char *)sv->vec + sv->ce * sv->tamElem, elem, sv->tamElem);
    sv->ce++;
    return 1;
}

int buscar(char *linea, TDASimVec *sv, int (*cmp)(const void *, const void *))
{
    int i;
    sPalabras *vecPal = (sPalabras *)sv->vec;
    sPalabras temp;

    strcpy(temp.nom, linea);

    for(i = 0; i < sv->ce; i++)
    {
        if(cmp(&temp, &vecPal[i]) == 0)
        {
            vecPal[i].cont++;
            return i;
        }
    }

    return -1;
}

void ordenar(TDASimVec* sv, int (*cmp)(const void *, const void *))
{
    qsort(sv->vec, sv->ce, sv->tamElem, cmp);
}

void mostrar(TDASimVec* sv)
{
    sPalabras* vecPal = (sPalabras*)sv->vec;
    int i;

    printf("\nLas 10 palabras mas frecuentes son:\n");
    for(i = 0; i < 10 && i < sv->ce; i++)
    {
        printf("%d - %s con %d apariciones.\n", i+1, vecPal[i].nom, vecPal[i].cont);
    }
}

void destruirTDA(TDASimVec *sv)
{
    free(sv->vec);
    free(sv);
}
