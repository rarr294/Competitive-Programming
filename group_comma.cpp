#include <string>
using namespace std;

std::string group_by_commas(unsigned int n){
  if(n < 1000){
    return std::to_string(n);
  }

  string number = std::to_string(n);
  int total_digit = number.size( );
  int size = total_digit;
  while((size % 3) != 0){
    size++;
  }

  int total_padding = size - total_digit;
  for(int a = 1;a <= total_padding;a++){
    number.insert(0,"0");
  }

  for(int a = 3;a < size;a += 3){
     number.insert(a,",");
     a++;
  }

  for(int a = 1;a <= total_padding;a++){
    number.erase(0,1);
  }

  return number;
}
