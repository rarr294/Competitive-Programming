/*

Given two strings, the first being a random string and the second being the same as the first, 
but with three added characters somewhere in the string (three same characters),

Write a function that returns the added character
You can assume that string2 will aways be larger than string1, 
and there will always be three added characters in string2.

Examples
string1 = "hello"
string2 = "aaahello"
=> 'a'

string1 = "abcde"
string2 = "2db2a2ec"
=> '2'

string1 = "aabbcc"
string2 = "aacccbbcc"
=> 'c'

*/


/*

to solve this problem we can try to rebuild s2 using s1(after rebuild s2 == s1)
using this principle i can create algorithm to solve this problem whenever
s1[a] == s2[b] then we just need to make s2[b] = 0

when the loop is complete s2 will have 2 different value : 
0 and three char(which is the answer)

even though i'm rebuild s2 i don't store the rebuild result
we don't need it
*/

#include <string.h>

char added_char(char *s1,char *s2){
  int s1_size = strlen(s1);
  int s2_size = strlen(s2);

  for(int a = 0;a < s1_size;a++){
     for(int b = 0;b < s2_size;b++){
        if(s1[a] == s2[b]){
           s2[b] = 0;
           break;
        }
     }
  }

  for(int a = 0;a < s2_size;a++){
     if(s2[a] != 0){
       return str2[a];
     }
  }
  return 0; //return nothing
}
