/*

The input is a string str of digits. Cut the string into
chunks (a chunk here is a substring of the initial string) 
of size sz (ignore the last chunk if its size is less than sz).

If the sum of a chunk's digits is divisible by 2,reverse that chunk; 
otherwise rotate it to the left by one position. 
Put together these modified chunks and return the result as a string.

If
sz is <= 0 or if str == "" return ""
sz is greater (>) than the length of str
it is impossible to take a chunk of size sz hence return "".

Examples:
("123456987654", 6) --> "234561876549"
("123456987653", 6) --> "234561356789"
("66443875", 4) --> "44668753"
("66443875", 8) --> "64438756"
("664438769", 8) --> "67834466"
("123456779", 8) --> "23456771"
("", 8) --> ""
("123456779", 0) --> "" 
("563000655734469485", 4) --> "0365065073456944"

Example of a string rotated to the left by one position:
s = "123456" gives "234561".

*/



#include <stdlib.h>

char *revrot(const char *s,int sz){
  int offset = 0;
  int size = strlen(s);
  char *rest = malloc(size + 1);

  if(sz <= 0 || size == 0 || sz > size){
    *rest = 0;
    return rest;
  }

  for(int a = 0;a < size;a += sz){
     int sum = 0;
     int bound = a + sz;

     if(bound > size){ break; }

     for(int b = a;b < bound;b++){
       sum += *(s + b) - 48;
     }

     if((sum % 2) == 0){
       bound--;

       while(bound >= a){
         *(rest + offset++) = *(s + bound);
         bound--;
       }
       continue;
     }

     for(int b = a + 1;b < bound;b++){
       *(rest + offset++) = *(s + b);
     }

     *(rest + offset++) = *(s + a);
  }

  *(rest + offset) = 0;
  return rest;
}
