/*

Rules/Note:

(1). If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.
(2). All the lines in the pattern have same length i.e equal to the number of characters in the longest line.
(3). Range of n is (-∞,100]

Examples:

pattern(5):

    1    
   121   
  12321  
 1234321 
123454321
 1234321 
  12321  
   121   
    1    


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
 12345678987654321 
  123456787654321  
   1234567654321   
    12345654321    
     123454321     
      1234321      
       12321       
        121        
         1         

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
 123456789012343210987654321 
  1234567890123210987654321  
   12345678901210987654321   
    123456789010987654321    
     1234567890987654321     
      12345678987654321      
       123456787654321       
        1234567654321        
         12345654321         
          123454321          
           1234321           
            12321            
             121             
              1              


*/

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

string pattern(int n){
  if(n <= 0){
    return "";
  }

  int offset = 0;
  int total_space = n - 1;

  string result;
  vector<string> p;

  for(int a = 1;a <= n;a++){
     string diamond;

     for(int b = 1;b <= total_space;b++){
       diamond += 32;
     }

     int counter = 1;
     while(counter <= a){
       diamond += to_string(counter % 10);
       counter++;
     }

     counter -= 2;
     while(counter >= 1){
       diamond += to_string(counter % 10);
       counter--;
     }

     for(int b = 1;b <= total_space;b++){
       diamond += 32;
     }
     diamond += 10;

     p.push_back(diamond);
     total_space--;
  }

  int size = p.size();
  for(int a = 0;a < size;a++){
     result += p[a];
  }

  size -= 2;
  while(size >= 0){
    result += p[size];
    size--;
  }
  result.erase(result.begin() + result.size() - 1);
  return result;
}
