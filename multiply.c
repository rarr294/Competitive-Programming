/*

you have to multiply each number by 5
raised to the number of digits of each numbers

for example:

  3 -->    15  (  3 * 5¹)
 10 -->   250  ( 10 * 5²)
200 --> 25000  (200 * 5³)
  0 -->     0  (  0 * 5¹)
 -3 -->   -15  ( -3 * 5¹)

*/

#include <math.h>

int multiply(int number){
  int n = (number < 0) ? number * -1 : number;
  int total_digit = 0;
  
  while(
  total_digit++,
  n = (n - (n % 10)) / 10){}
  
  return number * pow(5,total_digit);
}
