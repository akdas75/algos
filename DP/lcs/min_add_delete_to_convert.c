/*
Minimum Number of Insertion and Deletion to convert String a to String b
*/

/*
https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/ 
*/


#include <stdio.h>
#include <string.h>
 

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char *X, char *Y, int m, int n)
{

    int L[m + 1][n + 1];

    int i, j;

    for (i = 0; i <= m; i++)
        L[0][i] = 0;

    for (i = 0; i <= n; i++)
        L[i][0] = 0;

    for (i = 1; i <= m; i++)
    {

        for (j = 1; j <= n; j++)
        {

            if (X[i - 1] == Y[j - 1])
            {

                L[i][j] = 1 + L[i - 1][j - 1];
            }
            else
            {

                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // uncomment this code to print table
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            printf("%4d", L[i][j]);
        printf("\n");
    } 

    return L[m][n];
}

// Driver Code
int main()
{
    char *X = "heap";
    char *Y = "pea";

    int m = strlen(X), n = strlen(Y);

    int len = lcs(X, Y, m, n);
 
    printf("Length of LCS is %d \n", len);
   

    printf ("Number of deleteions %d \n",m - len);  
    printf ("Number of insertions %d \n",n - len);
    
    return 0;
}