#include <stdio.h>

int main()
{
    int num, contp = 0, contn = 0, cont0 = 0;

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    while (num >= 0)
    {
        if (num > 0)
            contp++;
        else
        {
            if (num < 0)
                contn = contn + 1;
            else
                cont0++;
        }

        printf("Ingrese un numero entero: ");
        scanf("%d", &num);
    }

    printf("\n%d %d %d", contp, contn, cont0);

    return 0;
}
