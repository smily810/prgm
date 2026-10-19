#include<stdio.h>

int a[10][10], b[10];
int n, source;

void dfs(int source)
{
    int v;
    b[source] = 1;

    for(v = 1; v <= n; v++)
    {
        if(a[source][v] == 1 && b[v] == 0)
        {
            printf("vertex %d --> vertex %d\n", source, v);
            dfs(v);
        }
    }
}

void main()
{
    int i, j;

    printf("enter the number of cities\n");
    scanf("%d", &n);

    printf("enter the adjacency matrix\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("enter the source vertex\n");
    scanf("%d", &source);

    printf("nodes reachable from source vertex are\n");
    dfs(source);
}
