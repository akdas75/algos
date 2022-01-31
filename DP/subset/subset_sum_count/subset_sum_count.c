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

int 
subsetSum_count_recursive (int set[], int n, int sum) {

    if (sum == 0)
        return 1;

    if (n == 0) 
        return 0;    

    // If last element is greater than sum,
    // then ignore it
    if (set[n-1] > sum) {            
        return subsetSum_count_recursive(set, n-1, sum);
    } else {
        return (subsetSum_count_recursive(set, n-1, sum - set[n-1])  +
                 subsetSum_count_recursive(set, n-1, sum));
    }   

}

bool 
SubsetSum_dp_count (int set[], int n, int sum) {

    bool K[n + 1][sum + 1];

    int i,j;

    for (i=0; i <= sum; i++) {
        K[0][i] = 0;
    }

     for (i=0; i<n; i++) {
        K[i][0] = 1;
    } 

    for (i=1; i<=n; i++) {

        for (j=1; j<=sum; j++) {

            if ( set[i-1] > j) {

                 K[i][j] = K[i - 1][j];

            } else {

                 K[i][j] =  K[i - 1][j] + 
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
    //int set[] = {3, 34, 4, 12, 5, 2}; 
    //int sum = 9; 
    //int n = sizeof(set)/sizeof(set[0]); 

     int set[] = { 3, 3, 3, 3 };
    int n = sizeof(set) / sizeof(int);
    int sum = 6;

    int m;
    m = subsetSum_count_recursive(set, n, sum);
	printf("subset count %d \n", m); 
   

    m = SubsetSum_dp_count(set, n, sum);
	printf("subset count %d \n", m); 

    return 0; 
} 
