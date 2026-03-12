/*

You are given an array (which will have a length of at least 3, but could be very large) containing integers. 
The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. 
Write a method that takes the array as an argument and returns this "outlier" N.

Examples

[2, 4, 0, 100, 4, 11, 2602, 36] -->  11 (the only odd number)
[160, 3, 1719, 19, 11, 13, -21] --> 160 (the only even number)

*/

#include <stddef.h>

int find_outlier(int value[],size_t count){
  int odd_total = 0;
  int even_total = 0;

  for(int a = 0;a <= 2;a++){
     if(((value[a] < 0 ? value[a] * -1 : value[a]) % 2) == 0){
       even_total++;
       continue;
     }
     odd_total++;
  }

  if(even_total > odd_total){
     for(int a = 0;a < count;a++){
        if(((value[a] < 0 ? value[a] * -1 : value[a]) % 2) != 0){
           return value[a];
        }
     }
  }

  for(int a = 0;a < count;a++){
     if(((value[a] < 0 ? value[a] * -1 : value[a]) % 2) == 0){
        return value[a];
     }
  }
  return 0;
}
