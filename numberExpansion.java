class Kata {
  public static String expandedForm(int num){
    String number = Integer.toString(num);
    //edge case
    if(num < 10){
      return number;
    }
    //
    ArrayList<ArrayList<Integer>> expansion = new ArrayList<>();
    int size = number.length();
    int size_cpy = size-1;

    //expansion parser
    for(int a = 0;a < size;a++){
      ArrayList<Integer> exp = new ArrayList<>();
      exp.add((int)number.charAt(a)); //CHAR
      exp.add(size_cpy); //power
      exp.add(0); //index[2] for storing 10^n
      size_cpy--;
      expansion.add(exp);
    }
    //

    //exponential evaluation
    int base = 10;
    size = expansion.size();
    for(int a = 0;a < size;a++){
       int power = expansion.get(a).get(1);
       expansion.get(a).set(2,(int)Math.pow(base,power));
    }
    //

    //expansion to string
    ArrayList<String> expanded =  new ArrayList<>();
    for(int a = 0;a < size;a++){
       StringBuilder num_exp = new StringBuilder(Integer.toString(expansion.get(a).get(2)));
       int digit = expansion.get(a).get(0);
       num_exp.setCharAt(0,(char)digit);
       expanded.add(num_exp.toString());
    }
    //

    //reassemble data
    size = expanded.size();
    String result = "";
    for(int a = 0;a < size;a++){
      if(expanded.get(a).charAt(0) == '0'){
        continue;
      }
      result += expanded.get(a);
      result += " + ";
    }
    //

    //pop back
    StringBuilder rest = new StringBuilder(result);
    rest.deleteCharAt(rest.length()-1);
    rest.deleteCharAt(rest.length()-1);
    rest.deleteCharAt(rest.length()-1);
    //
    return rest.toString();
  }
}
