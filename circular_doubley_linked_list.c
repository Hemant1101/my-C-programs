#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void createCDlist(struct Node **head)
{
    struct Node *new_node, *ptr, *temp;
    int num;
    printf("\n Enter –1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (*head == NULL)
        {
            new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = num;
            temp = ptr = *head;
            while (ptr->next != *head)
                ptr = ptr->next;
            new_node->prev = ptr;
            ptr->next = new_node;
            new_node->next = *head;
            temp->prev = new_node;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
}

void insert_beg(struct Node **head)
{
    struct Node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    ptr = *head;
    while (ptr->next != *head)
        ptr = ptr->next;
    new_node->prev = ptr;
    ptr->next = new_node;
    new_node->next = *head;
    new_node->next->prev = new_node;
    *head = new_node;
    return;
}

void insert_end(struct Node **head)
{
    struct Node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = num;
    ptr = *head;
    while (ptr->next != *head)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = *head;
    new_node->next->prev = new_node;
    return;
}

void delete_beg(struct Node **head)
{
    struct Node *ptr, *temp;
    temp = ptr = *head;
    while (ptr->next != *head)
        ptr = ptr->next;
    ptr->next = temp->next;
    *head = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return;
}

void delete_end(struct Node **head)
{
    struct Node *ptr, *temp;
    temp = ptr = *head;
    while (ptr->next != *head)
        ptr = ptr->next;
    ptr->prev->next = *head;
    temp->prev = ptr->prev;
    free(ptr);
    return;
}

void delete_node(struct Node **head)
{
    struct Node *ptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);
    ptr = *head;
    if (ptr->data == val)
    {
        delete_beg(head);
        return;
    }
    else
    {
        while (ptr->data != val)
            ptr = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return;
    }
}

void delete_list(struct Node **head)
{
    struct Node *ptr;
    ptr = *head;
    while (ptr->next != *head)
        delete_end(head);
    free(head);
    return;
}

void printlist(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    while (ptr->next != head)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data);
    return;
}

int main()
{
    struct Node *head;
    head = NULL;
    createCDlist(&head);
    insert_beg(&head);
    insert_end(&head);
    printlist(head);
    delete_beg(&head);
    delete_end(&head);
    delete_node(&head);
    printlist(head);
    delete_list(&head);
    return 0;
}