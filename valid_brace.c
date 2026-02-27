/*

Write a function that takes a string of braces, and determines if the order of the braces is valid. 
It should return true if the string is valid, and false if it's invalid.

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.
What is considered Valid?

A string of braces is considered valid if all braces are matched with the correct brace.
Examples

"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False

*/


#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool valid_braces(const char *braces){
  int size = strlen(braces);
  char *stack = malloc(size);
  int idx = 0;

  for(int a = 0;a < size;a++){    
     if(braces[a] == '}'){
       if(idx == 0){
          goto gohere;
       }else if(stack[idx - 1] == '{'){
         idx--;
         continue;
       }
     }else if(braces[a] == ')'){
       if(idx == 0){
          goto gohere;
       }else if(stack[idx - 1] == '('){
         idx--;
         continue;
       }
     }else if(braces[a] == ']'){
       if(idx == 0){
          goto gohere;
       }else if(stack[idx - 1] == '['){
         idx--;
         continue;
       }
     }
     gohere:
     stack[idx++] = braces[a];
  }
  if(idx == 0){
     return true;
  }
  return false;
}
