import java.util.ArrayList;
import java.util.Arrays;

public class Math {
   public static int[] Interval(int[] arr, String str){
      int size = str.length()-1;
      if((size < 0) || (arr.length == 0)){
        int[] empty = new int[0];
        return empty;
      }
     
      //extracting the number
      String operand_1 = "";
      String operand_2 = "";
      int index = 1;
      int index_op2;
      while(true){
        if(str.charAt(index) == ','){
           index_op2 = index + 1;
           break;
        }
        operand_1 += str.charAt(index);
        index++;
      }
     
      while(true){
        if((str.charAt(index_op2) == ']') || 
           (str.charAt(index_op2) == ')')){
            break;
        }
        operand_2 += str.charAt(index_op2);
        index_op2++;
      }   
      int operand1 = Integer.parseInt(operand_1);
      int operand2 = Integer.parseInt(operand_2);
      //
     
      char first_code = str.charAt(0);
      char last_code = str.charAt(size);
     
      //calculate interval
      if(first_code == '('){
        operand1++;
      }
     
      if(last_code == ')'){
        operand2--;
      }
      
      ArrayList<Integer> result = new ArrayList<>();
      for(int a = 0;a < arr.length;a++){
        if((arr[a] >= operand1) && 
           (arr[a] <= operand2)){
            result.add(arr[a]);
        }
      }
      //  
     
      int[] arrs = new int[result.size()];   
      for(int i = 0; i < result.size(); i++) {
         arrs[i] = result.get(i);
      }
      Arrays.sort(arrs);
      return arrs;        
   }
}
