#include <string>
#include <vector>
#include <algorithm>
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

string multiply(string a, string b){
  //handling a or b = 0
  if((a == "0") || (b == "0")){
    return "0";
  }
  //
  
  int size_a = a.size();
  int size_b = b.size();
  
  //remove leading zeros
  for(int c = 0;c < size_a;c++){
    if(a[0] != '0'){
       break;
    }
    a.erase(0,1);
  }

  for(int c = 0;c < size_b;c++){
    if(b[0] != '0'){
       break;
    }
    b.erase(0,1);
  }
  //

  size_a = a.size()-1;
  size_b = b.size()-1;

  //swapping
  if(size_b > size_a){
    swap(a,b);
    swap(size_a,size_b);
  }
  //

  //mult big int
  vector<string> mult;
  char carry = (char)0;
  string number = "";
  for(int b_ = size_b;b_ >= 0;b_--){
     for(int a_ = size_a;a_ >= 0;a_--){
        char operand1 = a[a_] - 48;
        char operand2 = b[b_] - 48;
        char rest = operand1 * operand2 + carry;
       
        //handling msb carry
        if((rest >= 10) && (a_ == 0)){
          //reversing using modulo
          char last_digit = rest % 10;
          number += (last_digit + 48);
          char first_digit = (rest - last_digit)/10;
          number += (first_digit + 48);
          carry = (char)0;
          continue;
          //
        }
        //

        //handling carry
        if(rest >= 10){
          char last_digit = rest % 10;
          number += (last_digit + 48);
          char first_digit = (rest - last_digit)/10;
          carry = first_digit;
          continue;
        }
        carry = (char)0;
        number += (rest + 48);
        //
     }
     reverse(number.begin(),number.end());
     mult.push_back(number);
     number = "";
  }
  //
  
  //add padding
  size_t sizes = mult.size();
  for(size_t padding = 1;padding < sizes;padding++){
     for(int inner = 1;inner <= padding;inner++){
       mult[padding].push_back('0');
     }
  }
  //

  //add leading zero
  size_t last_size = mult[sizes-1].size();
  for(int a = 0;a < sizes;a++){
     size_t total_lead = last_size - mult[a].size();
     for(int c = 1;c <= total_lead;c++){
       mult[a].insert(0,"0");
     }
  }
  //

  //multiplying
  string result = mult[0];
  for(int a = 1;a < sizes;a++){
     result = add(result,mult[a]);
  }
  //
  return result;
}
