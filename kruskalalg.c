#include <stdio.h>

#define MAXV 10
#define MAXE 100

int n, e;
int U[MAXE], V[MAXE], W[MAXE];
int parent[MAXV];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    parent[find(a)] = find(b);
}

void sortEdges() {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (W[j] > W[j + 1]) {
                int tempU = U[j], tempV = V[j], tempW = W[j];
                U[j] = U[j+1]; 
                V[j] = V[j+1];
                W[j] = W[j+1];
                U[j+1] = tempU;
                V[j+1] = tempV;
                W[j+1] = tempW;
            }
        }
    }
}

void kruskal() {
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges();

    printf("\nMST Edges:\n");
    int count = 0;
    
    for (int i = 0; i < e && count < n - 1; i++) {
        if (find(U[i]) != find(V[i])) {
            printf("%d -- %d (w = %d)\n", U[i], V[i], W[i]);
            Union(U[i], V[i]);
            count++;
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &U[i], &V[i], &W[i]);

    kruskal();

    return 0;
}