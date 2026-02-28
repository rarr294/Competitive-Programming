/*

Write a function that takes a string input, and returns the first character that is not repeated anywhere in the string.

For example, if given the input "stress", the function should return 't',
since the letter t only occurs once in the string, and occurs first in the string.

As an added challenge, upper- and lowercase characters are considered the same character, 
but the function should return the correct case for the initial character.
For example, the input "sTreSS" should return "T".

If a string contains only repeating characters, 
return an empty string ("");

Note: despite its name in some languages, 
your function should handle any Unicode codepoint:

"@#@@*"    --> "#"
"かか何"   --> "何"
"🐐🦊🐐" --> "🦊"

*/

class Kata {
  public static String firstNonRepeatingLetter(String s){
    int size = s.length();
    short[] freq = new short[1114112];
    
    for(int a = 0;a < size;a++){
       int unicode = s.codePointAt(a);
       if(unicode >= 65 && unicode <= 90){
          unicode += 32;
       }
       freq[unicode]++;
    }
    
    for(int a = 0;a < size;a++){
       int unicode = s.codePointAt(a);
       char upCase_flag = 0;
      
       if(unicode >= 65 && unicode <= 90){
          unicode += 32;
          upCase_flag = 1;
       }      
      
       if(freq[unicode] == 1){
          if(upCase_flag == 1){
            unicode -= 32;
          }
          return String.valueOf(Character.toChars(unicode));
       }
    }
    return "";
  }
};
