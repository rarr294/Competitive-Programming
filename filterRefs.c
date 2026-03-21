/*

Most of us used to need to make a quick copy of text from Wikipedia, 
but those reference marks, e.g. [1], sprinkled all over can get quite annoying!

Now you, code warrior, are about to make a difference! 
Given a string, remove in-place all reference marks 
(which have the format [n], where n - is an integer) 
and return it.

It's important to note,however, that these marks 
do not nest - thus you should not worry about the cases with nested marks, 
e.g. [[1]].

Reference marks do stack, 
though, e.g. [1][2][3].

It is also guaranteed that there will be no marks with non-digits between the brackets.

Example:
Given a source string: "Caesar is considered by many historians to be one of the greatest military commanders in history.[4]", 
your function should return: "Caesar is considered by many historians to be one of the greatest military commanders in history."

Addendum:
Please keep in mind, that these marks can theoretically appear anywhere within the source string.
Remove the marks only. No whitespace stripping or any other form of the source string mutation is required.
StringsFiltering

*/

#include <string.h>

void filterRefsOut(char *src){
  
  while(*src){
    
    if(*src != 91){ 
      goto gohere; 
    }

    char *first_pos = src;

    while(1){
      if(*src == 93 && *(src + 1) != 91){
        src++;
        break;
      }
      src++;
    }

    memmove(first_pos,src,strlen(src) + 1);

    src = first_pos - 1;

    gohere:
    src++;
  }
}
