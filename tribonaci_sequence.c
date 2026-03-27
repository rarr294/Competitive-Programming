#include <stdlib.h>
#include <string.h>

typedef long long intll;

intll *tribonacci(const intll *sign,size_t n){
  intll *rest = malloc(n * sizeof(intll));
  memcpy(rest,sign,(sizeof(intll) * 3));

  int offset = 0;

  for(int a = 3;a < n;a++){
    intll sum = 0;
    int mod_off = offset;

    for(int b = 1;b <= 3;b++){
      sum += *(rest + mod_off++);
    }

    *(rest + a) = sum;
    offset++;
  }

  return rest;
}
