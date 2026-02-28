#include <string.h>

unsigned exponent(unsigned base,unsigned n){
   if(n == 0){
     return 1;
   }
   int a = base;
   for(int b = 1;b < n;b++){
      a *= base;
   }
   return a;
}

unsigned bin_to_decimal(const char *bin){
  unsigned sum = 0;
  unsigned exponential = 0;
  
  for(int a = strlen(bin) - 1;a >= 0;a--){
    if(bin[a] == '1'){
      sum += exponent(2,exponential);
    }
    exponential++;
  }
	return sum;
}
