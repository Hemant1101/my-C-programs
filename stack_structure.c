#include <stdio.h>
#define max 10

struct STACK
{
    int top;
    int arr[max];
};
void push(struct STACK *st, int x)
{
    if (st->top == max - 1)
    {
        printf("Overflow");
    }
    else
    {
        int t;
        t = st->top;
        st->top = t + 1;
        st->arr[t + 1] = x;
        return;
    }
}
void pop(struct STACK *st)
{
    if (st->top == -1)
    {
        printf("Underflow");
    }
    else
    {
        int t;
        t = st->top;
        st->top = t - 1;
        printf("\n\t The popped elements is %d", st->arr[t]);
        st->arr[t] = NULL;
    }
    return;
}
void display(struct STACK *st)
{
    if (st->top == -1)
    {
        printf("Underflow");
    }
    else
    {
        int t;
        t = st->top;
        while (t >= 0)
        {
            printf("\n %d", st->arr[t]);
            t--;
        }
    }
    return;
}

int main()
{
    struct STACK s;
    int choice, num = 1;
    s.top = -1;
    while (num == 1)
    {
        printf("STACK menu:\n");
        printf("1.PUSH, 2. POP, 3. DISPLAY, 4.EXIT");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&s, 5);
            break;

        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            num = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}