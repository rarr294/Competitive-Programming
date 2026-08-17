/*

Note : This is low level version of part_of_list problem that using type punning

Write a function partlist that gives all the ways to divide a list (an array) of at least two elements into two non-empty parts.

    Each two non empty parts will be in a pair (or an array for languages without tuples or a structin C - C: see Examples test Cases - )
    Each part will be in a string
    Elements of a pair must be in the same order as in the original array.

Examples of returns in different languages:

a = ["az", "toto", "picaro", "zone", "kiwi"] -->
[["az", "toto picaro zone kiwi"], ["az toto", "picaro zone kiwi"], ["az toto picaro", "zone kiwi"], ["az toto picaro zone", "kiwi"]] 
or
 a = {"az", "toto", "picaro", "zone", "kiwi"} -->
{{"az", "toto picaro zone kiwi"}, {"az toto", "picaro zone kiwi"}, {"az toto picaro", "zone kiwi"}, {"az toto picaro zone", "kiwi"}}
or
a = ["az", "toto", "picaro", "zone", "kiwi"] -->
[("az", "toto picaro zone kiwi"), ("az toto", "picaro zone kiwi"), ("az toto picaro", "zone kiwi"), ("az toto picaro zone", "kiwi")]
or 
a = [|"az", "toto", "picaro", "zone", "kiwi"|] -->
[("az", "toto picaro zone kiwi"), ("az toto", "picaro zone kiwi"), ("az toto picaro", "zone kiwi"), ("az toto picaro zone", "kiwi")]
or
a = ["az", "toto", "picaro", "zone", "kiwi"] -->
"(az, toto picaro zone kiwi)(az toto, picaro zone kiwi)(az toto picaro, zone kiwi)(az toto picaro zone, kiwi)"

*/

#include <stdio.h>  
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *part_of_list(char *str,size_t size){

  char *rest = malloc(
    ((size - 1) * 2) * sizeof(uintptr_t)
  );

  for(size_t a = 0;a <= (size - 2);a++){

    //first pair
    size_t offset = 0;
    size_t fsize = (a + 1);

    for(size_t b = 0;b <= a;b++){
      fsize += strlen(
        (char*)*(uintptr_t*)(str + sizeof(uintptr_t) * b)
      );
    }

    char *rst = (char*)(*(uintptr_t*)(rest + (sizeof(uintptr_t) * 2) * a) = (uintptr_t)malloc(fsize));

    for(size_t b = 0;b <= a;b++){


      for(size_t off = 0;*(char*)((*(uintptr_t*)(str + sizeof(uintptr_t) * b)) + off);off++){
        *(rst + offset++) = *(char*)((*(uintptr_t*)(str + sizeof(uintptr_t) * b)) + off);
      }

      *(rst + offset++) = 32;
    }

    *(rst + offset - 1) = 0;
    //

    //second pair
    offset = 0;
    size_t ssize = ((size - 1) - (a + 1)) + 1;

    for(size_t b = (a + 1);b < size;b++){
      ssize += strlen(
        (char *)(*(uintptr_t*)(str + sizeof(uintptr_t) * b))
      );
    }

    rst = (char *)(*(uintptr_t*)((rest + (sizeof(uintptr_t) * 2) * a) + sizeof(uintptr_t)) = (uintptr_t)malloc(ssize));

    for(size_t b = (a + 1);b < size;b++){

      for(size_t off = 0;*(char*)((*(uintptr_t*)(str + sizeof(uintptr_t) * b)) + off);off++){
        *(rst + offset++) = *(char*)((*(uintptr_t*)(str + sizeof(uintptr_t) * b)) + off);
      }

      *(rst + offset++) = 32;
    }

    *(rst + offset - 1) = 0;
    //
  }

  return rest;
}

int main(){
  size_t size = 5;
  const char *str[5] = {"123","456","789","101112","131415"};
  char address[5 * sizeof(uintptr_t)];

  for(int a = 0;a < 5;a++){
    *(uintptr_t*)(address + sizeof(uintptr_t) * a) = (uintptr_t)*(str + a);
  }
  
  char *rest = part_of_list(address,5);
  for(int a = 0;a < 4;a++){
     printf("{\"%s\",\"%s\"}\n",
        (char *)*(uintptr_t*)(rest + (sizeof(uintptr_t) * 2) * a),
        (char *)*(uintptr_t*)((rest + (sizeof(uintptr_t) * 2) * a) + sizeof(uintptr_t))
     );
  }
}

