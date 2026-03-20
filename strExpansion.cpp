/*

Description:

Given a string that includes alphanumeric characters ("3a4B2d") return the expansion of that string: 

(1). The numeric values represent the occurrence of each letter preceding that numeric value. 
(2). There should be no numeric characters in the final string.

Notes :
(1). The first occurrence of a numeric value should be the number of times each character behind it is repeated, until the next numeric value appears
(2). If there are multiple consecutive numeric characters, only the last one should be used (ignore the previous ones)
(3). Empty strings should return an empty string.

Your code should be able to work for both lower and capital case letters.

"3D2a5d2f"  -->  "DDDaadddddff"    # basic example: 3 * "D" + 2 * "a" + 5 * "d" + 2 * "f"
"3abc"      -->  "aaabbbccc"       # not "aaabc", nor "abcabcabc"; 3 * "a" + 3 * "b" + 3 * "c"
"3d332f2a"  -->  "dddffaa"         # multiple consecutive digits: 3 * "d" + 2 * "f" + 2 * "a"
"abcde"     -->  "abcde"           # no digits
"1111"      -->  ""                # no characters to repeat
""          -->  ""                # empty string

*/

#include <string>

using namespace std;

string string_expansion(const string& s){
  int a = 0;
  string result = "";
  int size = s.size();

  while(a < size){
      char present_number_flag = 0;

     while(s[a] >= 48 && s[a] <= 57){
        present_number_flag = 1;
        a++;
     }

     if(present_number_flag == 0 && (a != size)){
       result.push_back(s[a++]);
       continue;
     }

     char upBound = s[a - 1];

     while((!(s[a] >= 48 && s[a] <= 57)) && (a != size)){
       for(char b = 49;b <= upBound;b++){
         result.push_back(s[a]);
       }
       a++;
     }
  }
  
  return result;
}
