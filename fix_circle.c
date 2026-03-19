/*

Write a function circle_mender that takes as an input a string representing a circle
with some holes and returns a string with the holes filled.

The input has the following characteristics:

It is a string representing an ASCII-art circle;
It consists of exactly 20 lines, each with 40 characters followed by a newline character;
The circle is drawn using the pound sign (#), and any holes within it are represented by spaces ( );
The edges of the circle are never missing.
Below are some examples to better represent what it is that is expected:

Example 1:
-------
Input:
                                        
                                        
                                        
                                        
                                        
                                        
             #                          
         #########                      
        #### # ####                     
       ###       ###                    
        #### # ####                     
         #########                      
             #                          
                                        
                                        
                                        
                                        
                                        
                                        
                                        
-------
Output:
                                        
                                        
                                        
                                        
                                        
                                        
             #                          
         #########                      
        ###########                     
       #############                    
        ###########                     
         #########                      
             #                          
                                        
                                        
                                        
                                        
                                        
                                        
                                        

*/

#include <string.h>

void circle_mender(char *c){
  int r_size = (char*)memchr(c,10,strlen(c)) - c + 1;

  while(*c){
    char *first_pos = memchr(c,35,r_size);

    if(!first_pos){
      c += r_size;
      continue;
    }

    char *upBound = c += r_size;
    
    while(*upBound != 35){
      upBound--;
    }

    while(first_pos <= upBound){
      (*first_pos == 32) ? (*(first_pos) = 35) : 0;
      first_pos++;
    }
  }
}
