#include <stdio.h>

int g[10][10];
int disc[10];
int low[10];
int parent[10];
int timeDFS;
int ap;

void dfs(int u, int n)
{
    int v;
    int children = 0;

    disc[u] = low[u] = ++timeDFS;

    for(v = 0; v < n; v++)
    {
        if(g[u][v])
        {
            if(disc[v] == 0)
            {
                children++;
                parent[v] = u;

                dfs(v, n);

                low[u] = low[u] < low[v] ? low[u] : low[v];

                if(parent[u] == -1 && children > 1)
                    ap = 1;

                if(parent[u] != -1 && low[v] >= disc[u])
                    ap = 1;
            }
            else if(v != parent[u])
            {
                if(low[u] > disc[v])
                    low[u] = disc[v];
            }
        }
    }
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for(i = 0; i < n; i++)
    {
        disc[i] = 0;
        parent[i] = -1;
    }

    dfs(0, n);

    if(ap == 0)
        printf("Biconnected");
    else
        printf("Not Biconnected");
}
