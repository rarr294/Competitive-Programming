/*

Given a list of digits, return the smallest number 
that could be formed from these digits, using the digits
only once (ignore duplicates). Only positive integers in 
the range of 1 to 9 will be passed to the function.

Examples
[1, 3, 1] ==> 13
[5, 7, 5, 9, 7] ==> 579
[1, 9, 3, 1, 7, 4, 6, 6, 7]  ==> 134679

*/

#include <stdlib.h>
#include <string.h>
#include <math.h>

int minValue(int* value,size_t size){
  int offset = 0;
  char *digit = malloc(size);

  for(int a = 0;a < size;a++){

    if(a == 0){
      *(digit + offset++) = *(value + a);
      continue;
    }

    int off = offset;

    while(off >= 1){

      if(*(value + a) < *(digit + off - 1)){
        *(digit + off) = *(digit + off - 1);
        off--;
        continue;
      }

      break;
    }

    (*(digit + off) = *(value + a),offset++);
  }

  int off = 0;
  char *uni_digit = malloc(size);

  for(int a = 0;a < offset;){

    if(a == (offset - 1)){
       *(uni_digit + off++) = *(digit + a);
       break;
    }

    if(*(digit + a) == *(digit + a + 1)){
       int val = *(digit + a);
       *(uni_digit + off++) = val;

       while(a++,*(digit + a) == val && a < offset){}
       continue;
    }

    *(uni_digit + off++) = *(digit + a++);
  }

  int sum = 0;
  int power = off - 1;

  for(int a = 0;a < off;a++){
    sum += *(uni_digit + a) * (int)pow(10,power--);
  }

  free(digit);
  free(uni_digit);
  return sum;
}
