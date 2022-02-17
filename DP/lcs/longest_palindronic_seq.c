/* Longest Palindromic Subsequence */

/*
LPS (a) = LCS (a - reverse (a))
*/


#include <stdio.h>
#include <string.h>






// function definition of the revstr()  
void revstr(char *str1)  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}




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



/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    char seqR[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);

    revstr (seqR);
    printf ("Reverse string %s \n",seqR);
    //printf ("The length of the LPS is %d", lps(seq));

    int len = lcs(seq, seqR, n, n);
 
    printf("Length of Longest Plandiromic sequence is %d \n", len);
   
    return 0;
}