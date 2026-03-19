/*

Write a function that returns the center of a 2-dim array.
You can assume all inputs will be rectangular matrices in array form. 
ex: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

*/

#include <vector>
#include <optional>

using opt_int_t = std::optional<int>;
using matrix_t = std::vector<std::vector<int>>;

using namespace std;

opt_int_t center(const matrix_t& mat) {
  return(
    ((mat.size() % 2) != 0)
    &&
    ((mat[0].size() % 2) != 0)
  ) ? (opt_int_t)(mat[mat.size() / 2][mat[0].size() / 2]) : nullopt;
}
