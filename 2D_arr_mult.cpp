#include <vector>
using namespace std;

vector<vector<int>> multiplication_table(int n){
   vector<vector<int>> mult;
   
   //creating row
   for(int a = 1;a <= n;a++){
     mult.push_back({});
   }
   //
  
   //filling the first row
   for(int a = 1;a <= n;a++){
     mult[0].push_back(a);
   }
   //
  
   //generating other row
   int mult_size = mult.size()-1;
   int size = mult[0].size()-1; 
   int b = 1;
   for(int a = 1;a <= mult_size;a++){    
      for(;b <= size;){
         for(int c = 0;c <= size;c++){           
           mult[a].push_back(
              (mult[0][b] * mult[0][c])
           );
         }
         b++;
         break;
      }
   }
  //
  return mult;
}
