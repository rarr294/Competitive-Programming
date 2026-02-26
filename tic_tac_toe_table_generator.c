/*

Do you have in mind the good old TicTacToe?

Assuming that you get all the data in one array, you put a space around each value, | as a columns separator and multiple - as rows separator, 
with something like ["O", "X", " ", " ", "X", " ", "X", "O", " "] you should be returning this structure (inclusive of new lines):

 O | X |   
-----------
   | X |   
-----------
 X | O |   

Now, to spice up things a bit, we are going to expand our board well beyond a trivial 3 x 3 square and we will accept rectangles of big sizes, still all as a long linear array.
For example, for "O", "X", " ", " ", "X", " ", "X", "O", " ", "O"] (same as above, just one extra "O") and knowing that the length of each row is 5, you will be returning

 O | X |   |   | X 
-------------------
   | X | O |   | O 

And worry not about missing elements, as the array/list/vector length is always going to be a multiple of the width

*/

#include <string.h>
#include <stdlib.h>

char *display_board(const char board[], int length, int width){
  int height = length / width;
  int width_size = width + width * 3;
  int total_size = width_size * (height * 2 - 1);
  int idx = 0;

  char *mem = malloc(total_size);
  char *cp_mem = mem;

  for(int a = 1;a <= height;a++){
    for(int b = 1;b <= width;b++){
       *(mem++) = 32;
       *(mem++) = board[idx++];
       *(mem++) = 32;
       *(mem++) = '|';
     }

     *(mem - 1) = 10;

     if(a == height){ 
        break;
     }
     memset(mem,'-',width_size - 1);
     *(mem += (width_size - 1)) = 10;
     mem++;
  }
  *(mem - 1) = 0;
  return cp_mem;
}
