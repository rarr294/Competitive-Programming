/*

Count the number of occurrences of each character and 
return it as a (list of tuples) in order of appearance. 
For empty output return (an empty list).

Consult the solution set-up for the exact data structure
implementation depending on your language.

Example:

ordered_count("abracadabra", *szout);

// using:
typedef struct Character_Count_Pair {
    char character;
    size_t count;
} ccp;

// returns:
{{'a', 5}, {'b', 2}, {'r', 2}, {'c', 1}, {'d', 1}}

// assigns length:
szout = 5

*/

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

typedef struct Character_Count_Pair {
    char character;
    size_t count;
} ccp;

ccp* ordered_count(char *str,size_t *sz){
  *sz = 0;
  
  if(!*str){
    return 0;
  }
  
  char key[128] = {0};
  ccp *mem = malloc(sizeof(ccp) * strlen(str));

  while(*str){

    if(*(key + *str) != 0){
      str++;
      continue;
    }

    *(key + *str) = 1;
    mem[*sz].character = *str;
    mem[*sz].count = 0;
    
    for(char *ptr = str;*ptr;ptr++){
      if(*ptr == mem[*sz].character){
        mem[*sz].count++;
      }
    }
                                                                       *sz = *sz + 1;
    str++;
  }

  return mem;
}
