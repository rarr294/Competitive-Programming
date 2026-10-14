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
  size_t n = 0;
  size_t size = 0;

  char fflag = 1;
  for(size_t a = 0;*(s + a);a++){
    ((*s == 11) || (*s == 10)) ? (fflag = 0) : (
      (size++),
      ((fflag) ? (n++) : (0))
    );
  }

  uint64_t goff = 0;
  uint64_t gcounter = 0;

  char *rest = malloc(size + 1);

  while(*s){

    if(gcounter == size){
      break;
    }

    while((*s != 11) && (*s != 10)){
      s++;
    }

    const char *s_cp = s - 1;
    for(size_t loff = 0;loff < size;loff += n){
      (*s_cp == 11) ? (0) : (
         gcounter++,
         *(rest + loff + goff) = *(s_cp--)
      );
    }

    goff++;
    (*s) ? (s++) : (0);
  }

  *(rest + size) = 0;
  return rest;
}

int main(){
  char *rest = code("I.was.going.fishing.that.morning.at.ten.o'clock");
  while(*rest){
    (*rest == 11) ? (printf("#")) : (printf("%c",*rest));
    rest++;
  }

  printf("\n");
};
