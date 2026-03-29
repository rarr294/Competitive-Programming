/*

Your task is to implement a function ipv4_to_binary
which takes in an IPv4 address ipv4_addr and writes 
the result converted into Dotted Binary Notation

example :

192.168.0.33    = 11000000.10101000.00000000.00100001
255.255.255.0   = 11111111.11111111.11111111.00000000
10.55.0.13      = 00001010.00110111.00000000.00001101
255.255.255.252 = 11111111.11111111.11111111.11111100

*/

#include <string.h>
#include <stdlib.h>

typedef unsigned char uint8t;

void toBin(char *p,char *rest){
  uint8t num = atoi(p);
  uint8t total_shift = 0;

  while(num){
    if(num & 128){
     *(rest + total_shift) = 49;
    }
    num <<= 1;
    total_shift++;
  }
}

void ipv4_to_binary(const char *ipv4, char *rest){
  memset(rest,48,36);

  while(1){
    int offset = 0;
    char ip4[4] = {0};

    while(*ipv4 != 46 && *ipv4 != 0){
      *(ip4 + offset++) = *ipv4;
      ipv4++;
    }

    if(!(*ipv4)){
      toBin(ip4,rest);
      *(rest + 8) = 0;
      break;
    }

    ipv4++;
    toBin(ip4,rest);
    *(rest += 8) = 46,rest++;
  }
}
