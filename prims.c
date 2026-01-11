#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    int adj[n][n], visited[n];
    int u = 0, v = 0, cost = 0, min = INT_MAX;

    printf("\nEnter the cost adjacency matrix (Enter 0 for no edge):\n");

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0; 
        for (int j = 0; j < n; j++)
        {
            printf("Weight[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] < min)
            {
                min = adj[i][j];
                u = i;
                v = j;
            }
        }
    }

    cost += min;
    visited[u] = 1;
    visited[v] = 1;

    printf("\nSpanning Tree: Edges are:\n");
    printf("{%d, %d} = %d\n", u, v, min);

    int e = 1;

    while (e < n - 1)
    {
        min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && adj[i][j] < min)
                    {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (min == INT_MAX)
        {
            printf("\nGraph is disconnected. No MST possible\n");
            return 0;
        }

        cost += min;
        visited[v] = 1;
        printf("{%d, %d} = %d\n", u, v, min);
        e++;
    }

    printf("\nTotal Cost = %d\n", cost);
    return 0;
}
