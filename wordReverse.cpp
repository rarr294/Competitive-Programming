#include <string>
#include <vector>
using namespace std;

std::string reverse_words(const std::string& str){
   unsigned int size = str.size()-1;
   std::vector<vector<int>> vect_2d;
   //tracking index
   int loop = 0;
   int track1 = 0;
   int track2;
   while(loop <= size){
     if(str[loop] == ' '){
       track2 = loop - 1;
       vect_2d.push_back({track1,track2});
       loop++;
       track1 = loop;
       continue;
     }else if(loop == size){
        vect_2d.push_back({track1,loop});
     }
     loop++;
   }
   //
   std::string empty_str;
   for(int a = vect_2d.size()-1;a >= 0;a--){
      int low = vect_2d[a][0];
      int high = vect_2d[a][1];
      for(;low <= high;low++){
         empty_str.push_back(str[low]);
      }
      empty_str.push_back(' ');
   }
   empty_str.pop_back();
   return empty_str;
}
