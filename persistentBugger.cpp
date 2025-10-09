#include <vector>
using namespace std;
int persistence(long long n){
  std::vector<int> total_mult;
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

    //multiplying all digit
    int size = digits.size()-1;
    for(int a = 1;a <= size;a++){
      digits[0] *= digits[a];
    }
    //
    
    n = digits[0];
    total_mult.push_back(digits[0]);
  }
  return total_mult.size();
}
