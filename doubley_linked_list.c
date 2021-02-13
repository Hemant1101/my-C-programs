#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void createlist(struct Node **head)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("enter the data:\n");
    scanf("%d", &newnode->data);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct Node *temp;
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void push(struct Node **head)
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    newnode->prev = NULL;
    temp = *head;
    temp->prev = newnode;
    *head = newnode;
}

int countlist(struct Node **head)
{
    int count = 1;
    struct Node *temp;
    temp = *head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void insert_at_pos(struct Node **head)
{
    int pos, i = 1, count;
    count = countlist(head);
    printf("length of list=\n%d\n", count);
    printf("Enter the position:\n");
    scanf("%d", &pos);
    if (pos == 0)
    {
        push(head);
        return;
    }
    if (pos > count)
    {
        printf("Invalid position!");
        return;
    }
    else
    {
        struct Node *temp, *prevnode, *newnode, *nextnode;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        temp = *head;
        printf("Enter the data:\n");
        scanf("%d", &newnode->data);
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        prevnode = temp;
        nextnode = temp->next;
        newnode->prev = prevnode;
        prevnode->next = newnode;
        newnode->next = nextnode;
    }
    return;
}

void insert_end(struct Node **head)
{
    struct Node *newnode, *temp;
    if (*head == NULL)
    {
        createlist(head);
        return;
    }
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void insert_before(struct Node **head)
{
    struct Node *newnode, *ptr;
    int val;
    printf("\n Enter the value before which the data has to be inserted : \n");
    scanf("%d", &val);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    ptr = *head;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr;
    newnode->prev = ptr->prev;
    ptr->prev->next = newnode;
    ptr->prev = newnode;
    return;
}

void insert_after(struct Node **head)
{
    struct Node *newnode, *ptr;
    int num, val;
    printf("\n Enter the value after which the data has to be inserted : \n");
    scanf("%d", &val);
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("\n Enter the data : \n");
    scanf("%d", &newnode->data);
    ptr = *head;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    newnode->prev = ptr;
    newnode->next = ptr->next;
    ptr->next->prev = newnode;
    ptr->next = newnode;
    return;
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

void delete_beg(struct Node **head)
{
    struct Node *ptr, *temp;
    temp = ptr = *head;
    temp = *head = ptr->next;
    temp->prev = NULL;
    free(ptr);
    return;
}

void delete_end(struct Node **head)
{
    struct Node *ptr;
    ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return;
}

void delete_after(struct Node **head)
{
    struct Node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to deleted : \n");
    scanf("%d", &val);
    ptr = *head;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return;
}

void delete_before(struct Node **head)
{
    struct Node *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to deleted : ");
    scanf("%d", &val);
    ptr = *head;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->prev;
    if (temp == *head)
        delete_beg(head);
    else
    {
        ptr->prev = temp->prev;
        temp->prev->next = ptr;
    }
    free(temp);
    return;
}

void delete_list(struct node **head)
{
    while (*head != NULL)
    {
        delete_beg(head);
    }
    return;
}

int main()
{
    struct Node *head;
    head = NULL;
    createlist(&head);
    push(&head);
    insert_end(&head);
    insert_at_pos(&head);
    printlist(head);
    delete_beg(&head);
    delete_end(&head);
    delete_after(&head);
    delete_before(&head);
    printlist(head);
    delete_list(&head);
    return 0;
}