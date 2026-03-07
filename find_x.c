/*

We have a function that takes in an integer n, and returns a number x.

Lets call this function findX(n)/find_x(n) (depending on your language):

long long find_x(int n) {
  long long x = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2*n; j++)
      x += i + j;
  }
  return x;
}

The functions loops throught the number n and at every iteration, 
performs a nested loop on 2*n, at each iteration of this nested loop it increments x with the 
(nested loop index + parents loop index).

This works well when the numbers are reasonably small.

find_x(2) //=> 16
find_x(3) //=> 63
find_x(5) //=> 325
But may be slow for numbers > 103

So your task is to optimize the function findX/find_x, so it works well for large numbers.

Input Range
1 <= n <= 106 

*/

/*
note from me about how i can solve this problem.

if we see the pattern :
(1). outer_loop always do N loop
(2). inner_loop always do (n * 2 - 1) loop that mean it's same like 1+2+3+.....+n(n not included)
(3). because inner_loop run N times, we can generate this formula :
     y         = n * 2 - 1
     inner_sum = ((y * (y + 1)) / 2) * n;
(4). outer_loop total number in inner loop always (a * y + 1)
(5). addition is commutative the order of the operands not important, using this fact i can
     optimize the code time complexity from O(n^2) to O(n)
*/

long long find_x(int n){  
  long long y = n * 2 - 1;
  long long x = ((y * (y + 1)) / 2) * n;
 
  for(int a = 1;a < n;a++){
     x += a * (y + 1);
  }
  
  return x;
}
