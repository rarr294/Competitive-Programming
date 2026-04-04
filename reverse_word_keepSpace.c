/*

Complete the function that accepts a string parameter, and 
reverses each word in the string. All spaces in the string 
should be retained.

Examples
"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"

*/

#include <stdlib.h>
#include <string.h>

char* reverseWords(const char* text){
  int offset = 0;
  int size = strlen(text);
  char *mem = malloc(size + 1);

  for(int a = 0;a < size;){

    *(text + a) == 32 ? *(mem + offset++) = 32 : 0;

    if(*(text + a) != 32){
      int b = a;

      while(b++,*(text + b) != 32 && *(text + b) != 0){}

      for(int c = b - 1;c >= a;c--){
        *(mem + offset++) = *(text + c);
      }

      a = b;
      continue;
    }

    a++;
  }

  *(mem + offset) = 0;
  return mem;
}
