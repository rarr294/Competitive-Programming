/*

Each exclamation mark's weight is 2; each question mark's weight is 3. 
Putting two strings left and right on the balance - are they balanced?

If the left side is more heavy, return "Left"; if the right side is more heavy, 
return "Right"; if they are balanced, return "Balance".

Examples

"!!", "??"     -->  "Right"
"!??", "?!!"   -->  "Left"
"!?!!", "?!?"  -->  "Left"
"!!???!????", "??!!?!!!!!!!"  -->  "Balance"

*/

char balance(const char *left, const char *right){

  int left_sum = 0;
  int right_sum = 0;

  while(*left && *right){

    left_sum += (
      (*left == 33) ? 2 :
      (*left == 63) ? 3 :
      0
    );

    right_sum += (
      (*right == 33) ? 2 :
      (*right == 63) ? 3 :
      0
    );

    left++,right++;
  }

  while(*left || *right){

    if(*left){

      left_sum += (
        (*left == 33) ? 2 :
        (*left == 63) ? 3 :
        0
      );

      left++;
      continue;
    }

    right_sum += (
      (*right == 33) ? 2 :
      (*right == 63) ? 3 :
      0
    );

    right++;
  }

  return (
    (left_sum > right_sum) ? 1 :
    (right_sum > left_sum) ? 2 :
    0
  );
}
