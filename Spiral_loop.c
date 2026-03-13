/*

Classic definition: A spiral is a curve which emanates from a central point, 
getting progressively farther away as it revolves around the point.

Your objective is to complete a function createSpiral(N) 
that receives an integer N and returns an NxN two-dimensional array 
with numbers 1 through NxN represented as a clockwise spiral.

Examples:

N = 3 Output: [[1,2,3],[8,9,4],[7,6,5]]

1    2    3    
8    9    4    
7    6    5    

N = 4 Output: [[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]

1   2   3   4
12  13  14  5
11  16  15  6
10  9   8   7

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

Current_direction value meaning :

1 = go right
2 = go bottom
3 = go left
4 = go up

*/

void create_spiral(int n){
  int *spiral = malloc(n * n * 4);
  memset(spiral,0,n * n * 4);

  int h_off = 0;
  int y_off = 0;

  int uBound = 1;/
  int lBound = 0;
  int rbBound = n;
  int total_loop = 2 * n - 1;
  char Current_direction = 1;

  int num = 1;

  for(int a = 1;a <= total_loop;a++){
     if(Current_direction == 1){

       while(h_off < rbBound){
         *(spiral + (n * y_off) + h_off++) = num++;
       }
       h_off--;
       y_off++;
       Current_direction = 2;

     }else if(Current_direction == 2){

       while(y_off < rbBound){
         *(spiral + (n * y_off) + h_off) = num++;
         y_off++;
       }

       h_off--;
       y_off--;
       Current_direction = 3;

     }else if(Current_direction == 3){

       while(h_off >= lBound){
         *(spiral + (n * y_off) + h_off--) = num++;
       }
       h_off++;
       y_off--;
       Current_direction = 4;

     }else if(Current_direction == 4){

       while(y_off >= uBound){
         *(spiral + (n * y_off) + h_off) = num++;
         y_off--;
       }

       y_off++;
       h_off++;

       uBound++;
       lBound++;
       rbBound--;
       Current_direction = 1;
     }
  }

  for(int a = 0;a < n;a++){
     for(int b = 0;b < n;b++){
       printf("%d ",*(spiral + (n * a) + b));
     }
     printf("\n");
  }
}

int main(){
  create_spiral(12);
}
