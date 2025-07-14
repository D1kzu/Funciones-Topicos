#include "gbib.h"

/*int permutarArchClientesALU(const char* archOri, const char* archDes)
{
    return 0;///IMPLEMENTE AQUI,
}
*/
/*int restaurarArchClientesALU(const char* archOri, const char* archDes)
{
    int i = 0, cantReg;
    char linea[MAX_LINE]; // 6 + 1 + 65 + 1 + 513 + 1 + 9 + 1
    sCliente* clientes;
    sPerm* perm;
    FILE* pClientePerm;
    FILE* pPerm;
    FILE* pClienteRest;

    pClientePerm = fopen(archOri, "rt");

    if (!pClientePerm)
        return 0; /// error

    pPerm = fopen("perm.txt", "rt");

    if (!pPerm)
    {
        fclose(pClientePerm);
        return 0; /// error
    }

    pClienteRest = fopen(archDes, "wt");

    if (!pClienteRest)
    {
        fclose(pClientePerm);
        fclose(pPerm);
        return 0; /// error
    }

    clientes = malloc(MAX_REG * sizeof(sCliente));

    if (!clientes)
    {
        fclose(pClientePerm);
        fclose(pPerm);
        fclose(pClienteRest);
        return 0; /// error
    }

    perm = malloc(MAX_REG * sizeof(sPerm));

    if (!perm)
    {
        fclose(pClientePerm);
        fclose(pPerm);
        fclose(pClienteRest);
        free(clientes);
        return 0; /// error
    }

    while (fgets(linea, MAX_LINE, pClientePerm))
    {
        trozarMedicionVariable(linea, clientes+i);
        i++;
    }

    cantReg = i;
    i = 0;
    while (fgets(linea, MAX_LINE_PERM, pPerm))
    {
        trozarMedicionFija(linea, perm+i);
        i++;
    }

    while (i)
    {
        i--;
        intercambioGenerico(&(clientes+(perm+i)->elem1)->saldo, &(clientes+(perm+i)->elem2)->saldo, sizeof(clientes->saldo));
    }

    for (i = 0; i < cantReg; i++)
        fprintf(pClienteRest, "%d|%s|%s|%.2f\n", (clientes+i)->legajo, (clientes+i)->nomYAp, (clientes+i)->codSeg, (clientes+i)->saldo);

    free(clientes);
    free(perm);
    fclose(pClientePerm);
    fclose(pPerm);
    fclose(pClienteRest);

    return 1; /// todo bien, lo hice con 1 el "todo bien" y no con 0, porque como esta en el main, si devuelvo 0 va a hacer un printf de error. 1 = verdadero, 0 = falso.
}
*/
/*void intercambioGenerico(void* elem1, void* elem2, size_t tamElem)
{
    size_t i;
    char aux;

    for (i = 0; i < tamElem; i++)
    {
        aux = *(char*)elem1;
        *(char*)elem1 = *(char*)elem2;
        *(char*)elem2 = aux;
        elem1++;
        elem2++;
    }
}
*/
/*void trozarMedicionVariable(char* linea, sCliente* cliente)
{
    char* p;

    p = strrchr(linea, '|');
    sscanf(p+1, "%f", &(cliente->saldo));
    *p = '\0';

    p = strrchr(linea, '|');
    sscanf(p+1, "%s", cliente->codSeg);

    p = strchr(linea, '|');
    sscanf(p+1, "%[^|]", cliente->nomYAp); /// probando con el debugger, me di cuenta que el utilizar %[^|], sí pone el '\0' en cliente->nomYAp
    *p = '\0';

    sscanf(linea, "%d", &(cliente->legajo));
}
*/
/*void trozarMedicionFija(char* linea, sPerm* perm)
{
    char temp[MAX_RANGE];

    strncpy(temp, linea, 5);
    sscanf(temp, "%d", &(perm->elem1));
    linea += 5;

    sscanf(linea, "%d", &(perm->elem2));
}
*/
