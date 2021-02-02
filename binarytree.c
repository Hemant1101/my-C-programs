#include <stdio.h>
#include <stdlib.h>

struct binarytree
{
    int data;
    struct binarytree *left;
    struct binarytree *right;
};

struct binarytree *create()
{
    struct binarytree *newnode;
    newnode = (struct binarytree *)malloc(sizeof(struct binarytree));
    printf("Enter the data or -1 for termination: \n");
    scanf("%d", &newnode->data);
    if (newnode->data == -1)
    {
        return NULL;
    }
    printf("enter left leaf:\n");
    newnode->left = create();
    printf("enter right leaf:\n");
    newnode->right = create();
    return newnode;
}

void preorder(struct binarytree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct binarytree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct binarytree *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct binarytree *root;
    root = create();
    printf("\ninorder traversal of tree:\n");
    inorder(root);
    printf("\npreorder traversal of tree:\n");
    preorder(root);
    printf("\npostorder traversal of tree:\n");
    postorder(root);
    return 0;
}