/*

Given a lowercase string that has alphabetic characters only and no spaces, 
return the highest value of consonant substrings. Consonants are any letters 
of the alphabet except "aeiou".

We shall assign the following values: a = 1, b = 2, c = 3, .... z = 26.

For example

"zodiac" -> 26
The consonant substrings are: "z", "d" and "c" with values "z" = 26, "d" = 4 and "c" = 3. The highest is 26.

"strength" -> 57
The consonant substrings are:

"str" and "ngth" 
with values "str" = 19 + 20 + 18 = 57 
and "ngth" = 14 + 7 + 20 + 8 = 49. 

The highest is 57.

*/

int solve(const char *s){
  int sum = 0;
  int cur_sum = 0;

  while(*s){
    char c = *s - 96;
    if(c == 1 || c == 5 || c == 9 || c == 15 || c == 21){
      (cur_sum > sum) ? (sum = cur_sum) : 0;
      cur_sum = 0;
      s++;
      continue;
    }
    cur_sum += c;
    s++;
  }
  (cur_sum > sum) ? (sum = cur_sum) : 0;
  return sum;
}
