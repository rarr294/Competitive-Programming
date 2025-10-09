#include  <vector>
using namespace std;

class Kata{
public:
   std::vector<int> sortArray(std::vector<int> array){
      std::vector<int> index;
      int size = array.size()-1;
      for(int a = 0;a <= size;a++){
        if((array[a] % 2) != 0){
           index.push_back(a);
           continue;
        }
      }
     
      int index_size = index.size()-1;
      for(int a = 1;a <= index_size;a++){
          int var = 1;
          for(int b = 0;b < index_size;b++){
              if(array[index[b]] > array[index[var]]){
                 int swap = array[index[b]];
                 array[index[b]]  = array[index[var]];
                 array[index[var]] = swap;
                 var += 1;
                 continue;
              }
              var += 1;
          }
       }
       return array;
    }
};
