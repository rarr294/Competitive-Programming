/*

Your job is to implement a function which write 
the last D digits of an integer N to *digits.

Special cases:
If D > (the number of digits of N), return all the digits.

If D <= 0, return an empty list.
Examples:
N = 1
D = 1
result = [1]

N = 1234
D = 2
result = [3, 4]

N = 637547
D = 6
result = [6, 3, 7, 5, 4, 7]

*/

#include <inttypes.h>

void checkGreater(uint64_t n,int *d){
  int total_digit = 0;
  while(total_digit++,n = (n - (n % 10)) / 10){}
  (*d > total_digit) ? (*d = total_digit) : 0;
}

unsigned last_digits(uint64_t n,int d,uint8_t *digits){     
  if(d <= 0){
     return 0;
  }

  checkGreater(n,&d);
  int offset = d - 1;

  for(int a = 1;a <= d;a++){
    n = (n - ((*(digits + offset--) = (n % 10)),(n % 10))) / 10;
  }

  return d;
}
