#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int *arr;
int *top;
int *start;
int stacks;

void init(int k)
{
    stacks = k;

    arr = malloc(sizeof(int) * SIZE);
    top = malloc(sizeof(int) * k);
    start = malloc(sizeof(int) * k);

    int per = SIZE / k;
    int i;

    for (i = 0; i < k; i++)
    {
        start[i] = i * per;
        top[i] = start[i] - 1;
    }
}

void push(int s, int x)
{
    int per = SIZE / stacks;

    if (top[s] == start[s] + per - 1)
    {
        printf("Overflow\n");
        return;
    }

    arr[++top[s]] = x;
}

int pop(int s)
{
    if (top[s] < start[s])
    {
        printf("Underflow\n");
        return -1;
    }

    return arr[top[s]--];
}

int main()
{
    int k, n, i, idx, x;

    scanf("%d %d", &k, &n);

    init(k);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &idx, &x);
        push(idx, x);
    }

    for (i = 0; i < stacks; i++)
    {
        while (top[i] >= start[i])
        {
            printf("%d\n", pop(i));
        }
    }

    return 0;
}
