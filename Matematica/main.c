#include "matematica.h"

int main()
{
    double n1=6.28318;
    double tol=0.02;
    //if(Fibonacci(n1))
       // printf("\n el numero %d pertenece a la serie de fibonacci",n1);
    //else
        //printf("\n el numero %d NO pertenece a la serie de fibonacci",n1);
    printf("el seno de x=%f es: %f",n1,seno(n1,tol));
return 0;
}

