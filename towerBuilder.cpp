/*

Build Tower Advanced

Build Tower by the following given arguments:

(1). number of floors (integer and always greater than 0)
(2). block size (width, height) (integer pair and always greater than (0, 0))

Example

tower of 3 floors with block size = (2, 3) looks like below

[
  '    **    ',
  '    **    ',
  '    **    ',
  '  ******  ',
  '  ******  ',
  '  ******  ',
  '**********',
  '**********',
  '**********'
]

tower of 6 floors with block size = (2, 1) looks like below

[
  '          **          ', 
  '        ******        ', 
  '      **********      ', 
  '    **************    ', 
  '  ******************  ', 
  '**********************'
]

*/



#include <vector>
#include <string>
#include <deque>

using namespace std;

std::vector<std::string> towerBuilder(int nFloors, int blockWidth, int blockHeight){
  deque<string> tower;
  int width = (nFloors - 1) * blockWidth * 2 + blockWidth;
  int total_space = blockWidth;

  for(int a = 1;a <= nFloors;a++){
     for(int b = 1;b <= blockHeight;b++){
        if(b > 1){
          tower.push_front(tower[0]);
          continue;
        }else if(a > 1){
          int total_mid = width - total_space * 2;
          string space(total_space,' ');
          string towerPart(total_mid,'*');

          string f;
          f.append(space);
          f.append(towerPart);
          f.append(space);

          tower.push_front(f);
          total_space += blockWidth;
          continue;
        }

        string first(width,'*');
        tower.push_front(first);
     }
  }

  vector<string> towers(tower.begin(),tower.end());
  return towers;
}
