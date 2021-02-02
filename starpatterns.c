#include <stdio.h>

void starpattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void revstarpattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = rows; j > i; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}

void pyramid(int rows)
{
    int min_star = 1;
    int x = rows;
    int y = x - 1;
    int k;
    for (int i = 0; i < x; i++)
    {
        for (int j = y; j > i; j--)
        {
            printf(" ");
        }
        for (k = 0; k < min_star; k++)
        {
            printf("*");
        }
        min_star += 2;
        printf("\n");
    }
}

void pyramid_1(int rows)
{
    int n = rows;
    int px = n;
    int py = n;
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < n * 2; j++)
        {
            if (j >= px && j <= py)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        px--;
        py++;

        printf("\n");
    }
}

int main()
{
    int rows, type;
    printf(" press 0 for starpattern and 1 for reverse starpattern , 2 for pyramid, 3 for pyramid_1.\n");
    scanf("%d", &type);
    printf(" how many rows you want?\n");
    scanf("%d", &rows);
    switch (type)
    {
    case 0:
        starpattern(rows);
        break;

    case 1:
        revstarpattern(rows);
        break;

    case 2:
        pyramid(rows);
        break;

    case 3:
        pyramid_1(rows);
        break;

    default:
        printf("Invalid Input.");
        break;
    }

    return 0;
}