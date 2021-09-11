/* Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right,
 * which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */

#include <cassert>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    assert(!grid.empty());
    assert(grid.size() > 0 && grid[0].size() > 0);

    int x = grid.size();
    int y = grid[0].size();

    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (i == 0 && j == 0) continue;

        int res;
        if (i - 1 >= 0 && j - 1 >= 0) {
          res =
              grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
        } else if (i - 1 >= 0) {
          res = grid[i - 1][j];
        } else {
          res = grid[i][j - 1];
        }
        grid[i][j] += res;
      }
    }
    return grid[x - 1][y - 1];
  }
};

/*
int main() {
  vector<vector<int>> x;
  x.push_back({1, 2, 3});
  x.push_back({4, 5, 6});

  Solution s;
  cout << s.minPathSum(x) << endl;
  return 0;
}
*/
