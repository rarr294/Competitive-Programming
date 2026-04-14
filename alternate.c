/*

Create a function that accepts a string as an argument and 
validates whether the vowels (a, e, i, o, u) and consonants 
are in alternate order.

Examples
"amazon" --> true
"apple" --> false
"banana" --> true

*/

char alternate(const char* str){
  char key[26] = {0};
  key[0]  = 1;
  key[4]  = 1;
  key[8]  = 1;
  key[14] = 1;
  key[20] = 1;

  str++;

  while(*str){
    char value1 = *(str - 1);
    char value2 = *str;

    (value1 > 96) ? value1 -= 32 : 0;
    (value2 > 96) ? value2 -= 32 : 0;

    value1 -= 65;
    value2 -= 65;

    if(
      (*(key + value1) == 1 && *(key + value2) == 1) ||
      (*(key + value1) == 0 && *(key + value2) == 0)
    ){
      return 0;
    }

    str++;
  }

  return 1;
}
