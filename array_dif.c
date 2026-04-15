/*

Implement a function that computes the difference between two lists. 
The function should remove all occurrences of elements from the first
list (a) that are present in the second list (b). The order of elements
in the first list should be preserved in the result.

Examples
If a = [1, 2] and b = [1], the result should be [2].
If a = [1, 2, 2, 2, 3] and b = [2], the result should be [1, 3].

*/

#include <stddef.h>
#include <string.h>

int *array_diff(int *a1,size_t n1,int *a2,size_t n2,size_t *z){
  *z = 0;
  
  if(a1 == 0){
    return 0;
  }
  
  int *rest = malloc(n1 * 4);
  
  if(a2 == 0){
    *z = n1;
    memcpy(rest,a1,n1 * 4);
    return rest;
  }

  for(int a = 0;a < n1;a++){
    char ava_flag = 0;

    for(int b = 0;b < n2;b++){
      if(a1[a] == a2[b]){
        ava_flag = 1;
        break;
      }
    }

    if(ava_flag == 1){
      continue;
    }

    *(rest + *z) = a1[a];
    *z = *z + 1;
  }

  return rest;
}
