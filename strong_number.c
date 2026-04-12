/*

Strong number is a number with the sum of the factorial 
of its digits is equal to the number itself.

For example, 145 is strong,
because 1! + 4! + 5! = 1 + 24 + 120 = 145.

Task Given a positive number, find if it is strong or not,
and return either "STRONG!!!!" or "Not Strong !!".

Examples
1 is a strong number, because 1! = 1, so return "STRONG!!!!".
123 is not a strong number, because 1! + 2! + 3! = 9 is not equal to 123, so return "Not Strong !!".
145 is a strong number, because 1! + 4! + 5! = 1 + 24 + 120 = 145, so return "STRONG!!!!".
150 is not a strong number, because 1! + 5! + 0! = 122 is not equal to 150, so return "Not Strong !!".

*/

int arr[9] = {1,2,6,24,120,720,5040,40320,362880};

const char* strong_num(int number){
  int n = (number < 0) ? (number *= -1) : number;
  int sum = 0;

  while(number){
    char digit = number % 10;

    if(digit != 0){
      sum += *(arr + digit - 1);
    }

    number = (number - digit) / 10;
  }

  return (n == sum) ? "STRONG!!!!" : "Not Strong !!";
}
