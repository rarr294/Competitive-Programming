/*

Example:

a(4) prints as

   A   
  A A  
 A A A 
A     A


a(8) prints as

       A       
      A A      
     A   A     
    A     A    
   A A A A A   
  A         A  
 A           A 
A             A

a(12) prints as

           A           
          A A          
         A   A         
        A     A        
       A       A       
      A         A      
     A A A A A A A     
    A             A    
   A               A   
  A                 A  
 A                   A 
A                     A

Note:

(1). Each line's length is 2n - 1
(2). Each line should be concatenate by line break "\n"
(3). If n is less than 4, it should return ""
(4). If n is odd, a(n) = a(n - 1), eg a(5) == a(4); a(9) == a(8)

*/

#include <stdlib.h>
#include <string.h>

char* a(int n){
  if(n < 4){
    char *mem = malloc(1);
    *mem = 0;
    return mem;
  }

  n -= (
    ((n % 2) != 0) ? 1 : 0
  );

  int offset = 0;
  int two_sum = 1;
  int total_space = n - 1;
  int mid_point = ((n - 2) / 2) + 2;

  char *triangle = malloc(2 * n * n);

  for(int a = 1;a <= n;a++){
     for(int b = 1;b <= total_space;b++){
       *(triangle + offset) = 32;
       offset++;
     }

     *(triangle + (offset++)) = 65;

      if(a == 1){
       goto gohere;
     }

     for(int b = 1;b <= two_sum;b++){
       *(triangle + (offset++)) = 32;
       if(a == mid_point){
         *(triangle + (offset++)) = 65;
         b++;
       }
     }

     two_sum += 2;
     if(a == mid_point){
       goto gohere;
     }

     *(triangle + (offset++)) = 65;

     gohere:
     for(int b = 1;b <= total_space;b++){
       *(triangle + (offset++)) = 32;
     }

     *(triangle + (offset++)) = 10;

     total_space--;
  }
  *(triangle + (offset - 1)) = 0;
  return triangle;
}
