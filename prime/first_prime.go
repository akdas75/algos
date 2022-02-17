

package main

import (
	"fmt"
	"math"
)

func is_prime (num int) bool {

	if num <= 1 {
	   return false
	}

	numF := float64 (num)
    m := math.Ceil(math.Sqrt(numF))
	l := int (m)

	for i := 2; i <= l; i++ {

		if (num % i == 0) {
			return false
		}
	}
    
	return true
}

func main () {

	fmt.Println ("First 10 prime numbers");

	numPrime := 0;
    element := 0;
    isPrime := false;
    

	for  {
           
		isPrime = is_prime (element);
		if (isPrime) {
		    fmt.Println (element)
			numPrime++;
		}	

		element++

		if (numPrime > 10) {
		    break;
		}	
            
	}


}