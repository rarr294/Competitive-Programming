#include <vector>
#include <numeric> 
unsigned long long solution(const std::vector<unsigned long long>& arr){
    if(arr.empty()){
      return 0;
    }
    unsigned long long g = arr[0];
    for(size_t i = 1; i < arr.size(); ++i){
        g = std::gcd(g, arr[i]);
    }
    return g * arr.size();
}
