#include <string>
#include <vector>
using namespace std;

std::string to_weird_case(std::string str){
   str.push_back(' '); //to make sure the last word inserted into the stack
   int size = str.size();

   //word parsing
   vector<string> word;
   string push_this = "";
   for(int a = 0;a < size;a++){
      if(str[a] == ' '){
         word.push_back(push_this);
         push_this = "";
         continue;
      }
      push_this += str[a];
   }
   //

   //convert str case
   int word_size = word.size();
   for(int a = 0;a < word_size;a++){
      int str_size = word[a].size();
      for(int b = 0;b < str_size;b++){
        if((b % 2) == 0){
          if((word[a][b] >= 97) && (word[a][b] <= 122)){
             word[a][b] -= 32;
          }
          continue;
        }
        if((word[a][b] >= 65) && (word[a][b] <= 90)){
           word[a][b] += 32;
        }
      }
   }
   //

   //reassmble the word
   string result;
   for(int a = 0;a < word_size;a++){
      int str_size = word[a].size();
      for(int b = 0;b < str_size;b++){
         result += word[a][b];
      }
      result += " ";
   }
   result.pop_back(); //remove the whitespace
   return result;
   //
}



