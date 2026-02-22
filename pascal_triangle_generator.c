/*
Task

Write a function that, given a depth n, returns n top rows of Pascal's Triangle flattened into a one-dimensional list/array.
Example:

n = 1: [1]
n = 2: [1,  1, 1]
n = 4: [1,  1, 1,  1, 2, 1,  1, 3, 3, 1]
*/

void pascals_triangle(unsigned n, unsigned triangle[n * (n + 1) / 2]){
  int index = 3;
  int before_index = 1;

  for(int a = 1;a <= n;a++){
     if(a == 1){
        triangle[0] = 1;
        continue;
     }else if(a == 2){
        triangle[1] = 1;
        triangle[2] = 1;
        continue;
     }
     triangle[index++] = 1;

     int total_loop = a - 2;
     for(int b = 1;b <= total_loop;b++){
        triangle[index++] = triangle[before_index] + triangle[++before_index];
     }

     before_index++;
     triangle[index++] = 1;
  }
}
