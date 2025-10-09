#include <map>
#include <string>
#include <set>
using namespace std;

std::map<char, unsigned> count(const std::string& str) {
   int size = str.size()-1;
   if(size == -1){return {};} 
   std::set<char> v(str.begin(),str.end());
   std::vector<char> vect(v.begin(),v.end());
   std::map<char,unsigned> maps;
   int vect_size = vect.size()-1;
   for(int a = 0;a <= vect_size;a++){
     maps[vect[a]] = 0;
   }
   for(int a = 0;a <= size;a++){
     maps[str[a]]++;
   }
   return maps;  
}
