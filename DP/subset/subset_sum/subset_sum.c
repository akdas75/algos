/*
    Given a set of non-negative integers, and a value sum, 
    determine if there is a subset of the given set with sum equal to given sum. 

    Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
    Output: True  
    There is a subset (4, 5) with sum 9.
*/

#include <stdio.h>

#define true 1
#define false 0

typedef unsigned char bool;

bool 
isSubsetSum_recursive (int set[], int n, int sum) {

    if (sum == 0)
        return true;

    if (n == 0) 
        return false;    

    // If last element is greater than sum,
    // then ignore it
    if (set[n-1] > sum) {            
        return isSubsetSum_recursive(set, n-1, sum);
    } else {
        return (isSubsetSum_recursive(set, n-1, sum - set[n-1])  ||
                 isSubsetSum_recursive(set, n-1, sum));
    }   

}

bool 
isSubsetSum_dp (int set[], int n, int sum) {

    bool K[n + 1][sum + 1];

    int i,j;

    for (i=0; i <= sum; i++) {
        K[0][i] = false;
    }

     for (i=0; i<=n; i++) {
        K[i][0] = true;
    } 

    for (i=1; i<=n; i++) {

        for (j=1; j<=sum; j++) {

            if ( set[i-1] > j) {

                 K[i][j] = K[i - 1][j];

            } else {

                 K[i][j] =  K[i - 1][j] || 
                            K[i - 1][j - set[i-1]];

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
    int set[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 9; 
    int n = sizeof(set)/sizeof(set[0]); 
    if (isSubsetSum_recursive(set, n, sum) == true) 
	   printf("Found a subset with given sum \n"); 
    else
	   printf("No subset with given sum \n"); 

    if (isSubsetSum_dp(set, n, sum) == true) 
	   printf("Found a subset with given sum \n"); 
    else
	   printf("No subset with given sum \n"); 

    return 0; 
} 
