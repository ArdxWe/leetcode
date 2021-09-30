/* Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands. An island is surrounded by water
 * and is formed by connecting adjacent lands horizontally or vertically. You
 * may assume all four edges of the grid are all surrounded by water.
 */

#include <vector>

using std::vector;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size(); i++) {
      flags_.push_back(vector<bool>(grid[0].size(), false));
    }
    m_ = grid.size();
    n_ = grid[0].size();

    for (int i = 0; i < flags_.size(); i++) {
      for (int j = 0; j < flags_[0].size(); j++) {
        if (grid[i][j] == 1 && !flags_[i][j]) {
          res_++;
          dfs(grid, i, j);
        }
      }
    }
    return res_;
  }

  void dfs(vector<vector<char>>& grid, int i, int j) {
    flags_[i][j] = true;

    if (i + 1 < m_ && grid[i + 1][j] == 1 && !flags_[i + 1][j]) {
      dfs(grid, i + 1, j);
    }

    if (i - 1 >= 0 && grid[i - 1][j] == 1 && !flags_[i - 1][j]) {
      dfs(grid, i - 1, j);
    }

    if (j + 1 < n_ && grid[i][j + 1] == 1 && !flags_[i][j + 1]) {
      dfs(grid, i, j + 1);
    }

    if (j - 1 >= 0 && grid[i][j - 1] == 1 && !flags_[i][j - 1]) {
      dfs(grid, i, j - 1);
    }
  }

 private:
  vector<vector<bool>> flags_{};
  int m_ = 0;
  int n_ = 0;
  int res_ = 0;
};
