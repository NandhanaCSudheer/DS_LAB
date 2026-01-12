#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;  

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void BFS(int start) {
    enqueue(start);
    visited[start] = 1;

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
    int edges, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

   
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) - vertices numbered from 0 to %d:\n", n-1);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;  
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal:\n");
    BFS(start);

    return 0;
}