#include <string>
#include <vector>
using namespace std;

std::vector<std::string> solution(const std::string &s){
     int str_size = s.size();
     vector<string> rest;
     if((str_size % 2) == 0){
             int index_1 = 0;
             int index_2 = 1;
             string concat = "";
             for(int b = 2;b <= str_size;b += 2){
                concat += s[index_1];
                concat += s[index_2];
                index_1 += 2;
                index_2 += 2;
                rest.push_back(concat);
                concat = "";
           }
           return rest;
     }
     str_size -= 1;
     int index_1 = 0;
     int index_2 = 1; 
     string concat = "";
     for(int b = 2;b <= str_size;b += 2){
            concat += s[index_1];
            concat += s[index_2];
            index_1 += 2;
            index_2 += 2;
            rest.push_back(concat);
            concat = "";
      }
       concat = s[str_size];
       concat += '_';
      rest.push_back(concat);
      return rest;
}
