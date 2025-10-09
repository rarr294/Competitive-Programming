#include <vector>
using namespace std;

bool contains_all(const std::vector<int>& arr, const std::vector<int>& target){
  int arr_size = arr.size()-1;
  int tgt_size = target.size();

  int counter = 0;
  for(int a = 0;a <= (tgt_size-1);a++){
     for(int b = 0;b <= arr_size;b++){
        if(target[a] == arr[b]){
          counter++;
          break;
        }
     }
  }

  if(counter == tgt_size){
     return true;
  }else{
     return false;
  }
}
