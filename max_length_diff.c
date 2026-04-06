/*

You are given two arrays a1 and a2 of strings.
Each string is composed with letters from a to z. 
Let x be any string in the first array and y be any 
string in the second array.

Find max(|(length(x) − length(y)|)

Example:
a1 = ["hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"]
a2 = ["cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"]
mxdiflg(a1, a2) --> 13

*/

#include <stddef.h>
#include <string.h>

int mxdiflg(const char *ar1[],size_t sz1,const char *ar2[],size_t sz2){

  if(ar1 == 0 || ar2 == 0){
    return -1;
  }

  int zr1 = 0; //zero1
  int zr2 = 0; //zero2

  int ar1_mx[2] = {strlen(*ar1),0};
  int ar2_mx[2] = {strlen(*ar2),0};

  for(int a = 0;a < sz1;a++){
    int size = strlen(*(ar1 + a));

    (size == 0) ? zr1++ : 0;
    (size < *ar1_mx) ? (*ar1_mx = size) : 0;
    (size > *(ar1_mx + 1)) ? (*(ar1_mx + 1) = size) : 0;
  }

  for(int a = 0;a < sz2;a++){
    int size = strlen(*(ar2 + a));

    (size == 0) ? zr2++ : 0;
    (size < *ar2_mx) ? (*ar2_mx = size) : 0;
    (size > *(ar2_mx + 1)) ? (*(ar2_mx + 1) = size) : 0;
  }


  if(zr1 == sz1 || zr2 == sz2){
    return -1;
  }

  int max = 0;
  for(int x = 0;x <= 1;x++){

    for(int y = 0;y <= 1;y++){
      int val = *(ar1_mx + x) - *(ar2_mx + y);
      (val < 0) ? (val *= -1) : 0;

      if(val > max){
        max = val;
      }

      if(*ar2_mx == *(ar2_mx + 1)){
        break;
      }

    }

    if(*ar1_mx == *(ar1_mx + 1)){
      break;
    }
  }

  return max;
}
