#include <string>
#include <vector>
using namespace std;

std::string pig_it(std::string str){
  str.push_back(' '); //add padding
  int size = str.size();
  vector<string> word;

  //extract the word
  string words = "";
  for(int a = 0;a < size;a++){
    if(str[a] == ' '){
      word.push_back(words);
      words = "";
      continue;
    }
    words += str[a];
  }
  //

  //Pig Latin
  int word_size = word.size();
  for(int a = 0;a < word_size;a++){
    //edge case
     if(!((word[a][0] >= 65 && word[a][0] <= 90) || (word[a][0] >= 97 && word[a][0] <= 122))){
        continue;
     }
     //
     word[a] += word[a][0]; //move first to last
     word[a].erase(0,1); //erase first
     word[a] += "ay";
  }
  //

  //reassamble the word
  for(int a = 1;a < word_size;a++){
    word[0] += " ";
    word[0] += word[a];
  }
  //
  return word[0];
}
