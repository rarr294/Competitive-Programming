#include <vector>
#include <algorithm>

long nextBigger(long n) {
    std::vector<int> digits;
    long temp = n;
    while (temp > 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    int i = digits.size() - 2;
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        i--;
    }
    if (i < 0) {
        return -1;
    }
    int j = digits.size() - 1;
    while (digits[j] <= digits[i]) {
        j--;
    }
    std::swap(digits[i], digits[j]);
    std::reverse(digits.begin() + i + 1, digits.end());
    long result = 0;
    for (int d : digits) {
        result = result * 10 + d;
    }
    return result;
}
