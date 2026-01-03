#include <string.h>
#include <stddef.h>

void only_duplicates(char *s){
  char bucket[27] = {0};
  int size = strlen(s);

  //convert all uppercase to lowercase
  for(int a = 0;a < size;a++){
     if(s[a] >= 65 && s[a] <= 90){
        s[a] += 32;
     }
  }
  //

  //fill the bucket
  for(int a = 0;a < size;a++){
    bucket[(s[a] - 96)] += 1;
  }
  //

  //remove unique
  for(int a = 0;a < size;a++){
    if(bucket[(s[a] - 96)] == 1){
       char save = s[a]; //handle edge case
       memmove(
         (s + a),
         (s + a + 1),
         strlen(s + a + 1) + 1
       );
       size = strlen(s);
       bucket[save - 96] = 0;
       a = -1;
    }
  }
  //
}

/*
int main(){
  char str[] = {"foundersandcoders"};
  only_duplicates(str);
  printf("%d\n",strcmp(str,"ondersndoders")); //output : 0
};
*/
