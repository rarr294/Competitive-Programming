#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class LongestConsec{
public:
  static std::string longestConsec(const std::vector<std::string> &v, int k){
     int size = v.size()-1;
     if(((size+1) == 0) || (k > (size+1)) || (k <= 0)){
       return "";
     }
     vector<string> concat;
     int a = 0;
     while(a <= size){
       string push_con;
       int index = a;
       for(int c = 1;c <= k;c++){
         push_con += v[index];
         index++;
       }
       concat.push_back(push_con);
       if(index > size){
         break;
       }
       a++;
     }

   //finding the index of longest string
    int sizes = concat.size()-1;
    vector<int> size_vect;
    for(int a = 0; a <= sizes;a++){
      size_vect.push_back(concat[a].size());
    }

    vector<int> copying_size_vect = size_vect;
    sort(size_vect.begin(),size_vect.end());

      //linear search to find maximum value index
      for(int a = 0;a <= sizes;a++){
         if(copying_size_vect[a] == size_vect[sizes]){
            return concat[a];
         }
      }
      //
    //
    return "";
  }
};
