#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void createClist(struct Node **head)
{
    int c = 1;
    while (c != -1)
    {
        struct Node *newnode, *temp;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data:\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (*head == NULL)
        {
            newnode->next = newnode;
            *head = newnode;
        }
        else
        {
            temp = *head;
            while (temp->next != *head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = *head;
        }
        printf("Enter 1 to continue -1 to end\n");
        scanf("%d", &c);
    }
    return;
}

void insertatbeg(struct Node **head)
{
    struct Node *newnode, *temp;
    if (*head == NULL)
    {
        createClist(head);
        return;
    }
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = *head;
    *head = newnode;
    return;
}

void insert_end(struct Node **head)
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = *head;
}

void delete_beg(struct Node **head)
{
    struct Node *temp, *ptr;
    if (*head == NULL)
    {
        printf("Underflow\n");
    }
    ptr = temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = ptr->next;
    *head = ptr->next;
    free(ptr);
    return;
}

void delete_end(struct Node **head)
{
    struct Node *temp, *ptr;
    temp = ptr = *head;
    while (temp->next != *head)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = *head;
    free(temp);
    return;
}

void delete_after(struct Node **head)
{
    struct Node *ptr, *preptr;
    int val;
    printf(" Enter the value after which the node has to deleted : \n");
    scanf("%d", &val);
    ptr = *head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    if (ptr == *head)
        *head = preptr->next;
    free(ptr);
    return;
}

void delete_list(struct Node **head)
{
    struct Node *ptr;
    ptr = *head;
    while (ptr->next != *head)
    {
        delete_end(head);
    }
    free(*head);
    return;
}

void printClist(struct Node *head)
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    temp = head;
    printf("circular linked list:\n");
    while (temp->next != head)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    return;
}

int main()
{
    struct Node *head;
    head = NULL;
    createClist(&head);
    printClist(head);
    insert_end(&head);
    insertatbeg(&head);
    printClist(head);
    delete_end(&head);
    delete_beg(&head);
    printClist(head);
    delete_list(&head);
    return 0;
}