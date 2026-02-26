/*

Given an array of strings and a character to be used as border, output the frame with the content inside.

Notes:

    Always keep a space between the input string and the left and right borders.
    The biggest string inside the array should always fit in the frame.
    The input array is never empty.

Example

frame(['Create', 'a', 'frame'], '+')

Output:

++++++++++
+ Create +
+ a      +
+ frame  +
++++++++++

*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *frame(const char *text[], size_t nline, char ch){
  int biggest_size = strlen(text[0]);
  for(int a = 0;a < nline;a++){
     if(strlen(text[a]) > biggest_size){
        biggest_size = strlen(text[a]);
     }
  }

  int width_size = biggest_size + 5;
  char *mem = malloc(width_size * (nline + 2));
  char *cp_mem = mem;

  memset(mem,ch,width_size);
  mem += width_size;
  *(mem - 1) = 10;

  for(int a = 0;a < nline;a++){
    int size = strlen(text[a]);

    *(mem++) = ch;
    *(mem++) = 32;
    memcpy(mem,text[a],size);
    mem += size;

    if(size < biggest_size){
       int total_space = biggest_size - size;
       for(int a = 1;a <= total_space;a++){
          *(mem++) = 32;
       }
    }

    *(mem++) = 32;
    *(mem++) = ch;
    *(mem++) = 10;
  }

  memset(mem,ch,width_size);
  mem += width_size;
  *(mem - 1) = 0;
  return cp_mem;
}
