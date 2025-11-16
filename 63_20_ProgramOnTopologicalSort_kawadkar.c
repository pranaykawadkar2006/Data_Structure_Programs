#include <stdio.h>

int g[10][10];
int visited[10];
int stack[10];
int top = -1;

void topo(int v, int n)
{
    int i;
    visited[v] = 1;

    for(i = 0; i < n; i++)
        if(g[v][i] && !visited[i])
            topo(i, n);

    stack[++top] = v;
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    for(i = 0; i < n; i++)
        if(!visited[i])
            topo(i, n);

    while(top >= 0)
        printf("%d ", stack[top--]);
}
