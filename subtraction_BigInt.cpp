// Important Note
// the reason i create the addWithSigned Interface for subtraction big int because
// i want to make sure the sub() function only doing 1 simple job : subtract without handling the msb borrow
// addWithSigned() will ensure that there are no msb borrows 

#include <string>
using namespace std;

std::string add(std::string a,std::string b){
  int size_a = a.size();
  int size_b = b.size();

  //add padding byte to data
  int padding;
  if(size_a < size_b){
    int total_padding = size_b - size_a;
    padding = size_b;
    for(int add_pad = 1;add_pad <= total_padding;add_pad++){
       a.insert(0,"0");
    }
  }else if(size_b < size_a){
    int total_padding = size_a - size_b;
    padding = size_a;
    for(int add_pad = 1;add_pad <= total_padding;add_pad++){
       b.insert(0,"0");
    }
  }else if(size_a == size_b){
    padding = size_a;
  }
  std::string result(padding,'0');
  //

  //adding operation
  int carry = 0;
  int size = a.size()-1;
  while(size >= 0){
    int first = a[size] - 48;
    int second= b[size] - 48;
    int add = first + second + carry;

    //handling carry
    if(add > 9){
      int last_digit = add % 10;
      result[size] = last_digit + 48;
      carry = 1;
      size--;
      continue;
    }
    //
    carry = 0;
    result[size] = add + 48;
    size--;
  }
  //

  //handling msb carry
  if(carry == 1){
    result.insert(0,"1");
  }
  //
  return result;
}

std::string sub(std::string a,std::string b){
  int size_a = a.size();
  int size_b = b.size();

  //add padding byte to data
  int padding;
  if(size_a < size_b){
    int total_padding = size_b - size_a;
    padding = size_b;
    for(int add_pad = 1;add_pad <= total_padding;add_pad++){
       a.insert(0,"0");
    }
  }else if(size_b < size_a){
    int total_padding = size_a - size_b;
    padding = size_a;
    for(int add_pad = 1;add_pad <= total_padding;add_pad++){
       b.insert(0,"0");
    }
  }else if(size_a == size_b){
    padding = size_a;
  }
  std::string result(padding,'0');
  //

  //sub operation
  int size = a.size()-1;
  while(size >= 0){
    int first = a[size] - 48;
    int second= b[size] - 48;
    int sub = first - second;

    //handling borrow
    if(sub < 0){
      int borrowLeftOp = 10 + first;
      a[size - 1] -= 1;
      borrowLeftOp -= second;
      result[size] = borrowLeftOp + 48;
      size--;
      continue;
    }
    //

    result[size] = sub + 48;
    size--;
  }
  //

  //remove leading zero if exist
  size = a.size();
  if(result[0] == '0'){
    result.erase(0,1);
  }
  //
  return result;
}

char LessThenComparator(string a,string b){
   int a_size = a.size();
   int b_size = b.size();
   if(a[0] == '-' && b[0] != '-'){return (char)1;}
   if(a[0] != '-' && b[0] == '-'){return (char)0;}
   if(a_size < b_size){return (char)1;}
   if(a_size > b_size){return (char)0;}
   if(a_size == b_size){
     int size = a.size();
     for(int c = 0;c < size;c++){
       if(a[c] < b[c]){
          return (char)1;
       }
     }
     return (char)0;
   }
   return '0'; //compile with no error
};

string addWithSigned(string a,string b){
   int debugBreak = 0;
   if(a[0] == '-' && b[0] == '-'){
      a.erase(0,1);
      b.erase(0,1);
      string bothNegative = add(a,b);
      bothNegative.insert(0,"-");
      return bothNegative;
   }else if(a[0] != '-' && b[0] != '-'){
      return add(a,b);
   }

   //remove sign
   if(a[0] == '-'){
     a.erase(0,1);
   }

   if(b[0] == '-'){
     b.erase(0,1);
   }
   //

   if(a == b){
     return "0";
   }

   //swap to make sure a always less then b
   if(!(LessThenComparator(a,b))){
     string tmp = a;
     a = b;
     b = tmp;
   }
   //

   //sub big int
   if(LessThenComparator(a,b)){
     string tmp = a;
     a = b;
     b = tmp;
     string result = sub(a,b);
     result.insert(0,"-");
     return result;
   }
   return sub(a,b);
   //
};
