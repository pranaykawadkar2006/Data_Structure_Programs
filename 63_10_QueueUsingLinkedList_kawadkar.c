#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *tmp = malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = NULL;

    if (!rear)
    {
        front = rear = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = tmp;
    }
}

int dequeue()
{
    if (!front)
    {
        printf("Underflow\n");
        return -1;
    }

    int x = front->data;
    struct Node *t = front;
    front = front->next;

    if (!front)
        rear = NULL;

    free(t);
    return x;
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

    while (front)
    {
        printf("%d\n", dequeue());
    }

    return 0;
}
