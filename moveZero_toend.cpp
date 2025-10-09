#include <vector>
using namespace std;

std::vector<int> move_zeroes(const std::vector<int>& input){
  std::vector<int> cpy = input;
  int size = cpy.size() - 1;
  auto it = cpy.begin();

  //counting number of zero
  auto count_zero = 0;
  for(auto a = 0;a <= size;a++){
     if(cpy[a] == 0){
        count_zero++;
     }
  }
  //
  if(count_zero == (size + 1)){
    return cpy;
  }else{
     //deleting all zero
     for(int a = 0;a <= size;a++){
        if(cpy[a] == 0){
          cpy.erase(it + a);
        }
     }
    
    for(int a = 0;a <= (cpy.size()-1);a++){
        if(cpy[a] == 0){
          cpy.erase(it + a);
        }
     }
     //putting all zero at the end
     for(int a = 1;a <= count_zero;a++){
       cpy.push_back(0);
     }
     return cpy;
  }
}
