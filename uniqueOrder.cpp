#include <string>
#include <vector>
using namespace std;
template <typename T> 
std::vector<T> uniqueInOrder(std::vector<T> iterable){
   int size = iterable.size()-1;
    if(size == -1){
     return {};
   }
   std::vector<T> result;
   T state = iterable[0];
   for(int a = 0;a <= size;a++){
      if(state != iterable[a]){
         result.push_back(state);
         state = iterable[a];
      }
   }
   result.push_back(state);
   return result;

}
std::vector<char> uniqueInOrder(std::string iterable){
   int size = iterable.size()-1;
   if(size == -1){
     return {};
   }
   std::vector<char> result;
   char state = iterable[0];
   for(int a = 0;a <= size;a++){
      if(state != iterable[a]){
         result.push_back(state);
         state = iterable[a];
      }
   }
   result.push_back(state);
   return result;
}
