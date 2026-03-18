/*

given a string follow these rule :

(1). shift each letter by a given number but the transformed letter must be a letter (circular shift)
(2). replace each digit by its complement to 9
(3). keep such as non alphabetic and non digit characters
(4). downcase each letter in odd position, upcase each letter in even position (the first character is in position 0)
(5). reverse the whole result

Example:
your text: "BORN IN 2015!", shift 1
1 + 2 + 3 -> "CPSO JO 7984!"
4 "CpSo jO 7984!"
5 "!4897 Oj oSpC"

*/

#include <stdlib.h>
#include <string.h>

char *playPass(const char *s, int shift){
  int offset = 0;
  int size = strlen(s);
  char *rest = malloc(size + 1);
  *(rest + size--) = 0;

  while(size >= 0){

    if(*(s + size) >= 48 && *(s + size) <= 57){
      *(rest + offset++) = 9 - ((*(s + size)) - 48) + 48;
      goto gohere;
    }else if(
      (*(s + size) >= 65 && *(s + size) <= 90)
                         ||
      (*(s + size) >= 97 && *(s + size) <= 122)
    ){

      char a = (*(s + size) >= 65 && *(s + size) <= 90) ?
         *(s + size) - 65 : *(s + size) - 97;

      *(rest + offset++) = ((size % 2) == 0) ?
          ((a + shift) % 26) + 65 : ((a + shift) % 26) + 97;
      goto gohere;
    }

    *(rest + offset++) = *(s + size);
    gohere:
    size--;
  }
  
  return rest;
}
