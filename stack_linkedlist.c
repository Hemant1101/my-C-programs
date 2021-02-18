#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}
void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Underflow");
    }
    else
    {
        while (temp != NULL)
        {
            printf("\n %d", temp->data);
            temp = temp->link;
        }
    }
    return;
}
void peek()
{
    if (top == NULL)
    {
        printf("Underflow");
    }
    else
    {
        printf("\n top element of stack is %d", top->data);
    }
    return;
}
void pop()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Underflow");
    }
    else
    {
        printf("%d", top->data);
        top = top->link;
        free(temp);
    }
    return;
}

int main()
{
    push(5);
    peek();
    display();
    pop();
    return 0;
}