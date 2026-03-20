/*

Write a function that returns both 
the minimum and maximum number of the given 
list/array.

Examples (Input --> Output)
[1,2,3,4,5] --> [1,5]
[2334454,5] --> [5,2334454]
[1]         --> [1,1]

*/

void min_max(const int *ar,int c,int *min,int *max){
  *min = *a,*max = *a;
  for(int a = 1;a < c;a++){
    (*(ar + a) < *min) ? (*min = *(ar + a)) : 0;
    (*(ar + a) > *max) ? (*max = *(ar + a)) : 0;
  }
}
