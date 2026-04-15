/*

The weight of a number is sum of its digits.

For example 99 will have "weight" 18, 100 will have "weight" 1 
so in the list 100 will come before 99.

Given a string with the weights of FFC members in normal order 
can you give this string ordered by "weights" of these numbers?

Example:
"56 65 74 100 99 68 86 180 90" ordered by numbers weights becomes: 

"100 180 90 56 65 74 68 86 99"
When two numbers have the same "weight", 
let us class them as if they were strings(alphabetical ordering)
and not numbers:

180 is before 90 since,having the same "weight" (9), it comes before as a string.
All numbers in the list are positive numbers and the list can be empty.

Notes
it may happen that the input string have leading, trailing whitespaces and more than a 
unique whitespace between two consecutive numbers

*/

#include <stdlib.h>
#include <string.h>

const char *g_str;

int cmp(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;

    int w1 = x[1];
    int w2 = y[1];

    if (w1 < w2) return -1;
    if (w1 > w2) return 1;

    // tie → lexicographical
    return strcmp(g_str + x[0], g_str + y[0]);
}

char *orderWeight(const char *str){
  g_str = str;
  int size = 0;
  int str_size = 0;

  for(int off = 0;*(str + off);){
     if(*(str + off) == 32){
       off++;
       continue;
     }

     size++;
     while(*(str + off) != 32 && *(str + off) != 0){
       off++;
       str_size++;
     }
     str_size++;
  }

  int offset = 0;
  int *mem = malloc(size * 8);

  for(int off = 0;*(str + off);){
     if(*(str + off) == 32){
       off++;
       continue;
     }

     int digit_sum = 0;
     *(mem + offset++) = off;

     while(*(str + off) != 32 && *(str + off) != 0){
       digit_sum += *(str + off) - 48;
       off++;
     }

     *(mem + offset++) = digit_sum;
  }

  qsort(mem, size, 2 * sizeof(int), cmp);

  offset = 0;
  char *rest = malloc(str_size);

  for(int a = 0;a < size;a++){
    const char *s = (str + *(mem + a * 2));

    while(*s != 32 && *s != 0){
      *(rest + offset++) = *s;
      s++;
    }

    *(rest + offset++) = 32;
  }
  
  free(mem);
  *(rest + offset - 1) = 0;
  
  return rest;
}
