/*

Find the number with the most digits.
If two numbers in the argument array have the same number of digits, 
return the first one in the array.

*/

#include <stddef.h>

int digit_count(int n){
  int size = 0;
  while(
    size++,
    n -= (n % 10),
    n /= 10 
  ){}
  return size;
} 

int find_longest(const int numbers[], size_t numbers_size){
   int value = numbers[0];
   for(int a = 0;a < numbers_size;a++){
      if(digit_count(numbers[a]) > digit_count(value)){
         value = numbers[a];
      }
   }
   return value;
}
