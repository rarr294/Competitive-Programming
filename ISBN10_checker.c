#include <stdbool.h>
#include <string.h>
 
bool is_valid_ISBN_10 (const char *ISBN){
  int size = strlen(ISBN);
  int adder = 0; 
  
  //edge case
  if(size < 10 || size > 10){
    return 0;
  }
  
  for(int a = 0;a <= 8;a++){
    if(!(ISBN[a] >= '0' && ISBN[a] <= '9')){
      return 0;
    }
  }
  //
  
  for(int a = 0;a <= 9;a++){
     if((a == 9) && (ISBN[a] == 'X')){
       adder += (10 * (a + 1)); //if last digit is X then last digit is 10
       break;
     }
     adder += ((ISBN[a] - 48) * (a + 1));
  }
  return ((adder % 11) == 0) ? 1 : 0;
}
