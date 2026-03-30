/*

In this Kata, you will be given an array and your task will be 
to determine if an array is in ascending or descending order and 
if it is rotated or not.

Consider the array [1,2,3,4,5,7,12]. This array is sorted in Ascending order. 
If we rotate this array once to the left, we get [12,1,2,3,4,5,7] and twice-rotated 
we get [7,12,1,2,3,4,5]. These two rotated arrays are in Rotated Ascending order.

Similarly,the array [9,6,5,3,1] is in Descending order,but we can rotate it to get 
an array in Rotated Descending order: [1,9,6,5,3] or [3,1,9,6,5] etc.

Arrays will never be unsorted,except for those that are rotated as shown above. 
Arrays will always have an answer, as shown in the examples below.

More examples:

solve([1,2,3,4,5,7]) = "A" -- Ascending
solve([7,1,2,3,4,5]) = "RA" -- Rotated ascending
solve([4,5,6,1,2,3]) = "RA" -- Rotated ascending
solve([9,8,7,6]) = "D" -- Descending
solve([5,9,8,7,6]) = "RD" -- Rotated Descending

*/

#include <stddef.h>

enum array_type {A, RA, D, RD};

enum array_type find_array_type(size_t size,int *arr){
  int asc_flag = 0;
  int desc_flag = 0;

  for(int a = 1;a < size;a++){
    (*(arr + a - 1) > *(arr + a)) ? asc_flag = 1 : 0;
    (*(arr + a - 1) < *(arr + a)) ? desc_flag = 1 : 0;
  }

  return
  (asc_flag == 0) ? A  :
  (desc_flag == 0) ? D :
  (*(arr + size - 1) < *(arr)) ? RA : RD;
}
