#include <vector>
using namespace std;

typedef unsigned long long int64;

int64 powInt(int64 base, int64 p) {
    int64 result = 1;
    for(int i = 0; i < p; i++) {
       result *= base;
    }
    return result;
}

class DigPow{
public:
    static int digPow(int n, int p) {
       int cpy = n;
       vector<int> base;

       // extract digit
       while (n != 0) {
         int digit = n % 10;
         base.push_back(digit);
         n /= 10;
       }

       //exponent
       int size = base.size() - 1;
       vector<int64> exponential;
       for(; size >= 0; size--) {
          exponential.push_back(powInt(base[size], p));
           p++;
       }

       // sum
        int64 sum = 0;
        for (int64 val : exponential) {
            sum += val;
        }

        // modulo & division
        if (sum % cpy == 0) {
            return sum / cpy;
        }
        return -1;
    }
};
