/* Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 */

#include <vector>

using std::vector;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int res = 0;
    vector<vector<int>> copy = triangle;

    for (int i = triangle.size() - 2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        copy[i][j] = copy[i + 1][j] > copy[i + 1][j + 1]
                         ? copy[i + 1][j + 1] + copy[i][j]
                         : copy[i + 1][j] + copy[i][j];
      }
    }
    return copy[0][0];
  }
};
