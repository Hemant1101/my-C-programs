#include <stdio.h>
int main()
{
    int num, first, middle, last, search_element;
    printf("Enter number of elements-");
    scanf("%d", &num);
    int arr[num];
    printf("Enter the elements=\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the element to search=\n");
    scanf("%d", &search_element);
    first = 0;
    last = num - 1;
    middle = (first + last) / 2;
    while (first <= last)
    {
        if (arr[middle] < search_element)
        {
            first = middle + 1;
        }
        else if (arr[middle] == search_element)
        {
            printf("found element at position %d", middle + 1);
            break;
        }
        else
        {
            last = middle - 1;
            middle = (first + last) / 2;
        }
        if (first > last)
        {
            printf("NOT FOUND.");
        }
    }

    return 0;
}