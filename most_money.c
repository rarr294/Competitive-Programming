#include <stddef.h>

#define NAMELIM 0x8

struct student {
    char name[NAMELIM+1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};

const char *most_money(const struct student *v, size_t n){
  const char *ret_name = v[0].name;
  unsigned money = (v[0].fives * 5) + (v[0].tens * 10) + (v[0].twenties * 20);
  char sameAmount_Flag = 0;

  for(int a = 1;a < n;a++){
     unsigned student_money = (v[a].fives * 5) + (v[a].tens * 10) + (v[a].twenties * 20);
     if(student_money > money){
        money = student_money;
        ret_name = v[a].name;
     }else if(student_money == money){
        sameAmount_Flag = 1;
        continue;
     }
     sameAmount_Flag = 0;
  }

  if(sameAmount_Flag == 1){
    const char *all = "all";
    return all;
  }

  return ret_name;
}
