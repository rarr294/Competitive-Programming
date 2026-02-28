/*

Hereinafter, [space] refers to " ", [tab] refers to "\t", and [LF] refers to "\n" for illustrative purposes. 
This does not mean that you can use these placeholders in your solution.

In esoteric language called Whitespace, 
numbers are represented in the following format:

first character represents the sign: [space] for plus, [tab] for minus;
characters after that are the binary representation of the absolute value of the number, with [space] for 0, [tab] for 1, the rightmost bit is the least significand bit, and no leading zero bits.
the binary representation is immediately followed by [LF].

Notes
Valid Whitespace number must always have at least two characters: a sign and the terminator. In case there are only two characters, the number is equal to zero.
For the purposes of this kata, zero must always be represented as [space][LF].
In Whitespace, only space, tabulation and linefeed are meaningful characters. 
All other characters are ignored. However, for the purposes of this simple kata, please do not add any other characters in the output.
In this kata, input will always be a valid negative or positive integer.
For your convenience, in this kata we will use unbleach() function when evaluating your results.
This function replaces whitespace characters with [space], [tab], and [LF] to make fail messages more obvious. You can see how it works in Example Test Cases.


Examples
1 in Whitespace is " \t\n".
0 in Whitespace is " \n".
-1 in Whitespace is "\t\t\n".
2 in Whitespace is " \t \n".
-3 in Whitespace is "\t\t\t\n".

*/


#include <string.h>
#include <stdlib.h>

char *whitespace_number(int n){
   char neg_flag = (n < 0) ? 
     (n *= -1,1) : 0;
  
   if(n == 0){
      char *mem = malloc(3);
      mem[0] = ' ';
      mem[1] = '\n';
      mem[2] = 0;
      return mem;
   }
  
   int c = n;
   int bin_bucket_size = 0;
   while(bin_bucket_size++,c /= 2){}
  
   char *w = malloc(bin_bucket_size + 3);
   char *bin_bucket = malloc(bin_bucket_size);
  
   int idx = 0;
   while(bin_bucket[idx++] = n % 2,n /= 2){}

   idx = 0;
   bin_bucket_size--;
  
   w[idx++] = (neg_flag == 1) ? 
     '\t' : ' ';
  
   while(bin_bucket_size >= 0){
     w[idx++] = 
        (bin_bucket[bin_bucket_size] == 1)
        ?
       '\t' : ' ';
      bin_bucket_size--;
   }
   w[idx++] = '\n';
   w[idx] = 0;
  return w;
}
