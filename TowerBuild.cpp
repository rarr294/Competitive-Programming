#include <string>
#include <vector>
using namespace std;

std::vector<std::string> towerBuilder(unsigned nFloors){
  std::vector<std::string> tower = {""};
  int term = 1 + (nFloors-1) * 2;
  int a = 1;
  while(a <= term){
    std::string temp = "";
    int b = 1;
    while(b <= a){
      temp.push_back('*');
      b++;
    }
    tower.push_back(temp);
    a += 2;
  }
  tower.erase(tower.begin()); 
  int counter = 1;
  int tower_size = tower.size()-2;
  while(tower_size >= 0){
    int b = 1;
    while(b <= counter){
      tower[tower_size].insert(
        tower[tower_size].begin(),' '
      );
      tower[tower_size].push_back(' ');
      b++;
    }
    counter++;
    tower_size--;
  }  
  return tower;
}
