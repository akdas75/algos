#include <stdio.h>
#include <string.h>

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

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

    /**************************************/
    /* print the longest subsequence */

    i = m;
    j = n;

    char buf[50]="";
    int index =0;
    printf("Traversing .... \n");
    while (i > 0 && j > 0)
    {

        //printf ("## %c  %c\n",X[i-1], Y[j-1]);
        printf ("$$ %d  %d\n",i, j);

        if (X[i - 1] == Y[j - 1])
        {

            i--;
            j--;
            printf("## %c \n", X[i]);
            buf[index++] = X[i];
        }
        else
        {
            if (L[i - 1][j] > L[i][j - 1])
            {
                printf("#XX %c \n", X[i-1]);
                buf[index++] = X[i-1];
                i--;
            }
            else
            {
                printf("#YY %c \n", Y[j-1]);
                buf[index++] = Y[j-1];
                j--;
            }
        }
    }

    while (i > 0) {

        printf("#$$ XX %c \n", X[i-1]);
         
        buf[index++] = X[i-1];
        i--;  

    }

    while (j > 0) {

         printf("#$$ YY %c \n", Y[i-1]);

         buf[index++] = Y[j-1];
                j--;

    }

    buf[index++] = '\0';
    printf ("%s \n",buf);

    revstr(buf);
    printf ("%s \n",buf);

    return L[m][n];
}

/* Driver program to test above function */
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    //printf ("%d %lu \n",m,sizeof (X));

    printf("Length of LCS is %d", lcs(X, Y, m, n));

    return 0;
}
