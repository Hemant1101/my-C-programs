#include <stdio.h>
#include <stdlib.h>

struct qnode
{
    int data;
    struct qunode *next;
};

struct queue
{
    struct qnode *front;
    struct qnode *rear;
};

struct qnode *newnode(int k)
{
    struct qnode *temp = (struct qnode *)malloc(sizeof(struct qnode));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

struct queue *createqueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue *q, int k)
{
    struct qnode *temp = newnode(k);
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
    q->rear->next = q->front;
}

void dequeue(struct queue *q)
{
    if (q->front == NULL)
    {
        return;
    }
    if (q->front == q->rear)
    {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        struct qnode *temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
}

void display(struct queue *q)
{
    struct qnode *temp;
    temp = q->front;
    if (temp == NULL)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n");
        while (temp != q->rear)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
    }
    return;
}

int main()
{
    struct queue *q = createqueue();
    enqueue(q, 5);
    enqueue(q, 10);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}