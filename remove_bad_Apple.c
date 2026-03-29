/*

Description:
Help a fruit packer sort out the bad apples.
There are 7 varieties of apples, all packaged as pairs and stacked in a fruit box. 
Some of the apples are spoiled. The fruit packer will have to make sure the spoiled 
apples are either removed from the fruit box or replaced. Below is the breakdown:

Apple varieties are represented with numbers, 1 to 9
A fruit package is represented with a 2 element array [4,3]
A fruit package with one bad apple, or a bad package, is represented with [2,0] or [0,2]
A fruit package with two bad apples, or a rotten package, is represented with [0,0]
A fruit box is represented with:

[ [ 1, 3 ],
[ 7, 6 ],
[ 7, 2 ],
[ 1, 3 ],
[ 0, 2 ],
[ 4, 5 ],
[ 0, 3 ],
[ 7, 6 ] ]

Write a program to clear the fruit box off bad apples.
The INPUT will be a fruit box represented with a 2D array: 
[[1,3],[7,6],[7,2],[1,3],[0,2],[4,5],[0,3],[7,6]]

The OUTPUT should be the fruit box void of bad apples:
[[1,3],[7,6],[7,2],[1,3],[2,3],[4,5],[7,6]]

Conditions to be met:
1.A bad package should have the bad apple replaced if there is another bad package with a good apple to spare. 
  Else, the bad package should be discarded.
2.The order of the packages in the fruit box should be preserved. 
3.Rotten packages should be discarded.
4.There can be packages with the same variety of apples,
  e.g [1,1],this is not a problem.

*/

#include <string.h>

void remove_apple(char *box,int *box_num){
  int a = 0;
  while(a < *box_num){
    char *ptr = (box + 2 * a);

    if(*ptr != 0 && *(ptr + 1) != 0){
      a++;
      continue;
    }else if(*ptr == 0 && *(ptr + 1) == 0){
      remove_:
      memmove(ptr,ptr + 2,2 * (*box_num - (a + 1)));
      *box_num = *box_num - 1;
      continue;
    }

    int b = a + 1;

    char value1 = (*ptr == 0) ? *(ptr + 1) : *ptr;
    char value2 = 0;

    char remove_flag = 0;
    while(b < *box_num){
      char *p = (box + 2 * b);

      if(*p == 0 && *(p + 1) == 0){
        memmove(p,p + 2,2 * (*box_num - (b + 1)));
        *box_num = *box_num - 1;
        continue;
      }else if(
        (*p != 0 && *(p + 1) == 0) ||
        (*p == 0 && *(p + 1) != 0)
      ){

        value2 = (*p == 0) ? *(p + 1) : *p;

        memmove(p,p + 2,2 * (*box_num - (b + 1)));
        *box_num = *box_num - 1;

        remove_flag = 1;
        break;
      }

      b++;
    }

    if(remove_flag == 0){
      goto remove_;
    }

    *ptr = value1;
    *(ptr + 1) = value2;
  }
}
