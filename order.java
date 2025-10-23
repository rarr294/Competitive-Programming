import java.util.ArrayList;

class Order{
  public static String order(String words){
    ArrayList<ArrayList<Integer>> pos = new ArrayList<>();
    int size = words.length();
    if(size == 0){
      return "";
    }

    //extracting total_word
    int total_word = 0;
    for(int a = 0;a < size;a++){
       if(words.charAt(a) == ' '){
         total_word++;
       }
    }
    total_word++;
    //

    //add empty arr
    for(int a = 1;a <= total_word;a++){
      ArrayList<Integer> empty = new ArrayList<>();
      pos.add(empty);
    }
    //

    //filling the empty arr
    String space = ' ' + words;
    int space_size = space.length();
    int pos_index = 0;
    for(int a = 0;a < space_size;a++){
       if(space.charAt(a) == ' '){
          pos.get(pos_index).add(a);
          pos_index++;
       }
    }

    pos_index = 0;
    for(int a = 0;a < size;a++){
      int utfCode = (int)words.charAt(a);
      if((utfCode >= 48) && (utfCode <= 57)){
        pos.get(pos_index).add(utfCode);
        pos_index++;
      }
    }

    space = words + ' ';
    space_size = space.length();
    pos_index = 0;
    for(int a = 0;a < space_size;a++){
      if(space.charAt(a) == ' '){
         pos.get(pos_index).add(a - 1);
         pos_index++;
      }
    }
    //

    //sort the Object using bubbleSort
    int outSize = pos.size()-1;
    for(int out = 1;out < outSize;out++){
      int first = 0;
      for(int second = 1;second <= outSize;second++){
         int firstData = pos.get(first).get(1);
         int secondData = pos.get(second).get(1);
         if(firstData > secondData){
           ArrayList<Integer> tmp = pos.get(first);
           pos.set(first,pos.get(second));
           pos.set(second,tmp);
         }
         first++;
      }
    }
    //

    //reassemble the Data
    total_word -= 1;
    String result = "";
    for(int a = 0;a <= total_word;a++){
       int start = pos.get(a).get(0);
       int end = pos.get(a).get(2);
       for(;start <= end;start++){
          result += words.charAt(start);
       }
       if(a == total_word){
         break;
       }
       result += ' ';
    }
    //
    return result;
    //
  }
}
