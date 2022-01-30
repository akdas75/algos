

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef unsigned char bool;



// Driven Program
int main()
{
    int set[] = { 3, 1, 4, 2, 2, 1 };

    int n = sizeof(set) / sizeof(set[0]);

    int sum = 0;

    for (int i=0; i <n; i++) {
        
        sum +=  set[i];

    }

    printf ("Sum is %d \n",sum);

    /* subset problem */

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

     printf("\n");
     for (int j = 0; j <= sum; j++)
          printf ("%4d", K[n][j]);

     printf("\n"); 
    int diff = 1000000;

    printf("\n");
    for(int i=0; i<=sum/2; i++) {

        int first = i;
        int second = sum-i;

        if ((K[n][i] == true)  && (diff > abs (first - second))) {

            diff = abs (first - second);

        }
    }

    printf ("Minimum diff %d \n",diff);

    return 0;
}