/*

write a function that sums a list, but ignores any 
duplicated items in the list.

For instance, for the list [3, 4, 3, 6] the function should return 10,
and for the list [1, 10, 3, 10, 10] the function should return 4.

*/

#include <stddef.h>
#include <stdlib.h>

int sum_no_duplicates(size_t size,int *arr){

  int offset = 0;
  int *mem = malloc(size * 4);

  for(int a = 0;a < size;a++){
    if(offset == 0){
      *(mem + offset++) = *(arr + a);
      continue;
    }

    int b = offset;

    while(b >= 1){

      if(*(arr + a) == *(mem + b - 1)){
        break;
      }

      if(*(arr + a) < *(mem + b - 1)){
        *(mem + b) = *(mem + b - 1);
        b--;
        continue;
      }

      break;
    }

    *(mem + b) = *(arr + a);
    offset++;
  }

  int a = 0;
  int sum = 0;

  while(a < size){

    if((a + 1) == size){
      sum += *(mem + a);
      break;
    }

    if(*(mem + a) == *(mem + a + 1)){
      int val = *(mem + a++);
      while(a < size){
        if(*(mem + a) != val){
          break;
        }
        a++;
      }
      continue;
    }

    sum += *(mem + a);
    a++;
  }

  free(mem);
  return sum;
}
