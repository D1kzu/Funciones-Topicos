#include <stdio.h>
#include <stdlib.h>

#include "examen.h"


#define NOMARCHEMP "empleados.bin"
#define NOMARCHEST "estudiantes.bin"


#define EXAMEN

#ifdef EXAMEN
    #define fbbinaria fbbinariaALUAGUSTIN
#endif // EXAMEN

typedef struct{
    tEstudiante est;
    int resultado;
}tEstudianteTest;



int main() {
    tEstudiante est;
    crearLoteEstudiantesDefault(NOMARCHEST);
   // VERARCHIVO(NOMARCHEST);
    //system("pause");
    //comEstDNI = comparacion estudiante por DNI
    est.dni = 10;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }

    puts("-------------------");
    est.dni = 20;
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }
    est.dni = 30;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }est.dni = 40;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }
    est.dni = 50;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }
     est.dni = 60;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }
     est.dni = 70;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }
     est.dni = 80;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }
     est.dni = 90;
    //풲enemos un estudiante con DNI 25?
    if(fbbinaria(&est, NOMARCHEST, sizeof(est), comEstDNI)){
        printf("Estudiante %d encontrado...\n", est.dni);
        printf("%d %s %s %.2f\n", est.dni, est.nombre, est.apellido, est.promedio);
    }else{
        printf("Estudiante %d NO encontrado...\n", est.dni);

    }
    // Return success status
    return 0;
}
