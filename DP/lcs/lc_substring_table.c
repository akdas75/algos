

#include <stdio.h>
#include <string.h>

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

int 
lcs( char *X, char *Y, int m, int n ) {

    int L[m+1][n+1];

    printf ("%d  %d\n",m,n);

    int i,j;

    int lcs =0;

    for (i=0; i<=m; i++)
        L[0][i] = 0;

      for (i=0; i<=n; i++)
        L[i][0] = 0;  


      for (i=1; i<=m; i++) {
          
          for (j=1; j<=n; j++)   {

              if (X[i-1] == Y[j-1]) {

                  L[i][j] = 1 + L[i-1][j-1];
                  if(lcs < L[i][j])
	                {
	                    lcs = L[i][j];
	                   
	                }

              } else {

                  L[i][j] = 0;
              }

          }
      }    

       // uncomment this code to print table
     for (int i = 0; i <= m; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", L[i][j]);
     }

     printf ("\n");

    return lcs;
}





 
/* Driver program to test above function */
int main()
{
char X[] = "OldSite:GeeksforGeeks.org";
char Y[] = "NewSite:GeeksQuiz.com";
 
int m = strlen(X);
int n = strlen(Y);

//printf ("%d %lu \n",m,sizeof (X));
 
printf("Length of LCS is %d", lcs( X, Y, m, n ) );
 
return 0;
}


