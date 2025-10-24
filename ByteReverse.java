import java.util.ArrayList;

class Kata {
   public static int[] DataReverse(int[] data){
     ArrayList<ArrayList<Integer>> Store_Byte = new ArrayList<>();
     int data_length = data.length;
     
     if(data_length == 0){
       return new int[0];
     }

     ArrayList<Integer> Byte = new ArrayList<>();
     for(int a = 0;a <= data_length;a++){
       if(((a % 8) == 0) && (a != 0)){
         //outbound index handler
         if(a == data_length){
            Store_Byte.add(Byte);
            break;
         }
         //
         Store_Byte.add(Byte);
         Byte = new ArrayList<>(); //set Byte to empty
       }
       Byte.add(data[a]);
     }

     //reassamble Byte
     int Size = Store_Byte.size()-2;
     for(int size = Size + 1;Size >= 0;Size--){
       Store_Byte.get(size).addAll(Store_Byte.get(Size));
     }
     int size = Store_Byte.get(Store_Byte.size()-1).size();

     int[] result = new int[size];
     int last_index = Store_Byte.size()-1;
     for(int a = 0;a < size;a++){
       result[a] = Store_Byte.get(last_index).get(a);
     }
     //
     return result;
   }
}
