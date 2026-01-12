#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

/* Queue operations */
void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

/* BFS function */
void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    /* Initialize adjacency matrix and visited */
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}
