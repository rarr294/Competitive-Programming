#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;

std::vector<int> solve(std::vector<int> vec) {
   set<int> key(vec.begin(),vec.end());
   map<int,int> frequency;

  //Creating Key
  for(int keys : key){
    frequency[keys] = 0;
  }
  //

  //Counting Frequency
  for(int freq : vec){
     frequency[freq]++;
  }
  //

  //Convert map to 2d Vector
  vector<vector<int>> vect;
  for(pair<int,int> freq : frequency){
     vector<int> push = {freq.first,freq.second};
     vect.push_back(push);
  }
  //

  //sort by frequency
  int size = vect.size();
  for(int a = 1;a <= size;a++){
     int in1 = 0;
     for(int in2 = 1;in2 < size;in2++){
        int first = vect[in1][1];
        int second = vect[in2][1];
        if(first < second){
          vector<int> tmp = vect[in1];
          vect[in1] = vect[in2];
          vect[in2] = tmp;
        }
        in1++;
     }
  }
  int in1 = 0;
  for(int in2 = 1;in2 < size;in2++){
     int first = vect[in1][1];
     int second = vect[in2][1];
     if(first == second){
        first = vect[in1][0]; //3
        second = vect[in2][0]; //2
        if(first > second){
           vector<int> tmp = vect[in1];
           vect[in1] = vect[in2];
           vect[in2] = tmp;
        }
     }
  }
  //

  //reassemble
  vector<int> result;
  for(vector<int> v : vect){
     int size = v[1];
     for(int a = 1;a <= size;a++){
        result.push_back(v[0]);
     }
  }
  //
  return result;
}
