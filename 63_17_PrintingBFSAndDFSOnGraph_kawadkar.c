#include <stdio.h>

int g[10][10];
int visited[10];
int q[10];
int f = 0, r = -1;

void bfs(int v, int n)
{
    int i;
    visited[v] = 1;
    q[++r] = v;

    while(f <= r)
    {
        v = q[f++];

        for(i = 0; i < n; i++)
        {
            if(g[v][i] && !visited[i])
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

void dfs(int v, int n)
{
    int i;
    visited[v] = 1;

    for(i = 0; i < n; i++)
        if(g[v][i] && !visited[i])
            dfs(i, n);
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    bfs(0, n);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0, n);
}
