#include <string>
  
auto makeLooper(const std::string& text){
   int index = -1;
   auto func = [text,index]() mutable{
     int size = text.size()-1;
     index++;
     if(index > size){
        index = 0;
     }
     return text[index];
   };
   return func;
}
