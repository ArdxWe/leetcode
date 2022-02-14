/*
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water. The area of an
 * island is the number of cells with a value 1 on the island. Return the
 * maximum area of an island in grid. If there is no island, return 0.
 */

#include <vector>

namespace {
using std::max;
using std::vector;
}  // namespace

class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    // copy visited flag
    flag_.reserve(grid.size());
    for (const auto& item : grid) {
      flag_.emplace_back(item.size(), false);
    }

    int res = 0;

    // compute every node
    for (int i = 0; i < static_cast<int>(flag_.size()); i++) {
      for (int j = 0; j < static_cast<int>(flag_[0].size()); j++) {
        res = max(res, compute(grid, i, j));
      }
    }

    return res;
  }

 private:
  // get every node size, if this node has computed, return 0
  int compute(const vector<vector<int>>& grid, int i, int j) {
    if (i >= grid.size() || j >= grid[0].size()) {
      return 0;
    }
    if (grid[i][j] == 0 || flag_[i][j]) {
      return 0;
    }

    flag_[i][j] = true;

    int res = 1;

    res += compute(grid, i - 1, j) + compute(grid, i + 1, j) +
           compute(grid, i, j - 1) + compute(grid, i, j + 1);

    return res;
  }

 private:
  vector<vector<bool>> flag_{};
};
