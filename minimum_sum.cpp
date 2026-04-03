/*

Given a 2D ( nested ) list ( array, vector, .. ) of size m * n, 
your task is to find the sum of the minimum values in each row.

For Example:

[ [ 1, 2, 3, 4, 5 ]        #  minimum value of row is 1
, [ 5, 6, 7, 8, 9 ]        #  minimum value of row is 5
, [ 20, 21, 34, 56, 100 ]  #  minimum value of row is 20
]

So the function should return 26 because the sum of the minimums is 1 + 5 + 20 = 26.
Note: You will always be given a non-empty list containing positive values.

*/



#include <vector>

using namespace std;

int sum_of_minimums(vector<vector<int>> num){
  int sum = 0;
  int size = num.size();

  for(int a = 0;a < size;a++){
    int smallest = num[a][0];
    int arr_size = num[a].size();

    for(int b = 1;b < arr_size;b++){

      if(num[a][b] < smallest){
        smallest = num[a][b];
      }
    }

    sum += smallest;
  }

  return sum;
}
