

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef unsigned char bool;





/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Maximum Obtainable Value is %d", cutRod(arr, size, 0));

    getchar();
    return 0;
}