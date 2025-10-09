#include <string>
#include <algorithm>
using namespace std;

std::size_t duplicateCount(std::string i){
  //converting all uppercase to lowercase
  int size = i.size();
  for(int a = 0;a < size;a++){
    if((i[a] >= 65) && (i[a] <= 90)){
       int ascii = i[a] + 32;
       i[a] = ascii;
    }
  }
  //
  sort(i.begin(),i.end());
                     
  //counting duplicate 
  int counter = 0;
  int dup_count = 0;
  char state = i[0];
   for(int a = 0;a <= size;a++){
      if(state != i[a]){
         state = i[a];
         if(counter > 1){
           dup_count++;
           counter = 1;
         }
         continue;
      }
      counter++;
   }

   if(counter > 1){
      dup_count++;
   }
   return dup_count;   
  //
}
