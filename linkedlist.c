#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void createlist(struct Node **head)
{
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            // temp->next = temp;
        }
        if (temp->next == NULL)
        {
            temp->next = newnode;
        }
    }
}

void push(struct Node **head)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void pushatend(struct Node **head)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->next = newnode;
    }
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

void insertafterpos(struct Node **head, int count)
{
    int pos, i = 1;
    printf("Emter the position:\n");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("Invalid position!");
        return;
    }
    else
    {
        struct Node *temp, *newnode;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        temp = *head;
        printf("Enter the data:\n");
        scanf("%d", &newnode->data);
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insertafterval(struct Node **head)
{
    int key;
    printf("enter the value:\n");
    scanf("%d", &key);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    temp = *head;
    while (temp->data != key)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("value not found\n");
            return;
        }
    }
    if (temp->data == key)
    {
        printf("Enter the data\n");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
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

int main()
{
    struct Node *head;
    head = NULL;
    int loop = 1;
    int count;
    int choice;
    while (loop == 1)
    {
        printf("enter your choice:\nfor creating new linked list 1 or \n printing list 2 \n ");
        printf("to push a number at beginning 3\n to enter at any position 4\n  to enter at end 5 \n to enter after a value 6 \n or to quit 0\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createlist(&head);
            break;
        case 2:
            printlist(head);
            break;

        case 3:
            push(&head);
            break;

        case 4:
            count = countlist(&head);
            insertafterpos(&head, count);
            break;

        case 5:
            pushatend(&head);
            break;

        case 6:
            insertafterval(&head);
            break;

        case 0:
            loop = 0;
            free(head);
            break;

        default:
            printf("invalid entry try again.\n");
            break;
        }
    }

    return 0;
}