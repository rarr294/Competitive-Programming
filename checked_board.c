/*

Write a function which takes one parameter representing the dimensions of a checkered board. 
The board will always be square, so 5 means you will need a 5x5 board.

The dark squares will be represented by a unicode white square,while the light squares will be represented by a unicode black square 
(the opposite colours ensure the board doesn't look reversed on code wars' dark background). 
It should return a string of the board with a space in between each square and taking into account new lines.

An even number should return a board that begins with a dark square.
An odd number should return a board that begins with a light square.

Examples

Input: 5

Output:
■ □ ■ □ ■
□ ■ □ ■ □
■ □ ■ □ ■
□ ■ □ ■ □
■ □ ■ □ ■

There should be no trailing white space at the end of each line, or new line characters at the end of the string.

color_flag meaning :

1 = black
2 = white

*/

#include <stdlib.h>
#include <string.h>


char *board(unsigned n){
  char black[4] = {226,150,161,32};
  char white[4] = {226,150,160,32};

  int size = n * n * 4;
  char *board = malloc(size);

  int offset = 0;
  int total_loop = n * n;
  char global_color_flag = ((n % 2) == 0) ? 1 : 2;

  for(int outer = 1;outer <= n;outer++){
     char color_flag = global_color_flag;
     for(int a = 1;a <= n;a++){
        if(color_flag == 1){
           memcpy(board + offset,black,4);
           color_flag = 2;
        }else if(color_flag == 2){
           memcpy(board + offset,white,4);
           color_flag = 1;
        }
        offset += 4;
     }
     *(board + offset - 1) = 10;
     (global_color_flag == 1) ? (global_color_flag = 2) : (global_color_flag = 1);
  }
  *(board + size - 1) = 0;
  return board;
}
