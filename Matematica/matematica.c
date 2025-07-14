#include "matematica.h"

unsigned long long int factorial( int r)
{
    long long int resul = 1;
    int i;

    for (i=1;i<=r;i++)
        resul*=i;

    return resul;
}

int Combinatoria(unsigned int n1,unsigned int n2)
{
    int result=-1;
    if(n1>=n2){
    result=factorial(n1)/(factorial(n2)*factorial((n1-n2)));
    }
    return result;
}

double ex(int num,double tol)
{
    double result=1;
    double termino;
    int i=1;
    do{
        termino=pow(num,(double)(i))/(double)(factorial(i));
        result+=termino;
        i++;
    }while(termino>tol);
return result;
}

double raizCuadrada(int a,double tol)
{
    double resultado=1;
    double resultadoAnt=1;
    do{
        resultadoAnt=resultado;
       resultado=0.5*(resultadoAnt+(a/resultadoAnt));

    }while(fabs(resultadoAnt-resultado)>tol);

    return resultado;
}

int Fibonacci(int num)
{
    int anterior=0;
    int ant=1;
    int suma=0;

    do{
        suma=anterior+ant;
        anterior=ant;
        ant=suma;
    }while(num>suma);

    if(num==suma)
        return 1;
    else
        return 0;
}

double seno(double x,double tol)
{
    double tolerancia=0;
    double resultado=0;
    int i=1,j=0;
    do{
        tolerancia=pow(x,(double)(i+j))/factorial(i+j);
        i++;
        j++;
        if((j%2)!=0)
        resultado+=tolerancia;
        else
        resultado-=tolerancia;

    }while(fabs(tolerancia)>tol);
return fabs(resultado);
}

