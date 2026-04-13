/*

A Tidy Number is a number whose digits are in non-decreasing order.
Task : Given a number, determine if it is tidy or not.

Notes : The number passed will always be positive.

Examples
12 ==> return true
Explanation: Digits {1, 2} are in non-decreasing order (1 <= 2).

32 ==> return false
Explanation: Digits {3, 2} are not in non-decreasing order (3 > 2).

1024 ==> return false
Explanation: Digits {1, 0, 2, 4} are not in non-decreasing order (1 > 0).

13579 ==> return true
Explanation: Digits {1, 3, 5, 7, 9} are in non-decreasing order.

2335 ==> return true
Explanation: Digits {2, 3, 3, 5} are in non-decreasing order (3 = 3).

*/

char tidyNumber(unsigned int number){

  char prev_digit = number % 10;
  number = (number - prev_digit) / 10;

  while(number){
    char digit = number % 10;

    if(!(prev_digit >= digit)){
      return 0;
    }

    prev_digit = digit;
    number = (number - prev_digit) / 10;
  }

  return 1;
}
