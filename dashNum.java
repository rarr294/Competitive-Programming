class Solution {
  public static String dashatize(int num){
    StringBuilder number = new StringBuilder(Integer.toString(num));
    
    //remove sign
    if(number.charAt(0) == '-'){
       number.deleteCharAt(0);
    }
    //
    
    //edge case
    if(number.length() == 1){
       return number.toString();
    }
    //

    //add padding to front and end
    number.insert(0,'-');
    number.append('-');
    //

    //dash
    for(int a = 1;a <= number.length()-2;a++){
      int utfCode = (int)number.charAt(a) - 48;
      if((utfCode % 2) != 0){
         if(a > 0 && number.charAt(a-1) == '-'){
           number.insert(a+1,'-');
           a++;
           continue;
         }else if(number.charAt(a-1) != '-'){
           number.insert(a,'-');
           number.insert(a+2,'-');
           a += 2;
           continue;
         }
         number.insert(a-1,'-');
         number.insert(a+2,'-');
         a += 2;
      }
    }
    //

    //remove leading and trailing dash
    while(true){
      if(number.charAt(0) != '-'){
        break;
      }
      number.deleteCharAt(0);
    }

    while(true){
      if(number.charAt(number.length()-1) != '-'){
        break;
      }
      number.deleteCharAt(number.length()-1);
    }
    //
    return number.toString();
  }
}
