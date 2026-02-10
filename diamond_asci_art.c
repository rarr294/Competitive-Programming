#include <stdlib.h>
#include <stddef.h>

char *diamond (int n){
  if(n == 1){
    char *mem = malloc(3);
    mem[0] = '*';
    mem[1] = '\n';
    mem[2] = 0;
    return mem;
  }else if(n < 0 || (n % 2) == 0){
    return NULL;
  }
  
  int position = (n - 3) / 2 + 1;
  int size = (n * n) + 10;
  char *mem = malloc(size);

  int index = 0;

  for(int a = 1;a <= n;a += 2){
     for(int b = 1;b <= position;b++){
        mem[index++] = ' ';
     }

     for(int b = 1;b <= a;b++){
        mem[index++] = '*';
     }

     mem[index++] = '\n';
     position--;
  }

  n -= 2;
  int a = 1;
  while(n >= 0){
     for(int b = 1;b <= a;b++){
        mem[index++] = ' ';
     }

     for(int b = 1;b <= n;b++){
        mem[index++] = '*';
     }
     mem[index++] = '\n';
     a++;
     n -= 2;
  }
  mem[index] = 0;
  return mem;
}
