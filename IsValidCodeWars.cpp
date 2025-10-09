#include <string>
#include <vector>
using namespace std;

bool isValidMessage(std::string str){
   vector<string> name;
   vector<int> number;

   //extracting number
   int size = str.size()-1;
   string num;
   for(int a = 0;a <= size;a++){
    if(!((str[a] >= 48) && (str[a] <= 57))){
       if(num.size() == 0){
          continue;
       }
       number.push_back(stoi(num));
       num = "";
       continue;
    }
      num += str[a];
   }

  if(num.size() > 0){
     number.push_back(stoi(num));
  }
  //

  //extracting name
  string names;
  for(int a = 0;a <= size;a++){
    if((str[a] >= 48) && (str[a] <= 57)){
      if(names.size() == 0){
         continue;
      }
      name.push_back(names);
      names = "";
      continue;
    }
      names += str[a];
   }

  if(names.size() > 0){
     name.push_back(names);
  }
  //

  //isValid
  if((number.size() > name.size()) || ((str[size] >= 48) && (str[size] <= 57))){
     return false;
  }
  
  int sizeNum = number.size()-1;
  for(int a = 0;a <= sizeNum;a++){
     if(name[a].size() != number[a]){
       return false;
     }
  }
  return true;
  //
}
