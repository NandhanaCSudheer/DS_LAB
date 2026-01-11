#include <stdio.h>
#define MAX 100
void displayGraph();
void createGraph();
void bfs();
int graph[MAX][MAX] = {0}, vertices;
void main()
{
    printf("How many vertices are there? :");
    scanf("%d", &vertices);
    if (vertices <= 0 || vertices > MAX)
    {
        printf("\nInvalid no. of vertices\n");
        return;
    }
    createGraph();
    displayGraph();
    bfs();
}
void bfs()
{
    int queue[MAX], visited[MAX], front = 0, rear = 0, pop, start;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    printf("\nEnter the vertex to start BFS from: ");
    scanf("%d", &start);
    if (start < 0 || start >= vertices)
    {
        printf("\nInvalid start vertex!\n");
        return;
    }
    queue[rear] = start;
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front <= rear)
    {
        pop = queue[front];
        printf("%d", pop);
        front++;
        for (int i = 0; i < vertices; i++)
        {
            if (graph[pop][i] == 1 && !visited[i])
            {
                rear++;
                queue[rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
void createGraph()
{
    int a, b;
    printf("Enter edges(enter -1 to stop):\n");
    while (1)
    {
        printf("Enter the first endpoint of the edge: ");
        scanf("%d", &a);
        if (a == -1)
        {
            break;
        }
        printf("Enter the second endpoint of the edge: ");
        scanf("%d", &b);
        if (a >= vertices || b >= vertices || a < 0 || b < 0)
        {
            printf("Invalid edge. Please enter vertices between 0 and %d.\n", vertices - 1);
        }
        else
        {
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
    }
}
void displayGraph()
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
}
