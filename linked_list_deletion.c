#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void printlist(struct Node *node)
{
    printf("Linked list=\n");
    while (node != NULL)
    {
        printf(" %d \n", node->data);
        node = node->next;
    }
}

void pop(struct Node **head) // delete beginning
{
    struct Node *temp;
    temp = *head;
    *head = temp->next;
    free(temp);
    return;
}

void deletend(struct Node **head)
{
    struct Node *preptr, *ptr;
    ptr = *head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return;
}

void deletenode(struct Node **head)
{
    struct Node *preptr, *ptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted   : ");
    scanf("% d", &val);
    ptr = *head;
    if (ptr->data == val)
    {
        pop(&ptr);
        return;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                return;
            }
        }
        preptr->next = ptr->next;
        free(ptr);
        return;
    }
}

void delete_after(struct Node **head)
{
    struct Node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted: ");
    scanf("% d", &val);
    ptr = *head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return;
}

void delete_list(struct Node **head)
{
    struct Node *ptr;
    if (*head != NULL)
    {
        ptr = *head;
        while (ptr != NULL)
        {
            pop(ptr);
            ptr = *head;
        }
    }
    return;
}

int main()
{
    struct Node *head;
    head = NULL;
    push(&head);
    push(&head);
    push(&head);
    push(&head);
    printlist(head);
    pop(&head);
    printlist(head);
    deletend(&head);
    printlist(head);
    return 0;
}