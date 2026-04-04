/*

Oh, no! The number has been mixed up with the text. 
Your goal is to retrieve the number from the text, 
can you return the number back to its original state?

Your task is to return a number from a string.

Details
You will be given a string of numbers and letters mixed up,
you have to return all the numbers in that string in the order
they occur.
*/

#include <math.h>

long long filter_string(const char *value){
  int total_num = -1;
  const char *cp = value;

  while(
    ((*value >= 48 && *value <= 57) ? total_num++ : 0),
    (value++,*value)
  ){}

  long long num = 0;

  while(
    ((*cp >= 48 && *cp <= 57) ?
    num += (long long)((*cp - 48) * pow(10,total_num--)) : 0),
    (cp++,*cp)
  ){}

  return num;
}
