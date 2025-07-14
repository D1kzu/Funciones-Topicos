#include "Graf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define WIDTH 800
#define HEIGHT 600
#define XMIN -10
#define XMAX 10
#define YMIN -5
#define YMAX 5


int main() {
    char expr_str[100];
    printf("Ingrese la funcion f(x): ");
    fflush(stdin);
    gets(expr_str);
    while(strcmp(expr_str,"n"))
    {
        Ejes();
        printf("\nIngrese la funcion f(x): ");
        fflush(stdin);
        gets(expr_str);
    }
    return 0;
}
