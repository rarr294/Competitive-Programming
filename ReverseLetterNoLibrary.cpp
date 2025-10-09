#include <string>
using namespace std;

std::string reverse_letter(std::string str){
  int size = str.size();
  string result;
  
  for(;size >= 0;size--){
    if(!((str[size] >= 97) && (str[size] <= 122))){
       continue;
    }
    result.push_back(str[size]);
  }
  return result;
}
