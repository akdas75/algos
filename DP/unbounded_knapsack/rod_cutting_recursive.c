


// A Dynamic Programming solution for Rod cutting problem
#include<stdio.h>



// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}

/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n, int traverse_index){  

    int i, j;   

    if (n <= 0) {
        return 0;
    }

    printf ("Rod length %d \n",n);  

    int max_val = -1;

    for (i=0 ; i < n; i++) {    

        //printf ("Looping: %d ... %d \n", traverse_index, i);       

        max_val = max (max_val, price[i] + cutRod (price, n-1-i, traverse_index + 1));

    } 

    //printf ("Max val: %d  \n", max_val);
    return max_val;

}  

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Maximum Obtainable Value is %d", cutRod(arr, size, 0));

    getchar();
    return 0;
}