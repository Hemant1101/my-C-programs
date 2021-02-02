#include <stdio.h>

int main()
{
    int n, c, d, swap;

    printf("Enter number of elements\n");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements\n", n);

    for (c = 0; c < n; c++)
        scanf("%d", &arr[c]);

    for (int i = 0; i < n - 1; i++)
    {
        for (d = 0; d < n - 1; d++)
        {
            if (arr[d] > arr[d + 1])
            {
                swap = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = swap;
            }
        }
    }

    printf("Sorted list in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}