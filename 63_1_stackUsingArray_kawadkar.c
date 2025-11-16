#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int top = -1;
int a[MAX];

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Overflow\n");
        return;
    }

    a[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return -1;
    }

    return a[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("Empty\n");
        return -1;
    }

    return a[top];
}

int main()
{
    int n, x, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    while (top != -1)
    {
        printf("%d\n", pop());
    }

    return 0;
}
