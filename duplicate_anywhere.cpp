/*

You are given a table, in which every key is a stringified number, 
and each corresponding value is an array of characters, e.g.

{
  "1": ["A", "B", "C"],
  "2": ["A", "B", "D", "A"],
}

Create a function that returns a table with the same keys, but each character should appear only once among the value-arrays, e.g.

{
  "1": ["C"],
  "2": ["A", "B", "D"],
}

Rules
(1). Whenever two keys share the same character, 
    they should be compared numerically, and the larger key will keep that character. 
    That's why in the example above the array under the key "2" contains "A" and "B", as 2 > 1.

(2). If duplicate characters are found in the same array, the first occurance should be kept.

*/

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

using msv = std::map<std::string, std::vector<char>>;

msv remove_duplicate_ids(msv obj){
  msv cpy_obj = obj;
  vector<string> keys;

  for(auto &key : obj){
    keys.push_back(key.first);
    sort(cpy_obj[key.first].begin(),cpy_obj[key.first].end());
  }
  
  sort(keys.begin(), keys.end(),                        
      [](const string& a, const string& b){                    
      return stoi(a) < stoi(b);                                                                                      
  });

  int size = keys.size();                                                                                                
  for(int a = 0;a < size;a++){
      for(int b = a + 1;b < size;b++){
          vector<char> duplicate;
          set_intersection(
            cpy_obj[keys[a]].begin(),
            cpy_obj[keys[a]].end(),
            cpy_obj[keys[b]].begin(),
            cpy_obj[keys[b]].end(),
            back_inserter(duplicate)
        );

        int duplicate_size = duplicate.size();
        int mid_index = duplicate_size / 2;

        if(duplicate_size == 0){
           continue;
        }

        duplicate.erase(unique(duplicate.begin(),duplicate.end()),duplicate.end());

        for(int ab = 0;ab < obj[keys[a]].size();ab++){          
            if(obj[keys[a]][ab] == duplicate[mid_index]){
               obj[keys[a]].erase(obj[keys[a]].begin() + ab);
               ab--;
               continue;
            }else if(obj[keys[a]][ab] < duplicate[mid_index]){
               for(int g = mid_index;g >= 0;g--){
                   if(obj[keys[a]][ab] == duplicate[g]){
                      obj[keys[a]].erase(obj[keys[a]].begin() + ab);
                      ab--;
                      break;
                   }
               }
               continue;
            }
            for(int g = mid_index;g < duplicate_size;g++){
               if(obj[keys[a]][ab] == duplicate[g]){
                 obj[keys[a]].erase(obj[keys[a]].begin() + ab);
                 ab--;
                 break;
               }
            }
        }
     }
  }

  char number[128];
  for(int a = 0;a < size;a++){
    memset(number,0,128);
    for(int b = 0;b < obj[keys[a]].size();b++){
       number[obj[keys[a]][b]]++;
       if(number[obj[keys[a]][b]] > 1){
          obj[keys[a]].erase(obj[keys[a]].begin() + b);
          b--;
       }
    }
  }
  return obj;
}
        
