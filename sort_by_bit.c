void sort_by_bit(int arr[], int len){
  for(int a = 1;a <= len;a++){
    int a1 = 0;
    for(int a2 = 1;a2 < len;a2++){
      int c1 = __builtin_popcount(arr[a1]);
      int c2 = __builtin_popcount(arr[a2]);          
      if(c1 > c2){
        int tmp = arr[a1];
        arr[a1] = arr[a2];
        arr[a2] = tmp;     
      }else if(c1 == c2){
        if(arr[a1] > arr[a2]){
          int tmp = arr[a1];
          arr[a1] = arr[a2];
          arr[a2] = tmp;
        }
      }
      a1++;
    }
  }
}
