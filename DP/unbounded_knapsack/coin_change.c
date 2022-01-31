/*
Given a value N, if we want to make change for N cents, 
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? 
The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/


#include <stdio.h>

int 
coin_change_un_knp (int coin[], int n, int sum) {

    int K[n + 1][sum + 1];

    int i,j;

    for (i=0; i <= sum; i++) {
        K[0][i] = 0;
    }

     for (i=1; i<=n; i++) {
        K[i][0] = 1;
    } 

    for (i=1; i<=n; i++) {

        for (j=1; j<=sum; j++) {



            if (coin[i-1] > j) {

                 K[i][j] = K[i - 1][j];

            } else {

                 K[i][j] =  K[i - 1][j] +
                            K[i][j - coin[i-1]];

            }

        }    

    }

      // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", K[i][j]);
       printf("\n");
     }

    return K[n][sum];

}

// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", coin_change_un_knp(arr, m, 4));
   
    return 0;
}