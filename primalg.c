#include <stdio.h>

#define V 10

void prim(int weight[V][V], int n, int start) {
    int selected[V] = {0};
    int parent[V];
    int key[V];

    
    for (int i = 0; i < n; i++) {
        key[i] = 0;
        parent[i] = -1;
    }

    selected[start] = 1;  

 
    for (int v = 0; v < n; v++) {
        if (weight[start][v] != 0) {
            key[v] = weight[start][v];
            parent[v] = start;
        }
    }

    
    for (int edges = 1; edges < n; edges++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!selected[i] && key[i] > 0 && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (u == -1) break; 

        selected[u] = 1;

      
        for (int v = 0; v < n; v++) {
            if (!selected[v] && weight[u][v] != 0 &&
                (key[v] == 0 || weight[u][v] < key[v])) {

                key[v] = weight[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nMST Edges:\n");
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d - %d (w = %d)\n", parent[i], i, weight[i][parent[i]]);
        }
    }
}

int main() {
    int n, e, u, v, w;
    int weight[V][V] = {0};
    int adj[V][V] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);

        if (u == v) continue;  

        adj[u][v]++;

   
        if (weight[u][v] == 0 || w < weight[u][v]) {
            weight[u][v] = w;
            weight[v][u] = w;
        }
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    prim(weight, n, start);

    return 0;
}