/*

Given a triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...

find the triangle's row knowing its index(the rows are 1-indexed), 
e.g.:

odd_row(1)  ==  [1]
odd_row(2)  ==  [3, 5]
odd_row(3)  ==  [7, 9, 11]

Note: your code should be optimized to handle big inputs.

*/

#include <stdlib.h>

typedef unsigned long long uintll_t;

uintll_t *oddrow(size_t n){
  uintll_t *mem = malloc(n * sizeof(uintll_t));
  for(int a = 0;a < n;a++){
    (a == 0) ? (*mem = n * n - n + 1) : (
    *(mem + a) = ((n * n - n + 1) + 2 * a)
    );
  }
  return mem;
}
