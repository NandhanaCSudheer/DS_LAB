#include <stdio.h>
#include <stdlib.h> 

#define MAX_V 10


void topologicalSort(int graph[MAX_V][MAX_V], int V) {
    int indegree[MAX_V] = {0};
    int queue[MAX_V];
    int front = 0, rear = -1;
    int sorted[MAX_V];
    int count = 0;

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i; 
        }
    }
    while (front <= rear) {
        int u = queue[front++]; 
        sorted[count++] = u;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] == 1) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    queue[++rear] = v; 
            }
        }
    }
}
    if (count != V) {
        printf("\nGraph has a cycle. Topological sort is not possible.\n");
    } else {
        printf("\nTopological Order:\n");
        for (int i = 0; i < V; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");
    }
}
int main() {
    int V, E, u, v;

    printf("Enter number of vertices : ");
     scanf("%d", &V) ;
    

    printf("Enter number of edges: ");
    scanf("%d", &E);
    int graph[MAX_V][MAX_V] = {0}; 

    printf("Enter the edges (u v) where u is the start and v is the end vertex (starts with 0):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v) ;
        graph[u][v] = 1;
    }
    topologicalSort(graph, V);
    return 0;
}