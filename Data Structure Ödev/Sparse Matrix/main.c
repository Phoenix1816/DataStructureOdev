#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int n;
    int m;
    Edge *edges;
} SparseMatrixGraph;

SparseMatrixGraph *createGraph(int n, int m) {
    SparseMatrixGraph *g = (SparseMatrixGraph *)malloc(sizeof(SparseMatrixGraph));
    g->n = n;
    g->m = m;
    g->edges = (Edge *)malloc(m * sizeof(Edge));
    return g;
}

void addEdge(SparseMatrixGraph *g, int index, int src, int dest, int weight) {
    g->edges[index].src = src;
    g->edges[index].dest = dest;
    g->edges[index].weight = weight;
}

void printDenseMatrix(SparseMatrixGraph *g) {
    int i, j;

    int **mat = (int **)malloc(g->n * sizeof(int *));
    for (i = 0; i < g->n; i++) {
        mat[i] = (int *)calloc(g->n, sizeof(int));
    }

    for (i = 0; i < g->m; i++) {
        int r = g->edges[i].src;
        int c = g->edges[i].dest;
        mat[r][c] = g->edges[i].weight;
    }

    printf("Komþuluk Matrisi (dense gösterim):\n");
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < g->n; i++) free(mat[i]);
    free(mat);
}

void printNeighbors(SparseMatrixGraph *g, int vertex) {
    printf("%d numaralý düðümün komþularý: ", vertex);

    for (int i = 0; i < g->m; i++) {
        if (g->edges[i].src == vertex) {
            printf("%d (aðýrlýk=%d)  ", g->edges[i].dest, g->edges[i].weight);
        }
    }
    printf("\n");
}

int main() {

    // ---- TÜRKÇE KARAKTER DESTEÐÝ ----
    setlocale(LC_ALL, "");

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    // ---------------------------------

    int n = 5;
    int m = 4;

    SparseMatrixGraph *g = createGraph(n, m);

    addEdge(g, 0, 0, 1, 1);
    addEdge(g, 1, 0, 2, 1);
    addEdge(g, 2, 1, 3, 1);
    addEdge(g, 3, 3, 4, 1);

    printf("Sparse Matrix kullanýlarak oluþturulan grafik:\n\n");

    printDenseMatrix(g);

    printf("\n");
    printNeighbors(g, 0);
    printNeighbors(g, 1);
    printNeighbors(g, 3);

    free(g->edges);
    free(g);

    return 0;
}
