#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE];

int f1 = 0;
int r1 = 0;
int f2 = SIZE - 1;
int r2 = SIZE - 1;

void enqueue1(int x)
{
    if (r1 > r2 - 1)
    {
        printf("Overflow\n");
        return;
    }

    arr[r1++] = x;
}

int dequeue1()
{
    if (f1 == r1)
    {
        printf("Underflow\n");
        return -1;
    }

    return arr[f1++];
}

void enqueue2(int x)
{
    if (r2 < r1)
    {
        printf("Overflow\n");
        return;
    }

    arr[--r2] = x;
}

int dequeue2()
{
    if (f2 == r2)
    {
        printf("Underflow\n");
        return -1;
    }

    return arr[--f2];
}

int main()
{
    int n, i, q, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &q, &x);

        if (q == 1)
            enqueue1(x);
        else
            enqueue2(x);
    }

    while (f1 < r1)
    {
        printf("%d\n", dequeue1());
    }

    while (f2 < r2)
    {
        printf("%d\n", dequeue2());
    }

    return 0;
}
