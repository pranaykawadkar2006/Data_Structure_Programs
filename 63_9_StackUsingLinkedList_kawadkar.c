#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x)
{
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = top;
    top = tmp;
}

int pop()
{
    if (!top)
    {
        printf("Underflow\n");
        return -1;
    }

    int x = top->data;
    struct Node *t = top;
    top = top->next;
    free(t);
    return x;
}

int peek()
{
    if (!top)
    {
        printf("Empty\n");
        return -1;
    }

    return top->data;
}

int main()
{
    int n, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    while (top)
    {
        printf("%d\n", pop());
    }

    return 0;
}
