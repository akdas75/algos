

import math 

def is_prime (num):

    if num <= 1:
        return False

    k = math.sqrt(num)

    k = int (math.ceil(k))

    for i in range (2,k+1):
        #print (i)
        if num % i == 0:
            return False 
    return True

element = 0
numPrime = 0

while (True):
     
     isPrime = is_prime (element)
     if isPrime:
        print (element)
        numPrime = numPrime + 1  
          
     if numPrime == 10:
         break;
     element = element + 1

    





