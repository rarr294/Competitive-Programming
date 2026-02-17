/*
Christmas is coming, and your task is to build a custom Christmas tree with the specified characters and the specified height
Inputs:
chars: the specified characters.
n: the specified height. A positive integer greater than 2.

Output:
A multiline string. Each line is separated by \n. A tree contains two parts: leaves and trunks.
The leaves should be n rows. The first row fill in 1 char, the second row fill in 3 chars, and so on. 
A single space will be added between two adjust chars, and some of the necessary spaces will be added to the left side, to keep the shape of the tree. 
No space need to be added to the right side.The trunk should be at least 1 unit height, it depends on the value of the n. 
The minimum value of n is 3, and the height of the tree trunk is 1 unit height. If n increased by 3, and the tree trunk increased by 1 unit. 
For example, when n is 3,4 or 5, trunk should be 1 row; when n is 6,7 or 8, trunk should be 2 row; and so on.

Examples

For chars = "*@o" and n = 3,the output should be:
  *
 @ o
* @ o
  |

For chars = "1234" and n = 6,the output should be:

     1
    2 3
   4 1 2
  3 4 1 2
 3 4 1 2 3
4 1 2 3 4 1
     |
     |
*/

#include <stdlib.h>
#include <string.h>

char *custom_christmas_tree(const char *c, unsigned n){
  unsigned total_space = n-1;
  unsigned total_trunk = n;
  unsigned middle_trunk = (n + n - 1) / 2;
  unsigned length = strlen(c);

  while(
    (total_trunk % 3 == 0) ? 0 : total_trunk--,
    (total_trunk % 3) != 0
  ){}

  total_trunk /= 3;

  char *mem = malloc(
     ((n + n) * n) + ((n + n) * total_trunk)
  );

  unsigned index = 0;
  unsigned c_index = 0;
  for(unsigned a = 1;a <= n;a++){

    for(unsigned b = 1;b <= total_space;b++){
       mem[index++] = ' ';
    }

    for(unsigned d = 1;d <= a;d++){
       mem[index++] = c[c_index++];
       c_index = (c_index == length) ? 0 : c_index;
       mem[index++] = ' ';
    }

    mem[index - 1] = '\n';
    total_space--;
  }

  char *mem_ = malloc(middle_trunk + 2);
  for(unsigned a = 0;a <= middle_trunk;a++){
     if(a == middle_trunk){
        mem_[a] = '|';
        break;
     }
     mem_[a] = ' ';
  }
  mem_[middle_trunk + 1] = '\n';

  for(unsigned a = 1;a <= total_trunk;a++){
     memcpy(&mem[index],mem_,(middle_trunk + 2));
     index += (middle_trunk + 2);
  }
  mem[index-1] = 0;
  return mem;
}
