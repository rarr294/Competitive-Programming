#include <string>
#include <vector>
using namespace std;

std::string add(std::string a,std::string b){
  int size_a = a.size();
  std::string result(size_a,'0');
  
  //adding operation
  int carry = 0;
  int size = a.size()-1;
  while(size >= 0){
    int first = a[size] - 48;
    int second= b[size] - 48;
    int add = first + second + carry;
    //handling carry
    if(add > 9){
      int last_digit = add % 10;
      result[size] = last_digit + 48;
      carry = 1;
      size--;
      continue;
    }
    //
    carry = 0;
    result[size] = add + 48;
    size--;
  }
  //

  //handling msb carry
  if(carry == 1){
    result.insert(0,"1");
  }
  //
  return result;
}
