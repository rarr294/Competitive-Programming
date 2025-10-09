bool narcissistic(int value){
     int compare = value;
     int power = 0;
     int ctrl_loop = 1;
     while(ctrl_loop < value){
           power += 1;
           ctrl_loop  *= 10;
    }
    int result = 0;
    while(!(value < 10)){
          int digit = value % 10;
          int base_exponent = digit;
          for(int a = 1;a < power;a++){
                base_exponent *= digit;
          }
          result += base_exponent;
          value -= digit;
          value /= 10;
    }
    int base = value;
    for(int a = 1;a < power;a++){
         value *= base;
    }
    result += value;
    if(result == compare){
        return 1;
    }
    return 0;
}
