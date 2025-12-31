#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];  // adjacency list
int deg[MAX];         // degree array
int visited[MAX];
int N;                // node sayýsý

// ---------- DFS ----------
void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < deg[node]; i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

// ---------- BFS ----------
void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < deg[node]; i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
            }
        }
    }
}

int main() {

    N = 6; // 0..5

    // graph baþlangýçta boþ
    for (int i = 0; i < N; i++)
        deg[i] = 0;

    // ----- ÖRNEK GRAPH -----
    // 0 -- 1 -- 2
    // |    |
    // 3 -- 4 -- 5

    graph[0][deg[0]++] = 1;
    graph[1][deg[1]++] = 0;

    graph[1][deg[1]++] = 2;
    graph[2][deg[2]++] = 1;

    graph[0][deg[0]++] = 3;
    graph[3][deg[3]++] = 0;

    graph[1][deg[1]++] = 4;
    graph[4][deg[4]++] = 1;

    graph[3][deg[3]++] = 4;
    graph[4][deg[4]++] = 3;

    graph[4][deg[4]++] = 5;
    graph[5][deg[5]++] = 4;

    // ---------- DFS ----------
    for (int i = 0; i < N; i++)
        visited[i] = 0;

    printf("DFS (0'dan basla): ");
    dfs(0);
    printf("\n");

    // ---------- BFS ----------
    printf("BFS (0'dan basla): ");
    bfs(0);
    printf("\n");

    return 0;
}
