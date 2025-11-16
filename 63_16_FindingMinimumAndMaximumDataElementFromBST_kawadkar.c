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

int min(struct node *r)
{
    while(r->left)
        r = r->left;

    return r->data;
}

int max(struct node *r)
{
    while(r->right)
        r = r->right;

    return r->data;
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 50);
    insert(root, 20);
    insert(root, 80);

    printf("%d\n", min(root));
    printf("%d\n", max(root));
}
