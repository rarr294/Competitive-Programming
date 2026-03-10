/*

Description:
You are given a string of words (x), for each word within the string you need to turn the word 'inside out'. 
By this I mean the internal letters will move out, and the external letters move toward the centre.

If the word is even length, all letters will move. 
If the length is odd,you are expected to leave the 'middle' letter of the word where it is.

An example should clarify:

'taxi' would become 'atix' 'taxis' would become 'atxsi'
Words will be separated by exactly one space and there will be no leading or trailing spaces.

*/

#include <string>

using namespace std;

std::string insideOut(std::string x){
  x += ' ';
  string result;
  int size = x.size();

  for(int lowBound = 0;lowBound < size;lowBound++){
     int w_size = 0;
     int upBound = lowBound;

     while(x[upBound] != ' '){
       upBound++;
       w_size++;
     }

     if(w_size == 1){
       result += x[upBound - 1];
       result += ' ';
       lowBound = upBound;
       continue;
     }else if(w_size == 2){
       result += x[upBound - 2];
       result += x[upBound - 1];
       result += ' ';
       lowBound = upBound;
       continue;
     }

     if((w_size % 2) == 0){
       int mid = w_size / 2;

       for(int up = upBound - mid - 1;up >= lowBound;up--){
          result += x[up];
       }

       for(int up = upBound - 1;up >= upBound - mid;up--){
          result += x[up];
       }

       result += ' ';
       lowBound = upBound;
       continue;
     }

     int mid = lowBound + w_size / 2;
     for(int up = mid - 1;up >= lowBound;up--){
        result += x[up];
     }

     result += x[mid];

     for(int up = upBound - 1;up > mid;up--){
        result += x[up];
     }
     result += ' ';
     lowBound = upBound;
  }
  result.pop_back();
  return result;
}
