



#include<stdio.h>

int count( int S[], int m, int sum ) {


     /* base case */
    if (sum == 0)
          return 1;

    if (sum < 0)
          return 0;      

    if (m <= 0)
          return 0; 


     return (count (S, m, sum - S[m-1])   +  count (S, m-1, sum));    


}




// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, m, 4));
   
    return 0;
}