/*
Funny Dots

You will get two integers n (width) and m (height) and your task is to draw the following pattern. 
Each line is seperated with a newline (\n)

Both integers are equal or greater than 1; no need to check for invalid parameters.

Examples :

                                          
             +---+                          
dot(1, 1) => | o |              
             +---+                          

              +---+---+---+
              | o | o | o |
dot(3, 2) =>  +---+---+---+          
              | o | o | o |
              +---+---+---+
*/
#include <stdlib.h>
#include <string.h>

char *dot(unsigned width, unsigned height){
  unsigned width_size = (width + 1) + (width * 3) + 1;
  unsigned height_size = (height + 1) + height;
  unsigned total_size = width_size * height_size;
  char *mem = malloc(total_size);
  char *cp = malloc(width_size);
  char *cp_mem = mem;

  for(int a = 0;a < width_size;a++){
     if((a % 4) == 0){
       *(mem + a) = '+';
        continue;
     }
     *(mem + a) = '-';
  }
  *(mem + (width_size - 1)) = 10;
  memcpy(cp,mem,width_size);

  for(int a = 0;a < width_size;a++){
     if((a % 4) == 0){
       *(mem + width_size + a) = '|';
       continue;
     }else if((a % 2) == 0){
       *(mem + width_size + a) = 'o';
       continue;
     }
     *(mem + width_size + a) = ' ';
  }
  *(mem + width_size * 2 - 1) = 10;
  memcpy((mem + width_size * 2),cp,width_size);
  *(mem + width_size * 3 - 1) = 10;


  for(int a = 1;a < height;a++){
     memmove(
      (mem += (width_size * 2)),
      cp_mem,
      width_size * 3
    );
  }
  *(mem + width_size * 3 - 1) = 0;
  return cp_mem;
}

