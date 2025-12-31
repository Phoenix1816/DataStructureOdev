#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int N;

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int v = 0; v < N; v++) {
        if (graph[node][v] != 0 && !visited[v]) {
            dfs(v);
        }
    }
}

void findClusters() {
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    int clusterId = 1;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            printf("Cluster %d: ", clusterId++);
            dfs(i);
            printf("\n");
        }
    }
}

int main() {
    N = 5;

    // graph'i sýfýrla
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    // 0-1-2 baðlý (cluster 1)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;

    // 3-4 baðlý (cluster 2)
    graph[3][4] = graph[4][3] = 1;

    findClusters();

    return 0;
}
