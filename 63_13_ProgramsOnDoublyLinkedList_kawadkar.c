#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_front(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->prev = NULL;
    t->next = head;

    if(head)
        head->prev = t;

    head = t;
}

void insert_end(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if(head == NULL)
    {
        t->prev = NULL;
        head = t;
        return;
    }

    struct node *p = head;

    while(p->next)
        p = p->next;

    p->next = t;
    t->prev = p;
}

void delete(int x)
{
    struct node *p = head;

    while(p && p->data != x)
        p = p->next;

    if(p == NULL)
        return;

    if(p->prev)
        p->prev->next = p->next;
    else
        head = p->next;

    if(p->next)
        p->next->prev = p->prev;

    free(p);
}

void reverse()
{
    struct node *p = head, *temp = NULL;

    while(p)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    }

    if(temp)
        head = temp->prev;
}

int main()
{
    insert_front(10);
    insert_end(20);
    insert_end(30);
    delete(20);
    reverse();
}
