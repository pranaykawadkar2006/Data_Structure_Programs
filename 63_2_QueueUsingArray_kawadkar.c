#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int q[MAX];
int front = 0;
int rear = 0;

void enqueue(int x)
{
    if (rear == MAX)
    {
        printf("Overflow\n");
        return;
    }

    q[rear++] = x;
}

int dequeue()
{
    if (front == rear)
    {
        printf("Underflow\n");
        return -1;
    }

    return q[front++];
}

int main()
{
    int n, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    while (front < rear)
    {
        printf("%d\n", dequeue());
    }

    return 0;
}
