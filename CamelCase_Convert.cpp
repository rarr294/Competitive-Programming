#include <string>

std::string to_camel_case(std::string text) { 
  int size = text.size()-1;
  for(int a = 0;a <= size;a++){
     if((text[a] == '_') || (text[a] == '-')){ 
        a++;
        if(text[a] >= 97 && text[a] <= 122){
           int character = text[a] - 32;
           text[a] = character;
        }
        continue;
     }
  }
  std::string result;
  for(int a = 0;a <= size;a++){
     if((text[a] == '_') || (text[a] == '-')){
        continue;
     }
     result.push_back(text[a]);
  }
  text = result;
  return text;
}
