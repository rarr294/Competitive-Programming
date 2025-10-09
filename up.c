#include <stdlib.h>
#include <string.h>
#include <stdio.h> //tracing debug

int *up_array(const int arr[/* count */], unsigned *count){
  //handling null
  if(arr == NULL || count == 0){
    return NULL;
  }
  
  //
  int size = sizeof(int) * (*count);
  int total_element = size / 4;
  int *result = (int*)malloc(size);

  //copying
  memcpy(result,arr,size);
  //

  //handling edge case
  for(int a = 0;a < total_element;a++){
    if((arr[a] >= 10) || (arr[a] < 0)){
      *count = 0;
      return NULL;
    }
  }
  //

  //counting
  if(result[total_element - 1] < 9){
     result[total_element - 1]++;
     return result; //return memory address of &result[0]
  }
  
  int track_carry = 1;
  for(int a = total_element-1;a >= 0;a--){
     if(track_carry == 0){
       break;
     }
     if(result[a]++,result[a] >= 10){
        result[a] = 0;
        continue;
     }
     track_carry = 0; //controlling the loop
  }
  //

  //handling bug
  int bug_control = 1;
  for(int a = 0;a < total_element;a++){
    if(result[a] > 0){
      bug_control = 0; //disable bug control
      break;
    }
  }

  if(bug_control == 1){
     free(result);
     result = (int*)malloc(size + 4); //+1 index
     result[0] = 1;
     for(int a = 1;a < (total_element + 1);a++){
       result[a] = 0;
     }
     *count = total_element + 1;
  }
  //
  return result;
}
