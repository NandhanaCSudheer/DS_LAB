#include <stdio.h>

#define MAX 100

int main()
{
    int n, v1, v2;
    int adj[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Enter a valid number of vertices!\n");
        return 1;
    }

    while (1)
    {
        printf("Enter the starting vertex (-1 to stop): ");
        scanf("%d", &v1);
        if (v1 == -1)
            break;

        printf("Enter the ending vertex: ");
        scanf("%d", &v2);

        if (v1 < 0 || v2 < 0 || v1 >= n || v2 >= n)
        {
            printf("Enter valid vertices between 0 and %d\n", n - 1);
        }
        else
        {
            adj[v1][v2] = 1;
        }
    }

    printf("Topological Sorting is: ");

    for (int count = 0; count < n; count++)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int flag = 0;

                for (int j = 0; j < n; j++)
                {
                    if (adj[j][i] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }

                if (!flag)
                {
                    visited[i] = 1;

                    for (int k = 0; k < n; k++)
                    {
                        adj[i][k] = 0;
                    }

                    printf("%d ", i);
                    found = 1;
                    break;
                }
            }
        }

        if (!found)
        {
            printf("\nCycle detected. Topological sorting not possible.\n");
            return 1;
        }
    }

    return 0;
}
