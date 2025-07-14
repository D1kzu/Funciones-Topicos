#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define WIDTH 800
#define HEIGHT 600
#define XMIN -10
#define XMAX 10
#define YMIN -5
#define YMAX 5

unsigned char* crearBMP(int width, int height);
void dibujarPixel(unsigned char* img, int width, int height, int x, int y, unsigned char r, unsigned char g, unsigned char b);
void guardarBMP(const char* nombre, unsigned char* img, int width, int height);
void Ejes();

#endif // GRAF_H_INCLUDED
