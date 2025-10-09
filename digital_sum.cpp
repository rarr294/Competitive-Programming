#include <vector>
using namespace std;

int digital_root(int n){
  while(!(n < 10)){
    std::vector<int> digits;    
    
    //extracting all digit
    while(n != 0){
      int digit = n % 10;
      digits.push_back(digit);
      n -= digit;
      n /= 10;
    }
    //
    
    //adding all digit
    int size = digits.size()-1;
    for(int a = 1;a <= size;a++){
      digits[0] += digits[a];
    }
    //
    
    n = digits[0];
  }
  return n;
}
