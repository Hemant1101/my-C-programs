#include <stdio.h>
#include <string.h>

/* You manage atravel agency and you want your n=3 drivers to input thier following details:
1. name
2. driving license no
3. route
4. Kms
your program should be able to take n=3 as input and your drivers wil start inputing thier detils one by one 
your program will print details in beautifull fashion.
use structures.
*/

// my try was same as codewithharry bhai .

int main()
{
    struct drdetails
    {
        char arr[10];
        char arr2[10];
        char arr3[10];
        int k;
    } d1, d2, d3;

    printf("put your deatils first name then lic no then route then kms-\n");
    scanf("%s %s %s %d", &d1.arr, &d1.arr2, &d1.arr3, &d1.k);
    printf("put your deatils first name then lic no then route then kms-\n");
    scanf("%s %s %s %d", &d2.arr, &d2.arr2, &d2.arr3, &d2.k);
    printf("put your deatils first name then lic no then route then kms-\n");
    scanf("%s %s %s %d", &d3.arr, &d3.arr2, &d3.arr3, &d3.k);
    printf("%s %s %s %d\n", d1.arr, d1.arr2, d1.arr3, d1.k);
    printf("%s %s %s %d\n", d2.arr, d2.arr2, d2.arr3, d2.k);
    printf("%s %s %s %d\n", d3.arr, d3.arr2, d3.arr3, d3.k);

    return 0;
}
