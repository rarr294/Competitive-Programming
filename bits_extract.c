/*

Given a number n, you should find a set of numbers for which the sum equals n. 
This set must consist exclusively of values that are a power of 2 
(eg: 2^0 => 1, 2^1 => 2, 2^2 => 4, ...).

23 should return : 1,2,4,16 
because 1+2+4+16 = 23

56 should return : 8,16,32
because 8+16+32 = 56

0 must return (Null)0;

*/

#include <stdlib.h>
#define BASE 2

typedef unsigned long long uint64t;

void exponentBase2(int power,uint64t *addr){
  *addr = BASE;
  for(int a = 1;a < power;a++){
    *addr = *addr * BASE;
  }
}

uint64t *bits_extract(uint64t *offset,uint64t n){
  uint64t *rest = malloc(__builtin_popcountll(n) * 8);
  int power = 0;

  while(n){
    
    if(n & 1){
      if(power == 0){
        *(rest + *offset) = 1;
        *offset = *offset + 1;
        goto gohere;
      }

      exponentBase2(power,(rest + *offset));
      *offset = *offset + 1;
    }

    gohere:
    n >>= 1;
    power++;
  }
  
  return (n == 0) ? 0 : rest;
}
