/*

Examples
As the article states, RLE is a very simple form of data compression. 
It's only suitable for runs of data, as one can see in the following example:

runLengthEncoding "hello world!" 
`shouldBe` [(1,'h'), (1,'e'), (2,'l'), (1,'o'), (1,' '), (1,'w'),(1,'o'), (1,'r'), (1,'l'), (1,'d'), (1,'!')]

It's very effective if the same data value occurs in many consecutive data elements:
runLengthEncoding "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbb" 
`shouldBe` [(34,'a'), (3,'b')]

*/

#include <stddef.h>
#include <stdlib.h>

struct Character{
  unsigned count;
  unsigned char value;
};

struct Character *run_length_encoding(const char *str,size_t *size){
  if(*str == 0){
    return NULL;
  }
  
  const char* base = str;
  
  while(*str){
    
    if(*str != *(str + 1)){
       *size = *size + 1;
       str++;
       continue;
    }

    str += 2;
    *size = *size + 1;
    const char *first_pos = str - 1;

    while(*first_pos == *str){
      str++;
    }
  }

  int offset = 0;
  struct Character *mem = malloc(*size * sizeof(struct Character));

  while(*base){

     if(*base != *(base + 1)){
       mem[offset].count = 1;
       mem[offset++].value = *base;

       base++;
       continue;
     }

     base += 2;
     unsigned freq = 2;
     const char* first_pos = base - 1;

     while(*base == *first_pos){
       freq++;
       base++;
     }

     mem[offset].count = freq;
     mem[offset++].value = *first_pos;
  }
  
  return mem;
}
