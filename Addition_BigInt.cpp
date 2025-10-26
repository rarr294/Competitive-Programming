#include <string>
using namespace std;

std::string add(std::string a,std::string b){ 
  int size_a = a.size();
  int size_b = b.size();

  //add padding byte to data 
  int padding;
  if(size_a < size_b){
    int total_padding = size_b - size_a;
    padding = size_b;
    for(int add_pad = 1;add_pad <= total_padding;add_pad++){
       a.insert(0,"0");
    }
  }else{
    int total_padding = size_a - size_b;
    padding = size_a;
    for(int add_pad = 1;add_pad <= total_padding;add_pad++){
       b.insert(0,"0");
    }
  } 
  std::string result(padding,'0');
  //

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

std::string sum_strings(std::string a,std::string b) {
  return add(a,b);
}
