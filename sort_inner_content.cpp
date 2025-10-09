#include <string>
#include <algorithm>
#include <functional>
using namespace std;

std::string sortTheInnerContent(std::string words) {
   auto beg1 = words.begin();
   auto beg2 = words.begin();
   auto end = words.end();
   while(1){
     if(beg2 == end){
       beg1++;
       end--;
       if(beg1 == beg2){
         break;
       }
       sort(beg1,end,greater<char>()); //sort inner content
       break;
     }else if(*beg2 == ' '){
       beg1++;
       beg2--;
       if(beg1 > beg2){
         beg2 += 2;
         beg1 = beg2;
         continue;
       }
       sort(beg1,beg2,greater<char>()); //sort inner content 
       beg2 += 2;
       beg1 = beg2;
       continue;
     }
     beg2++;
   }
   return words;
}
