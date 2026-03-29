/*

Given a sequence of numbers.
find the largest pair sum in the sequence.

For example 

[3,2,3]             -->   6 (= 3  +  3)
[10, 14, 2, 23, 19] -->  42 (= 23 + 19)
[99, 2, 2, 23, 19]  --> 122 (= 99 + 23)

*/

#include <stddef.h>

typedef long long intll;

intll largest_pair_sum(size_t size,int *num){
  intll largest_1st = *num;

  for(int a = 1;a < size;a++){
    if(*(num + a) > largest_1st){
      largest_1st = *(num + a);
    }
  }

  int freq = 0;
  int first_flag = 0;
  intll largest_2nd = 0;

  for(int a = 0;a < size;a++){
    (*(num + a) == largest_1st) ? freq++ : 0;

    if(freq == 2){ return largest_1st + largest_1st;}

    if(*(num + a) < largest_1st && first_flag == 0){
      largest_2nd = *(num + a);
      first_flag = 1;
      continue;
    }

    (
     (*(num + a) > largest_2nd) &&
     (*(num + a) < largest_1st)
    ) ? largest_2nd = *(num + a) : 0;
  }

  return largest_1st + largest_2nd;
}
