#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::string highestScoringWord(std::string str){
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
  
  //doing sum 
  int Sizes = vect_2d.size()-1;
  std::vector<int> sum;
  for(int a = 0;a <= Sizes;a++){
    int lowest = vect_2d[a][0];
    int highest = vect_2d[a][1];
    int sums = 0;
    for(;lowest <= highest;lowest++){
      sums += (str[lowest]-96);
    }
    sum.push_back(sums);  
  }
  //
 
  //hashing part 
  std::vector<int> sum_cpy = sum;
  sort(sum_cpy.begin(),sum_cpy.end());
  int sum_size = sum_cpy.size()-1;
  for(int a = 0;a <= sum_size;a++){
     if(sum[a] == sum_cpy[sum_size]){
        int lowest = vect_2d[a][0];
        int highest = vect_2d[a][1];
        std::string result;       
        for(;lowest <= highest;lowest++){
           result.push_back(str[lowest]);
        }
        return result;
     }
  }
  // 

  //return-type func must have
  //return value
  return "nothing"; 
  //
}
