#include <bitset>
#include <string>
#include <cctype>
using namespace std;

bool is_pangram(const std::string &s) {
    std::bitset<26> b;
    for(char c : s) {
        if(std::isalpha(c)) {
            b.set(std::tolower(c) - 'a');
        }
    }
    return b.all(); 
}
