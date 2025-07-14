#include "Graf.h"

double mapX(double x) {
    return (x - XMIN) * WIDTH / (XMAX - XMIN);
}

double mapY(double y) {
    return HEIGHT - (y - YMIN) * HEIGHT / (YMAX - YMIN);
}

unsigned char* crearBMP(int width, int height) {
    return malloc(3 * width * height);
}

void dibujarPixel(unsigned char* img, int width, int height, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    int index = 3 * (y * width + x);
    img[index] = b;
    img[index + 1] = g;
    img[index + 2] = r;
}

void guardarBMP(const char* nombre, unsigned char* img, int width, int height) {
    FILE* f = fopen(nombre, "wb");

    unsigned char file[14] = {
        'B', 'M', 0,0,0,0, 0,0, 0,0, 54,0,0,0
    };
    unsigned char info[40] = {
        40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0
    };

    int fileSize = 54 + 3 * width * height;
    file[2] = (unsigned char)(fileSize);
    file[3] = (unsigned char)(fileSize >> 8);
    file[4] = (unsigned char)(fileSize >> 16);
    file[5] = (unsigned char)(fileSize >> 24);

    info[4] = (unsigned char)(width);
    info[5] = (unsigned char)(width >> 8);
    info[6] = (unsigned char)(width >> 16);
    info[7] = (unsigned char)(width >> 24);
    info[8] = (unsigned char)(height);
    info[9] = (unsigned char)(height >> 8);
    info[10] = (unsigned char)(height >> 16);
    info[11] = (unsigned char)(height >> 24);

    fwrite(file, 1, 14, f);
    fwrite(info, 1, 40, f);

    // BMP se guarda de abajo hacia arriba
    for (int y = height - 1; y >= 0; y--) {
        fwrite(img + (y * width * 3), 3, width, f);
    }

    fclose(f);
}

void Ejes()
{
    unsigned char* image = crearBMP(WIDTH, HEIGHT);
    static i=1;
    char* cadena=malloc(sizeof(int)+strlen("graficoN%d.bmp"));
    sprintf(cadena,"%sN_%d.%s","grafico",i,"bmp");
    // Fondo blanco
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++)
        image[i] = 255;

    // Ejes
    int ejeY = mapX(0);
    int ejeX = mapY(0);

    for (int x = 0; x < WIDTH; x++)
        dibujarPixel(image, WIDTH, HEIGHT, x, ejeX, 0, 0, 0);
    for (int y = 0; y < HEIGHT; y++)
        dibujarPixel(image, WIDTH, HEIGHT, ejeY, y, 0, 0, 0);



    guardarBMP(cadena, image, WIDTH, HEIGHT);
    printf("Gráfico guardado como graficoN_%d.bmp\n",i);
    i++;
    free(image);

}
