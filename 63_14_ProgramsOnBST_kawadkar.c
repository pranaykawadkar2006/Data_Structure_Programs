#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int x)
{
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct node* insert(struct node *root, int x)
{
    if(root == NULL)
        return create(x);

    if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void inorder(struct node *r)
{
    if(r)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node *r)
{
    if(r)
    {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r)
{
    if(r)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

void mirror(struct node *r)
{
    if(r)
    {
        struct node *t = r->left;
        r->left = r->right;
        r->right = t;

        mirror(r->left);
        mirror(r->right);
    }
}

struct node* parent(struct node *root, int x)
{
    if(root == NULL || root->data == x)
        return NULL;

    if((root->left && root->left->data == x) ||
       (root->right && root->right->data == x))
        return root;

    if(x < root->data)
        return parent(root->left, x);
    else
        return parent(root->right, x);
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    inorder(root);
}
