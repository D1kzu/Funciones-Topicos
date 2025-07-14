#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define MAX_COL 50

#define MAX_FIL 50

int multiplicarMatrices(int mat1[][MAX_COL],
                        int fmat1,
                        int cmat1,
                        int mat2[][MAX_COL],
                        int fmat2,
                        int cmat2,
                        int matR[][MAX_COL]);


char *rstrrchr(const char *cad, int c);


int multiplicarMatricesAlumno(int mat1[][MAX_COL],
                        int fmat1,
                        int cmat1,
                        int mat2[][MAX_COL],
                        int fmat2,
                        int cmat2,
                        int matR[][MAX_COL]);


char *rstrrchrAlumno(const char *cad, int c);

#endif // EXAMEN_H_INCLUDED
