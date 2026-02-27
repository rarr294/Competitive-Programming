/*

Rules:
(1). Take input as n which is always a natural number
(2). Space between each digit
(3). No space after the rows end

Examples

If n = 5, output should be:

 1 1 1 1 1
  2 2 2 2
   3 3 3
    4 4
     5             

f n = 9, output should be:

 1 1 1 1 1 1 1 1 1
  2 2 2 2 2 2 2 2
   3 3 3 3 3 3 3
    4 4 4 4 4 4
     5 5 5 5 5
      6 6 6 6
       7 7 7
        8 8
         9

If n = 16, output should be:

 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
  2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
   3 3 3 3 3 3 3 3 3 3 3 3 3 3
    4 4 4 4 4 4 4 4 4 4 4 4 4
     5 5 5 5 5 5 5 5 5 5 5 5
      6 6 6 6 6 6 6 6 6 6 6
       7 7 7 7 7 7 7 7 7 7
        8 8 8 8 8 8 8 8 8
         9 9 9 9 9 9 9 9
          0 0 0 0 0 0 0
           1 1 1 1 1 1
            2 2 2 2 2
             3 3 3 3
              4 4 4
               5 5
                6

*/



#include <stdlib.h>
#include <stdio.h>

char *pattern(unsigned n){
  int size = (n * 2 + 1) * n ;
  char *triangle = malloc(size);

  int number = 1;
  int idx = 0; 

  while(n >= 1){
    char digit = number % 10 + 48;

    for(int a = 1;a <= number;a++){
       triangle[idx++] = 32;
    }

    for(int a = 1;a <= n;a++){
       triangle[idx++] = digit;
       triangle[idx++] = 32;
    }

    triangle[idx - 1] = '\n';
    number++;
    n--;
  }
  triangle[idx - 1] = 0;
  return triangle;
}
