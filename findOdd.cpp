#include <set>
#include <vector>
#include <map>
using namespace std;

int findOdd(const std::vector<int>& numbers){
   std::set<int> number(numbers.begin(),numbers.end());
   std::vector<int> v(number.begin(), number.end());
   int vect_size = v.size()-1;
   int n_size = numbers.size()-1;
   std::map<int,int> maps;
   int control = 0;

   while(maps[v[control]] = 0,control++,control <= vect_size){}
   control = 0;
   while(maps[numbers[control]]++,control++,control <= n_size){}
   control = 0;
   while(1){
      if((maps[v[control]] % 2) != 0){
         control = v[control];
         break;
      }
      control++;
   }
   return control;
}
