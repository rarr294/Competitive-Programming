#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef long long int64t;

char *code(const char *s){

  char *rest;
  size_t str_size = strlen(s);

  if(str_size <= 2){
    rest = malloc(str_size + 1);
    memcpy(rest,s,str_size + 1);
    return rest;
  }

  size_t n = ceil(sqrt(str_size));

  int64t offset = 0;
  size_t size = n * n + n;
  rest = malloc(size + 1);

  size_t goff = 0;
  size_t gcounter = 0;

  for(size_t a = 1;a <= n;a++){

    int64t roff = (offset += n) - 1;
    *(rest + offset) = 10;

    if(gcounter == str_size){
      for(size_t a = 1;a <= n;a++){
        *(rest + roff--) = 11;
      }

      continue;
    }

    int64t counter = 0;

    for(size_t off = 0;off < str_size;off += n){
      ((off + goff) >= str_size) ? (0) : (
        counter++,
        gcounter++,
        *(rest + roff--) = *(s + off + goff)
      );
    }

    int64t total_padding = n - counter;
    for(int64t a = 1;a <= total_padding;a++){
      *(rest + roff--) = 11;
    }

    goff++;
    offset++;
  }

  *(rest + size - 1) = 0;
  return rest;
}

char *decode(const char *s){

}










int main(){
  char *rest = code("I.was.going.fishing.that.morning.at.ten.o'clock");
  while(*rest){
    (*rest == 11) ? (printf("#")) : (printf("%c",*rest));
    rest++;
  }

  printf("\n");
};

/*
nmna
yjcn
qpwn
burc

bqyn
upjm
rwcn
cnna

bqyn
upjm
rwcn
cnna
*/
