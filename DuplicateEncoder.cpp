#include <string>
#include <map>
#include <set>
using namespace std;

std::string duplicate_encoder(std::string str){
  //convert char to lowercase
  size_t size = str.size();
  for(int a = 0;a < size;a++){
    if((str[a] >= 65) && (str[a] <= 90)){
       str[a] = str[a] + 32;
    }
  }
  //
  map<char,int> maps;
  set<char> txt(str.begin(),str.end());
  set<char>::iterator it = txt.begin();
  set<char>::iterator end = txt.end();

  //adding element to maps
  for(char c : txt){
    maps[c] = 0;
  }
  //

  //counting maps counter
  for(int a = 0;a < size;a++){
    maps[str[a]] += 1;
  }
  //

  //Duplicate Encoder
  string result = "";
  for(int a = 0;a < size;a++){
     if(maps[str[a]] > 1){
       result +=  ")";
       continue;
     }
     result += "(";
  }
  //
  return result; 
}
