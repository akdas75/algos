

// C program for above approach
#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b)
{
  return (a > b) ? a : b;
}

#define false 0
#define true  1

typedef unsigned char bool;
 
bool 
cutrod_unkp (int price[], int length[], int n) {

    int K[n + 1][n + 1];

    int i,j;

    /*
    for (i=0; i<n; i++) {
         printf ("%d ",length [i]);    
    
    } 
    */

    printf ("\n"); 

    for (i=0; i <= n; i++) {
        K[0][i] = 0;
    }

     for (i=0; i<=n; i++) {
        K[i][0] = 0;
    } 

    /* 
    for (i=0; i<n; i++) {
         printf ("%d ",length [i]);    
    
    }
    */

    printf ("\n");  

    for (i=1; i<=n; i++) {

        for (j=1; j<=n; j++) {

          //printf ("T1 MM %d : NN %d \n", length[i-1], j);

            if ( length[i - 1] > j) {

                 //printf ("T1 i %d : j %d \n", i, j);                 

                 K[i][j] = K[i - 1][j];

            } else {

               //printf ("T2 i %d : j %d \n", i, j);  

                 K[i][j] =  max (K[i - 1][j] , 
                            price[i-1] + K[i][j - length[i - 1]]);

            }

        }    

    }

      // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", K[i][j]);
       printf("\n");
     }

    return K[n][n];

}

/* Driver program to test above functions */
int main()
{
    int arr[] ={1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);

    int length [size];

    for (int i = 0; i < size; i++)
         length [i] = i+1;

    /* 
     for (int i = 0; i < size; i++)
         printf ("%d ",length [i]);  
    */       
    
    printf ("\n"); 

    printf("Maximum Obtainable Value is %d", cutrod_unkp(arr, length, size));

  
    return 0;
}
