#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *r, int x)
{
    if(r == NULL)
    {
        r = malloc(sizeof(struct node));
        r->data = x;
        r->left = r->right = NULL;
        return r;
    }

    if(x < r->data)
        r->left = insert(r->left, x);
    else
        r->right = insert(r->right, x);

    return r;
}

void range(struct node *r, int l, int h)
{
    if(r == NULL)
        return;

    if(r->data > l)
        range(r->left, l, h);

    if(r->data >= l && r->data <= h)
        printf("%d ", r->data);

    if(r->data < h)
        range(r->right, l, h);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 20);

    range(root, 7, 18);
}
