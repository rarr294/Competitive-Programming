/*

You are given a message (text) that you choose to read in a mirror (weirdo). 
Return what you would see, complete with the mirror frame. 

Example:

Hello World
*********
* olleH *
* dlroW *
*********

qtqxqtmbm grhminnwes xp r adguiw yugrijfspzzehot vngs

*******************
* mbmtqxqtq       *
* sewnnimhrg      *
* px              *
* r               *
* wiugda          *
* tohezzpsfjirguy *
* sgnv            *
*******************

don't have \n at the end of the string
*/


#include <stdlib.h>
#include <string.h>

char* mirror(const char* text){
  int w_size = 2;
  int row_size = 0;
  char first_flag = 1;
  int current_row_size = 0;

  const char *base = text;

  while(1){

    if(*text == 32){
      w_size++;

      if(row_size > (current_row_size - 5)){
         current_row_size = row_size + 5;
      }
      row_size = 0;
      first_flag = 2;
      goto gohere;
    }else if(*text == 0){
      w_size++;

      if(row_size > (current_row_size - 5)){
         current_row_size = row_size + 5;
      }

      break;
    }

    row_size++;
    (first_flag == 1) ? current_row_size++ : 0;

    gohere:
    text++;
  }

  int offset = current_row_size;
  char *mirrors = malloc(current_row_size * w_size);
  memset(mirrors,42,current_row_size);
  *(mirrors + offset - 1) = 10;

  text = base;
  while(1){                                                                                                     int ww_size = 0;

    if(*text == 32 || *text == 0){

      *(mirrors + offset++) = 42;
      *(mirrors + offset++) = 32;

      const char *t = text - 1;

      while(1){
        if(t == base){
          *(mirrors + offset++) = *t;
          ww_size++;
          break;
        }else if(*t == 32){
          break;
        }
        *(mirrors + offset++) = *t;
        ww_size++;
        t--;
      }

      while(ww_size < (current_row_size - 5)){
        *(mirrors + offset++) = 32;
        ww_size++;
      }

      *(mirrors + offset++) = 32;
      *(mirrors + offset++) = 42;
      *(mirrors + offset++) = 10;
    }

    if(*text == 0){
      break;
    }
    text++;
  }

  memset(mirrors + offset,42,current_row_size);
  *(mirrors + offset + current_row_size - 1) = 0;
  return mirrors;
}
