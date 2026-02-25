/*

Description:

Give you two number rows , columns and a string str. Returns a rows x columns table pattern and fill in the str(each grid fill in a char, 
the length of str is always less than or equals to the total numbers of grids):

If rows = 4 and columns = 4, str = "Hello World!"
The pattern should be a 4x4 table like this:

+---+---+---+---+
| H | e | l | l |   From left to right
+---+---+---+---+
| o |   | W | o |   and from top to bottom
+---+---+---+---+
| r | l | d | ! |   each row separated by "\n"
+---+---+---+---+
|   |   |   |   |
+---+---+---+---+

*/

#include <stdlib.h>
#include <string.h>

char *pattern(unsigned width, unsigned height,const char *str){
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
  mem = cp_mem;


  int size = strlen(str);
  int offset = 0;
  for(int a = 1;a <= height;a++){
     if(offset == size){
       break;
     }
     mem += ((a == 1) ? width_size : width_size * 2);
     for(int a = 1;a < width_size;a++){
       if(offset == size){
          break;
       }else if(((a % 2) == 0) && ((a % 4) != 0)){
          *(mem + a) = *(str + offset);
          offset++;
       }
     }
  }
  return cp_mem;
}
