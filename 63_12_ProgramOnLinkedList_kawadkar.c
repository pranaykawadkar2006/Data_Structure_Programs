#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = head;
    head = t;
}

void insert_end(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if(head == NULL)
    {
        head = t;
        return;
    }

    struct node *p = head;
    while(p->next)
        p = p->next;

    p->next = t;
}

void delete(int x)
{
    struct node *p = head, *q = NULL;

    while(p && p->data != x)
    {
        q = p;
        p = p->next;
    }

    if(p == NULL)
        return;

    if(q == NULL)
        head = head->next;
    else
        q->next = p->next;

    free(p);
}

void reverse()
{
    struct node *p = head, *q = NULL, *r = NULL;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;
}

struct node* middle()
{
    struct node *slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int detect_loop()
{
    struct node *slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }

    return 0;
}

void print_odd_even()
{
    struct node *p = head;

    while(p)
    {
        if(p->data % 2 != 0)
            printf("%d ", p->data);

        p = p->next;
    }

    p = head;

    while(p)
    {
        if(p->data % 2 == 0)
            printf("%d ", p->data);

        p = p->next;
    }
}

int main()
{
    create(10);
    insert_end(20);
    insert_end(15);
    delete(20);
    reverse();

    struct node *m = middle();
    printf("%d\n", m->data);

    print_odd_even();
}
