/*

a = {1,2,3,4,5}
b = {1,3,5}
a - b = {2,4}

*/

#include <stddef.h>
#include <stdlib.h>

int *array_diff(int *a1,size_t n1,int *a2,size_t n2,size_t *offset){
  *offset = 0;
  int *rest = malloc(n1);

  for(int a = 0;a < n1;a++){
    char push_flag = 1;
    for(int b = 0;b < n2;b++){
      if(*(a1 + a) == *(a2 + b)){
        push_flag = 0;
        break;
      }
    }
    if(push_flag == 1){
      *(rest + *offset) = *(a1 + a);
      *offset = *offset + 1;
    }
  }
  return rest;
}
