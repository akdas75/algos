

#include <stdio.h>
#include <string.h>

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

 int lcs1 = 0;

void
lcs (char *X, char *Y, int m, int n, int count) {

       printf ("%d %d \n",m,n);
       int res = 0;
       /* Base case */
       if ((m == 0) || (n == 0)) 
           return;

       if (X[m-1] == Y [n-1]) {

           count += 1;
           if (count > lcs1) {
               lcs1 = count;
               printf ("count %d \n",count);
              
           }
           lcs (X , Y, m -1 , n- 1,count);          
  
       }  else {

            lcs (X , Y, m  , n- 1, 0);
            lcs (X , Y, m -1 , n, 0);

       }  

}


/* Driver program to test above function */
int main()
{
char X[] = "Pban";
char Y[] = "Pcan";
 
int m = strlen(X);
int n = strlen(Y);


//printf ("%d %lu \n",m,sizeof (X));
 lcs( X, Y, m, n , 0);
printf("Length of LCS is %d",  lcs1);
 
return 0;
}


