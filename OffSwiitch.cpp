#include <vector>
using namespace std;

std::vector<int> off(int n){
  vector<char> switching = {0}; //index[0] = padding
  //creating switching
  for(int a = 1;a <= n;a++){
    switching.push_back((char)0);
  }
  //

 //edge case
 if(n <= 3){
   return {1};
 }
 //

 //Switching
 for(int a = 2;a <= n;a++){
   for(int b = a;b <= n;b += a){
      if(switching[b] == 0){
         switching[b] = (char)1;
         continue;
      }
      switching[b] = (char)0;
   }
 }
 // 

 //finding off switch
 vector<int> off_switch;
 for(int a = 1;a <= n;a++){
    if(switching[a] == 0){
       off_switch.push_back(a);
    }
 }
 //
 return off_switch;
}
