//low level version of lexiographical ordering

#include <string.h>
#include <stdint.h>
#include <sys/mman.h>

void lexio_order(char* addr,int size){

  for(int a = 1;a <= size;a++){
    char swap_flag = 0;

    for(int b = 1;b < size;b++){
      char *str1 = (char *)*(uintptr_t*)(addr + sizeof(uintptr_t) * (b - 1));
      char *str2 = (char *)*(uintptr_t*)(addr + sizeof(uintptr_t) * b);

      char *cp1 = str1;
      char *cp2 = str2;

      int notSame_flag = 0;

      while(*cp1 && *cp2){

        if(*cp1 != *cp2){
          notSame_flag = 1;
          break;
        }

        cp1++;
        cp2++;
      }

      if(((strlen(str1) > strlen(str2)) && (notSame_flag == 0)) || (*cp1 > *cp2)){
         char *tmp = str1;
         *(uintptr_t*)(addr + sizeof(uintptr_t) * (b - 1)) = (uintptr_t)str2;
         *(uintptr_t*)(addr + sizeof(uintptr_t) * b) = (uintptr_t)tmp;
         swap_flag = 1;
      }
    }

    if(swap_flag == 0){
      break;
    }
  }
}

int main(){
  char *page = mmap(NULL,4096,
  PROT_READ | PROT_WRITE,
  MAP_PRIVATE | MAP_ANONYMOUS,
  -1, 0);

  init_str(page);
  lexio_order(page,15);
}

