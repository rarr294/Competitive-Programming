/*

you will have to forget how to add two numbers.
In simple terms, our method does not like the principle of carrying over numbers and just writes down every number it calculates :-)
You may assume both integers are positive integers.

Examples :

16 + 18 = 214

16
18 +
214

122
 81 +
1103

*/

#include <stdlib.h>

unsigned digit_count(unsigned digit){
  unsigned total_digit = 0;
  while(total_digit++,digit -= (digit % 10),digit /= 10){}
  return total_digit;
}

unsigned exponent(unsigned base,unsigned power){
  if(power == 0){
    return 1;
  }
  unsigned expo = base;
  for(int a = 1;a < power;a++){
    expo *= base;
  }
  return expo;
}

unsigned add(unsigned x, unsigned y){
  unsigned x_count = digit_count(x);
  unsigned y_count = digit_count(y);

  if(y_count > x_count){
    unsigned tmp = x;
    x = y;
    y = tmp;
  }

  int pow = 0;
  int offset = -1;
  unsigned *mem = malloc(8 * x_count);

  while(y){
    unsigned x_digit = x % 10;
    unsigned y_digit = y % 10;

    mem[++offset] = x_digit + y_digit;
    pow += (mem[offset] > 9) ? 2 : 1;

    x -= x_digit;
    y -= y_digit;

    x /= 10;
    y /= 10;
  }

  if(x_count == y_count){
    goto convert_integer;
  }

  mem[++offset] = x;
  pow += (mem[offset] > 9) ? 2 : 1;

  convert_integer:
  pow--;
  unsigned sum = 0;

  while(offset >= 0){
    if(digit_count(mem[offset]) > 1){
       pow -= 2;
       if(pow == -1){
          sum += mem[offset];
          offset--;
          continue;
       }
       sum += (mem[offset--] * exponent(10,pow + 1));
       continue;
    }
    sum += (mem[offset--] * exponent(10,pow--));
  }
  return sum;
}
