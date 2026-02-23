/*
A format for expressing an ordered list of integers is to use a comma separated list of either

individual integers or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. 
The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example "12,13,15-17"

Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

Example:

range_extraction((const []){-10, -9, -8, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20}, 23);
returns "-10--8,-6,-3-1,3-5,7-11,14,15,17-20"
*/

#include <stdlib.h>
#include <string.h>

char *int_to_str(int n){
  char negative_flag = (n < 0) ?  (n *= -1,1) : 0;

  int num = n;
  int size = (negative_flag == 1) ? 2 : 1;

  while(size++,
  num -= (num % 10),
  num /= 10){}

  if(negative_flag == 0){
    char *mem = malloc(size--);
    mem[size--] = 0;

    while(
    mem[size--] = ((n % 10) + 48),
    n -= (n % 10),
    n /= 10
    ){}
    return mem;
  }

  char *mem = malloc(size--);
  mem[size--] = 0;

  while(
  mem[size--] = ((n % 10) + 48),
  n -= (n % 10),
  n /= 10
  ){}

  mem[size] = '-';
  return mem;
};

char *range_extraction(const int *args, size_t n){
  char *mem = malloc(n * 10);
  char *cp_mem = mem;

  short counter = 0;
  short lowBound;

  for(int a = 0;a < n;a++){
     if((a + 1) ==  n){
       goto gohere; //overflow handling
     }else if((args[a + 1] - args[a]) == 1){
       if(counter == 0){
         lowBound = a;
       }
       counter++;
       continue;
     }

     gohere:
     if(counter >= 1){
        char *lowBound_int = int_to_str(args[lowBound]);
        int Low_size = strlen(lowBound_int);

        char *upBound_int = int_to_str(args[a]);
        int Up_size = strlen(upBound_int);

        memcpy(mem,lowBound_int,Low_size);
        *(mem += Low_size,mem++) = (counter > 1) ? '-' : ',';

        memcpy(mem,upBound_int,Up_size);
        *(mem += Up_size,mem++) = ',';

        counter = 0;
        continue;
     }else if(((a + 1) == n) && counter == 1){ //last pair overflow handler
        char *lowBound_int = int_to_str(args[lowBound]);
        int Low_size = strlen(lowBound_int);

        char *upBound_int = int_to_str(args[a]);
        int Up_size = strlen(upBound_int);

        memcpy(mem,lowBound_int,Low_size);
        *(mem += Low_size,mem++) = ',';

        memcpy(mem,upBound_int,Up_size);
        *(mem += Up_size,mem++) = ',';

        continue;
     }

     char *lowBound_int = int_to_str(args[a]);
     int Low_size = strlen(lowBound_int);

     memcpy(mem,lowBound_int,Low_size);
     *(mem += Low_size,mem++) = ',';

     counter = 0;
  }
  *(--mem) = 0;
  return cp_mem;
}

