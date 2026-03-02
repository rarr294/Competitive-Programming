/*

ou have to write a function which creates the following pattern (See Examples) upto desired number of rows.
If the Argument is 0 or a Negative Integer then it should return "" i.e. empty string.

Examples:

Argument: 9

123456789
234567891
345678912
456789123
567891234
678912345
789123456
891234567
912345678

Argument: 11

1234567891011
2345678910111
3456789101112
4567891011123
5678910111234
6789101112345
7891011123456
8910111234567
9101112345678
1011123456789
1112345678910

*/

#include <string>

using namespace std;

string pattern(int n){
  if(n <= 0){
    return "";
  }
  string p;

  int counter = 0;
  for(int a = 0;a < n;a++){
     for(int b = a + 1;b <= n;b++){
        p += to_string(b);
     }

     for(int c = 1;c <= counter;c++){
        p += to_string(c);
     }

     p += 10;
     counter++; 
  }
  p.erase(p.begin() + p.size() - 1);
  return p;
}

    2 hours ago
