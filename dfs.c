#include <stdio.h>
void dfs(int n, int graph[n][n], int visited[], int source)
{
    printf("%d", source);
    visited[source] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[source][i] == 1 && !visited[i])
        {
            dfs(n, graph, visited, i);
        }
    }
}
int main()
{
    int n;
     int v1, v2;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
     int visited[n];
    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    printf("Enter edges(enter -1 to stop):\n");
    while (1)
    {
        printf("Enter the first endpoint of the edge: ");
        scanf("%d", &v1);
        if (v1 == -1)
        {
            break;
        }
        printf("Enter the second endpoint of the edge: ");
        scanf("%d", &v2);
        if (v1 >= n || v2 >= n || v1 < 0 || v2 < 0)
        {
            printf("Invalid edge.Please enter vertices between 0 and %d.\n", n - 1);
        }
        else
        {
            graph[v1][v2] = 1;
            graph[v2][v1] = 1;
        }
    }
    int source;
    printf("Enter the starting node: ");
    scanf("%d", &source);
    if (source < 0 || source >= n)
    {
        printf("Invalid starting node!\n");
        return 1;
    }
    printf("DFS -> ");
    dfs(n, graph, visited, source);
    printf("\n");
    return 0;
}