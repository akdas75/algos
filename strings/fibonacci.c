
/* A Fibonacci sequence is the integer sequence of 0, 1, 1, 2, 3, 5, 8.... */
#include <stdio.h>
#include <stdlib.h>

void loop (int f1, int f2) {

    int f3;

    int n = 10;

    printf ("%d \n",f1);
    printf ("%d \n",f2);

    for (int i; i<n; i++) {
        
        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;

        printf ("%d \n",f3);

    }

}

void fib_l (int n) {

    printf ("computing fib for %d \n",n);

    int f1 = 1;
    int f2 = 1;

    int f3;

    for (int i =2; i<n; i++) {

        f3 = f2 + f1;
        f1 = f2;
        f2 = f3;

         printf ("fib_l %d \n",f3);
        

    }  

    printf ("fib_l final %d \n",f3);

}


#if 0
In this sequence the nth term is the sum of (n-1)th and (n-2)th terms.

To generate we can use the recursive approach,
 but in dynamic programming the procedure is simpler. 
 It can store all Fibonacci numbers in a table, by using that 
 table it can easily generate the next terms in this sequence.
#endif

int fibonacciNumber_dp(int n){
    int fibArray[n],i;
    fibArray[0] = 0, fibArray[1] = 1;
    for(i=2; i<n; i++)
        fibArray[i] = fibArray[i-1]+fibArray[i-2];
    return fibArray[n-1];
}


int *cache = NULL; 


int fib_r (int n) {

   // printf ("element %d \n",n);

    if  (n <=  1 ) {
        //printf ("returning %d \n",n);
        return n;
    }


    printf ("cache %d \n",cache[n-1]);

    if (cache [n-1] < 0) {

        printf ("coming here 1 %d \n", n);

         int k2 = (fib_r (n - 1) + fib_r (n - 2));
         cache [n-1] = k2;
         return k2;
    } else {
        printf ("coming here 2  %d \n", n);
        return cache [n-1];
    }  
    return 0; 

}

int main () {

    int f1 = 1;
    int f2 = 1;

    loop (f1 , f2);

    int k = 9;
    cache = (int *)malloc (k * sizeof (int));

    for (int i =0; i < k; i++) {
          cache [i] = -1;
    }

    for (int i =0; i < k; i++) {
          printf ("%d \n",cache [i]);
    }

    int m  = fib_r (k);
    printf ("FIB %d \n",m);

    for (int i =0; i < k; i++) {
          printf ("%d \n",cache [i]);
    }

    fib_l (9);

    int k5 = fibonacciNumber_dp (9);
    printf ("%d \n",k5);

    
}