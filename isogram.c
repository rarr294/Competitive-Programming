/*

An isogram is a word that has no repeating letters,consecutive or non-consecutive. 
Implement a function that determines whether a string that contains only letters is an isogram. 
Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true
"aba" --> false
"moOse" --> false (ignore letter case)

*/

#include <string.h>

char IsIsogram(const char *str){
  char key[256];
  memset(key,0,256);

  while(*str){
    char x = (*str >= 65 && *str <= 90) ? *str + 32 : *str;

    if(*(key + x) == 0){
      *(key + x) = 1;
    }else if(*(key + x) == 1){
      return 0;
    }
    str++;
  }
  
  return 1;
}
