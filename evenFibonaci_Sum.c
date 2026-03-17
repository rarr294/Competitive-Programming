/*

Give the summation of all even numbers in a Fibonacci sequence 
up to limit,but not including limit.

For example:

33 --> 10 : (0 1 1 2 3 5 8 13 21)[2 + 8 = 10]
25997544 --> 19544084
0 --> 0

*/

typedef unsigned long long ull;

ull even_fib(ull limit){
  ull sum = 0;
  ull before = 1;
  ull current = 2;
  ull save_before = 1;

  while(current < limit){
    save_before = current;

    if((current % 2) == 0){
      sum += current;
    }

    current += before;
    before = save_before;
  }
  return sum;
}
