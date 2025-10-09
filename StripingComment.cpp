#include <string>
#include <unordered_set>
#include <sstream>
#include <cctype>

std::string stripComments(
  const std::string& str,
  const std::unordered_set<char>& markers
){
    std::stringstream input(str);
    std::string line;
    std::string result;
    bool first = true;
    while (std::getline(input, line)) {
        for (size_t i = 0; i < line.size(); i++) {
            if (markers.count(line[i])) {
                line = line.substr(0, i);
                break;
            }
        }
        while (!line.empty() && std::isspace(static_cast<unsigned char>(line.back()))) {
            line.pop_back();
        }
        if (!first) result += "\n";
        result += line;
        first = false;
    }
    return result;
}
