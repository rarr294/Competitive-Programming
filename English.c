/*

Given a string of arbitrary length with any ascii characters.
Write a function to determine whether the string contains the 
whole word "English".

The order of characters is important -- a string "abcEnglishdef" 
is correct but "abcnEglishsef" is not correct.

Upper or lower case letter does not matter -- "eNglisH" is also correct.
Return value as boolean values, true for the string to contains "English",
false for it does not.

*/

#include <string.h>
#include <stdio.h>

char sp_eng(const char* str){
  char english[8] = {0};

  while(1){

    char en = (*str > 90) ? (*str - 32) : *str;

    if(en == 69){

      char off = 0;
      const char *s = str;

      while(*s && off < 7){

        en = (*s > 90) ? (*s - 32) : *s;

        if(off == 0){
          *(english + off++) = en;
          s++;
          continue;
        }

        if(en == *(english + off - 1)){
          break;
        }

        *(english + off++) = en;
        s++;
      }

      if(!strcmp(english,"ENGLISH")){
        return 1;
      }

      memset(english,0,8);
    }

    if(!(*str)){
      return 0;
    }

    str++;
  }

  return 0;
}
