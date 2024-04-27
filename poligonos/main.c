#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return abs((A.X*(B.Y-C.Y) + B.X*(C.Y-A.Y) + C.X*(A.Y-B.Y))/2.0);
}

Ponto* leituraPontos(FILE* file, int n) {
    Ponto* pontos = (Ponto*) malloc(n * sizeof(Ponto));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%f %f", &pontos[i].X, &pontos[i].Y);
    }
    return pontos;
}

float calculaArea(Ponto* pontos, int n) {
    float area = 0.0;
    for (int i = 0; i < n - 1; i++) {
        area += AreaTriangulo(pontos[0], pontos[i], pontos[i+1]);
    }
    return area;
}

int main() {
    FILE *file = fopen("poligono.txt", "r");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    Ponto* pontos = leituraPontos(file, n);
    fclose(file);

    float area = calculaArea(pontos, n);
    printf("A area do poligono: %.2f\n", area);

    free(pontos);
    return 0;
}
