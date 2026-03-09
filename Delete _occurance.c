/*

Task
Given a list and a number, create a new list that contains each number of list at most N times, without reordering.
For example if the input number is 2, and the input list is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], 
drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3].
With list [20,37,20,21] and number 1, the result would be [20,37,21].

*/

#include <stddef.h>
#include <stdlib.h>

int *delete_nth(size_t szin,const int *order,int n,size_t *szout){  
  if(order == NULL){
     *szout = 0;
     return NULL;
  }
  
  *szout = 1;
  int *freq = malloc(szin * 8);
  int *rest = malloc(szin * 4);

  int freq_size = 2;
  rest[0] = order[0];
  freq[0] = order[0];
  freq[1] = 1;

  for(int a = 1;a < szin;a++){
     int b = 0;
     char ava_flag = 0;

     while(b < freq_size){
        if(order[a] == freq[b]){
           ava_flag = 1;
           break;
        }
        b += 2;
     }

     if(ava_flag == 0){
       rest[*szout] = order[a];
       *szout = *szout + 1;

       freq[freq_size++] = order[a];
       freq[freq_size++] = 1;
       continue;
     }

     if(freq[b + 1] >= n){
        continue;
     }

     rest[*szout] = order[a];
     *szout = *szout + 1;
     freq[b + 1]++;
  }
  
  return rest;
}
