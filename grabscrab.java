/*

Pirates have notorious difficulty with enunciating. 
They tend to blur all the letters together and scream at people.
At long last, we need a way to unscramble what these pirates are saying.

Write a function that will accept a jumble of letters as well as a dictionary, 
and output a list of words that the pirate might have meant.

For example:

grabscrab( "ortsp", ["sport", "parrot", "ports", "matey"] )
Should return ["sport", "ports"].

Return matches in the same order as in the dictionary. 
Return an empty array if there are no matches.

Good luck!

*/

import java.util.List;
import java.util.ArrayList;

class Grab{
  public static List<String> grabscrab(String s, List<String> words){
     List<String> result = new ArrayList<>();
     int size = words.size();
     int s_size = s.length();
     char[] s_arr = new char[s_size];
     s_arr[0] = s.charAt(0);

     //insertion sort
     for(int a = 1;a < s_size;a++){
        int offset = a;
        while(offset > 0){
          if((int)(s_arr[offset - 1]) > (int)(s.charAt(a))){
            s_arr[offset] = s_arr[offset - 1];
          }else if((int)(s_arr[offset - 1]) <= (int)(s.charAt(a))){
            break;
          }
          offset--;
        }
        s_arr[offset] = s.charAt(a);
     }
     //

     for(int a = 0;a < size;a++){
       String word = words.get(a);

       if(word.length() != s_size){
         continue;
       }

       char[] w_arr = new char[s_size];
       w_arr[0] = word.charAt(0);

       //insertion sort
       for(int b = 1;b < s_size;b++){
          int offset = b;
          while(offset > 0){
            if((int)(w_arr[offset - 1]) > (int)(word.charAt(b))){
              w_arr[offset] = w_arr[offset - 1];
            }else if((int)(w_arr[offset - 1]) <= (int)(word.charAt(b))){
              break;
            }
            offset--;
          }
          w_arr[offset] = word.charAt(b);
       }
       //


       char notEqual_flag = (char)0;
       for(int b = 0;b < s_size;b++){
          if(s_arr[b] != w_arr[b]){
            notEqual_flag = (char)1;
            break;
          }
       }

       if(notEqual_flag == 1){
         continue;
       }
       result.add(word);
     }
     return result;
  }
}
