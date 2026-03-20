/*

given a string of words 
return the length of the shortest word(s).
String will never be empty 

example :

the world maybe who knows perhaps : return 3

*/

#include <sys/types.h>

ssize_t find_short(const char *s){
  char first_flag = 0;
  ssize_t p_sum = 0;
  ssize_t c_sum = 0;

  while((*s == 0) ? (
  (p_sum < c_sum) ? (c_sum = p_sum,0) : 0
  ) : 1
  ){
    (*s == 32 && first_flag == 0) ?
    (c_sum = p_sum,p_sum = -1,first_flag = 1) : (*s == 32) ?
    ((p_sum < c_sum) ? (c_sum = p_sum,p_sum = -1) : (p_sum = -1))
    : 0;
    s++;
    p_sum++;
  }

  return (c_sum == 0) ? p_sum : c_sum;                           
}
