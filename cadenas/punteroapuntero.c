#include <stdio.h>
#define TAM 5
int main()
{
    int vec[TAM]={3,4,5,6,7};
    int *pvec=vec;
    int** ppvec=&pvec;
    printf("\n%d",vec[0]);
    printf("\n%d",pvec);
    printf("\n%d",ppvec);
    printf("\n%d",*ppvec);
    printf("\n%d",**ppvec);
}
