#include <string>
#include <iostream>
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

  //operation
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

std::string incrementString(std::string str){
  int size = str.size()-1;
  if(!(str[size] >= 48 && str[size] <= 57)){
    str.push_back('1');
    return str;
  }

  //extracting number 
  std::string number;
  int index_digit;
  int index;

  for(int high = size;high >= 0;high--){
     if(!(str[high] >= 48 && str[high] <= 57)){
        index_digit = high + 1;
        index = index_digit;
        break;
     }
  }
  //

  //increment
  for(;index_digit <= size;index_digit++){
     number.push_back(str[index_digit]);
  }

  str.erase(index,number.size());
  std::string adding = add(number,"1");
  str += adding;
  //
  return str;
}
