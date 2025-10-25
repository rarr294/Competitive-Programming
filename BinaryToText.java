import java.util.*;

class Solution{
  public static String binaryToText(String binary){
    ArrayList<String> Binary = new ArrayList<>();
    int size = binary.length();

    //edge case
    if(size == 0){
      return "";
    }
    //

    //Extracting Binary
    String bit = "";
    for(int a = 0;a <= size;a++){
      if(((a % 8) == 0) && (a != 0)){
         //outbound index handler
         if(a == size){
            Binary.add(bit);
            break;
         }
         //
         Binary.add(bit);
         bit = ""; //set bit to empty
      }
      bit += binary.charAt(a);
    }
    //

    //Creating hash bit position
    int power = 7;
    Map<Integer,Integer> bitHash = new HashMap<>();
    for(int a = 0;a <= 7;a++){
       bitHash.put(a,power);
       power--;
    }
    //

    //bit decoding
    int length = Binary.size();
    String decode = "";
    for(int a = 0;a < length;a++){
       String bits = Binary.get(a);
       int utfCounter = 0;
       for(int b = 0;b <= 7;b++){
         if(bits.charAt(b) == '1'){
            utfCounter += Math.pow(2,bitHash.get(b));
         }
       }
      decode += (char)utfCounter;
    }
    //
    return decode;
  }
}
