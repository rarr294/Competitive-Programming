#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::string spinWords(std::string str){
  vector<string> vect;
  size_t size = str.size();

  //extractin
  string word = "";
  for(size_t a = 0;a < size;a++){
    if(str[a] == ' '){
      vect.push_back(word);
      word = "";
      continue;
    }
    word += str[a];
  }
  vect.push_back(word);
  //

  //reversing word
  size_t vect_size = vect.size();
  for(size_t a = 0;a < vect_size;a++){
    if(vect[a].size() >= 5){
      reverse(vect[a].begin(),vect[a].end());
    }
  }
  //

  //concat
  string result = "";
  for(size_t a = 0;a < vect_size;a++){
    result += vect[a];
    result += " ";
  }
  result.pop_back();
  //
  return result;
}
