// author:Hemant1101
// lang: C
// topic: Implementation of Binary tree and it's travarsals

#include <stdio.h>
#include <stdlib.h>

struct binarytree
{
    int data;
    struct binarytree *left;
    struct binarytree *right;
};

struct qnode
{
    struct binarytree *data;
    struct qnode *next;
};

struct queue
{
    struct qnode *rear;
    struct qnode *front;
};

struct binarytree *create();
void preorder(struct binarytree *);
void inorder(struct binarytree *);
void postorder(struct binarytree *);
void levelorder(struct binarytree *);

struct queue *createqueue();
int isemptyqueue(struct queue *);
struct binarytree *dequeue(struct queue *);
void enqueue(struct queue *, struct binarytree *);
void deletequeue(struct queue *);

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
    printf("\nlevelorder traversal of tree:\n");
    levelorder(root);
    return 0;
}

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

void levelorder(struct binarytree *root)
{
    struct binarytree *temp;
    struct queue *q = createqueue();
    if (!root)
    {
        return;
    }
    enqueue(q, root);
    while (!isemptyqueue(q))
    {
        temp = dequeue(q);
        printf("%d ", temp->data);
        if (temp->left)
        {
            enqueue(q, temp->left);
        }
        if (temp->right)
        {
            enqueue(q, temp->right);
        }
    }
    deletequeue(q);
}

struct qnode *newnode(struct binarytree *ptr)
{
    struct qnode *temp = (struct qnode *)malloc(sizeof(struct qnode));
    temp->data = ptr;
    temp->next = NULL;
    return temp;
}

struct queue *createqueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

int isemptyqueue(struct queue *q)
{
    if (q->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct binarytree *dequeue(struct queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    struct qnode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    struct binarytree *ptr = temp->data;
    free(temp);
    return ptr;
}

void enqueue(struct queue *q, struct binarytree *root)
{
    struct qnode *temp = newnode(root);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deletequeue(struct queue *q)
{
    free(q);
}
