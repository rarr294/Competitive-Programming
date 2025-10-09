#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

long parse_int(const string &numberStr) {
    unordered_map<string, int> numbers = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
        {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
        {"eighteen", 18}, {"nineteen", 19},
        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
        {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}
    };
    long result = 0;       
    long current = 0;      
    string word;
    stringstream ss(numberStr);
    while (ss >> word) {
        if (word == "and") {
            continue; 
        } else if (numbers.count(word)) {
            current += numbers[word];
        } else if (word == "hundred") {
            current *= 100;
        } else if (word == "thousand") {
            result += current * 1000;
            current = 0;
        } else if (word == "million") {
            result += current * 1000000;
            current = 0;
        } else {
            size_t dash = word.find('-');
            if (dash != string::npos) {
                string left = word.substr(0, dash);
                string right = word.substr(dash + 1);
                if (numbers.count(left)) current += numbers[left];
                if (numbers.count(right)) current += numbers[right];
            }
        }
    }
    return result + current;
}
