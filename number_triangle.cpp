/*

Rules/Note:

(1). If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.
(2). All the lines in the pattern have same length i.e equal to the number of characters in the last line.
(3). Range of n is (-∞,100]

Examples:

pattern(5):

    1    
   121   
  12321  
 1234321 
123454321

pattern(10):

         1         
        121        
       12321       
      1234321      
     123454321     
    12345654321    
   1234567654321   
  123456787654321  
 12345678987654321 
1234567890987654321

pattern(15):

              1              
             121             
            12321            
           1234321           
          123454321          
         12345654321         
        1234567654321        
       123456787654321       
      12345678987654321      
     1234567890987654321     
    123456789010987654321    
   12345678901210987654321   
  1234567890123210987654321  
 123456789012343210987654321 
12345678901234543210987654321

*/

#include <string>

using namespace std;

string pattern(int n){
  if(n <= 0){
    return "";
  }

  int offset = 0;
  int total_space = n - 1;

  string triangle;;

  for(int a = 1;a <= n;a++){
     for(int b = 1;b <= total_space;b++){
       triangle += 32;
     }

     int counter = 1;
     while(counter <= a){
       triangle += to_string(counter % 10);
       counter++;
     }

     counter -= 2;
     while(counter >= 1){
       triangle += to_string(counter % 10);
       counter--;
     }

     for(int b = 1;b <= total_space;b++){
       triangle += 32;
     }
     triangle += 10;
     total_space--;
  }
  triangle.erase(triangle.begin() + triangle.size() - 1);
  return triangle;
}
