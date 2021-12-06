/* Write an efficient algorithm that searches for a target value in an m x n
 * integer matrix. The matrix has the following properties: Integers in each row
 * are sorted in ascending from left to right. Integers in each column are
 * sorted in ascending from top to bottom.
 */

#include <vector>

namespace {
using std::vector;
}  // namespace

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }

    int x = 0;
    int y = matrix[0].size() - 1;
    while (y >= 0 && x < matrix.size()) {
      if (matrix[x][y] == target) {
        return true;
      } else if (matrix[x][y] > target) {
        y--;
      } else {
        x++;
      }
    }

    return false;
  }
};
