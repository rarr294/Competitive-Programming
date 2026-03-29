/*

This time no story, no theory. 
The examples below show you how to write function accum:

Examples:
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"

The parameter of accum is a string which includes only letters 
from a..z and A..Z.

*/


#include <stdlib.h>
#include <string.h>

char *accum(const char *s){
  int offset = 0;
  int n = strlen(s);
  char *mem = malloc((n * (n + 1)) / 2 + n);

  for(int a = 0;a < n;a++){
    char m = (!(*(s + a) > 96)) ? *(s+a)+32 : *(s+a);
    *(mem + offset++) = m - 32;

    int bound = a + 1;
    for(int a = 2;a <= bound;a++){
      *(mem + offset++) = m;
    }

    *(mem + offset++) = 45;
  }

  *(mem + offset - 1) = 0;
  return mem;
}
