#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct {
    float X;
    float Y;
} Ponto;


float calcularAreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float det = (A.X * B.Y + B.X * C.Y + C.X * A.Y) - (A.Y * B.X + B.Y * C.X + C.Y * A.X);
    return 0.5 * abs(det);
}

int main() {
    FILE *file;
    int numVertices;

    setlocale(LC_ALL, "pt_BR.UTF-8");
    
   
    file = fopen("C:/Users/paulo/Desktop/output/vertices.txt", "r" );
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    
    fscanf(file, "%d", &numVertices);
    

    Ponto *vertices = malloc(sizeof(Ponto) * numVertices);
    
    for (int i = 0; i < numVertices; i++) {
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
    }
    
    fclose(file);
    

    float areaTotal = 0.0;
    
    for (int i = 1; i < numVertices - 1; i++) {
        areaTotal += calcularAreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    
   
    printf("A area do poligono e: %.2f\n", areaTotal);
    
   
    free(vertices);
    
    return 0;
}
