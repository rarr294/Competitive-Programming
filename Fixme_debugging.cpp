#include <string>
#include <vector>
using namespace std;

class Dinglemouse {
    std::string name;
    int age;
    char sex; 
    vector<int> tracking;    
public:
    Dinglemouse(){}

    Dinglemouse &setAge(int a){
       // linear search 
       for(size_t b = 0; b < tracking.size(); b++){
          if(tracking[b] == 1){
             this->age = a;
             return *this;
          }
       }
      //
      tracking.push_back(1);
      this->age = a;
      return *this;
    }

    Dinglemouse &setSex(char s){       
       // linear search 
       for(size_t b = 0; b < tracking.size(); b++){
          if(tracking[b] == 2){
             this->sex = s;
             return *this;
          }
       }
      //
      tracking.push_back(2);
      this->sex = s;
      return *this;
    }

    Dinglemouse &setName(const std::string &n){     
        // linear search 
       for(size_t b = 0; b < tracking.size(); b++){
          if(tracking[b] == 3){
             this->name = n;
             return *this;
          }
       }
      //
      tracking.push_back(3);
      this->name = n;
      return *this;
    }

    std::string hello(){
       string value = "Hello. ";
       if (tracking.empty()){
          value.pop_back();
          return value;
       }         
       for (size_t a = 0; a < tracking.size(); a++) {
          if (tracking[a] == 1){
             value += "I am " + to_string(age) + ". ";
          }else if (tracking[a] == 2){
              if(sex == 'M'){
                 value += "I am male. ";         
              }else{
                 value += "I am female. ";
              }
          }else if(tracking[a] == 3){
              value += "My name is " + name + ". ";
          }
       }
       value.pop_back();
       return value;
    }
};
