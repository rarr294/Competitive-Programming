/*

Description:
Well met with Fibonacci bigger brother, AKA Tribonacci. 
As the name may already reveal,it works basically like a Fibonacci, 
but summing the last (instead of 2) numbers of the sequence to generate the next. 

So, if we are to start our Tribonacci sequence with [1, 1, 1] as 
a starting input(AKA signature), we have this sequence:

[1, 1 ,1, 3, 5, 9, 17, 31, ...]

But what if we started with [0, 0, 1] as a signature? As starting with [0, 1] instead of [1, 1] 
basically shifts the common Fibonacci sequence by once place,you may be tempted to think that we 
would get the same sequence shifted by 2 places, but that is not the case and we would get:

[0, 0, 1, 1, 2, 4, 7, 13, 24, ...]

(1). Signature will always contain 3 numbers
(2). n will always be a non-negative number; 
(2). if n == 0, then return 0

Task : create a fibonacci function that given a signature array, 
returns the first n elements(signature included).

*/


#include <stdlib.h>
#include <string.h>

typedef long long intll;

intll *tribonacci(const intll *sign,size_t n){
  intll *rest = malloc(n * sizeof(intll));
  memcpy(rest,sign,(sizeof(intll) * 3));

  int offset = 0;

  for(int a = 3;a < n;a++){
    intll sum = 0;
    int mod_off = offset;

    for(int b = 1;b <= 3;b++){
      sum += *(rest + mod_off++);
    }

    *(rest + a) = sum;
    offset++;
  }

  return rest;
}
