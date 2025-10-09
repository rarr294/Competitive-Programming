int Add(int x, int y) {
   while (y != 0) {
     int sum = x ^ y;    
     int carry = (x & y) << 1;
      x = sum;
      y = carry;
    }
    return x;
}
